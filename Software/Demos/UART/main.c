
#include <util/delay.h>
#include "../../ELATUS/Treiber/Peripherie/led.h"
#include "../../ELATUS/Treiber/Schnittstellen/uart.h"





int main(void){
  
  
  //_delay_ms(5000);
  elatus_LEDs_init(LED_1 | LED_2 | LED_3 | LED_4);
  elatus_UART_init(9600);
  //elatus_LCD_writeChar('H');
   
  
  
  
  while(1){
    
       elatus_UART_SendByte('A');
       _delay_ms(1000);
      }
    elatus_LEDs_on(LED_1 | LED_2);
    elatus_LEDs_off(LED_3 | LED_4 );
    //_delay_ms(1000);
    elatus_LEDs_off(LED_1 | LED_2 );
    elatus_LEDs_on(LED_3 | LED_4);
    elatus_LEDs_on(LED_3 | LED_4);
    //_delay_ms(1000);
    
  
  
  
  
}
