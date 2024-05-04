#include "Task_Init.h"

/* 初始化主任务 */
void Task_Init()
{
    taskENTER_CRITICAL(); // 进入临界区	
	
	    WatchDog_Init(&PC_Dog, 1);
	
    /* 创建任务 */
	  xTaskCreate((TaskFunction_t)Task_Protect,       "Task_Protect",             128, NULL, 7, &Task_Protect_handle);
  vTaskDelete(NULL);   // 删除开始空闲任务

    taskEXIT_CRITICAL(); // 退出临界区
}
