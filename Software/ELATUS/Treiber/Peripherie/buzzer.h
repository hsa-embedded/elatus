/* 
 *  @brief Diese Headerfile enthaelt alle erforderlichen Definitionen und Funktionen
 *
 *  @author Andreas Schumann
 *  
 *  @note Diese Header nicht eigenstaendig includieren.
 *
*/

#ifndef _BUZZER_H_
#define _BUZZER_H_

     /* Includes: */
     #include <avr/io.h>
     #include "../../Allgemein/elatus.h"
     #include <util/delay.h>
  


     /* Makros: */



     /* Inline Funktionen: */
    static inline void elatus_SUMMER_init(void){
      ELATUS_BUZZER_DDR |= ELATUS_BUZZER_BUZZER;
     }

    static inline void elatus_SUMMER_beep(uint16_t period){
      while(period--){
        ELATUS_BUZZER_PORT ^= ELATUS_BUZZER_BUZZER;
        _delay_ms(1);
      }
    }



#endif

