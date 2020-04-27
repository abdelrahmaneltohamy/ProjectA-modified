/*
 * ULTRASONIC_prg.c
 *
 *  Created on: Feb 2, 2020
 *      Author: Hatem
 */


#include "ultrasonic.h"

#include "timer0.h"
#include "timer2.h"

extern volatile uint8_t g_tick_front;
extern volatile uint8_t pulse_flag_0;
extern volatile uint8_t pulse_flag_2;
volatile uint16_t Distance_front = 0;
volatile uint16_t Distance_front_arr[3] = {0};
volatile uint8_t Distance_front_sample_count = 0;

void Ultrasonic_init(void)
{
	SET_BIT(SensorPort, TRIGGERFRONT);
	SET_BIT(SensorPort, TRIGGERRIGHT);
	CLEAR_BIT(SensorPort, ECHORIGHT);
}

void Ultrasonic_front_start(void)
{
	SET_BIT(PORTA, TRIGGERFRONT);
	pulse_flag_0 = 0;
	timer0_init();
}

void Ultrasonic_right_start(void)
{
	SET_BIT(PORTA, TRIGGERRIGHT);
	pulse_flag_2 = 0;
	timer2_init();
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
	Distance_front_arr[Distance_front_sample_count] = ((g_tick_front * 16 * 16) - 200) /58;
	++Distance_front_sample_count;

	if (Distance_front_sample_count == 3)
	{
		Distance_front_sample_count = 0;

		Distance_front = (Distance_front_arr[0]+Distance_front_arr[1]+Distance_front_arr[2])/3;
		//Distance_front = Distance_front_arr[0] < Distance_front_arr[1] ? (Distance_front_arr[0] < Distance_front_arr[2] ? Distance_front_arr[0] : Distance_front_arr[2]) : (Distance_front_arr[1] < Distance_front_arr[2] ? Distance_front_arr[1] : Distance_front_arr[2]);
	}

    g_tick_front = 0;
	pulse_flag_0 = 0;

}

