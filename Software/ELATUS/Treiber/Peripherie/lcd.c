#include "lcd.h"

void elatus_LCD_writeChar(char word){
  ELATUS_LCD_PORT_SS |= (1 << ELATUS_LCD_SS);
  
  SPDR = word;
  while(!(SPSR & (1<<SPIF)))
       ;
  ELATUS_LCD_PORT_SS ^= (1 << ELATUS_LCD_SS);
  ELATUS_LCD_PORT_SS ^= (1 << ELATUS_LCD_SS);
  
  _delay_us(13);
  ELATUS_LCD_PORT_SS &= ~(1 << ELATUS_LCD_SS);
}


void elatus_LCD_init(void){
          elatus_SPI_init();
	  
	  ELATUS_LCD_DDR_SS |= (1 << ELATUS_LCD_SS);
	  ELATUS_LCD_PORT_SS |= (1 << ELATUS_LCD_SS);
	  
	  _delay_ms(WAIT_FOR_DISPLAY_READY);
	  
	  ELATUS_LCD_PORT_SS &= ~(1 << ELATUS_LCD_SS);
	  _delay_ms(30);
	  
	  elatus_LCD_sendCommand(COMMAND_FUNCTION_SET_DATA); //31
	  
	  elatus_LCD_sendCommand(COMMAND_BIAS_SET); //14
	  
	  elatus_LCD_sendCommand(COMMAND_POWER_CONTROL); //55
	 
	  elatus_LCD_sendCommand(COMMAND_FOLLOWER_CONTROL); //6d
          
	  elatus_LCD_sendCommand(COMMAND_CONTRAST_SET);//70
	  elatus_LCD_sendCommand(COMMAND_FUNCTION_SET_SWITCH);//38
	  elatus_LCD_sendCommand(COMMAND_DISPLAY_ON_OFF); //0f
	  elatus_LCD_sendCommand(COMMAND_CLEAR_DISPLAY);
	  elatus_LCD_sendCommand(COMMAND_ENTERY_MODE_SET); //06
	  elatus_LCD_sendCommand(COMMAND_CURSOR_OFF);
	  
	  
	  
}



void elatus_LCD_writeString(char *string,uint8_t status){
  
  if(status)
    elatus_LCD_sendCommand(0x01);
  
  _delay_ms(2);
  while(*string)   
    elatus_LCD_writeChar(*string++);


}







