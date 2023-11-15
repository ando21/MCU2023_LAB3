/*
 * global.h
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define A SEG0_Pin
#define B SEG1_Pin
#define C SEG2_Pin
#define D SEG3_Pin
#define E SEG4_Pin
#define F SEG5_Pin
#define G SEG6_Pin
#define EN0 EN0_Pin
#define EN1 EN1_Pin
#define EN2 EN2_Pin
#define EN3 EN3_Pin


extern int led_status_1;
extern int led_status_2;

extern int traffic_status;
extern int led7seg_status;

extern int led7buffer[4];
extern int OUT;
extern int blink_state;
extern int red_timer;
extern int yellow_timer;
extern int green_timer;
extern int red_timer_mode;
extern int yellow_timer_mode;
extern int green_timer_mode;

#endif /* INC_GLOBAL_H_ */
