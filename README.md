# ![NOKO](http://www.nikolairadke.de/NOKOlino/nokolino_klein.png) NOKOlino

The ATTiny-based litte brother of NOKO. Tiny and cute. And everyone is invited to **contribute**. NOKOlino is for everyone. This Repository ist for the **PCB** version of NOKOlino, easy and fast to build. See [PCB](https://github.com/NikolaiRadke/NOKOlino_2/tree/master/PCB.md). on how to get your own boards.  
  
What's new? See the [newsblog](https://github.com/NikolaiRadke/NOKOlino_2/tree/master/NEWS.md)  

![NOKOlino light blue](http://www.nikolairadke.de/NOKOlino/nokolino_wiki.png)
  
Like his big brother **NOKO**, the little NOKOlino delights it's surroundings with cheeky comments. But unlike NOKO he is more obstinate - no radio, a display, no frills. Instead of an Arduino he has a small **ATtiny** microcontroller, only one on-off switch and a big button. But he is small, can stay active for days and is, in contrast to his big brother, very easy to build.  
  
Another useful application option would be to use the hardware without the monster suit as a **music box** in an old used doll to bring it back to modern days, maybe with other sounds or songs.  

What does he to - technically? Whenever you press his button, he will laugh. And when he's just turned on, he says something random randomly every statistically 10 minutes. That's ist. Quiet a lot for a stuffed monster!  
  
**NOKOlino** stands for **NO**ra and Ni**KO**s monster - the appendix **lino** describes the small version.  
  
### Notes for non-German NOKOlino makers  
  
Right now, the building wiki, the voice set and the manual are in German. I'll try to translate the wiki and the manual on day. Until then, feel free to ask me for translation, if you need help. **Contribute!** I need an English voice set and English text files. In addition, any other language is welcome, NOKO is to be cosmopolitan!
  
### Prerequisites
  
NOKOlino needs Arduino IDE 1.6.6 or newer (https://www.arduino.cc/en/Main/Software). Copy the folder `NOKOlino/src/NOKOlino/` into your sketch folder and install ATtiny support. See [how to compile](https://github.com/NikolaiRadke/NOKOlino_2/tree/master/howto_compile) for further instructions. 
  
### Content

```
NOKO/
├── howto_compile/
|   Manual how compile the sketches in your Arduino IDE and precompiled sketched  
|   └── precompiled/
|       Precompiled hex files
|       ├── ATtiny45/
|       |   Version for the ATtiny45.
|       └── ATtiny85/
|           Version for the ATtiny85.
|
├── linux_uploader/
|   Tool for uploading MP3-files to the JQ6500.
|
├── manual/
|   NOKO manual in PDF format and a template for a packaging design.
|   └── scribus/
|       Source documents for Scribus with all illustrations and fonts.
|
├── mp3/
|   Voice sets for the 4MB-JQ6500 in German. English needed? Contribute!
|   ├── male/
|   |   Male voice set, spoken by Carsten Caniglia.
|   └── female/
|   |   Female voice set, spoken by Norma Anthes
|
├── schematics/
|   The schematics for the NOKOlino parts, the NOKO sewing pattern and shopping list.
|   └── gerber/
|       The gerber files for the PCB to build by your own.
|
└── src/
    ATtiny sketch
    └── NOKOlino/
        One file, no libraries, no frills. Just NOKOlino. 
```
### Let's get started!

Interested in NOKOlino? Great! Let's start here:  
[German wiki](https://github.com/NikolaiRadke/NOKOlino_2/wiki).  
English wiki will follow. One day...
