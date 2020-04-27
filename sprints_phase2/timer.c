/*
 * TIMER.c
 *
 *  Created on: 02 feb, 2020
 *      Author: Hazem
 */

#include"timer.h"

volatile uint8_t pulse_flag = 0;
volatile uint32_t g_tick = 0;

ISR(TIMER0_OVF_vect)
{
	if(pulse_flag == 0)
	{
		CLEAR_BIT(PORTA, PIN0);
		pulse_flag = 1;
	}
	else
	{
		g_tick++;
	}
}

/* Description : 
 * For clock = 16 MHz and it will overflow every 16 us
 * initial timer counter = 0
 */

void timer0_init(void)
{
	TCNT0 = 0; //timer initial value (2 ticks in 1 us)
	SET_BIT(TIMSK, TOIE0); //enable overflow interrupt
	SET_BIT(TCCR0, FOC0);
	SET_BIT(TCCR0, CS00);
}

