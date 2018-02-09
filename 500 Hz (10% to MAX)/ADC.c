#include <p30f3013.h>   
                        
#include "system.h" 
#include "math.h"

extern float data1;

void ADC_Read(void);


void ADC_Read(void)
{
long adc_data;
        
	    ADCON1bits.ASAM = 1;		//Start A/D converter
        while (!IFS0bits.ADIF);		//while A/D interrupt has not occured
        ADCON1bits.ASAM = 0; 		//Stop A/D converter
        adc_data = ADCBUF0+ADCBUF1+ADCBUF2+ADCBUF3+ADCBUF4+ADCBUF5+ADCBUF6+ADCBUF7+
                   ADCBUF8+ADCBUF9+ADCBUFA+ADCBUFB+ADCBUFC+ADCBUFD+ADCBUFE+ADCBUFF;
        adc_data = adc_data >> 4;

        data1 = adc_data;
           
        IFS0bits.ADIF = 0;		//Reset A/D interrupt
}
