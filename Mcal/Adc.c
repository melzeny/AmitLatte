/*
 * Adc.c
 *
 *  Created on: Feb 19, 2021
 *      Author: Muhammad.Elzeiny
 */
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Bit_Man.h"
#include "Adc.h"
#include "Adc_Cfg.h"


#define ADC_PRESCALER_2          0x01
#define ADC_PRESCALER_4          0x02
#define ADC_PRESCALER_8          0x03
#define ADC_PRESCALER_16         0x04
#define ADC_PRESCALER_32         0x05
#define ADC_PRESCALER_64         0x06
#define ADC_PRESCALER_128        0x07

#define ADC_VREF_SOURCE_AREF     0x00
#define ADC_VREF_SOURCE_AVCC     0x01
#define ADC_VREF_SOURCE_2_56     0x03

#define ADC_RESOLUTION_8      0x1
#define ADC_RESOLUTION_10     0x0

#define ADC_TRIGGER_SOURCE_FREE_RUNNING    0x00
#define ADC_TRIGGER_SOURCE_ANCOMPARATOR    0x01
#define ADC_TRIGGER_SOURCE_EXT0            0x02
#define ADC_TRIGGER_SOURCE_TIM0COMP        0x03
#define ADC_TRIGGER_SOURCE_TIM0OVF         0x04
#define ADC_TRIGGER_SOURCE_TIM1COMPB       0x05
#define ADC_TRIGGER_SOURCE_TIM1OVF         0x06
#define ADC_TRIGGER_SOURCE_TIM1CP          0x07





void Adc_Init(void)
{
#if (ADC_AUTO_TRIGGER_EN==ENABLE)
    ADCSRA.B.ADATE = STD_HIGH;
    SFIOR |= ADC_TRIGGER_SOURCE_SELECTOR<<5;
#endif
#if (ADC_INTERRUPT_EN == ENABLE)
    ADCSRA.B.ADIE = STD_HIGH;
#endif
    ADCSRA.B.ADPS = ADC_PRESCALER_SELECTOR;
    ADMUX.B.REFS = ADC_VREF_SOURCE_SELECTOR;

    /*Left adjustment if the 8 bit resolution is selected*/
    ADMUX.B.ADLAR = ADC_RESOLUTION_SELECTOR;


    ADCSRA.B.ADEN = STD_HIGH;


}
void Adc_StartConversion(Adc_ChannelType ChannelId)
{
   ADMUX.B.MUX = ChannelId;
   ADCSRA.B.ADSC = STD_HIGH;

}
void Adc_GetConversionResult(uint16 * Ptr2Result)
{
#if ADC_RESOLUTION_SELECTOR == ADC_RESOLUTION_8
	*Ptr2Result = ADCH;
#elif ADC_RESOLUTION_SELECTOR == ADC_RESOLUTION_10
	*Ptr2Result = ADC;
#endif
}
