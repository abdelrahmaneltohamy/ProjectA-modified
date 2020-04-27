/*
 * wifi_driver.h
 *
 *  Created on: Feb 5, 2020
 *      Author: eldra
 */

#ifndef WIFI_DRIVER_H_
#define WIFI_DRIVER_H_
#include "uart_driver.h"
#include "bit_math.h"
#include "reg.h"
#include "interrupt.h"
void wifisetup();
void get_the_command(uint8_t received_char);
void delay();


#endif /* WIFI_DRIVER_H_ */
