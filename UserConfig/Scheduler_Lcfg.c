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
void Switch_StateUpdateTask(void);

/***************CONFIGURATION***************/
#define SCHEDULER_NUM_OF_TASKS      1

Scheduler_TaskType Tasks[SCHEDULER_NUM_OF_TASKS] =
{
		{0,Switch_StateUpdateTask,5,TaskStatus_Active }
};
/**************************/
const uint8 Scheduler_NumOfTasks = SCHEDULER_NUM_OF_TASKS;

