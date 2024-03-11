


//******************************************************************************
// ====== Заголовочные файлы ====== 
//******************************************************************************
#include "main.h"


//******************************************************************************
// ====== Макросы ====== 
//******************************************************************************
    #define Num_Teeth  16        //!< Количество зубчиков
    #define Wheel_Lenth 2.14     //!< Периметр колеса
    #define REDUCTION  4.3       //!< редукция моста


    // Объявление глобальных переменных
		float Intertime,TotalSpeed, TotalSpeedPrefer=0;
				
uint16_t Full_Speed_count(void)
    {
		SystemCoreClockUpdate();
		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
		Intertime = ((float)htim1.Init.Prescaler+1)*((float)htim1.Init.Period+1)/(HAL_RCC_GetPCLK1Freq()*2);
		TotalSpeed= Wheel_Lenth*Total_count/Num_Teeth/REDUCTION/Intertime/1000*3600;
		TotalSpeed= (TotalSpeed+TotalSpeedPrefer)/2;
		Total_count=0;
		TotalSpeedPrefer=TotalSpeed;
      return 1;
    }



