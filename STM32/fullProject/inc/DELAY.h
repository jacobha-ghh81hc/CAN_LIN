#ifndef DELAY_H_
#define DELAY_H_


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h" //Khong can cung duoc

/* FUNCTION PROTOTYPE---------------------------------------------------------------------*/
void Delay_ms( uint32_t timeNeedDelay);
void Delay_us( uint32_t timeNeedDelay);



#ifdef __cplusplus
}
#endif


#endif /* DELAY_H_ */
