/*
 * lab_05_Lcd.c
 *
 *  Created on: Jan 29, 2021
 *      Author: future
 */

#include "Dio.h"
#include "Lcd.h"

void lab_05_lcd(void)
{

	Dio_Init();

	Lcd_Init();
	Lcd_WriteString("Mohamed");

	while(1)
	{




	}





}
