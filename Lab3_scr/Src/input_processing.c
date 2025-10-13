/*
 * input_processing.c
 *
 *  Created on: Oct 10, 2025
 *      Author: khoil
 */
#include "main.h"
#include "input_reading.h"
#include "input_processing.h"
enum ButtonState {
    BUTTON_RELEASED,
    BUTTON_PRESSED,
    BUTTON_PRESSED_MORE_THAN_1_SECOND
};

enum ButtonState buttonState[3]= {BUTTON_RELEASED};
/*
 * Handles Mode selection using Button 1.
 * Each press increases the mode number (1 → 4), then cycles back to 1.
 * Resets counters when returning to Mode 1.
 * FSM behavior:
 *   - BUTTON_RELEASED → if pressed → BUTTON_PRESSED + increment mode
 *   - BUTTON_PRESSED  → if released → BUTTON_RELEASED
 */
void UpdateMode() {
	switch (buttonState[0]) {
		case BUTTON_RELEASED:
			if (is_button_pressed(0)) {
				buttonState[0] = BUTTON_PRESSED;
				mode++;
				if (mode > 4) {
					mode = 1;
					resetCountValue();
				}
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(0)) {
				buttonState[0] = BUTTON_RELEASED;
			}
			break;
		default:
			break;
	}
}
/*
 * Increments the draft duration value depending on the current mode:
 *   Mode 2 → Red duration
 *   Mode 3 → Yellow duration
 *   Mode 4 → Green duraton
 *go back to 0 when exceeding 99 seconds.
 */
static void increaseDraftValue() {
	switch (mode) {
		case 2:
			red_draft++;
			if (red_draft > 99) red_draft = 0;
			break;
		case 3:
			yellow_draft++;
			if (yellow_draft > 99) yellow_draft = 0;
			break;
		case 4:
			green_draft++;
			if (green_draft > 99) green_draft = 0;
			break;
		default:
			break;
	}
}
/*
 * Saves the updated draft values (red_draft, yellow_draft, green_draft)
 * into their actual duration variables. It also ensures total cycle
 * timing remains consistent by adjusting related light durations.
 * The `diff` variable represents the change in time for the modified color.
 */
static void setDurationValue() {
	int diff = 0;
	switch (mode) {
		case 2:
			diff = red_draft - red_value;
			red_value = red_draft;
			green_value += diff;
			green_draft += diff;
			break;
		case 3:
			diff = yellow_draft - yellow_value;
			yellow_value = yellow_draft;
			red_value += diff;
			red_draft += diff;
			break;
		case 4:
			diff = green_draft - green_value;
			green_value = green_draft;
			green_value += diff;
			green_draft += diff;
			break;
		default:
			break;
	}
}
/*
 * Handles the adjustment of light durations using Button 2 and Button 3.
 * Button 2:
 *   - Short press → increment draft value (red/yellow/green)
 *   - Long press  → continuously increment draft value while held
 * Button 3:
 *   - Short press → confirm and save new duration (apply draft values)
 *
 *
enum LEDState {RED, YELLOW, GREEN}; * FSMs for Button 2 and Button 3 manage press, release, and long-press states.
 */
void UpdateDurationValue() {
	switch (buttonState[1]) {
		case BUTTON_RELEASED:
			if (is_button_pressed(1)) {
				buttonState[1] = BUTTON_PRESSED;
				increaseDraftValue();
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(1)) {
				buttonState[1] = BUTTON_RELEASED;
			}
			if (is_button_pressed_1s(1)) {
				buttonState[1] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
				increaseDraftValue();
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND:
			if (!is_button_pressed(1)) {
				buttonState[1] = BUTTON_RELEASED;
			}
			if (is_button_held(1)) {
				reset_flagForButtonHold(1);
				increaseDraftValue();
			}
			break;
		default:
			break;
	}

	switch (buttonState[2]) {
		case BUTTON_RELEASED:
			if (is_button_pressed(2)) {
				buttonState[2] = BUTTON_PRESSED;
				setDurationValue();
			}
			break;
		case BUTTON_PRESSED:
			if (!is_button_pressed(2)) {
				buttonState[2] = BUTTON_RELEASED;
			}
			break;
		default:
			break;
	}
}

