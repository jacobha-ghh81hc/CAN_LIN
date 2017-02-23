/* Includes ------------------------------------------------------------------*/
#include "LIN_CONFIG.h"
#include "LED_CONFIGURATION.h"
#include "DELAY.h"

linTaskStruct masterTask;

void LIN_Configuration (uint32_t BaudRate)
{
	//Cau hinh USART2
	USART_InitTypeDef USART_Setting;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	USART_Setting.USART_BaudRate=BaudRate;
	USART_Setting.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_Setting.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_Setting.USART_Parity=USART_Parity_No;
	USART_Setting.USART_StopBits=USART_StopBits_1;
	USART_Setting.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART2, &USART_Setting);


	//Cau hinh GPIO Tx, Rx
	GPIO_InitTypeDef USART_Tx, USART_Rx;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	USART_Tx.GPIO_Mode=GPIO_Mode_AF;
	USART_Tx.GPIO_OType=GPIO_OType_PP;
	USART_Tx.GPIO_PuPd=GPIO_PuPd_UP;
	USART_Tx.GPIO_Speed=GPIO_Speed_100MHz;
	USART_Tx.GPIO_Pin=GPIO_Pin_2;//Tx la Pin A2
	GPIO_Init(GPIOA,&USART_Tx);


	USART_Rx.GPIO_Mode=GPIO_Mode_AF;
	USART_Rx.GPIO_OType=GPIO_OType_PP;
	USART_Rx.GPIO_PuPd=GPIO_PuPd_NOPULL;
	USART_Rx.GPIO_Speed=GPIO_Speed_100MHz;
	USART_Rx.GPIO_Pin=GPIO_Pin_3;
	GPIO_Init(GPIOA,&USART_Rx);//Rx la Pin A3

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
	USART_ITConfig(USART2,USART_IT_TXE,ENABLE);
	USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART2,ENABLE);
	//USART_LINCmd(USART2,ENABLE);


	//Cau hinh NVIC
	NVIC_InitTypeDef USART_NVIC;
	USART_NVIC.NVIC_IRQChannel = USART2_IRQn;
	USART_NVIC.NVIC_IRQChannelPreemptionPriority = 0;
	USART_NVIC.NVIC_IRQChannelSubPriority = 1;
	USART_NVIC.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&USART_NVIC);
}


void LIN_MasterSendFrame (void)//After check bus state
 {
	linBusStateEnum checkStateBus=busStateIdle;
	linFrameStruct frameTest;

	if(checkStateBus==busStateIdle)
	{
		LIN_Send(breakField);
		checkStateBus=busStateBreak;
	}
	if(checkStateBus==busStateBreak)
	{
		LIN_Send(syncField);
		checkStateBus=busStateSync;
	}
	if(checkStateBus==busStateSync)//After send PID-->Find master's task
	{
		LIN_Send(frameTest.msgID);
		checkStateBus=busStatePid;
	}
	if(checkStateBus==busStatePid)
	{
		checkStateBus = LIN_MasterFindTask(0x80);
		if(checkStateBus==busStateTx)
		{
			//goi ham tinh checksum va send data
			LIN_CalculateChecksum();
			LIN_SendData();
		}
		if(checkStateBus==busStateRx)
		{
			//goi ham nhan data
		}
		if(checkStateBus==busStateIdle)
		{

		}

	}
 }

linBusStateEnum LIN_MasterFindTask (uint8_t pidFrame)//Need necessary to check Parity of ID?
{


	if(LIN_CheckPid(pidFrame) != linCheckPidOk)
	{
		LIN_MasterSendFrame();
	}

	else
	{
		switch(pidFrame)
		{
		case ((uint8_t)0x42):
			masterTask.linPid = 0x42;
			masterTask.linDirection = linDirectionTx;
			masterTask.dataLength = 4;
			return busStateTx;
			break;

		case ((uint8_t)0x06):
			masterTask.linPid = 0x06;
			masterTask.linDirection = linDirectionRx;
			masterTask.dataLength = 4;
			return busStateRx;
			break;
		}
	}
	return busStateIdle;
}

uint8_t LIN_CheckPid(uint8_t PidNeedCheck)
{
	if (linPidTable[PidNeedCheck & 0x3F] != PidNeedCheck)
	{
		return linCheckPidFail;
	}
	else
	{
		return linCheckPidOk;
	}
}

void LIN_Send (uint16_t somethingNeedTx)
{
	USART_SendData(USART2,somethingNeedTx);
	while(USART_GetITStatus(USART2,USART_IT_TXE)==RESET);
}


void LIN_SendData (void)
{
	for(uint8_t index=0;index<=9;index++)
	{
		LIN_Send(bufferLin[index]);
	}
}

int8_t LIN_CalculateChecksum (void)
{
	for(uint8_t index=0;index<=8;index++)
	{
		bufferLin[9] += bufferLin[index];
	}
	return bufferLin[9] = 0xFF - bufferLin[9];
}
