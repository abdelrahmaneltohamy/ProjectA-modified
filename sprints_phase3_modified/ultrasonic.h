/*
 * ULTRASONIC_int.h
 *
 *  Created on: Feb 2, 2020
 *      Author: Hatem
 */

#ifndef __ULTRASONIC_INT_H__
#define __ULTRASONIC_INT_H__

#include "std_types.h"
#include "bit_math.h"
#include "reg.h"
#include "interrupt.h"

#define SensorPort DDRA
#define InterruptPort DDRB
#define ECHOFRONT PIN2
#define TRIGGERFRONT PIN0
#define ECHORIGHT PIN1
#define TRIGGERRIGHT PIN2

extern void Ultrasonic_init(void);
extern void Ultrasonic_en_interrupt(void);
extern void Ultrasonic_front_start(void);
extern void Ultrasonic_right_start(void);

#endif /* ULTRASONIC_INT_H_ */
