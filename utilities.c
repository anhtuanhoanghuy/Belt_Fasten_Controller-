#include "MKL46Z4.h" 
volatile uint32_t msTicks = 0;

void init_SysTick_interupt(void) {
	SysTick->LOAD |= (SystemCoreClock/1000) - 1;
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}

void SysTick_Handler (void) {
	msTicks++;
}

void delay(uint32_t TICK) {
	while(msTicks < TICK);
	msTicks = 0;
}