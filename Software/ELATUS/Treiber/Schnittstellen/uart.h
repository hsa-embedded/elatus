


#ifndef _UART_H_
#define _UART_H_

    /* Makros; */
    
    

    /* Includes: */
    
    #include <avr/io.h>   
    #include "../../Allgemein/elatus.h"

   /* Functions: */
   void elatus_UART_writeString(char *string);
   void elatus_UART_SendByte(const char Byte);
   
   
   
   /*Inline Functions: */
   
   static inline void elatus_UART_init(uint32_t Baud){

     
     uint16_t ubrr = (uint16_t) ((uint32_t) F_CPU/(16*Baud) - 1);
     UBRR0H = (uint8_t) (ubrr>>8);
     UBRR0L = (uint8_t) (ubrr);
     UCSR0B |= (1<<TXEN0) | (1<<RXEN0);
     UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);
     
    do{
        UDR0;
      } while (UCSR0A & (1 << RXC0));
     
   }
   



#endif
