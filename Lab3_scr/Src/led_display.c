/*
 * led_display.c
 *
 *  Created on: Oct 10, 2025
 *      Author: khoil
 */
#include "led_display.h"
enum LEDState {RED, YELLOW, GREEN};
static void display7SEG(int num)
{
    // Turn off all segments first
    HAL_GPIO_WritePin(Led7_a_GPIO_Port, Led7_a_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Led7_b_GPIO_Port, Led7_b_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Led7_c_GPIO_Port, Led7_c_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Led7_d_GPIO_Port, Led7_d_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Led7_e_GPIO_Port, Led7_e_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Led7_f_GPIO_Port, Led7_f_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Led7_g_GPIO_Port, Led7_g_Pin, GPIO_PIN_SET);

    // Now enable the correct segments for each digit
    switch (num) {
        case 0:
            HAL_GPIO_WritePin(Led7_a_GPIO_Port, Led7_a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_b_GPIO_Port, Led7_b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_c_GPIO_Port, Led7_c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_d_GPIO_Port, Led7_d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_e_GPIO_Port, Led7_e_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_f_GPIO_Port, Led7_f_Pin, GPIO_PIN_RESET);
            break;
        case 1:
            HAL_GPIO_WritePin(Led7_b_GPIO_Port, Led7_b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_c_GPIO_Port, Led7_c_Pin, GPIO_PIN_RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(Led7_a_GPIO_Port, Led7_a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_b_GPIO_Port, Led7_b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_d_GPIO_Port, Led7_d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_e_GPIO_Port, Led7_e_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_g_GPIO_Port, Led7_g_Pin, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(Led7_a_GPIO_Port, Led7_a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_b_GPIO_Port, Led7_b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_c_GPIO_Port, Led7_c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_d_GPIO_Port, Led7_d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_g_GPIO_Port, Led7_g_Pin, GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(Led7_b_GPIO_Port, Led7_b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_c_GPIO_Port, Led7_c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_f_GPIO_Port, Led7_f_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_g_GPIO_Port, Led7_g_Pin, GPIO_PIN_RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(Led7_a_GPIO_Port, Led7_a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_c_GPIO_Port, Led7_c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_d_GPIO_Port, Led7_d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_f_GPIO_Port, Led7_f_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_g_GPIO_Port, Led7_g_Pin, GPIO_PIN_RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(Led7_a_GPIO_Port, Led7_a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_c_GPIO_Port, Led7_c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_d_GPIO_Port, Led7_d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_e_GPIO_Port, Led7_e_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_f_GPIO_Port, Led7_f_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_g_GPIO_Port, Led7_g_Pin, GPIO_PIN_RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(Led7_a_GPIO_Port, Led7_a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_b_GPIO_Port, Led7_b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_c_GPIO_Port, Led7_c_Pin, GPIO_PIN_RESET);
            break;
        case 8:
            HAL_GPIO_WritePin(Led7_a_GPIO_Port, Led7_a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_b_GPIO_Port, Led7_b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_c_GPIO_Port, Led7_c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_d_GPIO_Port, Led7_d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_e_GPIO_Port, Led7_e_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_f_GPIO_Port, Led7_f_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_g_GPIO_Port, Led7_g_Pin, GPIO_PIN_RESET);
            break;
        case 9:
            HAL_GPIO_WritePin(Led7_a_GPIO_Port, Led7_a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_b_GPIO_Port, Led7_b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_c_GPIO_Port, Led7_c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_d_GPIO_Port, Led7_d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_f_GPIO_Port, Led7_f_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(Led7_g_GPIO_Port, Led7_g_Pin, GPIO_PIN_RESET);
            break;
        default:
            // Show nothing if invalid
            break;
    }
}
//global variables
int count1 = RED_INIT;
int count2 = GREEN_INIT;
enum LEDState state1 = RED;
enum LEDState state2 = GREEN;


void resetCountValue() {
	count1 = red_value;
	count2 = green_value;
	state1 = RED;
	state2 = GREEN;
}
/**
 *   Runs normal traffic light mode:
 * - Alternates red, yellow, green phases for both directions
 * - Updates the countdown timers
 * - Controls GPIOs for LEDs based on timing
 */
void NormalMode() {
	count1--;
	count2--;
	//Control Way1
	switch (state1) {
		case RED:
			HAL_GPIO_WritePin(Way1_RED_GPIO_Port, Way1_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Way1_YELLOW_GPIO_Port, Way1_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Way1_GREEN_GPIO_Port, Way1_GREEN_Pin, GPIO_PIN_SET);
			if (count1 < 0) {
				count1 = green_value - 1;
				state1 = GREEN;
				HAL_GPIO_WritePin(Way1_RED_GPIO_Port, Way1_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way1_YELLOW_GPIO_Port, Way1_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way1_GREEN_GPIO_Port, Way1_GREEN_Pin, GPIO_PIN_RESET);
			}
			break;
		case YELLOW:
			HAL_GPIO_WritePin(Way1_RED_GPIO_Port, Way1_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Way1_YELLOW_GPIO_Port, Way1_YELLOW_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Way1_GREEN_GPIO_Port, Way1_GREEN_Pin, GPIO_PIN_SET);
			if (count1 < 0) {
				count1 = red_value - 1;
				state1 = RED;
				HAL_GPIO_WritePin(Way1_RED_GPIO_Port, Way1_RED_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Way1_YELLOW_GPIO_Port, Way1_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way1_GREEN_GPIO_Port, Way1_GREEN_Pin, GPIO_PIN_SET);
			}
			break;
		case GREEN:
			HAL_GPIO_WritePin(Way1_RED_GPIO_Port, Way1_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Way1_YELLOW_GPIO_Port, Way1_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Way1_GREEN_GPIO_Port, Way1_GREEN_Pin, GPIO_PIN_RESET);
			if (count1 < 0) {
				count1 = yellow_value - 1;
				state1 = YELLOW;
				HAL_GPIO_WritePin(Way1_RED_GPIO_Port, Way1_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way1_YELLOW_GPIO_Port, Way1_YELLOW_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Way1_GREEN_GPIO_Port, Way1_GREEN_Pin, GPIO_PIN_SET);
			}
			break;
		default:
			break;
	}
	//Control Way2
	switch (state2) {
		case RED:
			HAL_GPIO_WritePin(Way2_RED_GPIO_Port, Way2_RED_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Way2_YELLOW_GPIO_Port, Way2_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Way2_GREEN_GPIO_Port, Way2_GREEN_Pin, GPIO_PIN_SET);
			if (count2 < 0) {
				count2 = green_value - 1;
				state2 = GREEN;
				HAL_GPIO_WritePin(Way2_RED_GPIO_Port, Way2_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way2_YELLOW_GPIO_Port, Way2_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way2_GREEN_GPIO_Port, Way2_GREEN_Pin, GPIO_PIN_RESET);
			}
			break;
		case YELLOW:
			HAL_GPIO_WritePin(Way2_RED_GPIO_Port, Way2_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Way2_YELLOW_GPIO_Port, Way2_YELLOW_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Way2_GREEN_GPIO_Port, Way2_GREEN_Pin, GPIO_PIN_SET);
			if (count2 < 0) {
				count2 = red_value - 1;
				state2 = RED;
				HAL_GPIO_WritePin(Way2_RED_GPIO_Port, Way2_RED_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Way2_YELLOW_GPIO_Port, Way2_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way2_GREEN_GPIO_Port, Way2_GREEN_Pin, GPIO_PIN_SET);
			}
			break;
		case GREEN:
			HAL_GPIO_WritePin(Way2_RED_GPIO_Port, Way2_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Way2_YELLOW_GPIO_Port, Way2_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Way2_GREEN_GPIO_Port, Way2_GREEN_Pin, GPIO_PIN_RESET);
			if (count2 < 0) {
				count2 = yellow_value - 1;
				state2 = YELLOW;
				HAL_GPIO_WritePin(Way2_RED_GPIO_Port, Way2_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way2_YELLOW_GPIO_Port, Way2_YELLOW_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(Way2_GREEN_GPIO_Port, Way2_GREEN_Pin, GPIO_PIN_SET);
			}
			break;
		default:
			break;
	}

}
/*
*Returns the appropriate number to display on each 7-seg
*depending on the current mode of operation.
*/
static int get7SEG1Value() {
	switch (mode) { //Normal mode: show countdown for way 1
		case 1:
			return count1;
		case 2:
			return red_draft;
		case 3:
			return yellow_draft;
		case 4:
			return green_draft;
		default:
			break;
	}
	return 0;
}
static int get7SEG2Value() {
	switch (mode) {
		case 1:
			return count2;  //Normal mode: show countdown for way 2
		case 2:
			return red_draft;
		case 3:
			return yellow_draft;
		case 4:
			return green_draft;
		default:
			break;
	}
	return 0;
}
/*
 * Mode 1 → Normal traffic operation
 * Mode 2 → Flashing red (adjust red duration)
 * Mode 3 → Flashing yellow
 * Mode 4 → Flashing green
*/
void LedDispMode() {
	switch (mode) {
		case 1:
			if (get_timer0_flag()) {
				setTimer0(250);
				NormalMode();
			}
			break;
		case 2:
			if (get_timer0_flag()) {
				setTimer0(200);
				HAL_GPIO_TogglePin(Way1_RED_GPIO_Port, Way1_RED_Pin);
				HAL_GPIO_TogglePin(Way2_RED_GPIO_Port, Way2_RED_Pin);
				HAL_GPIO_WritePin(Way1_YELLOW_GPIO_Port, Way1_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way1_GREEN_GPIO_Port, Way1_GREEN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way2_YELLOW_GPIO_Port, Way2_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way2_GREEN_GPIO_Port, Way2_GREEN_Pin, GPIO_PIN_SET);
			}
			break;
		case 3:
			if (get_timer0_flag()) {
				setTimer0(200);
				HAL_GPIO_TogglePin(Way1_YELLOW_GPIO_Port, Way1_YELLOW_Pin);
				HAL_GPIO_TogglePin(Way2_YELLOW_GPIO_Port, Way2_YELLOW_Pin);
				HAL_GPIO_WritePin(Way1_RED_GPIO_Port, Way1_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way1_GREEN_GPIO_Port, Way1_GREEN_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way2_RED_GPIO_Port, Way2_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way2_GREEN_GPIO_Port, Way2_GREEN_Pin, GPIO_PIN_SET);
			}
			break;
		case 4:
			if (get_timer0_flag()) {
				setTimer0(200);
				HAL_GPIO_TogglePin(Way1_GREEN_GPIO_Port, Way1_GREEN_Pin);
				HAL_GPIO_TogglePin(Way2_GREEN_GPIO_Port, Way2_GREEN_Pin);
				HAL_GPIO_WritePin(Way1_YELLOW_GPIO_Port, Way1_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way1_RED_GPIO_Port, Way1_RED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way2_YELLOW_GPIO_Port, Way2_YELLOW_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(Way2_RED_GPIO_Port, Way2_RED_Pin, GPIO_PIN_SET);
			}
			break;
		default:
			break;
	}
}
/*
 *  LEDScanning()
 *  Implements multiplexed scanning for 5 display digits:
 *   - 4 digits for countdown timers (Way1, Way2)
 *   - 1 digit for mode indicator
 *  Called periodically (every few ms) to refresh each digit in sequence.
*/
void LEDScanning() {
	static int scan_index = 0;
	switch (scan_index) {
		case 0:
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			display7SEG(get7SEG1Value() / 10);
			scan_index = 1;
			break;
		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			display7SEG(get7SEG1Value() % 10);
			scan_index = 2;
			break;
		case 2:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			display7SEG(get7SEG2Value() / 10);
			scan_index = 3;
			break;
		case 3:
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			display7SEG(get7SEG2Value() % 10);
			scan_index = 4;
			break;
		case 4:
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, GPIO_PIN_SET);
			display7SEG(mode);
			scan_index = 0;
			break;
		default:
			break;
	}
}
