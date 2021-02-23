/*
 * Uart_Cfg.h
 *
 *  Created on: Feb 20, 2021
 *      Author: Muhammad.Elzeiny
 */

#ifndef AMITLATTE_USERCONFIG_UART_CFG_H_
#define AMITLATTE_USERCONFIG_UART_CFG_H_

#define UART_RX_COMPLETE_INT_EN					ENABLE
#define UART_TX_COMPLETE_INT_EN					DISABLE
#define UART_TXBUFFER_READY_INT_EN	        	DISABLE

#define UART_TX_EN							    ENABLE
#define UART_RX_EN							    ENABLE
/*
* UART_STOP_BITS_SIZE_1
* UART_STOP_BITS_SIZE_2
*/
#define UART_STOP_BITS_SIZE_SELECTOR            UART_STOP_BITS_SIZE_2
/*
* UART_PARITY_MODE_DISABLE
* UART_PARITY_MODE_EVEN
* UART_PARITY_MODE_ODD
*/
#define UART_PARITY_MODE_SELECTOR              UART_PARITY_MODE_EVEN
/*
* UART_DATA_SIZE_5
* UART_DATA_SIZE_6
* UART_DATA_SIZE_7
* UART_DATA_SIZE_8
*/
#define UART_DATA_SIZE_SELECTOR                 UART_DATA_SIZE_8

#define BAUDE_RATE_UBRR                         103
#define UART_MAX_RX_BUFFER_SIZE                 100

#endif /* AMITLATTE_USERCONFIG_UART_CFG_H_ */
