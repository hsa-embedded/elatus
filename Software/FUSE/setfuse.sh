#! /bin/bash
sudo avrdude -p atmega88 -P usb -c avrispv2  -U lfuse:w:0x7f:m -U hfuse:w:0xdf:m
