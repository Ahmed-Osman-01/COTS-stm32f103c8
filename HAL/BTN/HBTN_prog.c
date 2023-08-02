/*
 * BTN_prog.c
 *
 *  Created on: May 30, 2023
 *      Author: Osman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/MSTK/MSTK_int.h"

#include "HBTN_int.h"
#include "HBTN_priv.h"
#include "HBTN_config.h"


ErrorState_t HBTN_enInitBtn(const HBTN_Info_t * ptrBTN)
{
	ErrorState_t Local_ErrorState = OK;
	
	GPIO_enSetPinMode(ptrBTN->HBTN_Port, ptrBTN->HBTN_Pin, ptrBTN->HBTN_ConnectionType);

	switch(ptrBTN->HBTN_ConnectionType)
	{
		case HBTN_PULLDOWN_CONNECTION:
			GPIO_enSetPinValue( ptrBTN->HBTN_Port, ptrBTN->HBTN_Pin, GPIO_u8LOW);
			break;

		case HBTN_PULLUP_CONNECTION:
			GPIO_enSetPinValue( ptrBTN->HBTN_Port, ptrBTN->HBTN_Pin, GPIO_u8HIGH);
			break;

		default:
			Local_ErrorState = NOK;
			break;
	}
		
	return Local_ErrorState;
}




ErrorState_t HBTN_enReadBtn(const HBTN_Info_t * ptrBTN, u8 * ptrBTNState)
{
	ErrorState_t Local_ErrorState = OK;

	u8 Local_enBTNState = HBTN_RELEASED;
	static u8 prev_state = HBTN_RELEASED;

		/* first read for debouncing */
		GPIO_enGetPinValue( ptrBTN->HBTN_Port, ptrBTN->PushButtonPin, &Local_enBTNState);

		if ( Local_enBTNState == HBTN_PRESSED )
		{
			/* Delay for 30 ms */
			MSTK_SetBusyWait(30000);
			/* second read for debouncing */
			GPIO_enGetPinValue( ptrBTN->HBTN_Port, ptrBTN->PushButtonPin, &Local_enBTNState);

			if( Local_enBTNState == HBTN_PRESSED )
			{
				/* Process only one press even if the user hold the button down*/
				if ( prev_state == HBTN_RELEASED )
				{
					prev_state = HBTN_PRESSED;
					*ptrBTNState = HBTN_PRESSED;
				}
				else
				{
					/* do nothing */
				}

			} /* end of second read if check*/
			else
			{
				/* do nothing */
			}
		} /* end of first read if check*/
		else
		{
			/* When the button is released*/
			prev_state = HBTN_RELEASED;
			*ptrBTNState = HBTN_RELEASED;
		}

	return Local_ErrorState;
}
