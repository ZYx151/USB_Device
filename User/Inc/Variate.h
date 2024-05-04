/*!
 * @file     Variate.h
 * @date     2024-1-1
 * @brief    全局宏定义，引用外部变量，定义结构体头文件
 */
#ifndef __VARIATE_H
#define __VARIATE_H

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "WatchDog.h"
#include "Chassis.h"
#include "math.h"
#include "stm32f4xx.h"
#include "VCOMCOMM.h"
#include "usbd_def.h"

/** @brief 设备状态 */
typedef enum
{
	Device_Offline = 0,         //!< @brief 设备离线
	Device_Online  = 1,	        //!< @brief 设备在线
	Device_Error   = 2	        //!< @brief 设备错误        
} eDeviceState;
extern eDeviceState  Gimbal_State[2],Pluck_State, Shoot_State[3], Down_State, Remote_State, IMU_State, PC_State;

/** @brief  系统状态 */
typedef enum
{
	SYSTEM_STARTING = 0,        //!< @brief 正在启动
	SYSTEM_RUNNING  = 1,	    //!< @brief 正在运行
    SYSTEM_SHIFTING = 2,
    SYSTEM_STOPING = 3
} eSystemState;
extern eSystemState systemState;


extern WatchDog_TypeDef PC_Dog;
extern USBD_HandleTypeDef hUsbDeviceFS;

/* 任务句柄 */

extern TaskHandle_t  Task_Protect_handle;

#endif
