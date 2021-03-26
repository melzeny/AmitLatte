#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Bit_Man.h"
#include "I2c_Cfg.h"
#include "I2c.h"


#define I2c_STARTTx                    0x08u
#define I2C_REPEATED_STARTTx           0x10u
#define I2C_SLAW_ACK                   0x18u
#define I2C_SLAW_NOT_ACK               0x20u
#define I2C_DATATx_ACKRx               0x28u
#define I2C_DATATx_NOT_ACKRx           0x30u
#define I2C_ARBITRATION_LOST_SLAW      0x38u
#define I2C_SLAR_ACK                   0x40u
#define I2C_SLAR_NOT_ACK               0x48u
#define I2C_DATARx_ACKTx               0x50u
#define I2C_DATARx_NOT_ACKTx           0x58u

typedef enum
{
	I2c_Idle,
	I2c_Busy
}I2c_StatusType;
typedef enum
{
	I2c_MasterOpr_Write,
	I2c_MasterOpr_Read
}I2c_MasterOprType;
typedef struct
{
	I2c_StatusType Status;
	uint8 Sla;
	uint8 * Ptr2Msg;
	uint16 Size;
	I2c_MasterOprType I2c_MasterOpr;
}I2c_ParamType;

static I2c_ParamType I2c_Param;

void I2c_Init(void)
{
	/*Enable ACK Generation */
	SET_BIT(TWCR,6);

	/*TODO : Set baud rate and Prescaler */
    TWBR = 50;

	/*Enable Interrupt */
	SET_BIT(TWCR,0);
	/*Enable I2c */
	SET_BIT(TWCR,2);

}

Std_RetType I2c_Master_WriteData(uint8 SlaveAddr, uint8* Ptr2Msg, uint16 MsgSize)
{
	Std_RetType RetVal = E_OK;
	if(I2c_Param.Status != I2c_Busy)
	{
		I2c_Param.Status = I2c_Busy;

		I2c_Param.Sla = SlaveAddr;
		I2c_Param.Ptr2Msg = Ptr2Msg;
		I2c_Param.Size = MsgSize;
		I2c_Param.I2c_MasterOpr = I2c_MasterOpr_Write;
		/*Start Condition */
		SET_BIT(TWCR,5);
	}
	else
	{
		RetVal = E_NOT_OK;

	}
	return RetVal;
}
Std_RetType I2c_Master_ReadData(uint8 SlaveAddr, uint8* Ptr2Buffer, uint16 MsgSize)
{
	Std_RetType RetVal = E_OK;
	if(I2c_Param.Status != I2c_Busy)
	{
		I2c_Param.Status = I2c_Busy;

		I2c_Param.Sla = SlaveAddr;
		I2c_Param.Ptr2Msg = Ptr2Buffer;
		I2c_Param.Size = MsgSize;
		I2c_Param.I2c_MasterOpr = I2c_MasterOpr_Read;
		/*Start Condition */
		SET_BIT(TWCR,5);
	}
	else
	{
		RetVal = E_NOT_OK;

	}
	return RetVal;


}


void __vector_19(void) __attribute__((signal,used));
void __vector_19(void)
{
	static uint16 MsgIdx = 0;
	uint8 Status = TWSR&0b11111000U;

	switch (Status) {
	case I2c_STARTTx:
		/*Clear the start bit */
		//CLR_BIT(TWCR,5);

		/* Write SLA + Read\Write */
		TWDR = (I2c_Param.Sla<<1) | (I2c_Param.I2c_MasterOpr);
		break;
	case I2C_REPEATED_STARTTx:

		break;
	case I2C_SLAW_ACK:
	case I2C_SLAW_NOT_ACK:
		MsgIdx = 0;
		TWDR = I2c_Param.Ptr2Msg[MsgIdx++];
		I2c_Param.Size--;
		break;


	case I2C_DATATx_ACKRx:
	case I2C_DATATx_NOT_ACKRx:
		if(I2c_Param.Size == 0)
		{
			/* Generate Stop Condition */
			SET_BIT(TWCR,4);
			/*Set I2c to Idle state */
			I2c_Param.Status = I2c_Idle;
		}
		else
		{
			TWDR = I2c_Param.Ptr2Msg[MsgIdx++];
			I2c_Param.Size--;
		}
		break;
	case I2C_ARBITRATION_LOST_SLAW:

		break;
	case I2C_SLAR_ACK:
		MsgIdx = 0;
		I2c_Param.Ptr2Msg[MsgIdx++] = TWDR;
		I2c_Param.Size--;
		break;
	case I2C_SLAR_NOT_ACK:

		break;
	case I2C_DATARx_ACKTx:
	case I2C_DATARx_NOT_ACKTx:
		if(I2c_Param.Size != 0)
		{
			I2c_Param.Ptr2Msg[MsgIdx++] = TWDR;
			I2c_Param.Size--;
		}
		else
		{
			/* Generate Stop Condition */
			SET_BIT(TWCR,4);
			/*Set I2c to Idle state */
			I2c_Param.Status = I2c_Idle;
		}
		break;


	default:
		break;
	}
	/* Clear Flag */
	SET_BIT(TWCR,7);

}



