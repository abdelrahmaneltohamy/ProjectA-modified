/*
 * DIO_reg.h
 *
 *  Created on: Jan 27, 2020
 *      Author: Hatem
 */

#ifndef __DIO_REG_H__
#define __DIO_REG_H__



// PORT PINS
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//TIMER0 PINS
#define CS00 0
#define CS01 1
#define FOC0 7
#define TOIE0 0

//TIMER1 PINS
#define WGM10  0
#define WGM12  3
#define COM1A1 7
#define COM1B1 5
#define CS11   1

//TIMER2 PINS
#define CS20   0
#define CS21   1
#define CS22   2
#define FOC2   7
#define TOIE2  6

//PORT A
#define PORTA *((volatile uint8_t *)0x3B)
#define DDRA  *((volatile uint8_t *)0x3A)
#define PINA  *((volatile uint8_t *)0x39)

//PORT B
#define PORTB *((volatile uint8_t *)0x38)
#define DDRB  *((volatile uint8_t *)0x37)
#define PINB  *((volatile uint8_t *)0x36)

//PORT C
#define PORTC *((volatile uint8_t *)0x35)
#define DDRC  *((volatile uint8_t *)0x34)
#define PINC  *((volatile uint8_t *)0x33)

//PORT D
#define PORTD *((volatile uint8_t *)0x32)
#define DDRD  *((volatile uint8_t *)0x31)
#define PIND  *((volatile uint8_t *)0x30)

//TIMER
#define TCCR2 *((volatile uint8_t *)0x45)
#define TCNT2 *((volatile uint8_t *)0x44)
#define OCR2  *((volatile uint8_t *)0x43)
#define TIMSK (*(volatile uint8_t *)(0x59))
#define TCCR0 (*(volatile uint8_t *)(0x53))
#define TCNT0 (*(volatile uint8_t *)(0x52))
#define OCR0  *((volatile uint8_t *)0x5C)
#define TCNT1L  *((volatile uint8_t *)0x4C)
#define TCNT1H  *((volatile uint8_t *)0x4D)
#define OCR1AL  *((volatile uint8_t *)0x4A)
#define OCR1AH  *((volatile uint8_t *)0x4B)
#define OCR1BL  *((volatile uint8_t *)0x48)
#define OCR1BH  *((volatile uint8_t *)0x49)
#define TCCR1A  *((volatile uint8_t *)0x4F)
#define TCCR1B  *((volatile uint8_t *)0x4E)


//INTERRUPTS
#define SREG      *((volatile uint8_t *)0x5F)
#define GICR      *((volatile uint8_t *)0x5B)
#define MCUCSR    *((volatile uint8_t *)0x54)
#endif /* __DIO_REG_H__ */
