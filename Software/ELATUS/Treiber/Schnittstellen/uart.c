#include "uart.h"




void elatus_UART_SendByte(const char Byte){
  
  while(!(UCSR0A & (1 << UDRE0)))
    ;
  UDR0 = Byte;
}


void elatus_UART_writeString(char *string){
  

  while(*string)   
    elatus_UART_SendByte(*string++);


}


