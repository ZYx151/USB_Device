#include "Task_Protect.h"

void Task_Protect ()
{
  static uint8_t charr[5]="Hello";

		static portTickType currentTime;
	for(;;)
	{
		currentTime = xTaskGetTickCount();
		  /* 看门狗轮询 */
		  WatchDog_Polling();
			VCOMM_Transmit(0,1,charr,sizeof(charr));
	     vTaskDelayUntil (&currentTime,500);
	  
	}
	
}
