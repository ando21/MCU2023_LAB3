/*
 * traffic_light.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */
#include "traffic_light.h"
#include "software_timer.h"
#include "segment_7_led.h"

int VERTICAL = 1;
int HORIZONTAL = 0;
int RED = 1;
int YELLOW = 2;
int GREEN = 3;

int NORMAL_RED_DURATION = 5;
int NORMAL_YELLOW_DURATION = 2;
int NORMAL_GREEN_DURATION = 3;
int verticalLightState = 1;
int	horizontalLightState = 3;
int vertCounter = 5;
int horizonCounter = 3;


void INIT(int duration) {
	HAL_GPIO_WritePin(GPIOA, EN2, RESET);
	HAL_GPIO_WritePin(GPIOB, EN4, RESET);
	HAL_GPIO_WritePin(GPIOA, EN1, SET);
	HAL_GPIO_WritePin(GPIOB, EN3, SET);

	setTimer(duration);
	red(VERTICAL);
	green(HORIZONTAL);
	setSegmentDuration();
	digit = 1;
}

void red(int state) {
	switch(state) {
	case 1:
		HAL_GPIO_WritePin(GPIOA, V_RED, RESET);
		HAL_GPIO_WritePin(GPIOA, V_YELLOW, SET);
		HAL_GPIO_WritePin(GPIOA, V_GREEN, SET);
		verticalLightState = RED;
		break;
	case 0:
		HAL_GPIO_WritePin(GPIOA, H_RED, RESET);
		HAL_GPIO_WritePin(GPIOA, H_YELLOW, SET);
		HAL_GPIO_WritePin(GPIOA, H_GREEN, SET);
		horizontalLightState = RED;
		break;
	}
}

void green(int state) {
	switch(state) {
	case 1:
		HAL_GPIO_WritePin(GPIOA, V_RED, SET);
		HAL_GPIO_WritePin(GPIOA, V_YELLOW, SET);
		HAL_GPIO_WritePin(GPIOA, V_GREEN, RESET);
		verticalLightState = GREEN;
		break;
	case 0:
		HAL_GPIO_WritePin(GPIOA, H_RED, SET);
		HAL_GPIO_WritePin(GPIOA, H_YELLOW, SET);
		HAL_GPIO_WritePin(GPIOA, H_GREEN, RESET);
		horizontalLightState = GREEN;
		break;
	}
}

void yellow(int state) {
	switch(state) {
	case 1:
		HAL_GPIO_WritePin(GPIOA, V_RED, SET);
		HAL_GPIO_WritePin(GPIOA, V_YELLOW, RESET);
		HAL_GPIO_WritePin(GPIOA, V_GREEN, SET);
		verticalLightState = YELLOW;
		break;
	case 0:
		HAL_GPIO_WritePin(GPIOA, H_RED, SET);
		HAL_GPIO_WritePin(GPIOA, H_YELLOW, RESET);
		HAL_GPIO_WritePin(GPIOA, H_GREEN, SET);
		horizontalLightState = YELLOW;
		break;
	}
}



void normalRun(int duration) {
	if (flag_signal == 1) {
//		if (segment_toggle_signal == 1) {
//			setSegmentDuration();
//			switch(digit) {
//			case 1:
//				digit = 2;
//				break;
//			case 2:
//				digit = 1;
//				break;
//			default:
//				break;
//			}
//		}
		display7SegPortA(vertCounter);
		vertCounter--;
		switch(verticalLightState) {
		case 1:
			if (vertCounter == 0) {
				verticalLightState = GREEN;
				vertCounter = 3;
				green(VERTICAL);
			} else {
				red(VERTICAL);
			}
			break;
		case 3:
			if (vertCounter == 0) {
				verticalLightState = YELLOW;
				vertCounter = 2;
				yellow(VERTICAL);
			} else {
				green(VERTICAL);
			}
			break;
		case 2:
			if (vertCounter == 0) {
				verticalLightState = RED;
				vertCounter = 5;
				red(VERTICAL);
			} else {
				yellow(VERTICAL);
			}
			break;
		}

		display7SegPortB(horizonCounter);
		horizonCounter--;
		switch(horizontalLightState) {
		case 1:
			if (horizonCounter == 0) {
				horizontalLightState = GREEN;
				horizonCounter = 3;
				green(HORIZONTAL);
			} else {
				red(HORIZONTAL);
			}
			break;
		case 3:
			if (horizonCounter == 0) {
				horizontalLightState = YELLOW;
				horizonCounter = 2;
				yellow(HORIZONTAL);
			} else {
				green(HORIZONTAL);
			}
			break;
		case 2:
			if (horizonCounter == 0) {
				horizontalLightState = RED;
				horizonCounter = 5;
				red(HORIZONTAL);
			} else {
				yellow(HORIZONTAL);
			}
			break;
		}
		setTimer(duration);
	}

}
