/*
 * software_timer.c
 *
 *  Created on: Nov 14, 2023
 *      Author: ADMIN
 */

#include "segment_7_led.h"
#include "software_timer.h"

int flag_signal = 0;
int segment_toggle_signal = 0; /*Not Toggle*/
int counter = 0; /*counter for 1s*/
int segment_counter = 50; /*counter for segment led toggle*/
int digit = 1;

void setTimer(int duration) {
	counter = duration;
	flag_signal = 0;
}

void setSegmentDuration() {
	segment_toggle_signal = 0; /*Not Toggle*/
	segment_counter = 50; /*counter for segment led toggle*/
}

void segmentActivate() {
	if (segment_counter > 0) {
		segment_counter--;
	} else {
		segment_toggle_signal = 1;
	}
}

void timerActivate() {
	if (counter > 0) {
		counter--;
	} else {
		flag_signal = 1;
	}
}
