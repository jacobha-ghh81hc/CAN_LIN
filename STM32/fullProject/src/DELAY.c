/* Includes ------------------------------------------------------------------*/
#include "DELAY.h"

volatile uint32_t msDelayCount, usDelayCount;

/*----------------------------Delay_ms-----------------------------------------*/
void Delay_ms( uint32_t timeNeedDelay)
{
	SysTick_Config(SystemCoreClock/1000); //1ms
	msDelayCount=timeNeedDelay;
	while(msDelayCount!=0);
}

/*----------------------------Delay_us-----------------------------------------*/
void Delay_us( uint32_t timeNeedDelay)
{
	SysTick_Config(SystemCoreClock/1000000); //1us
	usDelayCount=timeNeedDelay;
	while(usDelayCount!=0);
}
