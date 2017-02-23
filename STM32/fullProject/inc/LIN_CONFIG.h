#ifndef LIN_CONFIG_H_
#define LIN_CONFIG_H_


#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h" //Khong can cung duoc
#include "stm32f4_discovery.h"

#define syncField ((uint8_t)0x55)
#define breakField 0b0000000000000

#define linCheckPidOk 1
#define linCheckPidFail 0

#define linDirectionTx 0
#define linDirectionRx 1

int8_t bufferLin[9];

uint8_t dataLength[4];//Data length of frame

typedef struct
{
	uint8_t msgID;
	uint8_t data[8];
	uint8_t checkSum;
} linFrameStruct;

typedef struct
{
	uint8_t linPid;
	uint8_t linDirection;
	uint8_t dataLength;
} linTaskStruct;



const uint8_t linPidTable[64];

typedef enum
{
	busStateIdle = 0,
	busStateBreak,
	busStateSync,
	busStatePid,
	busStateRx,
	busStateTx,
} linBusStateEnum;

typedef enum
{
	usartBreakDetected = 0,
	usartTxCompleted,
	usartRxDataReceived,
	usartTxEmpty,
	usartParityError,
} usartStateEnum;



/* START ---------------------------------------------------------------------*/
 void LIN_Configuration (uint32_t BaudRate);
 linBusStateEnum LIN_MasterFindTask (uint8_t PidFrame);
 void LIN_MasterSendFrame (void);
 uint8_t LIN_CheckPid(uint8_t PidNeedCheck);
 void LIN_Send (uint16_t thingNeedTx);
 void LIN_SendData (void);
 int8_t LIN_CalculateChecksum (void);











#ifdef __cplusplus
}
#endif




#endif /* LIN_CONFIG_H_ */
