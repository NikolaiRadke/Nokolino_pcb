# ![NOKOlino](http://www.nikolairadke.de/NOKOlino_2/nokolino_klein3.png) NOKOlino (PCB)

The DIY-Kit Monster. Tiny and cute. And everyone is invited to **contribute**. NOKOlino is for everyone. This repository is for the **Kit (Bausatz)** edition of Nokolino, easy and fast to build.
  
What's new? See the [newsblog](https://github.com/NikolaiRadke/Nokolino/tree/master/NEWS.md).   

![Three NOKOlinos](http://www.nikolairadke.de/Nokolino/nokolinos.png)
  
Like his big brother **Noko**, the little NOKOlino delights it's surroundings with cheeky comments. But unlike Noko he is more obstinate - no radio, a display, no frills. Instead of an Arduino he has a small **ATtiny** microcontroller, only one on-off switch and a big button. But he is small, can stay active for days and is, in contrast to his big brother, very easy to build.  
  
Another useful application option would be to use the hardware without the monster suit as a **music box** in an old used doll to bring it back to modern days, maybe with other sounds or songs.  

What does he to - technically? Whenever you press his button, he will laugh. And when he's just turned on, he says something random randomly every statistically 10 minutes. That's it. Quiet a lot for a stuffed monster!  
  
**Nokolino** stands for **No**ra and Ni**ko**s monster - the appendix **lino** describes the small version.  
  
### Notes for non-German Nokolino makers  
  
Right now, the building wiki, the voice sets and the manual are in German. I'll try to translate the wiki and the manual one day. Until then, feel free to ask me for translation, if you need help. **Contribute!** I need an English voice set and English text files. In addition, any other language is welcome, Nokolino is to be cosmopolitan!
  
### Prerequisites
  
Except for some tools and time, the kit is ready to build. The ATtiny is preprogrammed and a the Nokolino male voice set is preinstalled. If you want to make some changes, Nokolino needs Arduino IDE 1.6.6 or newer (https://www.arduino.cc/en/Main/Software). Copy the folder `Nokolino/src/Nokolino/` into your sketch folder and install ATtiny support. See [how to compile](https://github.com/NikolaiRadke/Nokolino/tree/master/howto_compile) for further instructions. 
  
### Content

```
NOKO/
├── howto_compile/
|   Manual how compile the sketches in your Arduino IDE and precompiled sketched  
|   └── precompiled/
|
├── manual/
|   NOKO manual in PDF format and a template for a packaging design.
|
├── mp3/
|   Voice sets in German. English needed? Contribute!
|   ├── male/
|   |   Male voice set, spoken by Carsten Caniglia.
|   └── female/
|       Female voice set, spoken by Norma Anthes
|
├── schematics/
|   The schematics for the PCB parts, the sewing pattern and a shopping list.
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
[German wiki](https://github.com/NikolaiRadke/Nokolino/wiki).  
English wiki will follow. One day...
