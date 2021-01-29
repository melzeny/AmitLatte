/*
 * Lcd.h
 *
 *  Created on: Jan 29, 2021
 *      Author: future
 */

#ifndef AMITLATTE_HAL_INCLUDE_LCD_H_
#define AMITLATTE_HAL_INCLUDE_LCD_H_

void Lcd_Init(void);
void Lcd_WriteChar(uint8 CharToDisplay);
void Lcd_WriteCommand(uint8 CommandNum);

#endif /* AMITLATTE_HAL_INCLUDE_LCD_H_ */
