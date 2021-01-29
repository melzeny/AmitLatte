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
	_delay_ms(15);
	Lcd_WriteCommand(0x23);
	Lcd_WriteCommand(0x22);
	Lcd_WriteCommand(0x28);
	Lcd_WriteCommand(0x0E);
	Lcd_WriteCommand(0x01);

}
void Lcd_WriteChar(uint8 CharToDisplay)
{
	/*TODO : Set RS PIN to start writing data */
	Dio_WriteChannel(LCD_RS,STD_HIGH);

	/* TODO: Clear RW PIN */
	Dio_WriteChannel(LCD_RW,STD_LOW);

	/*TODO: Write Most 4-bits of the character*/
	Dio_WriteChannel(LCD_D4, GET_BIT(CharToDisplay,4));
	Dio_WriteChannel(LCD_D5, GET_BIT(CharToDisplay,5));
	Dio_WriteChannel(LCD_D6, GET_BIT(CharToDisplay,6));
	Dio_WriteChannel(LCD_D7, GET_BIT(CharToDisplay,7));

	/*TODO Write Enable Pulse */
	Dio_WriteChannel(LCD_E,STD_HIGH);
	_delay_ms(3);
	Dio_WriteChannel(LCD_E,STD_LOW);

	/*TODO: Write Least 4-bits of the character*/
	Dio_WriteChannel(LCD_D4, GET_BIT(CharToDisplay,0));
	Dio_WriteChannel(LCD_D5, GET_BIT(CharToDisplay,1));
	Dio_WriteChannel(LCD_D6, GET_BIT(CharToDisplay,2));
	Dio_WriteChannel(LCD_D7, GET_BIT(CharToDisplay,3));
	/*TODO Write Enable Pulse */
	Dio_WriteChannel(LCD_E,STD_HIGH);
	_delay_ms(3);
	Dio_WriteChannel(LCD_E,STD_LOW);


}
void Lcd_WriteString(uint8* Ptr2String,uint8 Row,uint8 Coloum)
{
	uint8 var;
	var=0x80|((Row*0x40)+Coloum);
	uint8 i=0;
	Lcd_WriteCommand(var);

	while (Ptr2String[i]!='\0')
	{

		Lcd_WriteChar(Ptr2String[i]);
		i++;
	}
}
void Lcd_WriteCommand(uint8 CommandNum)
{
	/*TODO : Clear RS PIN to start writing data */
	Dio_WriteChannel(LCD_RS,STD_LOW);
	/* TODO: Clear RW PIN */
	Dio_WriteChannel(LCD_RW,STD_LOW);
	/*TODO: Write Most 4-bits of the character*/
	Dio_WriteChannel(LCD_D4, GET_BIT(CommandNum,4));
	Dio_WriteChannel(LCD_D5, GET_BIT(CommandNum,5));
	Dio_WriteChannel(LCD_D6, GET_BIT(CommandNum,6));
	Dio_WriteChannel(LCD_D7, GET_BIT(CommandNum,7));

	/*TODO Write Enable Pulse */
	Dio_WriteChannel(LCD_E,STD_HIGH);
	_delay_ms(3);
	Dio_WriteChannel(LCD_E,STD_LOW);


	/*TODO: Write Least 4-bits of the character*/
	Dio_WriteChannel(LCD_D4, GET_BIT(CommandNum,0));
	Dio_WriteChannel(LCD_D5, GET_BIT(CommandNum,1));
	Dio_WriteChannel(LCD_D6, GET_BIT(CommandNum,2));
	Dio_WriteChannel(LCD_D7, GET_BIT(CommandNum,3));
	/*TODO Write Enable Pulse */
	Dio_WriteChannel(LCD_E,STD_HIGH);
	_delay_ms(3);
	Dio_WriteChannel(LCD_E,STD_LOW);




}

