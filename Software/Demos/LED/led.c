#include <util/delay.h>
#include "../../ELATUS/Treiber/Peripherie/led.h"






int main(void){
  
  elatus_LEDs_init(LED_1 | LED_2 | LED_3 | LED_4);
  
  
  
  
  while(1){
    elatus_LEDs_on(LED_1 | LED_2);
    elatus_LEDs_off(LED_3 | LED_4 );
    _delay_ms(1000);
    elatus_LEDs_off(LED_1 | LED_2 );
    elatus_LEDs_on(LED_3 | LED_4);
    elatus_LEDs_on(LED_3 | LED_4);
    _delay_ms(1000);
    
  }
  
  
  
}
