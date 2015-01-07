#include <util/delay.h>
#include "../../ELATUS/Treiber/Peripherie/led.h"
#include "../../ELATUS/Treiber/Schnittstellen/i2c_slave.h"

int main(void){  
  elatus_LEDs_init(LED_1 | LED_2 | LED_3 | LED_4);
  elatus_LEDs_off( LED_1 | LED_2 | LED_3 | LED_4);
  elatus_I2C_SLAVE_init(SLAVE_ADRESSE);

  while(1){
    _delay_ms(500);  
  }
  
  
  
}

void EVENT_I2C_Slave_addressed(void){
   I2C_Slave_ACK();
}

void EVENT_I2C_Slave_receive(){
 
   uint8_t data =0;
   data = I2C_Slave_data();

   switch(data){
     case 0x01:
       elatus_LEDs_toggle(LED_1);
     break;
     case 0x02:
       elatus_LEDs_toggle(LED_2);
     break;
     case 0x03:
       elatus_LEDs_toggle(LED_3);
     default:
       elatus_LEDs_toggle(LED_4);     
   }

   I2C_Slave_ACK();
}




