#include "adw.h"


ISR(ADC_vect)
{
   cli();                                        // IRQs global sperren
   uint16_t adc_value;                           // Wert aus Analog-Digital-Wandler
   uint8_t lowbyte, highbyte;
   lowbyte = ADCL;                               // hole zuerst low_Byte
   highbyte = ADCH;                              // danach high_Byte
                                                 // und fuege dann beide zusammen
   adc_value = highbyte;
   adc_value <<= 8;
   adc_value |= lowbyte;
                                                 // AD-Wert auf UART ausgeben
   EVENT_ADW_getvalue(adc_value);
   sei();                                        // Interrupts global wieder frei geben
}





