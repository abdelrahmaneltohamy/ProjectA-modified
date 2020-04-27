/*
 * BIT_MATH.h
 *
 *  Created on: Jan 27, 2020
 *      Author: Hatem
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg, bit) reg|=(1<<bit)
#define CLEAR_BIT(reg, bit) reg&=(~(1<<bit))
#define TOGGLE_BIT(reg, bit) reg^=(1<<bit)
#define GET_BIT(reg, bit) (reg>>bit)&1

#endif /* BIT_MATH_H_ */
