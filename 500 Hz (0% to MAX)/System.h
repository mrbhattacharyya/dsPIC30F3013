#include <p30f3013.h>


//Defines for System Clock Timing -
//For oscillator configuration XT x PLL8 mode,
//Device Throughput in MIPS = Fcy = 6000000*8/4 = 12 MIPS
//Instruction Cycle time = Tcy = 1/(Fcy) = 83.33 nanoseconds
#define XTFREQ          7372800       //On-board Crystal frequency
#define PLLMODE         16              //On-chip PLL setting
#define FCY             XTFREQ*PLLMODE/4        //Instruction Cycle Frequency


#define Switch_S6       PORTDbits.RD8   //Switch S6 is connected to RD8









