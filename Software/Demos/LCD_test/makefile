SHELL := /bin/bash
ELATUS_PATH = ../..

include $(ELATUS_PATH)/ELATUS/makefile


PROGRAMMER = 	avrispv2
MCU 	   = 	atmega88
F_CPU      = 	8000000UL
CC         = 	avr-gcc
# Target file name (without extension).
TARGET = 	lcd_demo

# List C source files here. (C dependencies are automatically generated.)
SRC = $(TARGET).c \
	$(ELATUS_LCD)

CC = avr-gcc

CFLAGS = -g -mmcu=$(MCU) -Wall -Wstrict-prototypes -Os -mcall-prologues -DF_CPU=$(F_CPU)


all: $(TARGET:%=%.hex)

$(TARGET:%=%.hex): $(TARGET:%=%.out)
	@echo
	@echo Creating load file for Flash: $(TARGET:%=%.hex)
	@echo
	avr-objcopy -R .eeprom -O ihex $(TARGET:%=%.out) $(TARGET:%=%.hex)
	@echo


$(TARGET:%=%.out): $(SRC:%.c=%.o)
	$(CC) $(CFLAGS) -o $(TARGET:%=%.out) -Wl,-Map,$(TARGET:%=%.map) $(SRC:%.c=%.o) 

clean:
	@echo
	@echo clean: $(TARGET)
	@echo      
	rm -f $(TARGET:%=%.hex)
	rm -f $(TARGET:%=%.map)
	rm -f $(TARGET:%=%.out)
	rm -f $(SRC:%.c=%.o)

program: 
	avrdude -p $(MCU) -P usb -c $(PROGRAMMER)  -U flash:w:$(TARGET:%=%.hex) 


