
#include "util/delay.h"
#include "Std_Types.h"
#include "BcdSevSeg.h"

void lab_02_BcdSevSeg(void)
{

	Dio_Init();
	while(1)
	{
		BcdSevSeg_Enable(BcdSevSeg_0);
		BcdSevSeg_Disable(BcdSevSeg_1);
		BcdSevSeg_DisplayNum(5);
        _delay_ms(10);
		BcdSevSeg_Enable(BcdSevSeg_1);
		BcdSevSeg_Disable(BcdSevSeg_0);
		BcdSevSeg_DisplayNum(9);
		_delay_ms(10);

	}



}
