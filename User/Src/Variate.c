#include "Variate.h"


/* 看门狗结构体定义 */
WatchDog_TypeDef PC_Dog;


/* 设备状态 */
eSystemState systemState = SYSTEM_STARTING;
eDeviceState Remote_State, IMU_State, Pluck_State, Gimbal_State[2], Shoot_State[3], Down_State, PC_State, Debug_State;


