#include "exercise1.h"

uint8_t led_status = LED_OFF;
uint8_t count = 0;
void init_exercise1(){
	//nothing
}
void led_on(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
}
void led_off(){
	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
}
void exercise1_run(){
	switch(led_status){
		case LED_ON:
			led_on();
			if(count >= 2){		// khi count == 2 sẽ chuyển trạng thái
				led_status = LED_OFF;
				count = 0;	//reset trạng thái count
			}
			break;
		case LED_OFF:
			led_off();
			if(count >= 2){		// khi count == 2 sẽ chuyển trạng thái
				led_status = LED_ON;
				count = 0;
			}
			break;
		default:
			break;
	}
	count++;
}


