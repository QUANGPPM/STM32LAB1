#ifndef  EXERCISE_7_TO_10_H__
#define  EXERCISE_7_TO_10_H__

#include "main.h"

#define LED_OFF GPIO_PIN_RESET	//because GPIO pin connect to postive pin of LED
#define LED_ON GPIO_PIN_SET


void init_exercise6_to_10();
void clearAllClock ();
void setNumberOnClock(int8_t num);
void clearNumberOnClock(int8_t num);
void exercise10_run();
uint8_t second_run();
uint8_t minute_run();


#endif
