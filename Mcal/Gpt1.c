/*
 * Gpt1.c
 *
 *  Created on: Feb 13, 2021
 *      Author: Muhammad.Elzeiny
 */

#define GPT1_MODE_NORMAL    0x00
#define GPT1_MODE_CTC_OCR   0x01
#define GPT1_MODE_CTC_ICR   0x02




#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Bit_Man.h"
#include "Gpt1_Cfg.h"
#include "Gpt1.h"

void Gpt1_Init(void)
{
   /*Set Timer1 Mode */
#if GPT1_MODE_SELECTOR==GPT1_MODE_NORMAL
     TCCR1A = TCCR1A &0b11111100;
     TCCR1B = TCCR1B &0b11100111;

#elif GPT1_MODE_SELECTOR==GPT1_MODE_CTC_OCR
     TCCR1A = TCCR1A &0b11111100;
     SET_BIT(TCCR1B,3);
     CLR_BIT(TCCR1B,4);

#elif GPT1_MODE_SELECTOR==GPT1_MODE_CTC_ICR
     TCCR1A = TCCR1A &0b11111100;
     SET_BIT(TCCR1B,3);
     SET_BIT(TCCR1B,4);
#endif
  SET_BIT(TCCR1A,6);
  /*Enable OVF Interupt*/

}
void Gpt1_StartTimer(uint16 TargetSteps)
{
    //OCRA = TargetSteps;
    /*Set Prescaler*/
	TCCR1B = TCCR1B & 0b11111000;
	TCCR1B = TCCR1B | (GPT1_PRESCALER_SELECTOR&0b00000111);
}
void Gpt1_StopTimer(void)
{
    /*Clear prescaler to Stop timer*/
	TCCR1B = TCCR1B & 0b11111000;
}
uint16 Gpt1_GetElapsedCount(void)
{

   return TCNT1;
}
