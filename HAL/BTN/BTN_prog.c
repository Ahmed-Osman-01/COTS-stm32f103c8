/*
 * BTN_prog.c
 *
 *  Created on: May 30, 2023
 *      Author: Osman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "BTN_int.h"
#include "BTN_priv.h"
#include "BTN_config.h"

ErrorState_t BTN_enInitBtn(const BTN_Info_t * ptrBTN)
{
	ErrorState_t Local_ErrorState = OK;
	
	GPIO_enSetPinMode(ptrBTN->BTN_Port, ptrBTN->BTN_Pin, ptrBTN->BTN_ConnectionType);

	switch(ptrBTN->BTN_ConnectionType)
	{
		case BTN_PULLDOWN_CONNECTION:
			GPIO_enSetPinValue( ptrBTN->BTN_Port, ptrBTN->BTN_Pin, GPIO_u8LOW);
			break;

		case BTN_PULLUP_CONNECTION:
			GPIO_enSetPinValue( ptrBTN->BTN_Port, ptrBTN->BTN_Pin, GPIO_u8HIGH);
			break;

		default:
			Local_ErrorState = NOK;
			break;
	}
		
	return Local_ErrorState;
}




ErrorState_t BTN_enReadBtn(const BTN_Info_t * ptrBTN, u8 * ptrBTNState);
{
	ErrorState_t Local_ErrorState = OK;

	u8 Local_enBTNState = BTN_RELEASED;
	static u8 prev_state = BTN_RELEASED;

		/* first read for debouncing */
		GPIO_enGetPinValue( ptrBTN->BTN_Port, ptrBTN->PushButtonPin, &Local_enBTNState);

		if ( Local_enBTNState == BTN_BTN_PRESSED )
		{
			_delay_ms(50);
			/* second read for debouncing */
			GPIO_enGetPinValue( ptrBTN->BTN_Port, ptrBTN->PushButtonPin, &Local_enBTNState);
			if( Local_enBTNState == BTN_BTN_PRESSED )
			{
				/* Process only one press even if the user hold the button down*/
				if ( prev_state == BTN_BTN_RELEASED)
				{
					prev_state = BTN_BTN_PRESSED;
					*ptrBTNState = BTN_BTN_PRESSED;
				}
				else
				{

				}

			} /* end of second read if check*/
			else
			{

			}
		} /* end of first read if check*/
		else
		{
			/* When the button is released*/
			prev_state = BTN_BTN_RELEASED;
			*ptrBTNState = BTN_BTN_RELEASED;
		}

	return Local_ErrorState;
}
