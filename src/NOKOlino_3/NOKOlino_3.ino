/* Nokolino V3.0 30.12.2019 - Nikolai Radke
 *  
 *  Sketch for Mini-Noko-Monster - NOT WORKING WITH V2.X HARDWARE!
 *  For Attiny85 | 8 Mhz - remember to flash your bootloader first
 *  For Attiny45 - disable ALL optional features to fit into flash
 *  SoftwareSerial needs 8 MHz to work correctly
 *  
 *  Flash-Usage: 4.832 (1.8.10 | ATTiny 1.0.2 | Linux X86_64 | ATtiny85 | BatteryWarning & StartupBeep)
 *  
 *  Circuit:
 *  1: RST | PB5  free
 *  2: A3  | PB3  Optional SFH300  
 *  3: A2  | PB4  Busy JQ6500 - 8
 *  4: GND        GND
 *  5: D0  | PB0  Button      - GND
 *  6: D1  | PB1  RX JQ6500   - 9   
 *  7: D2  | PB2  TX JQ6500   - 10       
 *  8: VCC        VCC
 *  
 *  Sleepmodes:
 *  0=16ms, 1=32ms, 2=64ms, 3=128ms, 4=250ms, 5=500ms
 *  6=1sec, 7=2sec, 8=4sec, 9=8sec
 */

#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <SoftwareSerial.h>
#include <EEPROM.h>

//--------------------------------------------------------------------------------
// Configuation
#define Time         10             // Say something every statistical 10 minutes
#define Volume       25             // Volume 0-30 - 25 is recommended 
#define Darkness     4              // Optional: The lower the darker the light must be

//#define Breadboard                // Breadboard or PCB?

// Own voice set?
//#define Set_own                   // Up to 16k files - if they fit into the flash...

#ifdef Set_own
  #define Button_event_own 0        // Last button event number (XX.mp3)
  #define Time_event_own   0        // Last time event number
#endif

#ifdef Breadboard
  #define Offset       0.3          // Battery measuring error
  #define maxInput     50           // Max. value from busy line 
#else
  #define Offset       0.1
  #define maxInput     0
#endif

// Optional - comment out with // to disable o remove // to enable
#define BatteryWarning              // Gives a warning when battery is low
//#define LightSensor               // Will be quite in the dark
//#define SleepComplain             // Will complain if button pressed while its dark
#define StartupBeep                 // Will say "beep" when turned on

//---------------------------------------------------------------------------------

// Optional battery warning
#define minCurrent   3.60 +Offset   // Low power warning current + measuring error
#define battLow      3.50 +Offset   // Minimal voltage before JQ6500 fails

// Hardware pins
#define TX      2
#define RX      1
#define Busy    2

// ADC and BOD
#ifndef cbi
  #define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
  #define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif
#define BODS 7                         // BOD sleep bit in MCUCR
#define BODSE 2                        // BOD sleep enable bit in MCUCR

// Variables
uint16_t address,seed,files;
uint16_t Button_event=30;
uint16_t Time_event=79;
volatile boolean f_wdt = 1;            // Volatile -> it is an interrupt routine
boolean  low=false;
boolean  dark=false;
char     buffer[4];

SoftwareSerial mp3(TX,RX);             // TX to D2, RX to D1

