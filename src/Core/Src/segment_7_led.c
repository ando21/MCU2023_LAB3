/*
 * segment_7_led.c
 *
 *  Created on: Nov 14, 2023
 *      Author: ADMIN
 */


#include "segment_7_led.h"
#include "software_timer.h"
#include "traffic_light.h"



void display7SegPortA(int number) {
	switch(number) {
	case 0:
		HAL_GPIO_WritePin(GPIOA, A, RESET);
		HAL_GPIO_WritePin(GPIOA, B, RESET);
		HAL_GPIO_WritePin(GPIOA, C, RESET);
		HAL_GPIO_WritePin(GPIOA, D, RESET);
		HAL_GPIO_WritePin(GPIOA, E, RESET);
		HAL_GPIO_WritePin(GPIOA, F, RESET);
		HAL_GPIO_WritePin(GPIOA, G, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, A, SET);
		HAL_GPIO_WritePin(GPIOA, B, RESET);
		HAL_GPIO_WritePin(GPIOA, C, RESET);
		HAL_GPIO_WritePin(GPIOA, D, SET);
		HAL_GPIO_WritePin(GPIOA, E, SET);
		HAL_GPIO_WritePin(GPIOA, F, SET);
		HAL_GPIO_WritePin(GPIOA, G, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, A, RESET);
		HAL_GPIO_WritePin(GPIOA, B, RESET);
		HAL_GPIO_WritePin(GPIOA, C, SET);
		HAL_GPIO_WritePin(GPIOA, D, RESET);
		HAL_GPIO_WritePin(GPIOA, E, RESET);
		HAL_GPIO_WritePin(GPIOA, F, SET);
		HAL_GPIO_WritePin(GPIOA, G, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, A, RESET);
		HAL_GPIO_WritePin(GPIOA, B, RESET);
		HAL_GPIO_WritePin(GPIOA, C, RESET);
		HAL_GPIO_WritePin(GPIOA, D, RESET);
		HAL_GPIO_WritePin(GPIOA, E, SET);
		HAL_GPIO_WritePin(GPIOA, F, SET);
		HAL_GPIO_WritePin(GPIOA, G, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, A, SET);
		HAL_GPIO_WritePin(GPIOA, B, RESET);
		HAL_GPIO_WritePin(GPIOA, C, RESET);
		HAL_GPIO_WritePin(GPIOA, D, SET);
		HAL_GPIO_WritePin(GPIOA, E, SET);
		HAL_GPIO_WritePin(GPIOA, F, RESET);
		HAL_GPIO_WritePin(GPIOA, G, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, A, RESET);
		HAL_GPIO_WritePin(GPIOA, B, SET);
		HAL_GPIO_WritePin(GPIOA, C, RESET);
		HAL_GPIO_WritePin(GPIOA, D, RESET);
		HAL_GPIO_WritePin(GPIOA, E, SET);
		HAL_GPIO_WritePin(GPIOA, F, RESET);
		HAL_GPIO_WritePin(GPIOA, G, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOA, A, RESET);
		HAL_GPIO_WritePin(GPIOA, B, SET);
		HAL_GPIO_WritePin(GPIOA, C, RESET);
		HAL_GPIO_WritePin(GPIOA, D, RESET);
		HAL_GPIO_WritePin(GPIOA, E, RESET);
		HAL_GPIO_WritePin(GPIOA, F, RESET);
		HAL_GPIO_WritePin(GPIOA, G, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, A, RESET);
		HAL_GPIO_WritePin(GPIOA, B, RESET);
		HAL_GPIO_WritePin(GPIOA, C, RESET);
		HAL_GPIO_WritePin(GPIOA, D, SET);
		HAL_GPIO_WritePin(GPIOA, E, SET);
		HAL_GPIO_WritePin(GPIOA, F, SET);
		HAL_GPIO_WritePin(GPIOA, G, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, A, RESET);
		HAL_GPIO_WritePin(GPIOA, B, RESET);
		HAL_GPIO_WritePin(GPIOA, C, RESET);
		HAL_GPIO_WritePin(GPIOA, D, RESET);
		HAL_GPIO_WritePin(GPIOA, E, RESET);
		HAL_GPIO_WritePin(GPIOA, F, RESET);
		HAL_GPIO_WritePin(GPIOA, G, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, A, RESET);
		HAL_GPIO_WritePin(GPIOA, B, RESET);
		HAL_GPIO_WritePin(GPIOA, C, RESET);
		HAL_GPIO_WritePin(GPIOA, D, RESET);
		HAL_GPIO_WritePin(GPIOA, E, SET);
		HAL_GPIO_WritePin(GPIOA, F, RESET);
		HAL_GPIO_WritePin(GPIOA, G, RESET);
		break;
	default:
		break;
	}
}

