///*
// * main.c
// *
// *  Created on: Feb 2, 2020
// *      Author: Hatem
// */
//
//#include "ultrasonic.h"
//#include "motor.h"
//#include "timer.h"
//#include "pwm.h"
//
//extern volatile uint8_t g_tick;
//extern volatile uint16_t Distance;
//
//int main()
//{
//	Ultrasonic_init();
//	uint8_t state = 0;
//	Ultrasonic_en_interrupt();
//	Motor_init();
//	Motor_move_forward();
//	timer1_pwm_init(110, 100);
//	while(1)
//	{
//		if(g_tick == 0)
//		{
//			Ultrasonic_start();
//			g_tick = 1;
//		}
//		if(Distance < 100 && state == 0)
//		{
//			state = 1;
//		}
//		else if(Distance > 150 && state == 1)
//		{
//			timer1_pwm_init(180, 170);
//			state = 2;
//		}
//		else if(Distance < 100 && state == 2)
//		{
//			state = 3;
//		}
//		else if(Distance > 150 && state == 3)
//		{
//			timer1_pwm_init(255, 245);
//			state = 4;
//		}
//		else if(Distance < 20 && state == 4)
//		{
//			Motor_stop();
//		}
//	}
//}
//

/*
 * main.c
 *
 *  Created on: Feb 2, 2020
 *      Author: Hatem
 */

#include "ultrasonic.h"
#include "motor.h"
#include "timer.h"
#include "pwm.h"

extern volatile uint8_t g_tick;
extern volatile uint16_t Distance;

int main()
{
	Ultrasonic_init();
	uint8_t state = 0;
	Ultrasonic_en_interrupt();
	SET_BIT(DDRB, PIN4);
	SET_BIT(DDRB, PIN5);
	Motor_init();
	Motor_move_forward();
	timer1_pwm_init(150, 150);
	while(1)
	{
		if(g_tick == 0)
		{
			Ultrasonic_start();
			g_tick = 1;
		}
		if (Distance !=0)
		{
			if(Distance < 100 && state == 0) // remove 80
			{
				state = 1;
			}
			else if(Distance > 160 && state == 1)
			{
				timer1_pwm_init(190, 190);
				state = 2;
			}
			else if(Distance < 100 && state == 2)
			{
				state = 3;
			}
			else if(Distance > 160 && state == 3)
			{
				timer1_pwm_init(255, 255);
				state = 4;
			}
			else if(Distance < 15 && state == 4)
			{
				Motor_stop();
			}
		}

	}
}


