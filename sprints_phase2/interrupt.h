/*
 * interrupt.h
 *
 *  Created on: Feb 2, 2020
 *      Author: eldra
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_


#define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)

#define INT2_vect               __vector_3
#define TIMER0_OVF_vect			__vector_11


#endif /* INTERRUPT_H_ */
