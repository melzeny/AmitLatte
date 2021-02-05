/*
 * lab_07_Scheduling.c
 *
 *  Created on: Feb 5, 2021
 *      Author: Muhammad.Elzeiny
 */
#include"Std_Types.h"
#include "Dio.h"
#include "Gpt.h"
#include "Cpu_GlobalInt.h"
#include "Scheduler.h"

void Task_01(void)
{

}
void Task_02(void)
{

}

void Task_03(void)
{

}

void lab_07_User(void)
{

	Dio_Init();
	Gpt_Init();
	ENABLE_GLOBAL_INTTERUPT();
	Gpt_StartTimer(250); /* 250 steps prescaler=64 FReqSys=16MHz ~= 1ms*/

    while(1)
    {



    }

}