void display7SegPortB(int number) {
	switch(number) {
	case 0:
		HAL_GPIO_WritePin(GPIOB, A, RESET);
		HAL_GPIO_WritePin(GPIOB, B, RESET);
		HAL_GPIO_WritePin(GPIOB, C, RESET);
		HAL_GPIO_WritePin(GPIOB, D, RESET);
		HAL_GPIO_WritePin(GPIOB, E, RESET);
		HAL_GPIO_WritePin(GPIOB, F, RESET);
		HAL_GPIO_WritePin(GPIOB, G, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, A, SET);
		HAL_GPIO_WritePin(GPIOB, B, RESET);
		HAL_GPIO_WritePin(GPIOB, C, RESET);
		HAL_GPIO_WritePin(GPIOB, D, SET);
		HAL_GPIO_WritePin(GPIOB, E, SET);
		HAL_GPIO_WritePin(GPIOB, F, SET);
		HAL_GPIO_WritePin(GPIOB, G, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, A, RESET);
		HAL_GPIO_WritePin(GPIOB, B, RESET);
		HAL_GPIO_WritePin(GPIOB, C, SET);
		HAL_GPIO_WritePin(GPIOB, D, RESET);
		HAL_GPIO_WritePin(GPIOB, E, RESET);
		HAL_GPIO_WritePin(GPIOB, F, SET);
		HAL_GPIO_WritePin(GPIOB, G, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, A, RESET);
		HAL_GPIO_WritePin(GPIOB, B, RESET);
		HAL_GPIO_WritePin(GPIOB, C, RESET);
		HAL_GPIO_WritePin(GPIOB, D, RESET);
		HAL_GPIO_WritePin(GPIOB, E, SET);
		HAL_GPIO_WritePin(GPIOB, F, SET);
		HAL_GPIO_WritePin(GPIOB, G, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, A, SET);
		HAL_GPIO_WritePin(GPIOB, B, RESET);
		HAL_GPIO_WritePin(GPIOB, C, RESET);
		HAL_GPIO_WritePin(GPIOB, D, SET);
		HAL_GPIO_WritePin(GPIOB, E, SET);
		HAL_GPIO_WritePin(GPIOB, F, RESET);
		HAL_GPIO_WritePin(GPIOB, G, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, A, RESET);
		HAL_GPIO_WritePin(GPIOB, B, SET);
		HAL_GPIO_WritePin(GPIOB, C, RESET);
		HAL_GPIO_WritePin(GPIOB, D, RESET);
		HAL_GPIO_WritePin(GPIOB, E, SET);
		HAL_GPIO_WritePin(GPIOB, F, RESET);
		HAL_GPIO_WritePin(GPIOB, G, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, A, RESET);
		HAL_GPIO_WritePin(GPIOB, B, SET);
		HAL_GPIO_WritePin(GPIOB, C, RESET);
		HAL_GPIO_WritePin(GPIOB, D, RESET);
		HAL_GPIO_WritePin(GPIOB, E, RESET);
		HAL_GPIO_WritePin(GPIOB, F, RESET);
		HAL_GPIO_WritePin(GPIOB, G, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, A, RESET);
		HAL_GPIO_WritePin(GPIOB, B, RESET);
		HAL_GPIO_WritePin(GPIOB, C, RESET);
		HAL_GPIO_WritePin(GPIOB, D, SET);
		HAL_GPIO_WritePin(GPIOB, E, SET);
		HAL_GPIO_WritePin(GPIOB, F, SET);
		HAL_GPIO_WritePin(GPIOB, G, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, A, RESET);
		HAL_GPIO_WritePin(GPIOB, B, RESET);
		HAL_GPIO_WritePin(GPIOB, C, RESET);
		HAL_GPIO_WritePin(GPIOB, D, RESET);
		HAL_GPIO_WritePin(GPIOB, E, RESET);
		HAL_GPIO_WritePin(GPIOB, F, RESET);
		HAL_GPIO_WritePin(GPIOB, G, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, A, RESET);
		HAL_GPIO_WritePin(GPIOB, B, RESET);
		HAL_GPIO_WritePin(GPIOB, C, RESET);
		HAL_GPIO_WritePin(GPIOB, D, RESET);
		HAL_GPIO_WritePin(GPIOB, E, SET);
		HAL_GPIO_WritePin(GPIOB, F, RESET);
		HAL_GPIO_WritePin(GPIOB, G, RESET);
		break;
	default:
		break;
	}
}
void displayA(int number) {
	switch(digit) {
	case 1:
		display7SegPortA(number / 10);
		HAL_GPIO_WritePin(GPIOA, EN1, RESET);
		HAL_GPIO_WritePin(GPIOB, EN2, SET);
		break;
	case 2:
		display7SegPortA(number % 10);
		HAL_GPIO_WritePin(GPIOA, EN1, SET);
		HAL_GPIO_WritePin(GPIOB, EN2, RESET);
		break;
	default:
		break;
	}
}
void displayB(int number) {
	switch(digit) {
	case 1:
		display7SegPortB(number / 10);
		HAL_GPIO_WritePin(GPIOA, EN3, RESET);
		HAL_GPIO_WritePin(GPIOB, EN4, SET);
		break;
	case 2:
		display7SegPortB(number % 10);
		HAL_GPIO_WritePin(GPIOA, EN3, SET);
		HAL_GPIO_WritePin(GPIOB, EN4, RESET);
		break;
	default:
		break;
	}
}

