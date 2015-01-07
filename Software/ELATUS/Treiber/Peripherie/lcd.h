/*
 * 
 * 
 * 
*/



#ifndef _LCD_H_
#define _LCD_H_
     /* Makros: */
     
     // Wait:
     #define WAIT_FOR_DISPLAY_READY 50
     
     // Command
     #define COMMAND_FUNCTION_SET_DATA 0x39
     #define COMMAND_BIAS_SET  0x14
     #define COMMAND_POWER_CONTROL 0x55
     #define COMMAND_FOLLOWER_CONTROL 0x6d
     #define COMMAND_CONTRAST_SET 0x70
     #define COMMAND_FUNCTION_SET_SWITCH 0x38
     #define COMMAND_DISPLAY_ON_OFF 0x0f
     #define COMMAND_CLEAR_DISPLAY  0x01
     #define COMMAND_ENTERY_MODE_SET 0x00
     #define COMMAND_CURSOR_OFF 0x0c
     #define CLEAR_DISPLAY 1
     #define NOT_CLEAR_DISPLAY 0
     
     /* Includes */

     #include "../../Allgemein/elatus.h"

     #include "../Schnittstellen/spi.h"
     #include <util/delay.h>


     /* Inline Funktionen: */
     void elatus_LCD_init(void);
     void elatus_LCD_writeChar(char word);
     void elatus_LCD_writeString(char *string, uint8_t status);
     
     static inline void elatus_LCD_sendByte(uint8_t Byte){
          ELATUS_LCD_PORT_SS &= ~(1 << ELATUS_LCD_SS);
          elatus_SPI_SendByte(Byte);
     }
     
     static inline void elatus_LCD_sendCommand(uint8_t Byte){
          
        
          ELATUS_LCD_PORT_SS &= ~(1 << ELATUS_LCD_SS);
	  SPDR = Byte;
	  while(!(SPSR & (1 << SPIF)));
       
	  ELATUS_LCD_PORT_SS ^= (1 << ELATUS_LCD_SS);
	  ELATUS_LCD_PORT_SS ^= (1 << ELATUS_LCD_SS);
	  _delay_us(13);
          /*
	  elatus_LCD_sendByte(Byte);
	  ELATUS_LCD_PORT_SS ^= (1 << ELATUS_LCD_SS);
	  ELATUS_LCD_PORT_SS ^= (1 << ELATUS_LCD_SS);
	  _delay_us(13);
	  */
       
          
     }
     
     
     
     
#endif
