#ifndef _I2C_H_
#define _I2C_H_

     /* Includes: */
     #include <avr/io.h>
     #include <avr/interrupt.h>
     #include <util/twi.h>
     #include "../../Allgemein/elatus.h"
     
     /* Makros: */
     #define SLAVE_ADRESSE 0x50
     
     #define I2C_Slave_ACK() TWCR = (1 << TWEN) | (1 << TWIE) | (1 << TWINT) | (1 << TWEA) | \
                             (0 << TWSTA) | (0 << TWSTO) | (0 << TWWC)
    
     #define I2C_Sĺave_NACK() TWCR = (1 << TWEN) | (1 << TWIE) | (1 << TWINT) | \
                             (0 << TWEA) | (0 << TWSTA) | (0 << TWSTO) | (0 << TWWC)
                             
    
     #define I2C_Slave_RESET() TWCR = (1 << TWEN) | (1 << TWIE) | (1 << TWINT) | \
                             (1 << TWEA) | (0 << TWSTA) | (1 << TWSTO) | (0 << TWWC)

     #define I2C_Slave_data() TWDR

     


     /* Functions: */
       //Event
     void EVENT_I2C_Slave_addressed(void);
     void EVENT_I2C_Slave_receive(void);

     /* Inline Funktionen: */
     void elatus_I2C_SLAVE_init(uint8_t adr);

     //static inline void I2c_
   
     


     //static inline void elatus_I2C_SLAVE_init(void){
         
     
#endif
