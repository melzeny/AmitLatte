/*
 * Spi.c
 *
 *  Created on: Feb 26, 2021
 *      Author: Muhammad.Elzeiny
 */
#include "Std_Types.h"
#include "Bit_Man.h"
#include "Mcu_Hw.h"
#include "Spi_Cfg.h"
#include "Spi.h"



void Spi_Init(void)
{
	/*TODO : Configure Data order Lsb\Msb */

    /*TODO: Configure Mode Master\Slave */

	/*TODO: Configure Clock phase and Clock polarity*/

	/*TODO: Configure Pre-scaler */

    /*TODO Enable INetrrupt if configured */

	/*TODO: Enable SPI */
}
uint8 Spi_StartTransmission(uint8 TxData)
{
	uint8 RxData;

    /*TODO Transmit Data */

	/*TODO: Polling until Msg has been transmitted */

	/*TODO  Receive Data */



	return RxData;
}

/*Serial Transfer Complete Interrupt */
void __vector_12(void) __attribute__((signal,used));
void __vector_12(void)
{


}
