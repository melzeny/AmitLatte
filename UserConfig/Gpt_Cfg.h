/*
 * Gpt_Cfg.h
 *
 *  Created on: Jan 30, 2021
 *      Author: future
 */

#ifndef AMITLATTE_USERCONFIG_GPT_CFG_H_
#define AMITLATTE_USERCONFIG_GPT_CFG_H_
/*
 * PLEASE choose from the followings
 *
 * GPT_PRESCALER_1       0x01
 * GPT_PRESCALER_8       0x02
 * GPT_PRESCALER_64      0x03
 * GPT_PRESCALER_256     0x04
 * GPT_PRESCALER_1024    0x05
 *
 * */
#define GPT_PRESCALER_SELECTOR     0x05
/*
 * PLEASE choose from the followings
 * GPT_TIMER_MODE_ONESHOT          0x00
 * GPT_TIMER_MODE_CONTINOUSE       0x01
 * */
#define GPT_TIMER_MODE_SELECTOR    0x01

#define GPT_INTERRUPT_EN          ENABLE

#define GPT_CALLBACK_PTR          user_TimerIsrCallBack


#endif /* AMITLATTE_USERCONFIG_GPT_CFG_H_ */
