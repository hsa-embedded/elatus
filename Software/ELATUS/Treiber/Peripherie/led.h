/*
 *  @file led.h
 *  @brief Diese Headerfile enthaelt alle erforderlichen Definitionen und Funktionen
 *
 *  @author Andreas Schumann
 *  
 *  @note Diese Header nicht eigenstaendig includieren.
 *
*/

#ifndef _LED_H_
#define _LED_H_

     /* Includes: */
     #include <avr/io.h>
     #include "../../Allgemein/elatus.h"
     
     
     /* Makros: */
     
     /* Inline Funktionen: */
    static inline void elatus_LEDs_init(const uint8_t LEDMask){
       ELATUS_LED_DDR  |= LEDMask;
       ELATUS_LED_PORT |= LEDMask;
     }
     
     
     
     static inline void elatus_LEDs_on(const uint8_t LEDMask){
       ELATUS_LED_PORT |= LEDMask; 
     }

     
     
     static inline void elatus_LEDs_off(const uint8_t LEDMask){
       ELATUS_LED_PORT &= ~LEDMask;
     }
     
     static inline void elatus_LEDs_toggle(const uint8_t LEDMask){
       ELATUS_LED_PORT ^= LEDMask;
     }
     
     
#endif
