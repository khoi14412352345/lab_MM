/*
 * timer.c
 *
 *  Created on: Oct 10, 2025
 *      Author: khoil
 */

#include "main.h"
#include "input_reading.h"
#include "timer.h"
int timer0_counter =0;
int timer0_flag = 0;
int timer2_counter = 0;
int timer2_flag = 0;

void setTimer0(int duration){
	timer0_counter = duration / TIMER_CYCLE;
	timer0_flag =0;

}
void setTimer2(int duration) {
	timer2_counter = duration / TIMER_CYCLE;
	timer2_flag = 0;
}

void timer_run() { // Hàm này được gọi trong ngắt TIM2 mỗi 10ms để giảm counter của các timer
    if (timer0_counter > 0) {
        timer0_counter--;
        if (timer0_counter == 0) timer0_flag = 1;
    }
    if (timer2_counter > 0) {
    		timer2_counter--;
    		if (timer2_counter == 0) timer2_flag = 1;
    	}

}
int get_timer0_flag() {
	return timer0_flag;
}
int get_timer2_flag() {
	return timer2_flag;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	timer_run();
    if (htim->Instance == TIM2)
    {
        button_reading();
    }
}

