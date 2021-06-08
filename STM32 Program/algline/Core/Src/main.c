/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile uint8_t flag;
volatile uint8_t flag2;
uint16_t ADCValues[8];
uint16_t Sensors_Tab[8];
int Weight[8]={3,-3, 2,-2, 1, 0, -1, 0}, PositionBefore;
int Integral;
volatile uint8_t Received[3];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
int _write(int file, char *ptr, int len){
	HAL_UART_Transmit(&huart1, (uint8_t*)ptr, len, 100);
	return len;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim10) {
		flag=1;
	}
}


void setup_uart(){
	HAL_Delay(1000);
	printf("AT+BAUD4");
	HAL_Delay(100);
	printf("AT+NAMEep_bt");
	HAL_Delay(100);
	printf("AT+PIN3498");
	HAL_Delay(100);
}

int ReadInfoFromSensors(){
	uint8_t i=0, amount=0;
	int sum=0;

	for(i=0; i<8; i++){
		if(ADCValues[i] > 2500){
			Sensors_Tab[i]=1;
			amount++;
		}
		else
			Sensors_Tab[i]=0;
	}

	for(i=0; i<8; i++){
		sum=sum + Sensors_Tab[i]*Weight[i];
	}

	return sum*10/amount;
}


void PID_loop(float KP, float KI, float KD, float loopTime){
	int Target=0, Tp=840, change=0, PWM_Value=0;
	int ErrP=0, ErrD=0, Err=0,  current=0;

	current = ReadInfoFromSensors();
	Err=(Target + current);
	ErrP = Err*KP;
	ErrD = ((Err- PositionBefore)/loopTime)*KD;
	Integral = Integral + (Err*KI*loopTime);
	PositionBefore=current;
	change =ErrP/10 + ErrD/10+ Integral/10;

	if(Err > 0){
		PWM_Value = Tp - change;
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, Tp-PWM_Value);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, Tp+PWM_Value);

	}
	else if (Err < 0){
		PWM_Value = Tp + change;
		 __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, Tp-PWM_Value);
		 __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, Tp+PWM_Value);
	}
	else if( Err == 0){
		 __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, Tp);
		 __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, Tp);
	}



}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {


	if(huart == &huart1){
		flag2 = 1;
	}
		HAL_UART_Receive_IT(&huart1, &Received, 1);


}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	float KP=3.5, KD=8, KI=0.5;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM10_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_ADC_Start_DMA(&hadc1, ADCValues, 8);
  HAL_TIM_Base_Start_IT(&htim10);
  HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
  setup_uart();
  HAL_GPIO_WritePin(D11_GPIO_Port, D11_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(D21_GPIO_Port, D21_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(D12_GPIO_Port, D12_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(D22_GPIO_Port, D22_Pin, GPIO_PIN_RESET);
  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 0);
  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 0);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  HAL_UART_Receive_IT(&huart1, &Received, 1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if( flag == 1){
		  PID_loop(KP,KD,KI, 0.01);

		  flag=0;
	  }

	  if ( flag2 == 1){
		  HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		  if(Received[0] == 'P'){
			  KP=(Received[1]*100+Received[2]*10 +Received[3])/10;
			  printf("odebrane %d", KP);
		  }
		  else if(Received[0] == 'D'){
			  KD=(Received[1]*100+Received[2]*10 +Received[3])/10;
			  printf("odebrane %d", KD);
		  }
		  else if(Received[0] == 'I'){
			  KI=(Received[1]*100+Received[2]*10 +Received[3])/10;
			  printf("odebrane %d", KI);
		  }
		  else{
			  printf("Zle wyslane");
		  }
		  flag2=0;
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 84;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
