#include <WatchDog.h>

#if defined(WatchDoglength) && WatchDoglength > 0

/*!@brief 看门狗列表*/
static WatchDogp List[WatchDoglength];

/*!@brief 看门狗长度*/
static uint16_t Len = 0;

void WatchDog_Polling(void) {
    for (uint8_t i = 0; i < Len; ++i) {
        List[i]->Life++;
        if (List[i]->Life > List[i]->Max) {
            WatchDog_CallBack(List[i]);
        }
    }
}

void WatchDog_Init(WatchDogp handle, uint32_t Life) {
    if (Len >= WatchDoglength)
        return;
    handle->Max = Life;
    handle->ID  = Len + 1;
    List[Len++] = handle;
}

void Feed_Dog(WatchDogp handle) {
    handle->Life = 0;
    FeedDog_CallBack(handle);
}

__weak void FeedDog_CallBack(WatchDogp handle) {
    UNUSED(handle);
}

__weak void WatchDog_CallBack(WatchDogp handle) {
    UNUSED(handle);
}

#endif
