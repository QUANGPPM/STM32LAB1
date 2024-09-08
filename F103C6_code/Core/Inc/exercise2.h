#ifndef  EXERCISE_2_H__
#define  EXERCISE_2_H__

#include "main.h"

#define LED_ON GPIO_PIN_RESET	//because GPIO pin connet to negative pin of LED
#define LED_OFF GPIO_PIN_SET

#define GREEN_TIME 3
#define YELLOW_TIME 2
#define RED_TIME 5

typedef enum{
	GREEN = 0u,
	YELLOW,
	RED
}traffic_state;

void init_exercise2();
void exercise2_run();

#endif
