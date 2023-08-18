

MS Windows instructions for flashing new firmware.
==================================================

1. Download AVRDude for window

https://github.com/avrdudes/avrdude/releases/download/v7.2/avrdude-v7.2-windows-x64.zip

2. Unzip into Downloads
3. Download hex file from this repo. Save into Downloads
4. Open CMD.exe; Run the following

```
cd Downloads\avrdude-v7.2-windows-x64
avrdude -p m32u4 -c avr109 -v -U flash:w:..\dkmain.hex:i
```

NB: _before_ running avrdude, press the reset button on the box. You have to run the above command within 6 seconds of pressing the reset button.

If that does not work, find which com? port the atmega32u4 is connected to.

(This is a bit of a guess)

- Go to Device Mananger
- Press the reset button on the device
- Look for the new com port in the device manager (it will appear for about 5 seconds and dissapear)

- Now run the following: replace COMn with the com port number that appears in the device manager.


```
cd Downloads\avrdude-v7.2-windows-x64
avrdude -p m32u4 -P COMn -c avr109 -v -U flash:w:..\dkmain.hex:i
```

