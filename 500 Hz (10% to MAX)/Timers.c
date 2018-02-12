//..........................TIMER.............................................................


#include <p30f3013.h>
#include "system.h"

void Timer1_Init(void);
void Timer2_Init(void);
void Timer3_Init(void);

void __attribute__((__interrupt__)) _T1Interrupt(void);
void __attribute__((__interrupt__)) _T2Interrupt(void);
void __attribute__((__interrupt__)) _T3Interrupt(void);

extern unsigned char ADC_flg, loop, ch, flag;
extern float Duty;

//..........................Timer1_Init FUNCTION................

void Timer1_Init(void)		//Generates Interrupt of about 100th of 0.5 second (Timer used to control every percent of the Duty Cycle)
{
        T1CON = 0x0000;		//Timer Prescale option of 1:1        
                               
        PR1 = 0x01F4;  
        IFS0bits.T1IF = 0;      
        IEC0bits.T1IE = 1;		//Interrupt Enabled    
        T1CONbits.TON=1;        
}

void Timer2_Init(void)		//Generates Interrupt of 0.5 seconds (Timer used to control the Duty Cycle)
{
        T2CON = 0x0030;		//Timer Prescale option of 1:256        
                               
        PR2 = 0xE100;  
        IFS0bits.T2IF = 0;      
        IEC0bits.T2IE = 1;		//Interrupt Enabled    
        T2CONbits.TON=1;        
}

void Timer3_Init(void)		//Generates Interrupt of 0.1 seconds
{
        T3CON = 0x0030;		//Timer Prescale option of 1:256        
                               
        PR3 = 0x2D00;  
        IFS0bits.T3IF = 0;      
        IEC0bits.T3IE = 0;		//Interrupt Disabled    
        T3CONbits.TON=1;        
}


void __attribute__((__interrupt__)) _T1Interrupt(void)
{
             
        loop++;
        if (loop < Duty) LATBbits.LATB0 =1;
        else LATBbits.LATB0 =0;
        if (loop>=100) 
		{
			loop = 0;	
		}
        IFS0bits.T1IF = 0;		//Resets Timer1 Interrupt flag 
		                     
}

void __attribute__((__interrupt__)) _T2Interrupt(void)
{
             
		ADC_flg = 1;
		flag++;
		
		IFS0bits.T2IF = 0;		//Resets Timer2 Interrupt flag                     
		
}

void __attribute__((__interrupt__)) _T3Interrupt(void)
{
             
       
		IFS0bits.T3IF = 0;		//Resets Timer3 Interrupt flag                     
}
