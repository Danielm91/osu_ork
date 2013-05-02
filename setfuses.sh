#!/bin/sh
avrdude -B 1000 -p atmega32u4 -P usb -c avrispmkII -u -U lfuse:w:0xde:m -U hfuse:w:0xd9:m -U efuse:w:0xc3:m

avrdude -V -B 100 -p atmega32u4 -P usb -c avrisp2 -e -U flash:w:BootloaderHID.hex
