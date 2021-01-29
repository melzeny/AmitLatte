/*
 * Lcd.c
 *
 *  Created on: Jan 29, 2021
 *      Author: future
 */
#include "Std_Types.h"
#include "Bit_Man.h"
#include "Dio.h"
#include "Lcd_Cfg.h"
#include "Lcd.h"
#include "util/delay.h"

void Lcd_Init(void)
{


}
void Lcd_WriteChar(uint8 CharToDisplay)
{
	/*TODO : Set RS PIN to start writing data */
     Dio_WriteChannel(Dio_Channel_B1,STD_HIGH);

	/* TODO: Clear RW PIN */
    Dio_WriteChannel(Dio_Channel_B2,STD_LOW);

	/*TODO: Write Most 4-bits of the character*/
    Dio_WriteChannel(Dio_Channel_A4, GET_BIT(CharToDisplay,4));
    Dio_WriteChannel(Dio_Channel_A5, GET_BIT(CharToDisplay,5));
    Dio_WriteChannel(Dio_Channel_A6, GET_BIT(CharToDisplay,6));
    Dio_WriteChannel(Dio_Channel_A7, GET_BIT(CharToDisplay,7));

    /*TODO Write Enable Pulse */
    Dio_WriteChannel(Dio_Channel_B3,STD_HIGH);
    _delay_ms(3);
    Dio_WriteChannel(Dio_Channel_B3,STD_LOW);

	/*TODO: Write Least 4-bits of the character*/

    /*TODO Write Enable Pulse */



}
void Lcd_WriteCommand(uint8 CommandNum)
{
	/*TODO : Clear RS PIN to start writing data */

	/* TODO: Set RW PIN */

	/*TODO: Write Most 4-bits of the character*/

    /*TODO Write Enable Pulse */


	/*TODO: Write Least 4-bits of the character*/

    /*TODO Write Enable Pulse */




}

