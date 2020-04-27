/*
 * timer2.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Hatem
 */

#include "timer2.h"

#include "ultrasonic.h"

volatile uint8_t pulse_flag_2 = 0;
volatile uint8_t g_tick_right = 0;
volatile uint8_t right_flag = 0;

ISR(TIMER2_OVF_vect)
{
	if(pulse_flag_2 == 0)
	{
		CLEAR_BIT(PORTA, TRIGGERRIGHT);
		pulse_flag_2 = 1;
	}
	if(right_flag == 0)
		right_flag = 1;
	else
	{
		++g_tick_right;
		right_flag = 0;
	}
}

void timer2_init(void)
{
	TCNT2 = 0; //timer initial value (2 ticks in 1 us)
	SET_BIT(TIMSK, TOIE2); //enable overflow interrupt
	SET_BIT(TCCR2, FOC2);
	SET_BIT(TCCR2, CS21);
}
