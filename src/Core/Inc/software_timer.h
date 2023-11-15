/*
 * software_timer.h
 *
 *  Created on: Nov 14, 2023
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int flag_signal;
extern int segment_toggle_signal;
extern int digit;

void setTimer(int duration);
void timerActivate();
void setSegmentDuration();
void segmentActivate();

#endif /* INC_SOFTWARE_TIMER_H_ */
