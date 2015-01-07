#ifndef _ELATUS_H_
#define _ELATUS_H_

   //#define F_CPU 8000000UL
   
   
   #define LED_1 (1 << 2)
   #define LED_2 (1 << 3)
   #define LED_3 (1 << 4)
   #define LED_4 (1 << 5)
   #define ELATUS_LED_DDR DDRD
   #define ELATUS_LED_PORT PORTD
   #define ELATUS_LED_PIN 1
   
//SPI

   #define ELATUS_SPI_DDR DDRB 
   #define ELATUS_SPI_PORT PORTB
   #define ELATUS_SPI_MOSI DDB3 
   #define ELATUS_SPI_MISO DDB4
   #define ELATUS_SPI_SCK DDB5
   
//LCD
   #define ELATUS_LCD_DDR_SS DDRB
   #define ELATUS_LCD_PORT_SS PORTB
   #define ELATUS_LCD_SS PB2

//BUZZER
   #define ELATUS_BUZZER_BUZZER (1 << 6)
   #define ELATUS_BUZZER_DDR DDRD
   #define ELATUS_BUZZER_PORT PORTD
   #define ELATUS_BUZZER_PIN 6
   
   
#endif   
