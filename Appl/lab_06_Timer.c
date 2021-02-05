/*
 * lab_06_Counter.c
 *
 *  Created on: Jan 30, 2021
 *      Author: future
 */
#include "Std_Types.h"
#include"Dio.h"
#include "Gpt.h"
#include "Cpu_GlobalInt.h"
/*Periodic Task 1ms*/
void user_TimerIsrCallBack(void)
{
	static uint32 counter = 0;
	if(counter==500)
	{
		Dio_FlipChannel(Dio_Channel_C7);
		counter =0;
	}
	counter++;
}
void lab_06_timer(void)
{
	Dio_Init();
	Gpt_Init();
	ENABLE_GLOBAL_INTTERUPT();
	Gpt_StartTimer(250); /* 250 steps prescaler=64 FReqSys=16MHz ~= 1ms*/
	while(1)
	{



	}
}
