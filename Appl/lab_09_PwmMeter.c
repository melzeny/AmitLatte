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

#include <stdlib.h>
#include "util/delay.h"
#include"Std_Types.h"
#include "Dio.h"
#include "Gpt2.h"
#include "Cpu_GlobalInt.h"
#include "Exti.h"
#include "Gpt1.h"


static uint32 T_us,Ton_us;

void User_PwmMeterWithExti_CallBack(void)
{
	static uint8 Flag = 0,t0,t1,t2,T_Steps,Ton_Steps;

	if(Flag == 0)
	{
		t0 = Gpt_GetElapsedCount();
		Flag =1;
	}
	else if(Flag == 1)
	{

		t1 = Gpt_GetElapsedCount();
		Flag =2;

	}
	else if (Flag == 2)
	{

		t2 = Gpt_GetElapsedCount();
		T_Steps = t2-t0;
		Ton_Steps = t1-t0;
		T_us = T_Steps*4;
		Ton_us = Ton_Steps*4;
		Flag = 0;
	}
}
void lab_09_PwmMeter_WithExti(void)
{
	uint8 StringBuffer[8];
	Dio_Init();
	//	Lcd_Init();
	Gpt1_Init();
	Gpt2_Init();
	Gpt2_GeneratePwm(30);
	Gpt1_StartTimer(65535);

	while(1)
	{
#if 0
		/*TODO : Clear LCD to Write new Reading */

		itoa(Ton_us,StringBuffer,10); /* Convert integer 'Ton_us' to String 'StringBuffer' */
		Lcd_WriteString("Ton = ",0,0);
		Lcd_WriteString(StringBuffer,0,8);


		itoa(T_us,StringBuffer,10);
		Lcd_WriteString("T = ",1,0);
		Lcd_WriteString(StringBuffer,1,8);

#endif
	}
}
void lab_09_PwmMeter_WithDio(void)
{
	static Dio_ChannelLevelType PreviousLevel,CurrentLevel;
	static uint8 T,Ton,t1,t2,t3,Flag=0;

	Dio_Init();
	Gpt1_Init();
	Gpt2_Init();
	ENABLE_GLOBAL_INTTERUPT();
	Gpt1_StartTimer(250);
	Gpt2_GeneratePwm(/*DutyCycle*/20);
	while(1)
	{
		CurrentLevel = Dio_ReadChannel(Dio_Channel_D6);
		if(CurrentLevel != PreviousLevel)
		{
			if((CurrentLevel == Dio_ChannelLevel_High ) && Flag==0)
			{
				/*Rising Edge occurred*/
				t1 = Gpt1_GetElapsedCount();
				Flag =1;
			}
			else if ((CurrentLevel == Dio_ChannelLevel_Low ) && Flag==1)
			{
				/*Falling Edge occured*/

				t2 = Gpt1_GetElapsedCount();
				Flag =2;
			}
			else if((CurrentLevel == Dio_ChannelLevel_High ) && Flag==2)
			{
				t3 = Gpt1_GetElapsedCount();
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
