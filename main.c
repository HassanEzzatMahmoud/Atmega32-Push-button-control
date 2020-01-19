/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: hassan
 */
#include"LIB/Types.h"
#include"LIB/util.h"
#include"DIO_int.h"
#define F_CPU 8000000UL
#include<util/delay.h>
#include"Button_int.h"

void main()
{
	u8 val;
	u8 count;
	u8 i;
	/********************Initialization*********************************/
	DIO_SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8INPUT); // Buttons PortS
	DIO_SetPortDirection(DIO_u8PORTB,DIO_u8OUTPUT); //

	/*
	DIO_SetPinValue(DIO_u8PortA,DIO_u8PIN0,DIO_u8HIGH); // Pull up resistance
	 */
	DIO_SetPortValue(DIO_u8PORTB,DIO_u8LOW);

	while(1)
	{
		val=BUTTON_GetReading();
		if(val==DIO_u8LOW) //Button is Pressed
		{
			for(i=0; i<8; i++)
			{DIO_SetPinValue(DIO_u8PORTB,i,DIO_u8HIGH);

			_delay_ms(50);
			DIO_SetPinValue(DIO_u8PORTB,i,DIO_u8LOW);
			//_delay_ms(10);
			}
			DIO_SetPinValue(DIO_u8PORTB,i,DIO_u8HIGH);
			count++;
			if((count%2)==0)
			{

				DIO_SetPortValue(DIO_u8PORTB,DIO_u8LOW);
				count=0;

			}
		}

	}

}





