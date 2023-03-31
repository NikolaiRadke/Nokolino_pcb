/*  Nokolino V4.0 31.03.2023 - Nikolai Radke
 *  
 *  Sketch for Mini Noko monster with new DFPlayer module
 *  For ATtiny45/85 - set to 8 Mhz and remember to flash your bootloader first
 *  DFPlayer: JL-AA19HFF851-94  works good
 *            YX5200-24SS       original player, works
 *            MH2024K-24SS      works slow, needs delays to set volume. Only 220920 has USB!
 *            GD3200B           makes too much noise, depends on amplifier chip. 
 *                              Only 2108xxxxxx has USB support.
 *            Most Chips support sleep mode, but no wake up...
 *  
 *  Flash usage: 4.012 (IDE 2.0.4 | AVR 1.8.6 | ATtiny 1.0.2 | Linux X86_64 | ATtiny85 )
 *  
 *  Circuit:
    1: RST | PB5  Free
    2: D3  | PB3  Button - GND 
    3: A2  | PB4  Busy   - 16 DFPlayer
    4: GND |      GND
    5: D0  | PB0  Power  - 01 DFPlayer
    6: D1  | PB1  TX     - 02 DFPlayer 
    7: D2  | PB2  RX     - 03 DFPlayer
    8: VCC        VCC
 *  
 *  Sleepmodes:
 *  0=16ms, 1=32ms, 2=64ms, 3=128ms, 4=250ms, 5=500ms
 *  6=1sec, 7=2sec, 8=4sec, 9=8sec
 *
 *  Changelog: Found an old battery low flag bug 
 */

#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>

//--------------------------------------------------------------------------------
// Configuation
#define Time         10                  // Say something every statistical 10 minutes
#define Volume       22                  // Volume 0-30 - 22 is recommended 
#define Sleep        1                   // Minutes to go to sleep - 1 hour default

#define Button_event 40                  // Last button event number (XXX.mp3)
#define Time_event   163                 // Last time event number -> Very last file is "beep"

#define Offset       0.1                 // Battery measuring error
#define maxInput     600                 // Max. value from busy line 

// Optional - comment out with // to disable o remove // to enable
#define StartupBeep                      // Will say "beep" when turned on
#define DeepSleep                        // Will go to deep sleep after ...
#define BatteryWarning                   // Gives a warning when battery is low

//---------------------------------------------------------------------------------

// Optional battery warning
#define minCurrent   3.30+Offset         // Low power warning current + measuring error
#define battLow      3.10+Offset         // Minimal voltage before DFPlayer fails

// Hardware pins
#define TX           PB1
#define RX           PB2
#define Busy         A2
#define DFPlayer     PB0
#define Button       PB3

// DFPlayer commands
#define SetVolume    0x06 
#define Play         0x0F 
#define Count        0x48

// ADC and BOD
#ifndef cbi
  #define cbi(sfr,bit) (_SFR_BYTE(sfr)& ~_BV(bit))
#endif
#ifndef sbi
  #define sbi(sfr,bit) (_SFR_BYTE(sfr)|=_BV(bit))
#endif
#define BODS 7                           // BOD sleep bit in MCUCR
#define BODSE 2                          // BOD sleep enable bit in MCUCR

// Variables
uint16_t seed,files;
uint16_t address=1;
boolean  low=false;                      // Set if battery too low
boolean  musicbox=false;                 // Set if in music box mode
char     count_files;                    // Files as char
uint8_t  files_byte[10];                 // Translate char to byte 
uint32_t countdown = 0;

SoftwareSerial mp3(TX,RX);               // TX to D2, RX to D1
ISR (PCINT3_vect) {}                     // Set hardware Interrupt on D3

