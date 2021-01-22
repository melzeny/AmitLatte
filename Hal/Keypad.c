/*
 * Keypad.c
 *
 *  Created on: Jan 22, 2021
 *      Author: future
 */
#include "Bit_Man.h"
#include "Dio.h"
#include "Keypad_Cfg.h"
#include "Keypad.h"


void Keypad_Init(void)
{
	/*attach internal pullup resistors on Col pins */
    Dio_WriteChannel(Dio_Channel_A0,Dio_ChannelLevel_High);
    Dio_WriteChannel(Dio_Channel_A1,Dio_ChannelLevel_High);
    Dio_WriteChannel(Dio_Channel_A2,Dio_ChannelLevel_High);
    Dio_WriteChannel(Dio_Channel_A3,Dio_ChannelLevel_High);


}
uint8 Keypad_GetPressedButton(void)
{
	/*Active Row_0  and de-active Row_1, Row_2, Row_3 (WRITE CHANNELs)*/


	/*Check for all Col (READ Channels )*/

	/*save the number if the Col is activated */




}
