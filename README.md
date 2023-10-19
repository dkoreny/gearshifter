NAME
====

Logitech GearShifter -> USB interface.

Synopsis
========

Plug in and play!

Description
===========

This project converts the analog signals provided by the DB9 on the gear shifter into USB signals that a host PC/Mac can understand.  

Hardware
--------

- Logitech Gear shifter.
- DB9 Male connector.
- atmega32u4 breakout board ( This was in my parts box, IIRC it came from adafruit )
- Hookup Wire.
- SSD1306 i2c OLED display.

Tools
-----

- Wire strippers
- Soldering iron
- Dupont crimper for fancy wiring work.
- Mini-USB cable


Dependancies
------------

- lufa library  (Refer to credits section)
- SSD1306 library (Refer to credits section) 
- gcc avr tool chain 
- avrdude

Building the Software
---------------------

0. Install prereqs
1. Download dependancies
2. Run Build
3. Upload flash (skip here if you want to use the provied hex file)

0. Install Pre-reqs.
--------------------

I develop on various OS's; I used debian 12 for this project. 

TODO: 
- build essentials.
- libusb and tools

```
apt install avr-tools
apt install avrdude
```

1. Download dependancies

Clone the repository.

```
git clone https://github.com/dkoreny/gearshifter
```

2. Run Build
```
cd ${HOME}/builds/gearshifter/src
make
```

3. Flash to board.  

- Plugin the atmega32u4 breakout board into the USB port.  
- Type the following command. (dont press enter yet)  

```
avrdude -p m32u4 -P /dev/ttyACM1 -c avr109 -v -U flash:w:dkmain.hex:i
```

- Press the button on the breakout board until the LED throbs;  
- NOW PRESS ENTER in the terminal.  

The board should be flashed with the new firmware.  

NB: You may need to replace /dev/ttyACM1 with the port your board uses. 

Quick way, run the following, then hit reset on the dev board. You should see the ttyACM device appear for a few seconds.

```
while true;
do
ls -ltr /dev/|tail -3
sleep 1
done
```

Pre-built images
----------------

There's a hex file: TODO: reference

Flash like so: replace /dev/ttyACM1 with your corresponding port.

```
avrdude -p m32u4 -P /dev/ttyACM1 -c avr109 -v -U flash:w:dkmain.hex:i
```

Hardware Configuration
----------------------

TODO's
- Wiring diagram 
- G29 Pinout

Axis Definition.
----------------

```
Front of Gear shifter (bit mounted on table)
           (G)

            |
            y
            |
    <---x---+---x--->
            |
            y
            |


  It's basically a HH pattern. With reverse, in position 6 but, the stick is pushed down prior
  to gear selection. (it toggles a switch internally; pin 2 active high)

```

G29 pinout
----------

```
      -------------
      \ 5 4 3 2 1 /
       \ 9 8 7 6 /
        ---------

 - Looking _at_ the G29 DB9 female connector. 
 - Or from the solder side of the male connector.

```

G29 Pin description.
--------------------

|Pin|Description|
|---|-----------|
| 1 | NC |
| 2 | Reverse |
| 3 | Vcc (5v)|
| 4 | X Axis 
| 5 | NC |
| 6 | Gnd |
| 7 | Vcc 5v)|
| 8 | Y Axis |
| 9 | NC |


Wiring Description
------------------

| GS Pin  	| atMega32u4 Pin|
|-----------|---------------|
| 2 		| D4 | 
| 3    		| Vcc|
| 4 		| F4 |
| 6 		| Gnd|
| 7 		| Vcc|
| 8 		| F6 |


TODO: insert some pics

Host Configration
-----------------

The device presents itself as a HID Joystick; it should be support on any modern OS; no drivers are required. So, just plug it in!

Mappings
--------

|Gear 		|JS Function	|
|-----------|---------------|
|Neutral	|Button 1 		|
|1st  		|Button 2 		|
|2nd  	 	|Button 3 		|
|3rd		|Button 4 		|
|4th 		|Button 5 		|
|5th 		|Button 6 		|
|6th 		|Button 7 		|
|Reverse 	|Button 8 		|


NB: Neutral has been removed as it's causing issues with beamNG. TODO: Testing.

Testing
-------

After flashing, run the following in a terminal window.
```
lsusb|grep LUFA
Bus 002 Device 117: ID 03eb:2043 Atmel Corp. LUFA Joystick Demo Application
```
You should see the LUFA Joystick demo application string.

Now run the following (using the ID from the above output)

