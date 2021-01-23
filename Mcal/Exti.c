/*
 * Exti.c
 *
 *  Created on: Jan 23, 2021
 *      Author: future
 */

#include "Std_Types.h"
#include "Bit_Man.h"
#include "Std_Types.h"
#include "Exti_Cfg.h"
#include "Exti.h"

void Exti_Init(void)
{

	/*init Exti according to CFG */
	/* Init EXTI 0 */
#if (EXTI_0_ENABLE==ENABLE)
	/*Configure sense mode */
	MCUCR = MCUCR & (0b11111100); /*Clear before Write */
    MCUCR = MCUCR | EXTI_0_SENSE_MODE_SELECTOR;

	/*enable Exti 0*/
    SET_BIT(GICR, 6);

#endif
}

/* ISR for EXTI 0*/
void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	EXTI_0_CALLBACK_PTR();


}
/* ISR for EXTI 1*/
void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{



}
/* ISR for EXTI 2*/
void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{



}




