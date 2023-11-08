/*
 * main.c
 *
 * Created: 10/20/2023 11:49:57 AM
 *  Author: omnia
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/SPI/SPI_INT.h"
#include "../MCAL/UART/UART_INTERFACE.h"
#include "../HAL/KEYPAD/KEYPAD.h"
#include "../HAL/LCD/LCD.h"


u8 readKeypad;
u8 readSPI;

int main()
{
	DIO_init();
	KEYPAD_INIT();
	LCD_INIT();
	_delay_ms(500);
	SPI_MASTER_INIT();
	UART_init(9600);
	UART_RX_ENABLE();
	
	u8 returnValu;
	
	
	while(1)
	{
		
		returnValu = USART_Receive();
		LCD_write_char(returnValu);
		//chip select
		DIO_SetPinVal(PB,4,0);
		readSPI = SPI_u8Transfer(returnValu);
		
		
	}
		
}
