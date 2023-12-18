#include "MKL46Z4.h" 
#include "LED.h"
extern volatile uint8_t status;
void init_switch(void) {
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; //Enable Clock to PORT C of Switch 1 and Switch 3
	PORTC->PCR[3] = PORT_PCR_MUX(1u)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_IRQC(0xA); // Config Pin 3 PORT C to GPIO, enable pull-up resistor and set falling edge interupt
	PTC->PDDR &= ~(1u<<3); //set PTC3 to Input
	PORTC->PCR[12] = PORT_PCR_MUX(1u)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK|PORT_PCR_IRQC(0xA); // Config Pin 12 PORT C to GPIO, enable pull-up resistor and set falling edge interupt
	PTC->PDDR &= ~(1u<<12);	//set PTC12 to Input
	NVIC_ClearPendingIRQ(31);	//Clear NVIC any pending interrupts on PORTC_D
	NVIC_EnableIRQ(31); // Enable NVIC interrupts source for PORTC_D module
}

void PORTC_PORTD_IRQHandler(void) {
	if ((PTC->PDIR & (1<<3)) == 0) { //Switch 1 is pressed
			PORTC->PCR[3] |= PORT_PCR_ISF_MASK;
			status ^= 0x01;
	}
	if ((PTC->PDIR & (1<<12)) == 0) { //Switch 3 is pressed
		PORTC->PCR[12] |= PORT_PCR_ISF_MASK; 
		status ^= 0x02;
	}
}
	