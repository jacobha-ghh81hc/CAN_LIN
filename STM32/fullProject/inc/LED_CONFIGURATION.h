#ifndef LED_CONFIGURATION_H_
#define LED_CONFIGURATION_H_


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h" // Khong can cung duoc

typedef enum
{
	LED12=((uint16_t)0x1000),
	LED13=((uint16_t)0x2000),
	LED14=((uint16_t)0x4000),
	LED15=((uint16_t)0x8000),
}LEDx;

/* START ---------------------------------------------------------------------*/
void LED_HARDWARE_CONFIG(void);
void LED_NHAPNHAY_MS(LEDx ledName, uint32_t howLong);
void LED_NHAPNHAY_US(LEDx ledName, uint32_t howLong);
void LED_ON_SERIAL(void);
void LED_ON(LEDx ledName);
void LED_OFF(LEDx ledName);



#ifdef __cplusplus
}
#endif


#endif /* LED_CONFIGURATION_H_ */
