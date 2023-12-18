#include "MKL46Z4.h"
#include "LED.h"
#include "switch.h"
#include "utilities.h"


volatile uint8_t status = 0x00; //Use this variable to read status of Switch 1 (bit 0), Switch 2 (bit 1), delay_status (bit 2)
int count = 0;

int main(void) {
	init_LED();
	init_switch();
	init_SysTick_interupt();
	delay(2);
	while(1) {
	if ((status & 0x01)== 0) { //chua ngoi tren xe
			green_LED_OFF();
			//SegLCD_Set(3,0x01); //OFF
			//delay(100);
			status &= ~(1<<2);
			if((status & 0x02)==0) { //chua ngoi tren xe va chua that day an toan
				red_LED_ON();
			} else { //chua ngoi tren xe ma da that day an toan 
				red_LED_OFF();
			}
		} else {	//Switch 1 nhan -> da ngoi tren xe 00000001
				if((status & 0x04) == 0) {
					//SegLCD_Set(4,4); //IN
					delay(1);
					count++;
					if (count < 10) {
						 if ((status & 0x02) != 0) { //Switch 1 nhan & switch 3 k nhan
									red_LED_OFF();
									green_LED_ON();
									//SegLCD_Set(4,4); //OK
									count = 0;
									status |= (1<<2);
						 }
					} else {
						 count = 0;
						 status |= (1<<2);                
						}
				} else {
						if ((status & 0x02) == 0) { //Switch 1 nhan & switch 3 khong nhan
							//SegLCD_Set(4,4); //IN
							green_LED_OFF();
							red_LED_ON();
							delay(1);
							red_LED_OFF();
							delay(1);
						} else {//Switch 1 nhan & switch 3 nhan
							red_LED_OFF();
							green_LED_ON();
							//SegLCD_Set(4,4); //OK
						}
				}
			}
		}
}