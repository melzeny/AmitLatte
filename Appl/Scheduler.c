/*
 * Scheduler.c
 *
 *  Created on: Feb 5, 2021
 *      Author: Muhammad.Elzeiny
 */
#include "Std_Types.h"
typedef void (*Ptr2FuncType)(void);

typedef struct
{
	uint8 TaskId;
	Ptr2FuncType TaskPtr;
	uint32 Periodicity;
}Scheduler_TaskType;



void Task_01(void)
{

}
void Task_02(void)
{

}

void Task_03(void)
{

}



/***************CONFIGURATION***************/
Scheduler_TaskType Tasks[3] =
{
		{0,Task_01,500 },
		{1,Task_02,700 },
		{2,Task_03,900 },
};
/******************STATIC_CODE***************/
/*Periodic Task 1ms*/
void Scheduler_Process(void)
{
	static uint32 counter = 0;
	if((counter%500) == 0)
	{
		Task_01();
	}
	if((counter%700) == 0)
	{

		Task_02();

	}
	if((counter%900) == 0)
	{
        Task_03();

	}
	counter++;
}
