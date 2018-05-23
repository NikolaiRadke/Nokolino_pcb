# Voice set for NOKOlino - German

There are foursets: a large male and a large female voice. Both need a **32 MBit** or bigger variant of the JQ6500 module. If you have an older, smaller **16 MBit** variant of the module, you need the smaller male or female version.  

Copy these mp3s on the JQ6500 module. Strictly observe the sequence!
021.mp3 must be copied as the 21st file. See the [Wiki](https://github.com/NikolaiRadke/NOKOlino_2/wiki/MP3s-aufspielen) for more 
detailed instructions.  

**Windows** users can use the (chinese) interface. See this [instructions](http://sparks.gogo.co.nz/jq6500/index.html), written by James Sleeman. **Linux** and **Mac** users should try the [uploading tool](https://github.com/NikolaiRadke/NOKOlino_2/tree/master/linux_uploader), written by Max Reinhard.  
  
**32 Mbit:**  

| Number  | Assignment               |
| --------|-------------------------:|
| 001-040 | Response to belly button |
| 041-163 | Time based events        |
| 164     | BEEP battery warning     |
  
**16 Mbit:**  

| Number  | Assignment               |
| --------|-------------------------:|
| 001-020 | Response to belly button |
| 021-069 | Time based events        |
| 070     | BEEP battery warning     |
  
The male voice has been spoken by my fellow actor [Carsten Caniglia](https://filmmakers.de/carsten-caniglia). Why? 
He has done a great job - moreover I don't want to listen to my own voice every day, especially when development takes more than a year! (Ian said I sound really weird in real life. Thanks, mate.). The female voice was spoken by my fellow actress [Norma Anthes](http://norma-anthes.de). Thank you, lady!    

### Your own voice set  
  
You want to use your own files? No problem. Look into the sketch **NOKOlino.ino**, set the definition **Set_own** and change the lines  
``` #define Button_event  0 ```  for the last voice file when the button is pressed and  
``` #define Time_event   0``` for the last voice file for the time based events.  
The *beep* for the battery warning should be the last file.  
  
Keep in your mind, that the device ist limited to **4Mbyte - 256kb** or **2Mbyte - 256kb**!  
