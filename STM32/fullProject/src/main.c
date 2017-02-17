#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void GPIO_Configuration (void);
void EXTI_Configuration (void);
void TIMER2_Configuration (void);
//void TIMER3_Configuration (void);
void Delay_Timer (void);

void Delay_ms( uint32_t num);
void Delay_us( uint32_t num);

int main(void)
{
	GPIO_Configuration();
	EXTI_Configuration();

	TIMER2_Configuration();
	//TIM_Cmd(TIM2,ENABLE);
	//TIMER3_Configuration();
	//SysTick_Config(SystemCoreClock/1000);
	GPIO_SetBits(GPIOD, GPIO_Pin_13);
	TIM_Cmd(TIM2,ENABLE);

	while(1)
	{
		Delay_Timer();
	}
}

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

void TIMER2_Configuration (void)
{
	TIM_TimeBaseInitTypeDef TIMER2;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_InternalClockConfig(TIM2);
	TIMER2.TIM_ClockDivision=TIM_CKD_DIV1;
	TIMER2.TIM_CounterMode=TIM_CounterMode_Up;
	TIMER2.TIM_Period=2999;
	TIMER2.TIM_Prescaler=42000;
	TIMER2.TIM_RepetitionCounter=0x0000;
	//TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	TIM_TimeBaseInit(TIM2,&TIMER2);
	TIM_GenerateEvent(TIM2,TIM_EventSource_Break);
	//TIM_Cmd(TIM2,ENABLE);

//	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
}

void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_D;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);

	GPIO_D.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_D.GPIO_OType=GPIO_OType_PP;
	GPIO_D.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_D.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_D.GPIO_Pin=GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_Init(GPIOD,&GPIO_D);
}

void EXTI_Configuration (void)
{
	EXTI_InitTypeDef EXTI_GPIO_A;
	NVIC_InitTypeDef NVIC_GPIO_A;
	GPIO_InitTypeDef GPIO_A;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_AHB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);

	GPIO_A.GPIO_Mode=GPIO_Mode_IN;
	GPIO_A.GPIO_OType=GPIO_OType_PP;
	GPIO_A.GPIO_Pin=GPIO_Pin_0;
	GPIO_A.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_A.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_Init(GPIOA,&GPIO_A);

	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource0);

	EXTI_GPIO_A.EXTI_Line=EXTI_Line0;
	EXTI_GPIO_A.EXTI_LineCmd=ENABLE;
	EXTI_GPIO_A.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_GPIO_A.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_GPIO_A);

	NVIC_GPIO_A.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_GPIO_A.NVIC_IRQChannelCmd=ENABLE;
	NVIC_GPIO_A.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_GPIO_A.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_GPIO_A);
}

/*----------------------------Delay_ms-----------------------------------------*/
void Delay_ms( uint32_t num)
{
uint32_t index = 0;
/* default system clock is 168MHz */
for(index = (168000 * num); index != 0; index--)
{}
}

/*----------------------------Delay_us-----------------------------------------*/
void Delay_us( uint32_t num)
{
uint32_t index = 0;
/* default system clock is 168MHz */
for(index = (168 * num); index != 0; index--)
{}
}

/*----------------------------Delay_timer-----------------------------------------*/
void Delay_Timer (void)
{
	//TIM_Cmd(TIM2,ENABLE);
	if(TIM_GetFlagStatus(TIM2,TIM_FLAG_Update)!=1)
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_13);
		TIM_ClearFlag(TIM2, TIM_FLAG_Update);
		GPIO_SetBits(GPIOD, GPIO_Pin_13);
		TIM_Cmd(TIM2,ENABLE);
	}
}



