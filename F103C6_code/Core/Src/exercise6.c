#include <exercise6.h>

uint8_t state = LED_ON;

void clearAllClock () {

}
void setNumberOnClock(int num){

}
void clearNumberOnClock(int num){

}

void init_exercise6_to_10(){
	//nothing
}

void LED_execute(uint8_t state){
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, state);
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, state);
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, state);
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, state);
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, state);
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, state);
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, state);
	HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, state);
	HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, state);
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, state);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, state);
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, state);
}

void exercise6_run(){
	switch(state){
		case LED_ON:
			LED_execute(LED_ON);
			if(1)
			{
				state = LED_OFF;
			}
			break;
		case LED_OFF:
			LED_execute(LED_OFF);
			if(1)
			{
				state = LED_ON;
			}
			break;
		default:
			break;
	}

}

