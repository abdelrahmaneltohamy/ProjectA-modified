/*
 * ULTRASONIC_prg.c
 *
 *  Created on: Feb 2, 2020
 *      Author: Hatem
 */


#include "ultrasonic.h"
#include "timer.h"

extern volatile uint16_t g_tick;
extern volatile uint8_t pulse_flag;
volatile uint16_t Distance = 0;

void Ultrasonic_init(void)
{
	SET_BIT(SensorPort, TRIGGERFRONT);
	//SET_BIT(SensorPort, TRIGGERRIGHT);
	//CLEAR_BIT(SensorPort, ECHORIGHT);
}

void Ultrasonic_start(void)
{
	SET_BIT(PORTA, TRIGGERFRONT);
	pulse_flag = 0;
	timer0_init();
}

void Ultrasonic_en_interrupt(void)
{
	CLEAR_BIT(SREG, PIN7);
	CLEAR_BIT(InterruptPort, ECHOFRONT);
	SET_BIT(GICR, PIN5);
	CLEAR_BIT(MCUCSR, PIN6);
	SET_BIT(SREG, PIN7);
}

ISR(INT2_vect)
{
	Distance = ((g_tick * 16) - 200) /100 ;
	g_tick = 0;
	pulse_flag = 0;
}

