#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "LED_CONFIGURATION.h"
#include "LIN_CONFIG.h"
#include "DELAY.h"


//void GPIO_Configuration (void);
//void EXTI_Configuration (void);
//void TIMER2_Configuration (void);
//void TIMER3_Configuration (void);
//void Delay_Timer (void);
//void USART_Configuration (uint32_t BaudRate);
//void USART_Tx (uint16_t charTx);
//uint16_t USART_Rx (void);
//uint16_t dataTx, dataRx;

int main(void)
{
	LED_HARDWARE_CONFIG();
	LED_ON(LED15);
	//GPIO_Configuration();
	//USART_Configuration(115200);

	//EXTI_Configuration();

	//TIMER2_Configuration();
	//TIM_Cmd(TIM2,ENABLE);
	//TIMER3_Configuration();
	LIN_Configuration(9600);
	//LIN_MasterSendFrame();

	LED_ON(LED12);

	while(1)
	{
		//LED_NHAPNHAY_MS(LED12,100);
//		Delay_us(10000);
//		GPIO_ToggleBits(GPIOD,LED15);
//		GPIO_ToggleBits(GPIOD,LED12);
//		Delay_ms(1000);
		//LED_NHAPNHAY_MS(LED12,1000);
		//LED_NHAPNHAY_MS(LED15,100);
		//LED_NHAPNHAY_US(LED14,1000000);
		//LED_ON_SERIAL();
		//USART_SendData(USART2,65);
		//while(USART_GetITStatus(USART2,USART_IT_TXE)==RESET);

	}
}
/*====================================================Function Define===============================*/

//void USART_Configuration (uint32_t BaudRate)
//{
//	// Cau hinh USART2
//
//	USART_InitTypeDef USART_Setting;
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
//	USART_Setting.USART_BaudRate=BaudRate;
//	USART_Setting.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
//	USART_Setting.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
//	USART_Setting.USART_Parity=USART_Parity_No;
//	USART_Setting.USART_StopBits=USART_StopBits_1;
//	USART_Setting.USART_WordLength=USART_WordLength_8b;
//	USART_Init(USART2, &USART_Setting);
//
//	// Cau hinh GPIO Tx, Rx
//
//	GPIO_InitTypeDef USART_Tx, USART_Rx;
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
//	USART_Tx.GPIO_Mode=GPIO_Mode_AF;
//	USART_Tx.GPIO_OType=GPIO_OType_PP;
//	USART_Tx.GPIO_PuPd=GPIO_PuPd_UP;
//	USART_Tx.GPIO_Speed=GPIO_Speed_100MHz;
//	USART_Tx.GPIO_Pin=GPIO_Pin_2;
//	GPIO_Init(GPIOA,&USART_Tx);
//
//	USART_Rx.GPIO_Mode=GPIO_Mode_AF;
//	USART_Rx.GPIO_OType=GPIO_OType_PP;
//	USART_Rx.GPIO_PuPd=GPIO_PuPd_NOPULL;
//	USART_Rx.GPIO_Speed=GPIO_Speed_100MHz;
//	USART_Rx.GPIO_Pin=GPIO_Pin_3;
//	GPIO_Init(GPIOA,&USART_Rx);
//
//	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
//	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
//	USART_ITConfig(USART2,USART_IT_TXE,ENABLE);
//	USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
//	USART_Cmd(USART2,ENABLE);
//
//	// Cau hinh NVIC
//
//	NVIC_InitTypeDef USART_NVIC;
//	USART_NVIC.NVIC_IRQChannel = USART2_IRQn;
//	USART_NVIC.NVIC_IRQChannelPreemptionPriority = 0;
//	USART_NVIC.NVIC_IRQChannelSubPriority = 1;
//	USART_NVIC.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&USART_NVIC);
//}

//void USART_Tx(uint16_t charTx)
//{
//	USART_SendData(USART2,charTx);
//	while(USART_GetITStatus(USART2,USART_IT_TXE)==RESET)
//	{
//		;
//	}
//}

//uint16_t USART_Rx (void)
//{
//	while(USART_GetITStatus(USART2,USART_IT_RXNE)==RESET)
//	{
//		;
//	}
//	return dataRx=USART_ReceiveData(USART2);
//}

