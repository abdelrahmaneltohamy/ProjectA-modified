/*
 * PWM.h
 *
 *  Created on: 02 feb, 2020
 *      Author: Hazem
 */


#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"
#include "bit_math.h"
#include "interrupt.h"
#include "reg.h"

void timer1_pwm_init(uint8_t set_duty_cycle1, uint8_t set_duty_cycle2);

#endif
