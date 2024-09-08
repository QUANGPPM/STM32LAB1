#include "exercise3.h"

traffic_light_t left_traffic, right_traffic,
				top_traffic, bottom_traffic;


void init_exercise3(){
	init_traffic_light(&left_traffic, &right_traffic,
						LED_10_GPIO_Port, LED_10_Pin,
						LED_11_GPIO_Port, LED_11_Pin,
						LED_12_GPIO_Port, LED_12_Pin,

						LED_4_GPIO_Port, LED_4_Pin,
						LED_5_GPIO_Port, LED_5_Pin,
						LED_6_GPIO_Port, LED_6_Pin,
						GREEN);

	init_traffic_light(&top_traffic, &bottom_traffic,
						LED_1_GPIO_Port, LED_1_Pin,
						LED_2_GPIO_Port, LED_2_Pin,
						LED_3_GPIO_Port, LED_3_Pin,

						LED_7_GPIO_Port, LED_7_Pin,
						LED_8_GPIO_Port, LED_8_Pin,
						LED_9_GPIO_Port, LED_9_Pin,
						RED);
}
void exercise3_run(){
	traffic_light_run(&left_traffic);
	traffic_light_run(&right_traffic);
	traffic_light_run(&top_traffic);
	traffic_light_run(&bottom_traffic);
}
