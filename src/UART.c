#include "LPC11xx.h"                    // Device header
#include "UART.h"
#define UART_BPS    115200
void UART_Init ()
{
	uint16_t usFdiv;
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<16);
	LPC_IOCON->PIO1_6 &=~0X07;
	LPC_IOCON->PIO1_6 |=0X01;
	LPC_IOCON->PIO1_7 &=~0X07;
	LPC_IOCON->PIO1_7 |=0X01;
	LPC_SYSCON->SYSAHBCLKCTRL &=~(1<<16);
	LPC_SYSCON->SYSAHBCLKCTRL |=(1<<12);
	LPC_SYSCON->UARTCLKDIV = 0X01;
	LPC_UART->LCR =0X83;
	usFdiv =(SystemCoreClock/LPC_SYSCON->UARTCLKDIV/16)/UART_BPS;
		LPC_UART->DLM=usFdiv/256;
		LPC_UART->DLL=usFdiv%256;
		LPC_UART->LCR=0x03;
	  LPC_UART->FCR=0x07;
}
uint8_t UART_GetByte(void)
{
	uint8_t ucRcvData;
	while ((LPC_UART->LSR &0x01)==0);
	ucRcvData =LPC_UART->RBR;
	return(ucRcvData);
}
void UART_SendByte(uint8_t ucDat)
{
	LPC_UART->THR =ucDat;
	while((LPC_UART->LSR&0x40)==0);
}
