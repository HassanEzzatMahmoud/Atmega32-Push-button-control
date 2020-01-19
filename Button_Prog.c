/*
 * Button.c
 *
 *  Created on: ???/???/????
 *      Author: hassan
 */
#include"LIB/Types.h"
#include"LIB/util.h"
#include"DIO_int.h"
#include"Button_int.h"
#include"Button_Cfg.h"
#define F_CPU 8000000UL
#include<util/delay.h>


u8 BUTTON_GetReading()
{
	u8 val;

	/**Pull up resistance */
	DIO_SetPinValue(BUTTON_PORT,BUTTON_PIN,DIO_u8HIGH);
	val=DIO_GetPinValue(BUTTON_PORT,BUTTON_PIN);

	if(val==DIO_u8LOW) // button is pressed
	{
		while(!DIO_GetPinValue(BUTTON_PORT,BUTTON_PIN));
		{
			_delay_ms(10); //for Bouncing

		}

		DIO_SetPinValue(BUTTON_PORT,BUTTON_PIN,DIO_u8HIGH);
	}

	return val;


}





