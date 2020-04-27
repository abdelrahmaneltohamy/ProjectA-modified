/*
 * phase3.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Hatem
 */

#include "motor.h"
#include "wifi_driver.h"

uint8_t falling_edge_flag = 0;
uint16_t Distance_right = 0;

int main()
{
	UART_Init(9600,NULL);
	wifisetup();
	while(1)

	{
		switch (UART_Receive_Byte())
		{
		case 'w' : Motor_move_forward(); break;
		case 's' : Motor_stop(); break;
		case 'a' : Motor_turn_left(); break;
		case 'd' : Motor_turn_right(); break;
		case 'x' : Motor_move_backward();break;
		case 'q' : Motor_slide_left();break;
		case 'e' : Motor_slide_right();break;

		}
	}

}
