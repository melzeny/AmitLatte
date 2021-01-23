/*
 * lab_03_Keypad.c
 *
 *  Created on: Jan 22, 2021
 *      Author: future
 */
#include "Std_Types.h"
#include "Dio.h"
#include "BcdSevSeg.h"
#include "Keypad.h"

void lap_03_keypad(void)
{
	uint8 NumFromKp =0 ;


	Dio_Init();

	BcdSevSeg_Enable(BcdSevSeg_1);

	while(1)
	{
		/*read the pressed button from the keypad*/
		NumFromKp = Keypad_GetPressedButton();
		if(NumFromKp  != 255)
			/*display the number on SevSegments*/
		{
			BcdSevSeg_DisplayNum(NumFromKp);
		}
		else
		{
			BcdSevSeg_DisplayNum(8);
		}
	}
}


