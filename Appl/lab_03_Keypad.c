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

	while(1);
	{
        /*read the pressed button from the keypad*/
        NumFromKp = Keypad_GetPressedButton();
		/*display the number on SevSegments*/
		BcdSevSeg_DisplayNum(NumFromKp);
		BcdSevSeg_Enable(BcdSevSeg_0);
		BcdSevSeg_Enable(BcdSevSeg_1);



	}





}


