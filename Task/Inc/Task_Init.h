#ifndef __TASK_INIT_H
#define __TASK_INIT_H

#include "Variate.h"
#include "main.h"
#include "cmsis_os.h"
#include "can.h"
#include "tim.h"

/**
 * @brief 断控保护任务
 */
void Task_Protect(void *pvParameters);

TaskHandle_t Task_Protect_handle;

#endif
