/*
 * phase3.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Hatem
 */

#include "ultrasonic.h"
#include "motor.h"
#include "pwm.h"
#include "timer0.h"

uint8_t falling_edge_flag = 0;
uint16_t Distance_right = 0;
extern volatile uint8_t g_tick_front;
extern volatile uint8_t g_tick_right;
extern volatile uint16_t Distance_front;
volatile uint16_t Distance_right_arr[3] = {0};
volatile uint8_t Distance_right_sample_count = 0;

int main()
{
	SET_BIT(DDRB, PIN4);
	SET_BIT(DDRB, PIN5);
	SET_BIT(DDRB, PIN6);
	SET_BIT(DDRB, PIN7);
	Ultrasonic_init();
	Ultrasonic_en_interrupt();
	Motor_init();
	enum s {move_forward_state, stop_decide_direction_state, turn_state};
	enum s state;
	state = move_forward_state;
//	timer1_pwm_init(192, 192);
	Motor_move_forward();
	while(1)
	{
		if(g_tick_front == 0)
		{
			Ultrasonic_front_start();
			g_tick_front = 1;
		}
		if(g_tick_right == 0)
		{
			Ultrasonic_right_start();
			g_tick_right = 1;
		}
		if(GET_BIT(PINA,ECHORIGHT) == 1)
		{
			falling_edge_flag = 1;
		}
		else if((GET_BIT(PINA,ECHORIGHT) == 0) && (falling_edge_flag == 1))
		{
			falling_edge_flag = 0;

			Distance_right_arr[Distance_right_sample_count] = ((g_tick_right * 16 * 16) - 200) /58;
				++Distance_right_sample_count;

			if (Distance_right_sample_count == 3)
			{
				Distance_right_sample_count = 0;

				Distance_right = (Distance_right_arr[0]+Distance_right_arr[1]+Distance_right_arr[2])/3;

				//Distance_right = Distance_right_arr[0] < Distance_right_arr[1] ? (Distance_right_arr[0] < Distance_right_arr[2] ? Distance_right_arr[0] : Distance_right_arr[2]) : (Distance_right_arr[1] < Distance_right_arr[2] ? Distance_right_arr[1] : Distance_right_arr[2]);
			}

			g_tick_right = 0;
		}
		if(Distance_front != 0 && Distance_right != 0)
		{

			if(Distance_front < 15)
			{
				SET_BIT(PORTB, PIN4);
				CLEAR_BIT(PORTB, PIN5);
				CLEAR_BIT(PORTB, PIN6);
				CLEAR_BIT(PORTB, PIN7);
			}
			else if(Distance_front > 15 && Distance_front < 30)
			{
				SET_BIT(PORTB, PIN5);
				CLEAR_BIT(PORTB, PIN4);
				CLEAR_BIT(PORTB, PIN6);
				CLEAR_BIT(PORTB, PIN7);
			}
			else if(Distance_front > 30 && Distance_front < 70)
			{
				SET_BIT(PORTB, PIN6);
				CLEAR_BIT(PORTB, PIN5);
				CLEAR_BIT(PORTB, PIN4);
				CLEAR_BIT(PORTB, PIN7);
			}
			else if(Distance_front > 70)
			{
				SET_BIT(PORTB, PIN7);
				CLEAR_BIT(PORTB, PIN5);
				CLEAR_BIT(PORTB, PIN6);
				CLEAR_BIT(PORTB, PIN4);
			}
			switch(state)
			{
			case move_forward_state:
				Motor_move_forward();
				if(Distance_front < 70)
				{
					state = stop_decide_direction_state;
					Motor_stop();
				}
				break;
			case stop_decide_direction_state:

				state = turn_state;
				if(Distance_right > 100)
				{
					Motor_turn_right();
				}
				else
				{
					Motor_turn_left();
				}
				break;
			case turn_state:
				if(Distance_front > 100)
				{
					state = move_forward_state;
					Motor_move_forward();
				}
				break;
			default: break;
			}
			if(Distance_front < 20)
			{
				Motor_stop();
			}
		}
	}
}
