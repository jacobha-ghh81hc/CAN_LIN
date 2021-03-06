/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_it.h"
#include "DELAY.h"
#include "LED_CONFIGURATION.h"

//extern void USART_Tx (uint16_t charTx);
//extern uint16_t USART_Rx (void);
//extern uint16_t dataRx;
//extern uint32_t delayCount;

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Interruption and Exception Handlers         */
/******************************************************************************/

void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN HardFault_IRQn 1 */

  /* USER CODE END HardFault_IRQn 1 */
}

void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN MemoryManagement_IRQn 1 */

  /* USER CODE END MemoryManagement_IRQn 1 */
}

void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN BusFault_IRQn 1 */

  /* USER CODE END BusFault_IRQn 1 */
}

void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
  }
  /* USER CODE BEGIN UsageFault_IRQn 1 */

  /* USER CODE END UsageFault_IRQn 1 */
}

void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

void SysTick_Handler(void)
{
	extern uint32_t msDelayCount, usDelayCount;
	if(msDelayCount!=0) msDelayCount--;
	if(usDelayCount!=0) usDelayCount--;
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
* @brief This function handles EXTI line0 interrupt.
*/
//void EXTI0_IRQHandler(void)
//{
//	static uint8_t count=0;
//	if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
//	    {
//		count++;
//	      switch(count)
//	      {
//	      case 1:
//	    	  GPIO_SetBits(GPIOD,GPIO_Pin_12);
//	    	  break;
////	      case 2:
////	      	  GPIO_SetBits(GPIOD,GPIO_Pin_13);
////	      	  break;
////	      case 3:
////	      	  GPIO_SetBits(GPIOD,GPIO_Pin_14);
////	      	  break;
////	      case 4:
////	      	  GPIO_SetBits(GPIOD,GPIO_Pin_15);
////	      	  break;
//	      }
//	      if(count==5) count=0;
//	      EXTI_ClearFlag(EXTI_Line0);
//	    }
//}

//void TIM2_IRQHandler(void)
//{
//	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
//    {
//		GPIO_ToggleBits(GPIOD,GPIO_Pin_13);
//		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//    }
//}

//void TIM3_IRQHandler(void)
//{
//	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
//    {
//		GPIO_ToggleBits(GPIOD,GPIO_Pin_14);
//		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
//    }
//}

void USART2_IRQHandler(void)
{
	LED_ON(LED13);
//	volatile uint16_t ch,string;
//	ch=USART_Rx();
//	USART_Tx(dataRx);
//	switch (ch)
//	{
//	case 'O':
//		GPIO_SetBits(GPIOD,GPIO_Pin_12);
//		break;
//	case 'F':
//		GPIO_ResetBits(GPIOD,GPIO_Pin_12);
//		break;
//	}
	USART_SendData(USART2,65);
	while(USART_GetITStatus(USART2,USART_IT_TXE)==RESET);
	if(USART_GetITStatus(USART2,USART_IT_TXE)==1)
	{

	}
}
