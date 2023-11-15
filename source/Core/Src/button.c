/*
 * button.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */


#include "button.h"
#include "main.h"

int pressed_flag0 =0;
int pressed_flag1 = 0;
int pressed_flag2 = 0;

int timeOutForKeyPressed0 = 200;
int timeOutForKeyPressed1 = 200;
int timeOutForKeyPressed2 = 200;

int pressBtn1() {
	if( pressed_flag0 == 1 ) {
		pressed_flag0 = 0;
		return 1;
	}
	return 0;
}

int pressBtn2() {
	if( pressed_flag1 == 1 ) {
		pressed_flag1 = 0;
		return 1;
	}
	return 0;
}

int pressBtn3() {
	if( pressed_flag2 == 1 ) {
		pressed_flag2 = 0;
		return 1;
	}
	return 0;
}


int keyReg0[3] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int keyReg1[3] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int keyReg2[3] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };
int keyReg3[3] = { NORMAL_STATE, NORMAL_STATE, NORMAL_STATE };

void getKeyInput1() {
	keyReg2[0] = keyReg1[0];
	keyReg1[0] = keyReg0[0];
	keyReg0[0] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);

	if( ( keyReg1[0] == keyReg0[0] ) && ( keyReg1[0] == keyReg2[0] ) ) {
		if( keyReg2[0] != keyReg3[0] ) {
			keyReg3[0] = keyReg2[0];
			if( keyReg3[0] == PRESSED_STATE ) {
				pressed_flag0 = 1;
			}
		}
	}
}

void getKeyInput2() {
	keyReg2[1] = keyReg1[1];
	keyReg1[1] = keyReg0[1];
	keyReg0[1] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);

	if( ( keyReg1[1] == keyReg0[1] ) && ( keyReg1[1] == keyReg2[1] ) ) {
		if( keyReg2[1] != keyReg3[1] ) {
			keyReg3[1] = keyReg2[1];
			if( keyReg3[1] == PRESSED_STATE ) {
				pressed_flag1 = 1;
			}
		}
	}
}

void getKeyInput3() {
	keyReg2[2] = keyReg1[2];
	keyReg1[2] = keyReg0[2];
	keyReg0[2] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);

	if( ( keyReg1[2] == keyReg0[2] ) && ( keyReg1[2] == keyReg2[2] ) ) {
		if( keyReg2[2] != keyReg3[2] ) {
			keyReg3[2] = keyReg2[2];
			if( keyReg3[2] == PRESSED_STATE ) {
				pressed_flag2 = 1;
			}
		}
	}
}