int main(void) {

#ifdef BatteryWarning
  uint16_t current;
  double vref;
  uint16_t counter=10;                 // Check shortly after startup
#endif

init(); {
  // Power saving
  MCUCR |= _BV(BODS) | _BV(BODSE);     // Disable brown out detection - default?
  ACSR |= _BV(ACD);                    // Disable analog comparator - default?
  DDRB &= ~(1<<PB0);                   // D0 INPUT
  PORTB |= (1<<PB0);                   // D0 HIGH 

  // Loop if there is a USB data connection for upload
  setup_watchdog(6);                   // Set sleep time to 1000ms  
  if (!(PINB & (1<<PB0))) {            // If button is pressed during startup
    while(1) attiny_sleep();           // sleep forever to upload files to JQ6500
  }

  // Start JQ6500
  mp3.begin(9600);
  mp3.write("\x7E\x02\x0C\xEF");       // Reset JQ6500
  delay(500);
  mp3.write("\x7E\x03\x11\x04\xEF");   // No loop
  delay(200);
  while (mp3.available()) mp3.read();  // Clear serial buffer
  mp3.write("\x7E\x02\x49\xEF");       // Count files on module
  delay(10);
  for (seed=0;seed<4;seed++) {         // Read 4 chars from module
    buffer[seed] = mp3.read();
  }
  files=(byte) strtoul(buffer,0,16);   // Convert to unsigned int

  // Nokolino mode | else Music box mode
  if (files>1) {
    // Randomize number generator
    address=eeprom_read_word(0);       // Read EEPROM address
    if ((address<2) || (address>(EEPROM.length()-3))) {           
    // Initialize EEPROM and size for first use or after end of cycle
      address = 2;                     // Starting address
      eeprom_write_word(0,address);    // Write starting address
      eeprom_write_word(address,0);    // Write seed 0
    }
    seed=eeprom_read_word(address);    // Read seed
    if (seed>900) {                    // After 900 write-cyles move to another address
      seed=0;                          // to keep the EEPROM alive
      address+=2;
      eeprom_write_word(0,address);
    }
    randomSeed(seed);                  // Randomize
    seed++;                            // New seed
    eeprom_write_word(address,seed);   // Save new seed for next startup

    // Select voice set
    if (files>80) {                    // Preset is 16MBit
      Button_event=40;                 // Set to 32MBit if more files
      Time_event=163;
    }
    #ifdef set_own                     // Or own voice set
      Button__event=Button_event_own;
      Time_event=Time_event_own
    #endif
    
    // Optional startup beep
    #ifdef StartupBeep
      delay(200);
      JQ6500_play(files);              // Nokolino says "Beep"
    #endif
  }
  
  mp3.write("\x7E\x02\x0A\xEF");       // Sleep, JQ6500!
  setup_watchdog(3);                   // Set sleep time to 128ms   
}

// Main loop
while(1) {
  // Wait for button or time and go to sleep - ~8 times/second         
  if (!low) {                          // Quiet if battery too low
    if (!(PINB & (1<<PB0))) {          // If button is pressed then
      if (dark) {                      // if fototransistor is available
        #ifdef SleepComplain           // and complain feature enabled
          if (files>1) {               // and not in music box mode
            JQ6500_play(Time_event);   // complain when button pressed
        #endif
      }
      else if (files>1) JQ6500_play(random(0,Button_event+1)); // Button event
      else JQ6500_play(1);             // or single music box file
    }
    else if ((!dark) && (files>1) && (random(0,Time*60*8)==1)) // Time event
      JQ6500_play(random(Button_event+1,Time_event+1)); 
  }
  attiny_sleep();                      // Safe battery
  
  // Optional: Check current
  #ifdef BatteryWarning
    if (counter==0) {
     current=MeasureVCC();
     vref=1024*1.1f/(double)current;
     if (vref<=minCurrent) {           // Current below minimum
       if (vref<=battLow) low=true;    // Power too low for JQ6500
       else JQ6500_play(Time_event+1); // Nokolino says "Beep"
     }
     else low=false;
     counter=400;                      // Every minute, 50x 128ms + some sleeping ms
    }
    counter--;
  #endif

  // Optional: Check darkness
  #ifdef LightSensor
    if (analogRead(A3)<=Darkness) dark=true;
    else dark=false;
  #endif
}}

void JQ6500_play(uint8_t f) {          // Plays MP3 number f
  mp3.write("\x7E\x03\x06");
  mp3.write(Volume);                   // Set volume
  mp3.write("\xEF");                   // JQ6500 looses volume settings after sleep... 
  delay(200);
  mp3.write("\x7E\x04\x03\x01");       // Play file number f
  mp3.write(f);
  mp3.write("\xEF");
  delay(200);
  while (analogRead(A2)>maxInput) attiny_sleep(); // Check busy
  mp3.write("\x7E\x02\x0A\xEF");       // Go back to sleep, JQ6500!
  delay(200);
}

void attiny_sleep() {                  // Sleep to save power  
  cbi(ADCSRA,ADEN);                    // Switch ADC off
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); 
  sleep_mode();                                         
  sbi(ADCSRA,ADEN);                    // Switch ADC on
}

void setup_watchdog(uint8_t mode) {    // Setup wake time
  uint8_t bb;
  bb=mode & 7;
  if (mode > 7) bb|= (1<<5);
  bb|= (1<<WDCE);
  MCUSR &= ~(1<<WDRF);
  WDTCR |= (1<<WDCE) | (1<<WDE);
  WDTCR = bb;
  WDTCR |= _BV(WDIE);
}

uint16_t MeasureVCC(void) {           // Thank you, Tim!
  PRR    &=~_BV(PRADC); 
  ADCSRA  =_BV(ADEN)|_BV(ADPS2)|_BV(ADPS1)|_BV(ADPS0); 
  ADMUX   =_BV(REFS2) | 0x0c; 
  _delay_ms(1);  
  ADCSRA  |=_BV(ADSC);
  while (!(ADCSRA&_BV(ADIF))); 
  ADCSRA  |=_BV(ADIF);
  return ADC;
}

ISR(WDT_vect) {                       // Set global flag
  f_wdt=1; 
}
