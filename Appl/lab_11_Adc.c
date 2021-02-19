/*
 * lab_11_Adc.c
 *
 *  Created on: Feb 19, 2021
 *      Author: Muhammad.Elzeiny
 */

#include "Dio.h"
#include "Lcd.h"
#include "Adc.h"


void lab_11_Adc(void)
{
	uint16 Result = 0;
	Dio_Init();
	Lcd_Init();
    Adc_Init();

  while(1)
  {
    Adc_GetConversionResult(&Result);


  }

}
