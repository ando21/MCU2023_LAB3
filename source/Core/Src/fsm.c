/*
 * fsm.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */


#include "fsm.h"
#include "main.h"
#include "software_timer.h"
#include "global.h"
#include "button.h"


void normalMode() {
	switch( led_status_1 ) {
	case 0:
		led_status_1 = 1;
		led7buffer[0] = red_timer / 10;
		led7buffer[1] = red_timer % 10 + 1;
		setTimer1(red_timer*1000);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, SET);

		if( flag1 == 1 ) {
			led_status_1 = 2;
			led7buffer[0] = green_timer / 10;
			led7buffer[1] = green_timer % 10 + 1;
			setTimer1(green_timer*1000);
		}
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, SET);

		if( flag1 == 1 ) {
			led_status_1 = 3;
			led7buffer[0] = yellow_timer / 10;
			led7buffer[1] = yellow_timer % 10 + 1;
			setTimer1(yellow_timer*1000);
		}
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, RESET);

		if( flag1 == 1 ) {
			led_status_1 = 1;
			led7buffer[0] = red_timer / 10;
			led7buffer[1] = red_timer % 10 + 1;
			setTimer1(red_timer*1000);
		}
		break;
	default:
		break;
	}
	switch( led_status_2 ) {
	case 0:
		led_status_2 = 2;
		led7buffer[2] = green_timer/10;
		led7buffer[3] = green_timer%10+1;
		setTimer3(green_timer*1000);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, SET);

		if( flag3 == 1 ) {
			led_status_2 = 2;
			led7buffer[2] = green_timer/10;
			led7buffer[3] = green_timer%10+1;
			setTimer3(green_timer*1000);
		}
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, SET);

		if( flag3 == 1 ) {
			led_status_2 = 3;
			led7buffer[2] = yellow_timer/10;
			led7buffer[3] = yellow_timer%10+1;
			setTimer3(yellow_timer*1000);
		}
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, RESET);

		if( flag3 == 1 ) {
			led_status_2 = 1;
			led7buffer[2] = red_timer/10;
			led7buffer[3] = red_timer%10+1;
			setTimer3(red_timer*1000);
		}
		break;
	default:
		break;
	}
	if( flag_7seg == 1) {
		led7buffer[1]--;
		led7buffer[3]--;
		if( led7buffer[1] < 0 ) {
			led7buffer[0]--;
			led7buffer[1] = 9;
			if( led7buffer[0] < 0 ) {
				led7buffer[0] = 0;
			}
		}
		if( led7buffer[3] < 0 ) {
			led7buffer[2]--;
			led7buffer[3] = 9;
			if( led7buffer[2] < 0 ) {
				led7buffer[2] = 0;
			}
		}
		setTime_counter_7seg(1000);
	}

}

void redIncrease() {
	if( flagBlinkMode == 1 ) {
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, blink_state);
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, blink_state);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, SET);
		blink_state = 1 - blink_state;
		setTimerBlinkMode(250);
	}
	if( pressBtn2() == 1) {
		red_timer_mode++;
		if( red_timer_mode > 99 ) {
			red_timer_mode = 0;
		}
	}
	if( pressBtn3() == 1 ) {
		red_timer = red_timer_mode;
	}
}

void greenIncrease() {
	if( flagBlinkMode == 1 ) {
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, blink_state);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, blink_state);
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, SET);
		blink_state = 1 - blink_state;
		setTimerBlinkMode(250);
	}
	if( pressBtn2() == 1) {
		green_timer_mode++;
		if( green_timer_mode > 99 ) {
			green_timer_mode = 0;
		}
	}
	if( pressBtn3() == 1 ) {
		green_timer = green_timer_mode;
	}
}

void amberIncrease() {
	if( flagBlinkMode == 1 ) {
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, blink_state);
		HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, blink_state);
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, SET);
		blink_state = 1 - blink_state;
		setTimerBlinkMode(250);
	}
	if( pressBtn2() == 1) {
		yellow_timer_mode++;
		if( yellow_timer_mode > 99 ) {
			yellow_timer_mode = 0;
		}
	}
	if( pressBtn3() == 1 ) {
		yellow_timer = yellow_timer_mode;
	}
}


void buttonStateFSM() {
	switch( traffic_status ) {
	case 0:
		traffic_status = 1;
		led_status_1 = 0;
		break;
	case 1:
		normalMode();
		if( pressBtn1() == 1 ) {
			traffic_status = 2;
			redIncrease();
			led7buffer[0] = red_timer_mode / 10;
			led7buffer[1] = red_timer_mode % 10;
			led7buffer[2] = 0;
			led7buffer[3] = 2;
		}
		break;
	case 2:
		redIncrease();
		led7buffer[0] = red_timer_mode / 10;
		led7buffer[1] = red_timer_mode % 10;
		led7buffer[2] = 0;
		led7buffer[3] = 2;
		if( pressBtn1() == 1 ) {
			red_timer_mode = red_timer;
			traffic_status = 3;
			greenIncrease();
			led7buffer[0] = green_timer_mode / 10;
			led7buffer[1] = green_timer_mode % 10;
			led7buffer[2] = 0;
			led7buffer[3] = 3;
		}
		break;
	case 3:
		greenIncrease();
		led7buffer[0] = green_timer_mode / 10;
		led7buffer[1] = green_timer_mode % 10;
		led7buffer[2] = 0;
		led7buffer[3] = 3;
		if( pressBtn1() == 1 ) {
			green_timer_mode = green_timer;
			traffic_status = 4;
			amberIncrease();
			led7buffer[0] = yellow_timer_mode / 10;
			led7buffer[1] = yellow_timer_mode % 10;
			led7buffer[2] = 0;
			led7buffer[3] = 4;
		}
		break;
	case 4:
		amberIncrease();
		led7buffer[0] = yellow_timer_mode / 10;
		led7buffer[1] = yellow_timer_mode % 10;
		led7buffer[2] = 0;
		led7buffer[3] = 4;
		if( pressBtn1() == 1 ) {
			yellow_timer_mode = yellow_timer;
			traffic_status = 1;
			led_status_1 = 0;
			led_status_2 = 0;
		}
		break;
	default:
		break;
	}
}
