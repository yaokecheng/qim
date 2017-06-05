#include "LPC11xx.h"         // Device header
#include "ADC.h"
#include <stdio.h>
#include <string.h>
#include "Systick.h"
#include "UART.h"
#include "LCD.h"

int main(void)	
{
	  ADC_Init();
	  Systick_Init();
	  UART_Init();
	  LCD_Init();
}	