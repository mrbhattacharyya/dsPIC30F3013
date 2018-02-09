//Pre-Processor Directives:
#include <p30f3013.h>
#include "system.h"

//#define PERIOD 0xB71D
//#define PERIOD 0xFFFF

void IO_Init(void);
//void Timer_Init(void);
void ADC_Init(void);

void IO_Init(void)
{
        LATBbits.LATB0 = 0;     
        TRISBbits.TRISB0 = 0;   
        LATBbits.LATB1 = 0;     
        TRISBbits.TRISB1 = 0;        
}    




/*void Timer_Init(void)
{
        T2CON = 0x0030;         //Timer1 set up to count on instruction cycle
                                //edge with 1:256 prescaler applied initially.
        PR2 = PERIOD;           //Period Register, PR1, set to maximum count
        IFS0bits.T2IF = 0;      //Clear the Timer1 Interrupt Flag
        IEC0bits.T2IE = 1;      //Enable Timer2 Interrupt Service Routine
        T2CONbits.TON=0;        //Start Timer 2

                                        //edge with 1:256 prescaler applied initially.
        
}*/


void ADC_Init(void)
{
        ADCON1bits.ADON = 0;	//A/D is off
        ADCON1bits.SSRC = 7;	//selects auto-convert mode
         
        ADCON2bits.SMPI = 15;	// Interrupts after writing 16-bytes in buffer
       
        
        ADCON3bits.ADCS = 11;	// Tad = 500 ns, Tconv = 7 us
        ADCON3bits.SAMC = 31;	// Sampling time = 15.5 us
      
         
       
        ADCHS = 0x0002;		//Connect RB2/AN2 as CH0 input  and also connect to positive CH1 input
		ADPCFG = 0xFFFB; 	//RB2 = analog
	
     
        IFS0bits.ADIF = 0;   // Clear the A/D interrupt flag bit
        ADCON1bits.ADON = 1;

}

