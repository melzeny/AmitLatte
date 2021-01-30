/*
 * Gpt.c
 *
 *  Created on: Jan 30, 2021
 *      Author: future
 */

#include "Std_Types.h"
#include "Bit_Man.h"
#include "Mcu_Hw.h"
#include "Gpt_Cfg.h"
#include "Gpt.h"


void Gpt_Init(void)
{
   /*TODO: Set Timer_mode to CTC */


	/*TODO: Enable Timer Interrupt based on configuration */


}
void Gpt_StartTimer(uint8 TargetSteps)
{
	/*TODO: Write the TargetSteps into OCR0 register */

	/*TODO: Set Prescaler */

}

void Gpt_StopTimer(void)
{
   /*TODO : Clear Prescaler field i.e. Disable Timer clock */

}
uint8 Gpt_GetElapsedCount(void)
{
   /*return TCNT0 value */


}
/*TIMER0_COMP interrupt*/
void __vector_10(void) __attribute__((signal,used));
void __vector_10(void)
{
	/*Check on Timer mode: if mode== one-shot then disable Timer0 */

	/*call the callback function*/

}

