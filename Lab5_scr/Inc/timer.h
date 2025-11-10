/*
 * timer.h
 *
 *  Created on: Nov 7, 2025
 *      Author: khoil
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIMER_CYCLE 10

void timer_run();
void setTimer0(int duration);
unsigned char get_timer0_flag();

void setTimer1(int duration);
unsigned char get_timer1_flag();


#endif /* INC_TIMER_H_ */
