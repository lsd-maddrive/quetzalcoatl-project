


//******************************************************************************
// ====== ������������ ����� ====== 
//******************************************************************************
#include "Speed_count.h"


//******************************************************************************
// ====== ������� ====== 
//******************************************************************************


    // ���������� ���������� ����������
		int16_t count=0,flag=0,Total_count=0;


uint16_t SpeedCnt(void)
    {
    // ���������� ��������� ����������
		float adc_data ;
		/*
		float voltage, referenceVoltage = 3.3; // ������� ����������, �������� 3.3�
		uint32_t adcMaxValue = 4095; // ������������ �������� ��� 12-������� ���
		uint32_t adcValue;
		uint16_t control=1;
		*/
			
		//   *******  �������� ���  ***********
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1,100);
		adc_data = HAL_ADC_GetValue(&hadc1);
		HAL_ADC_Stop(&hadc1);
		/*
		adcValue = HAL_ADC_GetValue(&hadc1); // �������� ����� ������ ���
		voltage = (adcValue * referenceVoltage) / adcMaxValue; // �������������� � ����������
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
				
				 * @brief - ��������� ������� CMD_GET_DI_NAMES.
				 * ���������� �������� ���������� ������. � ������ �������� ���� �������, 
				 * ���������� ������ �����. ���� ����� ����������� ������ ��� ����-����, 
				 * ��� ��������, ��� ��������� ����� �������� �� ���������.
				 * ������� ���������� ����������, �� ��� ���, ���� ����� �� ����� ��������� 4 ��������.
				
				//��������� ���� ������������ ��������
					

        break;

 

          default: control=1;
     		 }
*/
      return 1;
    }



