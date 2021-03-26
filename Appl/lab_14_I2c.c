/*
 * lab_14_I2c.c
 *
 *  Created on: Mar 26, 2021
 *      Author: Muhammad.Elzeiny
 */
#include "Cpu_GlobalInt.h"
#include "Dio.h"
#include "I2c.h"
#include <util/delay.h>
void lab_14_I2c(void)
{
	uint8 MsgArr[8]={1,2,3,4,5,6,7,8};
	Dio_Init();
	ENABLE_GLOBAL_INTTERUPT();
	I2c_Init();
	I2c_Master_WriteData(0,MsgArr,8);

	while(1)
	{

	}


}

