/*
 * traffic_light.h
 *
 *  Created on: Nov 15, 2023
 *      Author: ADMIN
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_
#include "segment_7_led.h"
#include "software_timer.h"

/*VERTICAL LIGHT*/
#define V_RED GPIO_PIN_1
#define V_YELLOW GPIO_PIN_2
#define V_GREEN GPIO_PIN_3
/*HORIZONTAL LIGHT*/
#define H_RED GPIO_PIN_4
#define H_YELLOW GPIO_PIN_5
#define H_GREEN GPIO_PIN_6

extern int RED;
extern int YELLOW;
extern int GREEN;

extern int VERTICAL;
extern int HORIZONTAL;
extern int vertCounter;
extern int horizonCounter;
extern int verticalLightState;
extern int horizontalLightState;



extern int NORMAL_RED_DURATION;
extern int NORMAL_YELLOW_DURATION;
extern int NORMAL_GREEN_DURATION;

void INIT(int duration);
void red(int state);
void yellow(int state);
void green(int state);

void normalRun(int duration);


#endif /* INC_TRAFFIC_LIGHT_H_ */
