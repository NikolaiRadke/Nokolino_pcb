# Voice set for Nokolino - German

Here you find four voice sets: Nokolino for the male and Nokolina for the female version, each with **2MB** for **16 MBit JQ6500** modules and **4MB** for the **32 MBit JQ6500 and JQ8400** modules.  

## JQ8400  
  
Plug in your JQ8400-module or Nokolino, delete the old files and copy the new mp3s on the module. Strictly observe the sequence! 021.mp3 must be copied as the 21st file. See the Wiki for more detailed instructions.

Linux and Mac can copy the files by simply marking them all and draging them into the folder. Windows has it's issues with the copying sequence. You can either copy them one by one oder use a copy tool like SmartCopyTool.

## JQ6500
  
**Windows** users can use the (chinese) interface. See this [instructions](http://sparks.gogo.co.nz/jq6500/index.html), written by James Sleeman. if you want an English interface or is the interface missing, look at my [JQ6500 rescue tool](https://github.com/NikolaiRadke/JQ6500-rescue-tool).  
  
**Linux** and **Mac** users should try the [uploading tool](https://github.com/NikolaiRadke/Nokolino_pcb/tree/master/linux_uploader), written by Max Reinhard.  

## Voice set structure  
  
**4MB**  

| Number  | Assignment               |
| --------|-------------------------:|
| 001-040 | Response to belly button |
| 041-163 | Time based events        |
| 164     | BEEP battery warning     |
  
**2MB**  

| Number  | Assignment               |
| --------|-------------------------:|
| 001-030 | Response to belly button |
| 031-079 | Time based events        |
| 080     | BEEP battery warning     |
  
The male voice has been spoken by my fellow actor [Carsten Caniglia](https://filmmakers.de/carsten-caniglia). Why? 
He has done a great job - moreover I don't want to listen to my own voice every day, especially when development takes more than a year! (Ian said I sound really weird in real life. Thanks, mate.). The female voice was spoken by my fellow actress [Norma Anthes](http://norma-anthes.de). Thank you, lady!    

### Your own voice set  
  
You want to use your own files? No problem. Look into the sketch **Nokolino.ino**. Change the lines  
``` #define Button_event  0 ```  for the last voice file when the button is pressed and  
``` #define Time_event   0``` for the last voice file for the time based events.  
The *beep* for the battery warning should be the last file.  
In **V3.0** set the definition **Set_own**. The **JQ6500** allows up to **65536** files, if the fit into the flash memory. The **JQ8400** is due programing issues limited to **255** files. That seems to be still enough.  
  
Keep in your mind, that the **JQ6500** memory is limited to **4Mbyte - 256kb** or **2Mbyte - 256kb**! The **JQ8400** provides full **4Mbyte**. 