```
sudo usbhid-dump -m 03eb:2043 -e stream 
```

This will capture the message from the gear shifter as it cycles through the gears.

The last byte will display the bitmask of each "button" sent to the host over usb.

- 01 - neutral.
- 02 - 1st 
- 04 - 2nd
etc etc..

```
Starting dumping interrupt transfer stream
with infinite timeout.

002:117:000:STREAM             1690887031.750101
 00 00 00 01

002:117:000:STREAM             1690887034.006110
 00 00 00 02

002:117:000:STREAM             1690887035.010094
 00 00 00 01

002:117:000:STREAM             1690887035.762041
 00 00 00 04

002:117:000:STREAM             1690887037.014062
 00 00 00 01

002:117:000:STREAM             1690887037.766051
 00 00 00 08

002:117:000:STREAM             1690887038.454038
 00 00 00 01

002:117:000:STREAM             1690887038.893959
 00 00 00 10

002:117:000:STREAM             1690887039.458020
 00 00 00 01

002:117:000:STREAM             1690887040.146011
 00 00 00 20

002:117:000:STREAM             1690887040.958000
 00 00 00 01

002:117:000:STREAM             1690887041.837986
 00 00 00 40

002:117:000:STREAM             1690887043.525958
 00 00 00 01

002:117:000:STREAM             1690887045.217933
 00 00 00 80

002:117:000:STREAM             1690887046.345912
 00 00 00 01

```


FAQ and Background
==================

Why? My nephew purchased this device expecting it to work with his existing steering wheel/pedal combo. But, alas, not compatible; the PC shop recommeded a device at jaycar. It was an USB-RS232 adapter; that had no hope of working. These gear shifters are analog!  

I took a look and though, what an interesting reverse engineering project! :-D  After some digging online, I found different pinouts and the like; after some probing with a mulitmeter, I worked out which of the three were the "real" ones, as documented above.

Why not arduino?
----------------

There are already a plethora of existing projects that use Arduino. I wanted to re-hone my C skills, re-learn AVR's and re-visit reading of good ole fashion datasheets.  I haven't used an AVR in eons.

How does the ASCII "art" font work?
-----------------------------------

I wanted a larger font on the screen, however, I'm not much of an artist, plus storing large bitmaps on a small uC would be tedious. Since the shape (bitmap) of the font already exists, I can use this to "draw" a larger font using ASCII.  

The font is stored in 5 bytes. (check SSD1306/lib/font.h)  

Check out this example:  
```
{ 0x27, 0x45, 0x45, 0x45, 0x39 }, // 35 5

00100111  //  so, lsb is top row, <<1 is next row, etc etc 
01000101  // 
01000101  // 
01000101  // 
00111001  // 


  S  SSS
 S   S S
 S   S S
 S   S S
  SSS  S

```

We'll need to flip it 90o; lsb is top row, <<1 is next row, etc etc

Reading down the columns from right -> left yeilds:

```
11111
10000
11110
00001
00001
10001
01110
00000

SSSSS
S    
SSSS
    S
    S
s   S
 SSS

```

How to loop on it's side? Some bit shifting and masking! :-) 

```
byte0 & 1<0 = x,0    // 128/8 = 16
byte0 & 1<1 = x,1
byte0 & 1<2 = x,2 ... (we'll actually.. setPosition takes pixel counts accrss)

byte1 & 1<0 = x+1,0
byte1 & 1<1 = x+1,1
byte1 & 1<2 = x+1,2 etc etc
```

So, the algorithm becomes:

```
  // this gives us a "byte" from the double array
  while (i < CHARS_COLS_LENGTH) 
  {
    char_byte=pgm_read_byte(&FONTS[character-32][i++]);  // get byte from array
    for (j=0;j<8;j++)   // step though each "bit"
    {
      if ((char_byte&1<i) == 1<i) // is the bit set?
      {
        // pixels, line number (0-7)
        SSD1306_SetPosition(i,j*CHARS_COLS_LENGTH);  // how to calc position? it's
        SSD1306_DrawChar(character);
      }
    }
  }
```

Since the font looked a bit "skinny" when the y position was calculated, it was shifted right by 3 (x8) instead of x5. It spreads it out and looks better on the screen (IMHO)


Credits
-------

LUFA			- http://www.fourwalledcubicle.com/LUFA.php
				- This is an absolutely _awesome_ library! :-) I recommend checking it out.
SSD1306 Library - https://github.com/Matiasus/SSD1306
                - I've made some modifications to this so it runs on the atmega32u4.





