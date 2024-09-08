#include "exercise2.h"

traffic_state traffic = GREEN;
uint8_t second_count = 0;
uint8_t set_up = 0;
void LED_execute(uint8_t second, traffic_state next_state,
				GPIO_PinState GR_LED, GPIO_PinState YL_LED, GPIO_PinState RE_LED){
	if(!set_up)	//setup
	{
		second_count = second-1;
		set_up = 1;
	}
	if(set_up && second_count > 0)	//execute
	{
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GR_LED);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, YL_LED);
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RE_LED);
	}
	if(second_count <= 0)	// change state
	{
		set_up = 0;
		traffic = next_state;
	}

}

void init_exercise2(){
	//nothing
}

void exercise2_run(){
	switch(traffic)
	{
		case GREEN:
			LED_execute(GREEN_TIME, YELLOW,
						LED_ON, LED_OFF, LED_OFF);
			break;
		case YELLOW:
			LED_execute(YELLOW_TIME, RED,
						LED_OFF, LED_ON, LED_OFF);
			break;
		case RED:
			LED_execute(RED_TIME, GREEN,
						LED_OFF, LED_OFF, LED_ON);
			break;
		default:
			break;

	}
	second_count--;
}
