#include "Cpu.h"
#include "Events.h"
#include "IO_Map.h"
//#include "IO1.h"
#include "SegLCD1.h"
#include "Green.h"
#include "RED.h"

//#include "BitIoLdd1.h"
//#include "LED_RED.h"
//#include "BitIoLdd2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "LCD.h"
#include "cstdio"


#define CW
/* variables */
LDD_TError Error;
LDD_TDeviceData *MySegLCDPtr, *RED, *Green;

char InpData[16];
char seg[]={7,8,10,11,17,37,38,53}; // seven segment connection 
char col[]={0,1,2,3}; //column of lcd
char sLCDBuffer[16];  //temporal buffer for the sLCD,
char buf[1];
int main_counter,i,j;

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */


	  
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  
  MySegLCDPtr = SegLCD1_Init(NULL);  //initialize sLCD according to PEx 
  R ED = RED_Init(NULL);
  Green = Green_Init(NULL);
  
  
  for(;;) 
   {
	  for(j=0;j<=7;j++){
	  	for(i=0;i<=3;i++){
	  		SymbolON(seg[j],i);
	  		for (main_counter=1000000 ; main_counter>0 ;main_counter--){}; //delay
	  		//SymbolOFF(seg[0],i);
	  	}
	  }

	  vfnLCD_All_Segments_OFF();

	  for(i=0;i<=9999;i=i+1111){
		  sprintf(sLCDBuffer,"%04i",i);
	  	vfnLCD_Write_Msg((uint8 *)sLCDBuffer);
	  	for (main_counter=1000000 ; main_counter>0 ;main_counter--){};
	  	 Green_NegVal(Green);
	  	 RED_NegVal(RED);
	  }
	 
	  vfnLCD_All_Segments_OFF();
    }
  
  
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
}  /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.2 [05.06]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
