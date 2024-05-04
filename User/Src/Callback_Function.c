#include "Callback_Function.h"

void VCOMM_CallBack(uint8_t fun_code, uint16_t id, uint8_t *data, uint8_t len)
{
	static uint8_t arr[20];
        	/* 转存数据 */
	    memcpy(&arr, data, sizeof(arr));
			VCOMM_Transmit(1,1,arr,sizeof(arr));
      Feed_Dog(&PC_Dog);
}

/* 喂狗回调函数 */
void FeedDog_CallBack(WatchDogp handle)
{
  /*
  ID
  1    WatchDog_Init(&Pc_Dog, 40);
	*/
  switch (handle->ID)
  {

    case 1:
    PC_State = Device_Online;
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
    break;
	}
}
/* 饿死回调函数 */
void WatchDog_CallBack(WatchDogp handle)
{
  /*
  ID
  1    WatchDog_Init(&PC_Dog,30);
  */
  switch (handle->ID)
  {

  case 1:
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
    PC_State = Device_Offline;
    break;

  }
}
