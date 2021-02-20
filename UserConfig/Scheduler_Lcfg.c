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
void Adc_LcdTask(void);

/***************CONFIGURATION***************/
#define SCHEDULER_NUM_OF_TASKS      1

Scheduler_TaskType Tasks[SCHEDULER_NUM_OF_TASKS] =
{
		{0,Adc_LcdTask,200,TaskStatus_Active }
};
/**************************/
const uint8 Scheduler_NumOfTasks = SCHEDULER_NUM_OF_TASKS;

