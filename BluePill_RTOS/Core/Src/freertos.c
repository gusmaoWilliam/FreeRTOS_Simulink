/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "usb_device.h"
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
/* USER CODE BEGIN Variables */
osThreadId Task3Handle;

uint8_t received = 0;
/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId HighTaskHandle;
osThreadId LowTaskHandle;
osSemaphoreId BinSemHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void send_deftask(void)
{
	CDC_Transmit_FS("Hello World!", sizeof("Hello World!"));
}
void send_task2(void)
{
	CDC_Transmit_FS("Hello Another World!\n", sizeof("Hello Another World!\n"));
}
void send_task3(void)
{
	CDC_Transmit_FS("Hello third World!\n", sizeof("Hello third World!\n"));
}


void Task3_Init(void const * argument);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartHighTask(void const * argument);
void StartLowTask(void const * argument);

extern void MX_USB_DEVICE_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of BinSem */
  osSemaphoreDef(BinSem);
  BinSemHandle = osSemaphoreCreate(osSemaphore(BinSem), 1);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of HighTask */
  osThreadDef(HighTask, StartHighTask, osPriorityAboveNormal, 0, 128);
  HighTaskHandle = osThreadCreate(osThread(HighTask), NULL);

  /* definition and creation of LowTask */
  osThreadDef(LowTask, StartLowTask, osPriorityBelowNormal, 0, 128);
  LowTaskHandle = osThreadCreate(osThread(LowTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
	osThreadDef(Task3, Task3_Init, osPriorityNormal,0, 128);
	Task3Handle = osThreadCreate(osThread(Task3), NULL);
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
		uint8_t temp_buffer[] = "Entered Normal Task!\n\r";
		USB_SendMessage(temp_buffer, sizeof(temp_buffer), 10);
		
		
		
		uint8_t temp_buffer2[] = "Leaving Normal Task!\n\r";
		USB_SendMessage(temp_buffer2, sizeof(temp_buffer2), 10);
		
    osDelay(500);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartHighTask */
/**
* @brief Function implementing the HighTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartHighTask */
void StartHighTask(void const * argument)
{
  /* USER CODE BEGIN StartHighTask */
  /* Infinite loop */
  for(;;)
  {
		uint8_t temp_buffer[] = "Hih Task Esperando Semaforo!\n\r";
		USB_SendMessage(temp_buffer, sizeof(temp_buffer), 10);
		
		osSemaphoreWait(BinSemHandle, osWaitForever);
		
		uint8_t temp_buffer3[] = "High Task Pegou Semaforo!\n\r";
		USB_SendMessage(temp_buffer3, sizeof(temp_buffer3), 10);
		
		uint8_t temp_buffer2[] = "High Task Soltando Semaforo!\n\r";
		USB_SendMessage(temp_buffer2, sizeof(temp_buffer2), 10);
		
		osSemaphoreRelease(BinSemHandle);
		
    osDelay(500);
  }
  /* USER CODE END StartHighTask */
}

/* USER CODE BEGIN Header_StartLowTask */
/**
* @brief Function implementing the LowTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLowTask */
void StartLowTask(void const * argument)
{
  /* USER CODE BEGIN StartLowTask */
  /* Infinite loop */
  for(;;)
  {
		uint8_t temp_buffer[] = "Low Task Esperando Semaforo!\n\r";
		USB_SendMessage(temp_buffer, sizeof(temp_buffer), 10);
		
		osSemaphoreWait(BinSemHandle, osWaitForever);
		
		uint8_t temp_buffer3[] = "Low Task Pegou Semaforo!\n\r";
		USB_SendMessage(temp_buffer3, sizeof(temp_buffer3), 10);
		
		HAL_Delay(5000);
		
		uint8_t temp_buffer2[] = "Low Task Soltando Semaforo!\n\r";
		USB_SendMessage(temp_buffer2, sizeof(temp_buffer2), 10);
		
		osSemaphoreRelease(BinSemHandle);
		
    osDelay(500);
  }
  /* USER CODE END StartLowTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void Task3_Init(void const * argument)
{
	for(;;)
  {
		//HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		//send_task3();
		osDelay(3000);
  }
}

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
