/*
 * Mcu_Hw.h
 *
 *  Created on: Jan 15, 2021
 *      Author: power system
 */

#ifndef MCU_HW_H_
#define MCU_HW_H_

/*DIO Register */
#define  DDRA     (*((volatile uint8*)0x3A))
#define  DDRC     (*((volatile uint8*)0x34))
#define  DDRD     (*((volatile uint8*)0x31))
#define  DDRB     (*((volatile uint8*)0x37))

#define  PORTA    (*((volatile uint8*)0x3B))
#define  PORTB    (*((volatile uint8*)0x38))
#define  PORTC    (*((volatile uint8*)0x35))
#define  PORTD    (*((volatile uint8*)0x32))

#define  PINA     (*((volatile uint8*)0x39))
#define  PINB     (*((volatile uint8*)0x36))
#define  PINC     (*((volatile uint8*)0x33))
#define  PIND     (*((volatile uint8*)0x30))

#define  MCUCR    (*((volatile uint8*)0x55))
#define  MCUCSR   (*((volatile uint8*)0x54))
#define  GICR     (*((volatile uint8*)0x5B))
#define  SREG     (*((volatile uint8*)0x5F))

/* TIMER0 REGISTER */
#define TCCR0      (*((volatile uint8*)0x53))
#define TCNT0      (*((volatile uint8*)0x52))
#define OCR0       (*((volatile uint8*)0x5C))
#define TIMSK      (*((volatile uint8*)0x59))

/* TIMER2 REGISTER */
#define TCCR2      (*((volatile uint8*)0x45))
#define TCNT2      (*((volatile uint8*)0x44))
#define OCR2       (*((volatile uint8*)0x43))

/* Timer1 Registers */
#define TCNT1H     (*((volatile uint8*)0x4D))
#define TCNT1L     (*((volatile uint8*)0x4C))
#define TCNT1      (*((volatile uint16*)0x4C))
#define OCRA       (*((volatile uint16*)0x4A))
#define OCRB       (*((volatile uint16*)0x48))
#define TCCR1A     (*((volatile uint8*)0x4F))
#define TCCR1B     (*((volatile uint8*)0x4E))
#define ICR1       (*((volatile uint16*)0x46))

#endif /* MCU_HW_H_ */
