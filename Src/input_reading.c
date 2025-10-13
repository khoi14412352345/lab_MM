/*
 * input_reading.c
 *
 *  Created on: Oct 10, 2025
 *      Author: khoil
 */

#ifndef SRC_INPUT_READING_C_
#define SRC_INPUT_READING_C_



#endif /* SRC_INPUT_READING_C_ */
#include "main.h"
#include "timer.h"
#include "input_reading.h"
// we aim to work with more than one buttons
#define NO_OF_BUTTONS 3

// timer interrupt duration is 10ms, so to pass 1 second,
// we need to jump to the interrupt service routine 100 times
#define DURATION_FOR_AUTO_INCREASING 1000 / TIMER_CYCLE
#define DURATION_FOR_HOLD 200 / TIMER_CYCLE

#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

// the buffer that the final result is stored after debouncing
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];

// we define three buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[NO_OF_BUTTONS];
// we define a flag for a button pressed more than 1 second
static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
//we define a flag a button held
static uint8_t flagForButtonHold[NO_OF_BUTTONS];
// we define counter for automatically increasing the value
// after the button is pressed more than 1 second and button hold
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];
static uint16_t counterForButtonHold[NO_OF_BUTTONS];
/*
 * Initializes all buffers, counters, and flags.
 */
void init_buffer() {
	for (int i = 0; i < NO_OF_BUTTONS; i++) {
		buttonBuffer[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer1[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer2[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer3[i] = BUTTON_IS_RELEASED;
		flagForButtonPress1s[i] = 0;
		flagForButtonHold[i] = 0;
		counterForButtonPress1s[i] = 0;
		counterForButtonHold[i] = 0;
	}
}
/*
 * Reads the button states and applies 3-sample debouncing.
 * Tracks press duration and sets flags for:
 *  - Press longer than 1 second
 *  - Continuous hold (after 1 second)
 */
void button_reading(void) {
    for (int i = 0; i < NO_OF_BUTTONS; i++) {
        debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
        debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
        debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, (1U << i));

        if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i] && debounceButtonBuffer3[i] == debounceButtonBuffer2[i])
            buttonBuffer[i] = debounceButtonBuffer1[i];

        if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
            // if a button is pressed, we start counting
            if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
                counterForButtonPress1s[i]++;
            } else {
                // the flag is turned on when 1 second has passed
                // since the button is pressed
                flagForButtonPress1s[i] = 1;
                // todo
				if (counterForButtonHold[i] < DURATION_FOR_HOLD) {
					counterForButtonHold[i]++;
					if (counterForButtonHold[i] >= DURATION_FOR_HOLD) {
						counterForButtonHold[i] = 0;
						flagForButtonHold[i] = 1;
					}
				}
			}
        } else {
            counterForButtonPress1s[i] = 0;
            flagForButtonPress1s[i] = 0;
            counterForButtonHold[i] = 0;
            flagForButtonHold[i] = 0;
        }
    }
}


unsigned char is_button_pressed(unsigned char index) {
    if (index >= NO_OF_BUTTONS) return 0;
    return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}
unsigned char is_button_pressed_1s(unsigned char index) {
    if (index >= NO_OF_BUTTONS) return 0;
    return (flagForButtonPress1s[index] == 1);
}
unsigned char is_button_held(unsigned char index) {
	if (index >= NO_OF_BUTTONS) return 0;
	return (flagForButtonHold[index] == 1);
}
void reset_flagForButtonHold(unsigned char index) {
	flagForButtonHold[index] = 0;
}

