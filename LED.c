#include "MKL46Z4.h"
void init_LED(void) {
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK; //Enable Clock to PORT D of Green LED
	PORTD->PCR[5] = PORT_PCR_MUX(1u);	// Config PORT D to GPIO
	PTD->PDDR |= 1<<5;	//set PTD5 to Output
	PTD->PSOR = 1<<5; //set bit 5 to 1
	
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK; //Enable Clock to port E of Red LED
	PORTE->PCR[29] = PORT_PCR_MUX(1u);;	// Config PORT E to GPIO
	PTE->PDDR |= 1<<29; //set PTE29 to Output
	PTE->PSOR = 1<<29; //set bit 29 to 1
}
void green_LED_ON(void) {
	PTD->PCOR = 1<<5; //clear bit 5 to 0
}
void green_LED_OFF(void) {
	PTD->PSOR = 1<<5; //set bit 5 to 1
}
void red_LED_ON(void) {
	PTE->PCOR = 1<<29; //clear bit 29 to 0
}
void red_LED_OFF(void) {
	PTE->PSOR = 1<<29; //set bit 29 to 1
}
