#include <exercise7_to_10.h>

uint8_t second = 0;
uint8_t minute = 0;

uint8_t second_LED = 0;
uint8_t minute_LED = 0;
uint8_t hour_LED = 0;
uint8_t old_second_LED = 0;
uint8_t old_minute_LED = 0;
uint8_t old_hour_LED = 0;

void clearAllClock() {
	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, LED_OFF);
}

void LED_execute(int8_t num, uint8_t state){
	switch(num)
		{
			case 0:
				HAL_GPIO_WritePin(LED_12_GPIO_Port, LED_12_Pin, state);
				break;
			case 1:
				HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, state);
				break;
			case 2:
				HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, state);
				break;
			case 3:
				HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, state);
				break;
			case 4:
				HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, state);
				break;
			case 5:
				HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, state);
				break;
			case 6:
				HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, state);
				break;
			case 7:
				HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, state);
				break;
			case 8:
				HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, state);
				break;
			case 9:
				HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, state);
				break;
			case 10:
				HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, state);
				break;
			case 11:
				HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, state);
				break;
			default:
				break;
		}
}
void setNumberOnClock(int8_t num){
	LED_execute(num, LED_ON);
}
void clearNumberOnClock(int8_t num){
	LED_execute(num, LED_OFF);
}

void init_exercise6_to_10(){
	setNumberOnClock(second_LED);
	setNumberOnClock(minute_LED);
	setNumberOnClock(hour_LED);
}


void set_led_to_clock(){
	//clear
	if(old_second_LED != second_LED){
		clearNumberOnClock(old_second_LED);
		old_second_LED = second_LED;
	}
	if(minute_LED != old_minute_LED){
		clearNumberOnClock(old_minute_LED);
		old_minute_LED = minute_LED;
	}
	if(hour_LED != old_hour_LED){
		clearNumberOnClock(old_hour_LED);
		old_hour_LED = hour_LED;
	}

	//set
	setNumberOnClock(second_LED);
	setNumberOnClock(minute_LED);
	setNumberOnClock(hour_LED);
}
uint8_t second_run(){
	//increase second
	second++;
	//update LED
	if(second % 5 == 0){
		second_LED = second/5;
	}
	//update infor to minute_run()
	if(second >= 60)
	{
		second = 0;
		second_LED = 0;
		return 1;
	}
	return 0;
}
uint8_t minute_run(){

	if(second_run())
	{
		//increase minute
		minute++;
		//update LED
		if(minute % 5 == 0){
			minute_LED = minute/5;
		}
		//update infor to hour_run()
		if(minute >= 60)
		{
			minute = 0;
			minute_LED = 0;
			return 1;
		}
	}
	return 0;
}
uint8_t clock_count(){
	if(minute_run())
	{
		hour_LED++;

		if(hour_LED >= 11)
		{
			hour_LED = 0;
			return 1;
		}
	}
	return 0;
}
void exercise10_run(){
	clock_count();
	set_led_to_clock();
}






