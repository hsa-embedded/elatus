/*
 * 
 * http://www.rn-wissen.de/index.php/ADC_(Avr)
 * 
*/



#ifndef _ADW_H_
#define _ADW_H_
     /* Makros: */
         #define BUFSIZE 11  
    #define ADC_H
    #define ADC_P1 0
    #define ADC_P2 1
    #define ADC_P3 2
    #define ADC_P4 3
     
     /* Includes */
     #include <avr/io.h>
     #include "../../Allgemein/elatus.h"
     #include <util/delay.h>

     /* Funktionen: */
     void EVENT_ADW_getvalue(uint16_t value);

     /* Inline Funktionen: */
     static inline void elatus_ADW_init() {
          ADCSRA = (1 << ADIE | 1 << ADEN | 1 << ADPS2 | 1 << ADPS1 | 1 << ADPS0);
     }
     
     static inline void elatus_ADW_getvalue(uint8_t channel){
          ADMUX = (channel | 1 << REFS0) ;
          ADCSRA |= 1 << ADSC;
     }

#endif
