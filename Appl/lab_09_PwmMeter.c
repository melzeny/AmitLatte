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

void User_PwmMeterWithExti_CallBack(void)
{


}
void lab_09_PwmMeter_WithExti(void)
{



	while(1)
	{




	}

}
void lab_09_PwmMeter_WithDio(void)
{
	static Dio_ChannelLevelType PreviousLevel,CurrentLevel;
	static uint8 T,Ton,t1,t2,t3,Flag=0;

	Dio_Init();
	Gpt_Init();
	Gpt2_Init();
	ENABLE_GLOBAL_INTTERUPT();
	Gpt_StartTimer(250);
	Gpt2_GeneratePwm(/*DutyCycle*/20);
	while(1)
	{
		CurrentLevel = Dio_ReadChannel(Dio_Channel_D6);
		if(CurrentLevel != PreviousLevel)
		{
			if((CurrentLevel == Dio_ChannelLevel_High ) && Flag==0)
			{
				/*Rising Edge occurred*/
				t1 = Gpt_GetElapsedCount();
				Flag =1;
			}
			else if ((CurrentLevel == Dio_ChannelLevel_Low ) && Flag==1)
			{
				/*Falling Edge occured*/

				t2 = Gpt_GetElapsedCount();
				Flag =2;
			}
			else if((CurrentLevel == Dio_ChannelLevel_High ) && Flag==2)
			{
				t3 = Gpt_GetElapsedCount();
				if((t3>t1) && (t2>t1))
				{
					T = t3-t1;
					Ton = t2-t1;
					Flag = 0;
				}
				else
				{
					/*The timer has overflowed */
				}

			}

		}

		PreviousLevel = CurrentLevel;

	}

}
