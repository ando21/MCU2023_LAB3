/*
 * software_timer.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */


#include "software_timer.h"

int timer0 = 0;
int flag0 = 0;

int timer1 = 0;
int flag1 = 0;

int timer2 = 0;
int flag2 = 0;

int timer3 = 0;
int flag3 = 0;

int time_7seg = 0;
int flag_7seg = 0;

int timerBlinkMode = 0;
int flagBlinkMode = 0;

int cycle = 10;

void setCycle(int userCycle) {
	cycle = userCycle;
}

void setTimer0(int duration) {
	timer0 = duration/cycle;
	flag0 = 0;
}
void setTimer1(int duration) {
	timer1 = duration/cycle;
	flag1 = 0;
}
void setTimer2(int duration) {
	timer2 = duration/cycle;
	flag2 = 0;
}
void setTimer3(int duration) {
	timer3 = duration/cycle;
	flag3 = 0;
}
void setTime_counter_7seg(int duration) {
	time_7seg = duration/cycle;
	flag_7seg = 0;
}
void setTimerBlinkMode(int duration) {
	timerBlinkMode = duration/cycle;
	flagBlinkMode = 0;
}

void timerRun() {
	if(timer0 > 0) {
		timer0--;
		if(timer0 <= 0) {
			flag0 = 1;
		}
	}
	if(timer1 > 0) {
		timer1--;
		if(timer1 <= 0) {
			flag1 = 1;
		}
	}
	if(timer2 > 0) {
		timer2--;
		if(timer2 <= 0) {
			flag2 = 1;
		}
	}
	if(timer3 > 0) {
		timer3--;
		if(timer3 <= 0) {
			flag3 = 1;
		}
	}
	if( time_7seg > 0 ) {
		time_7seg--;
		if( time_7seg <= 0 ) {
			flag_7seg = 1;
		}
	}
	if( timerBlinkMode > 0 ) {
		timerBlinkMode--;
		if( timerBlinkMode <= 0 ) {
			flagBlinkMode = 1;
		}
	}
}
void initial(){
	setCycle(10);
	setTimer0(1000);
	setTimer1(1000);
	setTimer2(1000);
	setTimerBlinkMode(1000);
	setTime_counter_7seg(1000);
}
