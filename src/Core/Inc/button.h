/*
 * button.h
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */
#include "main.h"
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define PRESSED 0
#define NORMAL 1
#define BTN1 GPIO_PIN_2
#define BTN2 GPIO_PIN_3
#define BTN3 GPIO_PIN_4

void getInput1();
void getInput2();
void getInput3();

int isBtn1Pressed();
int isBtn2Pressed();
int isBtn3Pressed();
#endif /* INC_BUTTON_H_ */
