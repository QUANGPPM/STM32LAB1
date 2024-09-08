#ifndef  EXERCISE_2_H__
#define  EXERCISE_2_H__

#include "main.h"

#define LED_OFF GPIO_PIN_RESET	//because GPIO pin connect to postive pin of LED
#define LED_ON GPIO_PIN_SET

#define GREEN_TIME 3
#define YELLOW_TIME 2
#define RED_TIME 5

typedef enum{
	GREEN = 0u,
	YELLOW,
	RED
}traffic_state;

typedef struct{
	/*
	 * GPIO parameters
	 */
	GPIO_TypeDef *GREEN_GPIOx;
	uint16_t GREEN_Pin;
	GPIO_TypeDef *YELLOW_GPIOx;
	uint16_t YELLOW_Pin;
	GPIO_TypeDef *RED_GPIOx;
	uint16_t RED_Pin;
	/*
	 * other parameters
	 */
	traffic_state state;
	uint8_t time;
	uint8_t set_up;
}traffic_light_t;

void init_traffic_light(traffic_light_t* traf_light1, traffic_light_t* traf_light2,
						//---the first traffic light---//
						GPIO_TypeDef *GREEN_GPIO1x, uint16_t GREEN_Pin1,
						GPIO_TypeDef *YELLOW_GPIO1x, uint16_t YELLOW_Pin1,
						GPIO_TypeDef *RED_GPIO1x, uint16_t RED_Pin1,
						//---the second traffic light---//
						GPIO_TypeDef *GREEN_GPIO2x, uint16_t GREEN_Pin2,
						GPIO_TypeDef *YELLOW_GPIO2x, uint16_t YELLOW_Pin,
						GPIO_TypeDef *RED_GPIOx, uint16_t RED_Pin,
						traffic_state state);

void traffic_light_run(traffic_light_t* traf_light);







#endif
