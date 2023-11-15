/*
 * segment_led.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */


#include "main.h"
#include "segment_led.h"
#include "software_timer.h"
#include "global.h"

void display7Seg(int number) {
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

void fsmled7seg() {
	switch( led7seg_status ) {
		  case LED1:
			  HAL_GPIO_WritePin(GPIOA, EN0, RESET);
			  HAL_GPIO_WritePin(GPIOA, EN1, SET);
			  HAL_GPIO_WritePin(GPIOB, EN2, SET);
			  HAL_GPIO_WritePin(GPIOB, EN3, SET);
			  display7Seg(led7buffer[0]);
			  if( flag2 == 1 ) {
				  led7seg_status = LED2;
				  setTimer2(250);
			  }
			  break;
		  case LED2:
			  HAL_GPIO_WritePin(GPIOA, EN0, SET);
			  HAL_GPIO_WritePin(GPIOA, EN1, RESET);
			  HAL_GPIO_WritePin(GPIOB, EN2, SET);
			  HAL_GPIO_WritePin(GPIOB, EN3, SET);
			  display7Seg(led7buffer[1]);
			  if( flag2 == 1 ) {
				  led7seg_status = LED3;
				  setTimer2(250);
			  }
			  break;
		  case LED3:
			  HAL_GPIO_WritePin(GPIOA, EN0, SET);
			  HAL_GPIO_WritePin(GPIOA, EN1, SET);
			  HAL_GPIO_WritePin(GPIOB, EN2, RESET);
			  HAL_GPIO_WritePin(GPIOB, EN3, SET);
			  display7Seg(led7buffer[2]);
			  if( flag2 == 1 ) {
				  led7seg_status = LED4;
				  setTimer2(250);
			  }
			  break;
		  case LED4:
			  HAL_GPIO_WritePin(GPIOA, EN0, SET);
			  HAL_GPIO_WritePin(GPIOA, EN1, SET);
			  HAL_GPIO_WritePin(GPIOB, EN2, SET);
			  HAL_GPIO_WritePin(GPIOB, EN3, RESET);

			  display7Seg(led7buffer[3]);
			  if( flag2 == 1 ) {
				  led7seg_status = LED1;
				  setTimer2(250);
			  }
			  break;
		  default:
			  break;
		  }
}
