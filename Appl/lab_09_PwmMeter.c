/*
 * lab_09_PwmMeter.c
 *
 *  Created on: Feb 12, 2021
 *      Author: Muhammad.Elzeiny
 */


/*
 * lab_08_Pwm.c
 *
 *  Created on: Feb 6, 2021
 *      Author: Muhammad.Elzeiny
 */

#include "util/delay.h"
#include"Std_Types.h"
#include "Dio.h"
#include "Gpt.h"
#include "Gpt2.h"
#include "Cpu_GlobalInt.h"
#include "Scheduler.h"

void User_PwmMeterCallBack(void)
{



}
void lab_09_PwmMeter(void)
{

	Dio_Init();
	Gpt_Init();
	Gpt2_Init();
	ENABLE_GLOBAL_INTTERUPT();
	Gpt_StartTimer(250);
	Gpt2_GeneratePwm(/*DutyCycle*/20);
	while(1)
	{



	}

}
