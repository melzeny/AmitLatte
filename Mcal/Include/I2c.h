/*
 * I2c.h
 *
 *  Created on: Mar 26, 2021
 *      Author: Muhammad.Elzeiny
 */

#ifndef AMITLATTE_MCAL_INCLUDE_I2C_H_
#define AMITLATTE_MCAL_INCLUDE_I2C_H_

void I2c_Init(void);
Std_RetType I2c_Master_ReadData(uint8 SlaveAddr, uint8* Ptr2Buffer, uint16 MsgSize);
Std_RetType I2c_Master_WriteData(uint8 SlaveAddr, uint8* Ptr2Msg, uint16 MsgSize);

#endif /* AMITLATTE_MCAL_INCLUDE_I2C_H_ */
