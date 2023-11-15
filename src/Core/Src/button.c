/*
 * button.c
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */


#include "button.h"

int pressed1 = 0;
int pressed2 = 0;
int pressed3 = 0;

int isBtn1Pressed() {
	if (pressed1 == 1) {
		pressed1 = 0;
		return 1;
	}
	return 0;
}

int isBtn2Pressed() {
	if (pressed2 == 1) {
		pressed2 = 0;
		return 1;
	}
	return 0;
}

int isBtn3Pressed() {
	if (pressed3 == 1) {
		pressed3 = 0;
		return 1;
	}
	return 0;
}


int keyReg0[3] = { NORMAL, NORMAL, NORMAL };
int keyReg1[3] = { NORMAL, NORMAL, NORMAL };
int keyReg2[3] = { NORMAL, NORMAL, NORMAL };
int keyReg3[3] = { NORMAL, NORMAL, NORMAL };

void getInput1() {
	keyReg2[0] = keyReg1[0];
	keyReg1[0] = keyReg0[0];
	keyReg0[0] = HAL_GPIO_ReadPin(GPIOB, BTN1);

	if( ( keyReg1[0] == keyReg0[0] ) && ( keyReg1[0] == keyReg2[0] ) ) {
		if( keyReg2[0] != keyReg3[0] ) {
			keyReg3[0] = keyReg2[0];
			if( keyReg3[0] == PRESSED ) {
				pressed1 = 1;
			}
		}
	}
}

void getInput2() {
	keyReg2[1] = keyReg1[1];
	keyReg1[1] = keyReg0[1];
	keyReg0[1] = HAL_GPIO_ReadPin(GPIOB, BTN2);

	if( ( keyReg1[1] == keyReg0[1] ) && ( keyReg1[1] == keyReg2[1] ) ) {
		if( keyReg2[1] != keyReg3[1] ) {
			keyReg3[1] = keyReg2[1];
			if( keyReg3[1] == PRESSED ) {
				pressed2 = 1;
			}
		}
	}
}

void getInput3() {
	keyReg2[2] = keyReg1[2];
	keyReg1[2] = keyReg0[2];
	keyReg0[2] = HAL_GPIO_ReadPin(GPIOB, BTN3);

	if( ( keyReg1[2] == keyReg0[2] ) && ( keyReg1[2] == keyReg2[2] ) ) {
		if( keyReg2[2] != keyReg3[2] ) {
			keyReg3[2] = keyReg2[2];
			if( keyReg3[2] == PRESSED ) {
				pressed3 = 1;
			}
		}
	}
}


