int main(void) {

  #ifdef BatteryWarning
    double vref;
    uint16_t counter=10;                 // Check shortly after startup
  #endif

  init(); {
    // Power saving
    MCUCR |= _BV(BODS) | _BV(BODSE);     // Disable brown out detection - default?
    ACSR |= _BV(ACD);                    // Disable analog comparator - default?
    setup_watchdog(3);                   // Set sleep time to 128ms  

    // Port Setup
    DDRB &= ~(1 << Button);              // D3 Button INPUT
    PORTB |= (1 << Button);              // D3 INPUT_PULLUP 
    DDRB |= (1 << DFPlayer);             // DFPlayer MOSFET switch
    PORTB &= ~(1 << DFPlayer);	         // LOW = power on

    // Start DFPlayer
    newdelay(2000);                      // Delay +500ms for MH2024k
    mp3.begin(9600);                     // Init Player
    newdelay(500);                       // Give DFPlayer time to settle
    command(SetVolume, 0, Volume, 245 - Volume);// Send volume command
    newdelay(50);                        // Delay for MH2024K

    // Set play mode | Button pressed = music box mode
    if (!(PINB & (1 << Button))) musicbox = true;  
    
    if (!musicbox) {
      // Randomize number generator
      address = eeprom_read_word(0);     // Read EEPROM address
      if ((address < 2) || (address > (EEPROM.length() - 3))) {           
        // Initialize EEPROM and size for first use or after end of cycle
        address = 2;                     // Starting address
        eeprom_write_word(0, address);   // Write starting address
        eeprom_write_word(address, 0);   // Write seed 0
      }
      seed = eeprom_read_word(address);  // Read seed
      if ( seed > 900) {                 // After 900 write-cyles move to another address
        seed = 0;                        // to keep the EEPROM alive
        address += 2;
        eeprom_write_word(0, address);
      }
      randomSeed(seed);                  // Randomize
      seed ++;                           // New seed
      eeprom_write_word(address,seed);   // Save new seed for next startup     
    }
    else {
      // Count files on card for music box mode | getfoldercount is broken on most devices
      command(Count, 0, 0, 179);
      for (seed = 0; seed < 10; seed ++) {// Read 10 HEX chars from module
        newdelay(100);                   // Delay for MH2024K
        files_byte[seed] = (uint8_t) mp3.read();// Convert red chars into uint8_t
      }
      files = files_byte[6] - 164;       // Substract speech set files for files in 02
    }

    // Optional startup beep
    #ifdef StartupBeep    
      play(Time_event + 1, 1);                // Nokolino says "Beep"       
    #endif 
  }

  // Main loop
  while(1) {
    // Wait for button or time and go to sleep - ~8 times/second         
    if (!low) {                          // Quiet if battery too low
      if (!(PINB & (1 << Button))) {     // If button is pressed then
        if (!musicbox) 
          play(random(0,Button_event + 1), 1);// Button event
        else {
          play(address, 2);              // or single music box files 
          (address == files)? address = 1 : address ++;
        }
      }
      else if ((!musicbox) && (random(0, Time * 60 * 8) == 1))// Time event
        play(random(Button_event + 1, Time_event + 1), 1); 
    }
  
    // Optional: Deep sleep 
    #ifdef DeepSleep
      if (countdown > Sleep * 433) {     // Check timer for deep sleep
        mp3.end();                       // Stop connection to JQ8400
        PORTB &= ~(1 << TX);	           // and power down pins
        PORTB &= ~(1 << RX);	           // to prevent drawing current from serial connection
        PORTB |= (1 << DFPlayer);        // Shut down JQ8400
        PCMSK |= bit (3);                // Set interrupt pin
        GIFR  |= bit (PCIF);             // Clear any outstanding interrupts
        GIMSK |= bit (PCIE);             // Enable pin change interrupts     
        WDTCR |= (1<<WDCE) | (1<<WDE);
        WDTCR = 0x00;                    // Disable watchdog
      }      
    #endif

    // Optional: Check current
    #ifdef BatteryWarning
      if (counter == 0) {
        low = false;                     // Reset warning flag
        vref = 1024 * 1.1f / (double)MeasureVCC();// Calculate battery current
        if (vref <= minCurrent) {        // Current below minimum
          if (vref <= battLow) low=true; // Power too low
          else play(Time_event + 1, 1);  // Nokolino says "Beep"
        }
        counter=433;                     // Every minute, 433x128ms+some runtime ms for 60s
      }
      counter --;
    #endif

    attiny_sleep();                      // Save power, about 7mA
  }
}

void play(uint8_t file, uint8_t folder) {// Plays M3 file in folder 01 or 02
  //command(0x0B, 0, 0, 240);            // Wake up DFPlayer - sleep is working, but not wakeing up
  command( Play, folder, file, 236 - file - folder);
  newdelay(1000);                        // Busy line needs time to settle
  while (analogRead(A2)<maxInput) {      // Check busy and play until end of file
    if ((musicbox) && (!(PINB & (1<<Button)))) {  // button pressed in music box mode
      newdelay(3000);                    // Wait 3 sec
      if (!(PINB & (1<<PB0))) break;     // Play next file if button is still pressed
    }
    attiny_sleep();                      // Save power while playing
  }
  //command(0x0A, 0, 0, 241);            // Send DFPlayer to sleep | Useless    
}

void command(uint8_t CMD,uint8_t CMD2,uint8_t VAL,uint8_t CHK) {
  mp3.write("\x7E\xFF\x06");
  mp3.write(CMD);                        // Write command
  mp3.write((uint8_t) 0x00);
  mp3.write(CMD2);                       // Write second command
  mp3.write(VAL);                        // Write value
  mp3.write("\xFE");
  mp3.write(CHK);                        // Write checksum
  mp3.write("\xEF");
  newdelay(100);                      
}

void attiny_sleep() {                    // Sleep to save power  
  uint8_t adcsra = ADCSRA;               // Save ADC control and status register A
  cbi(ADCSRA, ADEN);                     // Switch ADC off
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);   // Deep sleep
  sleep_mode();                          
  sbi(ADCSRA, ADEN);                     // Switch ADC on
  ADCSRA = adcsra;                       // Set ADCSRA register 
  countdown ++;                          // Countdown to deep sleep
}

void newdelay(uint16_t z) {              // New delay function to save flash
  uint32_t zmillis=millis();
  while (millis()-zmillis<z);
}

void setup_watchdog(uint8_t mode) {      // Setup wake time
  uint8_t bb;
  bb=mode & 7;
  if (mode>7) bb|= (1<<5);
  bb|= (1<<WDCE);
  MCUSR &= ~(1<<WDRF);
  WDTCR |= (1<<WDCE) | (1<<WDE);
  WDTCR = bb;
  WDTCR |= _BV(WDIE);
}

uint16_t MeasureVCC(void) {              // Thank you, Tim!
  PRR     &=~_BV(PRADC); 
  ADCSRA  =_BV(ADEN)|_BV(ADPS2)|_BV(ADPS1)|_BV(ADPS0); 
  ADMUX   =_BV(REFS2) | 0x0c; 
  newdelay(1); 
  ADCSRA  |=_BV(ADSC);
  while (!(ADCSRA&_BV(ADIF))); 
  ADCSRA  |=_BV(ADIF);
  return ADC;
}

ISR(WDT_vect) {}                         // Interrupt routine
 