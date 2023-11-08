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
	SPI_voidSlaveInit();
	
	while(1)
	{
		 readSPI = SPI_u8Recieve(readKeypad); 
		 //LCD_MOVE_CURSOR(1,1);
		 LCD_write_char(readSPI);
		//_delay_ms(500);
	}
		
}
