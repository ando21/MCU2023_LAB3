/*
 * global.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */
#include "global.h"

int led_status_1 = 0;
int led_status_2 = 0;

int traffic_status = 0;
int led7seg_status = 1;

int led7buffer[4] = {0, 0, 0, 0};
int OUT = 13;

int blink_state = 1;
int red_timer = 5;
int yellow_timer = 2;
int green_timer = 3;

int red_timer_mode = 5;
int yellow_timer_mode = 2;
int green_timer_mode = 3;

