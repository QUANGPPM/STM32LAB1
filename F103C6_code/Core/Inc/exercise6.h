#ifndef  EXERCISE_6_H__
#define  EXERCISE_6_H__

#include "main.h"

#define LED_OFF GPIO_PIN_RESET	//because GPIO pin connect to postive pin of LED
#define LED_ON GPIO_PIN_SET


typedef enum{
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NIGHT,
	TEN,
	ELEVEN
}clock_state;

void init_exercise6_to_10();

void exercise6_run();




#endif
