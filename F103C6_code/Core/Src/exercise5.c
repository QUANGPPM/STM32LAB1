#include "exercise5.h"

void init_exercise5(){
	init_exercise3();
	init_exercise4(SEG_0_GPIO_Port, SEG_0_Pin,
			  	  	 SEG_1_GPIO_Port, SEG_1_Pin,
					 SEG_2_GPIO_Port, SEG_2_Pin,
					 SEG_3_GPIO_Port, SEG_3_Pin,
					 SEG_4_GPIO_Port, SEG_4_Pin,
					 SEG_5_GPIO_Port, SEG_5_Pin,
					 SEG_6_GPIO_Port, SEG_6_Pin);
}

void exercise5_run(){
	exercise3_run();
	exercise4_run();
}
