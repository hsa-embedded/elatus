#include "main.h"

int main(void){


   SetupHardware();

  for(;;){
    _delay_ms(500);  
  }
  
  
  
}

void EVENT_I2C_Slave_addressed(void){
   I2C_Slave_ACK();
}



//To DO: Sollte nicht hier im Interrupt stehen !
void EVENT_I2C_Slave_receive(){
 
   uint8_t data =0;
   data = I2C_Slave_data();

   switch(data){
     case 0x01:
       elatus_LCD_writeString("LED 1 - Toggle",CLEAR_DISPLAY);
       elatus_LEDs_toggle(LED_1);
     break;
     case 0x02:
       elatus_LCD_writeString("UART ",CLEAR_DISPLAY);
       elatus_UART_writeString("TEST \r\n");
       elatus_LEDs_toggle(LED_1);
     break;
     case 0x03:
       elatus_LCD_writeString("3",NOT_CLEAR_DISPLAY);
       elatus_LEDs_toggle(LED_1);
     break;
     case 0x04:
       elatus_LCD_writeString("4",NOT_CLEAR_DISPLAY);
       elatus_LEDs_toggle(LED_1);
     break;
     default:
       elatus_LCD_writeString("Command not found",CLEAR_DISPLAY);
   }

   I2C_Slave_ACK();
}


void SetupHardware(void){
  elatus_LEDs_init(LED_1 | LED_2 | LED_3 | LED_4);
  elatus_LEDs_off( LED_1 | LED_2 | LED_3 | LED_4);
  elatus_I2C_SLAVE_init(SLAVE_ADRESSE);
  elatus_LCD_init();
  elatus_UART_init(9600);
  elatus_LCD_writeString("Embedded World",NOT_CLEAR_DISPLAY);
}



