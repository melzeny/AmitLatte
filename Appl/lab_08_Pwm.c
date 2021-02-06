/*
 * lab_08_Pwm.c
 *
 *  Created on: Feb 6, 2021
 *      Author: Muhammad.Elzeiny
 */


#include"Std_Types.h"
#include "Dio.h"
#include "Gpt.h"
#include "Cpu_GlobalInt.h"
#include "Scheduler.h"

void Task_Pwm(void)/*~ 5 ms*/
{

    Dio_FlipChannel(Dio_Channel_D0);


}

void lab_08_Pwm(void)
{
	Dio_Init();
	Gpt_Init();
	ENABLE_GLOBAL_INTTERUPT();
	Gpt_StartTimer(250); /* 250 steps prescaler=64 FReqSys=16MHz ~= 1ms*/

	while(1)
	{



	}

}
