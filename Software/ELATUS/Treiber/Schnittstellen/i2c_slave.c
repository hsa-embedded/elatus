#include "i2c_slave.h"

void elatus_I2C_SLAVE_init(uint8_t adr){
   TWAR = adr; 
   TWCR &= ~(1 << TWSTA) | (1 << TWSTO);
   TWCR |= (1 << TWEA) | (1 << TWEN) | (1 << TWIE);
   sei(); 
  
}

ISR (TWI_vect){
   
  switch(TW_STATUS){
    //Slave receive
    case TW_SR_SLA_ACK: //Slave Slave wurde adressiert
        EVENT_I2C_Slave_addressed();
        break;
    case TW_SR_DATA_ACK: //Daten wurden empfangen
        EVENT_I2C_Slave_receive();
        break;


    //Slave transmit
    case TW_ST_DATA_NACK: //Keine Daten mehr
    case TW_SR_DATA_NACK: // ???
    case TW_ST_LAST_DATA: // ???
    default:
        I2C_Slave_RESET(); 

      // data = TWDR; //DATEN auslesen
       
  }
 

}
