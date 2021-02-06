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
	static uint8 CounterFlag = 0;
	if(CounterFlag == 0)
	{
		Dio_WriteChannel(Dio_Channel_D0,STD_HIGH);
		CounterFlag++;
	}
	else if(CounterFlag == 1)
	{
		Dio_WriteChannel(Dio_Channel_D0,STD_LOW);
		CounterFlag++;
	}
	else if(CounterFlag == 3)
	{
		CounterFlag =0;
	}
	else
	{
		CounterFlag++;
	}


}

void lab_08_Pwm(void)
{
	Dio_Init();
	Gpt_Init();
	ENABLE_GLOBAL_INTTERUPT();
	Gpt_GeneratePwm(20); /* 20% duty cycle*/

	while(1)
	{



	}

}
