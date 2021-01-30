/*
 * lab_06_Counter.c
 *
 *  Created on: Jan 30, 2021
 *      Author: future
 */
#include "Std_Types.h"
#include"Dio.h"
#include "Gpt.h"

/*Periodic Task 10ms*/
void user_TimerIsrCallBack(void)
{
	static uint32 counter = 0;
	if(counter==40)
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
	Gpt_StartTimer(16); /* 16 steps ~= 10ms*/
	while(1)
	{



	}
}
