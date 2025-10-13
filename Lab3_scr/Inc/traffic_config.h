/*
 * traffic_config.h
 *
 *  Created on: Oct 12, 2025
 *      Author: khoil
 */

#ifndef INC_TRAFFIC_CONFIG_H_
#define INC_TRAFFIC_CONFIG_H_

//Default time duration values (in seconds or timer ticks)
//These define the initial durations for each traffic light color.
#define RED_INIT 30
#define YELLOW_INIT	5
#define GREEN_INIT 25

//config variable declarations
void LedTimeDurationInit();
extern int mode;
extern int red_value, yellow_value, green_value;

//These hold temporary "draft" values used during modification mode
//When the user confirms (presses Button3), these are copied to the actual values
extern int red_draft, yellow_draft, green_draft;

#endif /* INC_TRAFFIC_CONFIG_H_ */
