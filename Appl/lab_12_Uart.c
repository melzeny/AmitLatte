/*
 * lab_12_Uart.c
 *
 *  Created on: Feb 20, 2021
 *      Author: Muhammad.Elzeiny
 */

#include "Std_Types.h"

/*Tx Periodic Task ~50ms*/
void UartTx_Task(void)
{
	static Std_RetType RetVal = E_OK;
	uint8 DataToTransmit[]= "Message From Node 0";
	if(RetVal == E_OK)
	{
		RetVal = Uart_StartTansmit(DataToTransmit, sizeof(DataToTransmit) );
	}
}

/*Tx Periodic Task ~60ms*/
void UartRx_Task(void)
{
	static Std_RetType RetVal = E_OK;
	uint8 ReceivedData[16]= {0};
	uint32 Size = 0;
	if(RetVal == E_OK)
	{
		RetVal =Uart_GetReceivedData(ReceivedData,&Size);
		Lcd_WriteCommand(0x01);
		Lcd_WriteString(ReceivedData,0,0);
	}

}

void lab_12_uart(void)
{
	Dio_Init();
	Uart_Init();
	while(1)
	{

	}
}

