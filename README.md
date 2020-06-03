# ![Nokolino](http://www.nikolairadke.de/Nokolino/nokolino_back.jpg)  
  
*** **This Repository is currently under reconstruction - 03.06.2020** ***

The ATtiny-based litte brother of Noko. Tiny and cute. And everyone is invited to **contribute**. Nokolino is for everyone. This repository is for the **PCB** version of Nokolino, easy and fast to build. See [PCB](https://github.com/NikolaiRadke/NOKOlino_2/tree/master/PCB.md) on how to get your own boards. Do you own a complete kit? Look [here](https://github.com/NikolaiRadke/Nokolino).    
  
What's new? See the [newsblog](https://github.com/NikolaiRadke/NOKOlino_2/tree/master/NEWS.md).   

![Three NOKOlinos](http://www.nikolairadke.de/NOKOlino_2/nokolinos.png)
  
Like his big brother **Noko**, the little Nokolino delights it's surroundings with cheeky comments. But unlike Noko he is more obstinate - no radio, a display, no frills. Instead of an Arduino he has a small **ATtiny** microcontroller, only one on-off switch and a big button. But he is small, can stay active for days and is, in contrast to his big brother, very easy to build.  
  
Another useful application option would be to use the hardware without the monster suit as a **music box** in an old used doll to bring it back to modern days, maybe with other sounds or songs.  

What does he to - technically? Whenever you press his button, he will laugh. And when he's just turned on, he says something random randomly every statistically 10 minutes. That's ist. Quiet a lot for a stuffed monster!  
  
**Nokolino** stands for **No**ra and Ni**ko**s monster - the appendix **lino** describes the small version.  
  
### Notes for non-German Nokolino makers  
  
Right now, the building wiki, the voice set and the manual are in German. I'll try to translate the wiki and the manual on day. Until then, feel free to ask me for translation, if you need help. **Contribute!** I need an English voice set and English text files. In addition, any other language is welcome, NOKO is to be cosmopolitan!
  
### Prerequisites
  
Nokolino needs Arduino IDE 1.6.6 or newer (https://www.arduino.cc/en/Main/Software). Copy the folder `NOKOlino_2/src/NOKOlino/` into your sketch folder and install ATtiny support. See [how to compile](https://github.com/NikolaiRadke/NOKOlino_2/tree/master/howto_compile) for further instructions. 
  
### Content

```
Nokolino/
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
|   Nokolino manual in PDF format and a template for a packaging design.
|   └── scribus/
|       Source documents for Scribus with all illustrations and fonts.
|
├── mp3/
|   Voice sets for the 32MBit- & 16MBit-JQ6500 in German. English needed? Contribute!
|   ├── male/
|   |   Male voice set, spoken by Carsten Caniglia.
|   |   ├── mp3_16MBit/
|   |   |   80 files for smaller (2MiB) modules.
|   |   └── mp3_32Bit/
|   |       164 files for recommended (4MiB) modules.
|   └── female/
|       Female voice set, spoken by Norma Anthes
|       |   80 files for smaller (2MiB) modules.
|       └── mp3_32Bit/
|           164 files for recommended (4MiB) modules.
|
├── schematics/
|   The schematics for the Nokolino parts, the sewing pattern and shopping list.
|   ├── geda/
|   |   Source documents for gEDA.  
|   └── gerber/
|       The gerber files for the PCB to build by your own.
|
└── src/
    ATtiny sketch
    └── Nokolino/
        One file, no libraries, no frills. Just NOKOlino. 
```
### Let's get started!

Interested in Nokolino? Great! Let's start here:  
[German wiki](https://github.com/NikolaiRadke/NOKOlino_2/wiki).  
English wiki will follow. One day...


