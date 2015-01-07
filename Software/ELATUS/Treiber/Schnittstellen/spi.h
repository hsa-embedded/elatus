/*
 * 
 * 
 * 
*/


#ifndef _SPI_H_
#define _SPI_H_

     /* Includes: */
     #include <avr/io.h>
     #include "../../Allgemein/elatus.h"
     
     /* Makros: */
     
     /* Inline Funktionen: */
     
     static inline void elatus_SPI_init(void){
       

         ELATUS_SPI_DDR |= (1 << ELATUS_SPI_MOSI) | (1 << ELATUS_SPI_SCK);

	 //ELATUS_SPI_DDR &= ~(1 << ELATUS_SPI_MISO);
	 
         DDRB |= (1 << PB0 | 1 << PB1 | 1 << PB2);
	 SPSR |= (1 << SPI2X);
	 SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0);
	 SPSR |= (1 << SPI2X);
	  
     }
     
     static inline void elatus_SPI_SendByte(uint8_t Byte){
         SPDR = Byte;
	 while(! (SPSR & (1 << SPIF)))
	   ;
     }
     
     
     
     
#endif
