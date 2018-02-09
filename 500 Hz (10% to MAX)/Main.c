
#include <p30f3013.h>   
                        
#include "system.h" 
#include "math.h"
                      
_FOSC(CSW_FSCM_OFF & XT_PLL16);  
_FWDT(WDT_OFF);                 
_FBORPOR(MCLR_EN & PWRT_OFF);                                 
_FGS(CODE_PROT_OFF);           


//..........................FUNCTION DECLARATION........................
extern void Delay5ms (int);
extern void Delay5us (int);
extern void Timer1_Init(void);
extern void Timer2_Init(void);
extern void Timer3_Init(void);
extern void IO_Init(void);
extern void ADC_Init(void);
extern void ADC_Read(void);

int main (void);

//.................................................VARIABLE DECLARATION..............................

float data1 = 0.0 ; unsigned char ADC_flg = 0, flag=0, count =0, loop = 0;
float sf = 100.0/4096, temp_Duty=0.0, Duty = 0.0; 
//.........................MAIN ROUTINE..........................
int main (void)
{

        ADPCFG = 0xFFFF;   
                                                                       
		                                           
                               
        IO_Init(); 
		ADC_Init();
        ADC_Read();			
	    Duty= floor((sf*data1)+0.5);

        Delay5ms(100);
		
        Timer2_Init();
        Timer1_Init();  
     	Timer3_Init();
		while (1)
		{	
			if (ADC_flg == 1)
			{
				count++;
				if (count == 2)
				{
					ADC_Read();			
					temp_Duty= floor((sf*data1)+0.5);
					count =0;					
					
					if	(flag>=18) 
					{
							
						T2CONbits.TON = 0; 
						while(Duty>9)
						{ 
						while(IFS0bits.T3IF == 0);
						Duty = Duty-10;
						if(Duty <= 9) Duty = 9;
						IFS0bits.T3IF = 0;
						} 
						T2CONbits.TON = 1; 

						LATBbits.LATB1=~LATBbits.LATB1;
						flag=0;	
					
					}

					if(flag==0)
					{
						
						T2CONbits.TON = 0; 
						while(Duty<temp_Duty)
						{ 
						while(IFS0bits.T3IF == 0);
						Duty = Duty+10;
						if(Duty >= temp_Duty) Duty = temp_Duty;
						IFS0bits.T3IF = 0;
						}
						T2CONbits.TON = 1; 
					}
					else Duty = temp_Duty;
							
				}
				ADC_flg = 0;
			}         
				                  		
		}     
             

		return 0;               //Code never reaches here!
}


