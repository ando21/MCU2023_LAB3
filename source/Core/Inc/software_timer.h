/*
 * software_timer.h
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARET_TIMER_H_
/*flag sinal for timer interrupt */
extern int flag0;
extern int flag1;
extern int flag2;
extern int flag3;
extern int flag_7seg;
extern int flagBlinkMode;

void setCycle(int userCycle);
void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTime_counter_7seg (int duration);
void setTimerBlinkMode(int duration);
void timerRun();
void initial();

#endif /* INC_SOFTWARE_TIMER_H_ */