//void TIMER3_Configuration (void)
//{
//	TIM_TimeBaseInitTypeDef TIMER3;
//	NVIC_InitTypeDef NVIC_InitStructure;
//
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
//	TIM_InternalClockConfig(TIM3);
//	TIMER3.TIM_ClockDivision=TIM_CKD_DIV1;
//	TIMER3.TIM_CounterMode=TIM_CounterMode_Up;
//	TIMER3.TIM_Period=999;
//	TIMER3.TIM_Prescaler=42000;
//	TIMER3.TIM_RepetitionCounter=0x0000;
//	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
//	TIM_TimeBaseInit(TIM3,&TIMER3);
//	TIM_Cmd(TIM3,ENABLE);
//
//	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
//}

//void TIMER2_Configuration (void)
//{
//	TIM_TimeBaseInitTypeDef TIMER2;
//	NVIC_InitTypeDef NVIC_InitStructure;
//
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
//	TIM_InternalClockConfig(TIM2);
//	TIMER2.TIM_ClockDivision=TIM_CKD_DIV1;
//	TIMER2.TIM_CounterMode=TIM_CounterMode_Up;
//	TIMER2.TIM_Period=2999;
//	TIMER2.TIM_Prescaler=42000;
//	TIMER2.TIM_RepetitionCounter=0x0000;
//	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
//	TIM_TimeBaseInit(TIM2,&TIMER2);
//	TIM_GenerateEvent(TIM2,TIM_EventSource_Break);
//	TIM_Cmd(TIM2,ENABLE);
//
//	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
//}

//void GPIO_Configuration(void)
//{
//	GPIO_InitTypeDef GPIO_D;
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);
//
//	GPIO_D.GPIO_Mode=GPIO_Mode_OUT;
//	GPIO_D.GPIO_OType=GPIO_OType_PP;
//	GPIO_D.GPIO_PuPd=GPIO_PuPd_NOPULL;
//	GPIO_D.GPIO_Speed=GPIO_Speed_100MHz;
//	GPIO_D.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
//	GPIO_Init(GPIOD,&GPIO_D);
//}

//void EXTI_Configuration (void)
//{
//	EXTI_InitTypeDef EXTI_GPIO_A;
//	NVIC_InitTypeDef NVIC_GPIO_A;
//	GPIO_InitTypeDef GPIO_A;
//
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
//	RCC_AHB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
//
//	GPIO_A.GPIO_Mode=GPIO_Mode_IN;
//	GPIO_A.GPIO_OType=GPIO_OType_PP;
//	GPIO_A.GPIO_Pin=GPIO_Pin_0;
//	GPIO_A.GPIO_PuPd=GPIO_PuPd_NOPULL;
//	GPIO_A.GPIO_Speed=GPIO_Speed_100MHz;
//	GPIO_Init(GPIOA,&GPIO_A);
//
//	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource0);
//
//	EXTI_GPIO_A.EXTI_Line=EXTI_Line0;
//	EXTI_GPIO_A.EXTI_LineCmd=ENABLE;
//	EXTI_GPIO_A.EXTI_Mode=EXTI_Mode_Interrupt;
//	EXTI_GPIO_A.EXTI_Trigger=EXTI_Trigger_Rising;
//	EXTI_Init(&EXTI_GPIO_A);
//
//	NVIC_GPIO_A.NVIC_IRQChannel=EXTI0_IRQn;
//	NVIC_GPIO_A.NVIC_IRQChannelCmd=ENABLE;
//	NVIC_GPIO_A.NVIC_IRQChannelPreemptionPriority=0;
//	NVIC_GPIO_A.NVIC_IRQChannelSubPriority=0;
//	NVIC_Init(&NVIC_GPIO_A);
//}




/*----------------------------Delay_timer-----------------------------------------*/
//void Delay_Timer (void)
//{
//	//TIM_Cmd(TIM2,ENABLE);
//	if(TIM_GetFlagStatus(TIM2,TIM_FLAG_Update)!=1)
//	{
//		GPIO_ResetBits(GPIOD, GPIO_Pin_13);
//		TIM_ClearFlag(TIM2, TIM_FLAG_Update);
//		GPIO_SetBits(GPIOD, GPIO_Pin_13);
//		TIM_Cmd(TIM2,ENABLE);
//	}
//}
