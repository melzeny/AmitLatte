/*
 * Scheduler_Lcfg.c
 *
 *  Created on: Feb 5, 2021
 *      Author: Muhammad.Elzeiny
 */
#include "Scheduler.h"

/*
 *
 * Please declare the functions here
*/
void Task_01(void);
void Task_02(void);
void Task_03(void);

/***************CONFIGURATION***************/
#define SCHEDULER_NUM_OF_TASKS      3

Scheduler_TaskType Tasks[SCHEDULER_NUM_OF_TASKS] =
{
		{0,Task_01,500,TaskStatus_Active },
		{1,Task_02,700,TaskStatus_Active },
		{2,Task_03,900,TaskStatus_Active }
};
/**************************/
const uint8 Scheduler_NumOfTasks = SCHEDULER_NUM_OF_TASKS;

