/* Includes ------------------------------------------------------------------*/
#include "DELAY.h"
#include "LED_CONFIGURATION.h"


/*----------------------------Cau hinh 4 LED tren board F4-----------------------------------------*/
void LED_HARDWARE_CONFIG(void)
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

/*----------------------------Nhap nhay LED-----------------------------------*/
void LED_NHAPNHAY_MS(LEDx ledName, uint32_t howLong)
{
	Delay_ms(howLong);
	GPIO_ToggleBits(GPIOD,ledName);
}

void LED_NHAPNHAY_US(LEDx ledName, uint32_t howLong)
{
	Delay_us(howLong);
	GPIO_ToggleBits(GPIOD,ledName);
}
/*----------------------------Bat LED-----------------------------------------*/
void LED_ON(LEDx ledName)
{
	GPIO_SetBits(GPIOD,ledName);
}
/*----------------------------Tat LED-----------------------------------------*/
void LED_OFF(LEDx ledName)
{
	GPIO_ResetBits(GPIOD,ledName);
}
/*----------------------------Bat LED lien tiep-----------------------------------------*/
void LED_ON_SERIAL(void)
{
	GPIO_ToggleBits(GPIOD,LED12);
	Delay_ms(500);
	GPIO_ToggleBits(GPIOD,LED13);
	Delay_ms(500);
	GPIO_ToggleBits(GPIOD,LED14);
	Delay_ms(500);
	GPIO_ToggleBits(GPIOD,LED15);
	Delay_ms(500);
}
