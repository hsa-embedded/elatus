#include <util/delay.h>
#include "../../ELATUS/Treiber/Peripherie/led.h"
#include "../../ELATUS/Treiber/Schnittstellen/adw.h"
#include "../../ELATUS/Treiber/Schnittstellen/uart.h"

#define B_Y ADC_P3
#define B_Z ADC_P2
#define B_X ADC_P4 

char *int_to_ascii(uint32_t zahl, char *ascii_sp);

volatile uint16_t tmp_value = 0;


int main(void){
  
  elatus_LEDs_init(LED_1);
  elatus_ADW_init();
  elatus_UART_init(9600);
  
  char tmp_string[11];
  sei();



  while(1){
    elatus_UART_writeString("X -Wert = ");
    elatus_ADW_getvalue(B_X);
    elatus_UART_writeString(int_to_ascii(((uint32_t)tmp_value), tmp_string));
    //elatus_UART_writeString("\r\");
    _delay_ms(100);

    elatus_UART_writeString(" Y -Wert = ");
    elatus_ADW_getvalue(B_Y);
    elatus_UART_writeString(int_to_ascii(((uint32_t)tmp_value), tmp_string));
    //elatus_UART_writeString("\r\n");
    _delay_ms(100); 

    elatus_UART_writeString(" Z -Wert = ");
    elatus_ADW_getvalue(B_Z);
    elatus_UART_writeString(int_to_ascii(((uint32_t)tmp_value), tmp_string));
    elatus_UART_writeString("\r");
    _delay_ms(100);   

   

    _delay_ms(1000);
    
  }
  
  
  
}


void EVENT_ADW_getvalue(uint16_t value){
    tmp_value = value; 
}



// einen int32 in string wandeln
char *int_to_ascii(uint32_t zahl, char *ascii_sp){
  int8_t i = 10;
  *(ascii_sp + i--) = 0x00;
  while(i>=0){
    *(ascii_sp + i--) = zahl%10+ 0x30;
    zahl /= 10;
  }
 return ascii_sp;

}




