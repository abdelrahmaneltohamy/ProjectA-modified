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

int main()
{
	Ultrasonic_init();
	Ultrasonic_en_interrupt();
	Motor_init();
	SET_BIT(DDRB, PIN4);
	SET_BIT(PORTB, PIN4);
	enum s {move_forward_state, stop_decide_direction_state, turn_state};
	enum s state;
	state = move_forward_state;
	while(1)
	{
		if(g_tick_front == 0)
		{
			Ultrasonic_front_start();
			g_tick_front = 1;
			SET_BIT(PORTB, PIN4);
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
			Distance_right = ((g_tick_right * 16) - 200) /100 ;
			g_tick_right = 0;
			CLEAR_BIT(PORTB, PIN4);
		}
		if( Distance_front != 0 && Distance_right != 0)
		{

			switch(state)
			{
			case move_forward_state:
				Motor_move_forward();
				if(Distance_front < 30)
				{
					state = stop_decide_direction_state;
				}
				break;
			case stop_decide_direction_state:
				Motor_stop();
				state = turn_state;
				if(Distance_right > 50)
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
				}
				break;
			default: break;
			}

		}
	}
}


//
//			if(Distance_front != 0)
//			{
//				if(Distance_front < 15)
//				{
//					Motor_stop();
	//				CLEAR_BIT(PORTB, PIN4);
	//				if(Distance_right > 100)
	//				{
	//					if(Distance_front < 100)
	//					{
	//						Motor_turn_right();
	//					}
	//				}
	//				else
	//				{
	//					if(Distance_front < 100)
	//					{
	//						Motor_turn_left();
	//					}
	//				}
	//				Motor_move_forward();

