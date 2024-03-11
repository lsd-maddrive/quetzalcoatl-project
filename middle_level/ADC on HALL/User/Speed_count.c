


//******************************************************************************
// ====== Заголовочные файлы ====== 
//******************************************************************************
#include "Speed_count.h"


//******************************************************************************
// ====== Макросы ====== 
//******************************************************************************


    // Объявление глобальных переменных
		int16_t count=0,flag=0,Total_count=0;


uint16_t SpeedCnt(void)
    {
    // Объявление локальных переменных
		float adc_data ;
		/*
		float voltage, referenceVoltage = 3.3; // Опорное напряжение, например 3.3В
		uint32_t adcMaxValue = 4095; // Максимальное значение для 12-битного АЦП
		uint32_t adcValue;
		uint16_t control=1;
		*/
			
		//   *******  ОСНОВНОЙ КОД  ***********
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1,100);
		adc_data = HAL_ADC_GetValue(&hadc1);
		HAL_ADC_Stop(&hadc1);
		/*
		adcValue = HAL_ADC_GetValue(&hadc1); // Получаем сырые данные АЦП
		voltage = (adcValue * referenceVoltage) / adcMaxValue; // Преобразование в напряжение
		*/
		if (adc_data> 2000) 
			{
			//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
			count++;
			}
		else
			{
			//HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
			count=0;
			flag=0;
			}
		if (count> 10 && flag!=1)
			{
			Total_count++;
			flag=1;
			}
			
			
			
			
			
/**
      switch (CaseLog) 
				{
        case 1:
				
				 * @brief - Обработка команды CMD_GET_DI_NAMES.
				 * Отправляет названия дискретных входов. В начале отправки идет стопбит, 
				 * означающий начало слова. Если перед количеством байтов нет стоп-бита, 
				 * это означает, что последнее слово записано не полностью.
				 * Команду необходимо отправлять, до тех пор, пока ответ не будет содержать 4 элемента.
				
				//проверяем флаг переполнения отправки
					

        break;

 

          default: control=1;
     		 }
*/
      return 1;
    }



