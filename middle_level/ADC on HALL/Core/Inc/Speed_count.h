#ifndef _SPEEDCOUNT_H
#define _SPEEDCOUNT_H
#include "stdint.h"
#include "stm32f1xx_hal.h"

// =========== дхяйпермши ббнд/бшбнд ======



uint16_t SpeedCnt(void);
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;

#endif
