/*
 * segment_7_led.h
 *
 *  Created on: Nov 14, 2023
 *      Author: ADMIN
 */

#ifndef INC_SEGMENT_7_LED_H_
#define INC_SEGMENT_7_LED_H_
#include "main.h"

/*SEGMENT LED*/
#define A GPIO_PIN_9
#define B GPIO_PIN_10
#define C GPIO_PIN_11
#define D GPIO_PIN_12
#define E GPIO_PIN_13
#define F GPIO_PIN_14
#define G GPIO_PIN_15
/*ENABLE PIN*/
#define EN1 GPIO_PIN_7 /*GPIOA*/
#define EN2 GPIO_PIN_8 /*GPIOA*/
#define EN3 GPIO_PIN_0 /*GPIOB*/
#define EN4 GPIO_PIN_1 /*GPIOB*/

void display7SegPortA(int number); /*0 - 9*/
void display7SegPortB(int number);
void displayA(int number);
void displayB(int number);

#endif /* INC_SEGMENT_7_LED_H_ */
