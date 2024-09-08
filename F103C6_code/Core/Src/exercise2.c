#include "exercise2.h"


void LED_execute(traffic_light_t* traf_light, traffic_state next_state, uint8_t second,
				GPIO_PinState GR_LED, GPIO_PinState YL_LED, GPIO_PinState RE_LED){
	if(!traf_light->set_up)
	{
		traf_light->set_up = 1;
		traf_light->time = second-1;
	}
	if(traf_light->set_up && traf_light->time > 0)
	{
		HAL_GPIO_WritePin(traf_light->GREEN_GPIOx, traf_light->GREEN_Pin, GR_LED);
		HAL_GPIO_WritePin(traf_light->YELLOW_GPIOx, traf_light->YELLOW_Pin, YL_LED);
		HAL_GPIO_WritePin(traf_light->RED_GPIOx, traf_light->RED_Pin, RE_LED);
	}
	if(traf_light->time <= 0)
	{
		traf_light->set_up = 0;
		traf_light->state = next_state;
	}
}


void init_traffic_light(traffic_light_t* traf_light1, traffic_light_t* traf_light2,
						//---the first traffic light---//
						GPIO_TypeDef *GREEN_GPIO1x, uint16_t GREEN_Pin1,
						GPIO_TypeDef *YELLOW_GPIO1x, uint16_t YELLOW_Pin1,
						GPIO_TypeDef *RED_GPIO1x, uint16_t RED_Pin1,
						//---the second traffic light---//
						GPIO_TypeDef *GREEN_GPIO2x, uint16_t GREEN_Pin2,
						GPIO_TypeDef *YELLOW_GPIO2x, uint16_t YELLOW_Pin2,
						GPIO_TypeDef *RED_GPIO2x, uint16_t RED_Pin2,
						traffic_state state)
{
	// init the first traffic light
	traf_light1->GREEN_GPIOx = GREEN_GPIO1x;
	traf_light1->GREEN_Pin = GREEN_Pin1;
	traf_light1->YELLOW_GPIOx = YELLOW_GPIO1x;
	traf_light1->YELLOW_Pin = YELLOW_Pin1;
	traf_light1->RED_GPIOx = RED_GPIO1x;
	traf_light1->RED_Pin = RED_Pin1;
	traf_light1->state = state;
	traf_light1->time = 0;
	traf_light1->set_up = 0;
	// init the second traffic light
	traf_light2->GREEN_GPIOx = GREEN_GPIO2x;
	traf_light2->GREEN_Pin = GREEN_Pin2;
	traf_light2->YELLOW_GPIOx = YELLOW_GPIO2x;
	traf_light2->YELLOW_Pin = YELLOW_Pin2;
	traf_light2->RED_GPIOx = RED_GPIO2x;
	traf_light2->RED_Pin = RED_Pin2;
	traf_light2->state = state;
	traf_light2->time = 0;
	traf_light2->set_up = 0;
}

void traffic_light_run(traffic_light_t* traf_light){
	switch(traf_light->state)
	{
		case GREEN:
			LED_execute(traf_light, YELLOW, GREEN_TIME,
						LED_ON, LED_OFF, LED_OFF);
			break;
		case YELLOW:
			LED_execute(traf_light, RED, YELLOW_TIME,
									LED_OFF, LED_ON, LED_OFF);
			break;
		case RED:
			LED_execute(traf_light, GREEN, RED_TIME,
									LED_OFF, LED_OFF, LED_ON);
			break;
//		default:
//			break;
	}
	traf_light->time--;
}

