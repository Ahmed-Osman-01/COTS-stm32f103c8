/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     18/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     LED                                                                   */
/****************************************************************************************************/

/*
 * HLED_prog.c
 *
 *  Created on: May 29, 2023
 *      Author: Osman
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "LED_int.h"
#include "LED_config.h"
#include "LED_priv.h"

ErrorState_t LED_enInitLED(LED_t coppy_enLED)
{
	ErrorState_t local_err = OK;
	switch(coppy_enLED)
	{
	case LED_RED:
		GPIO_u8SetPinMode(LED_RED_PORT ,LED_RED_PIN, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
		break;

	case LED_GRN:
		GPIO_u8SetPinMode(LED_GRN_PORT ,LED_GRN_PIN, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
		break;

	case LED_BLUE:
		GPIO_u8SetPinMode(LED_BLUE_PORT ,LED_BLUE_PIN, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
		break;

	default:
		local_err = OUT_OF_RANGE_ERR;
		break;

	}

	return local_err;
}


ErrorState_t LED_enSetLEDOn(LED_t coppy_enLED)
{
	ErrorState_t local_err = OK;

	switch(coppy_enLED)
	{
	case LED_RED:
		#if (LED_RED_DIR == HLED_LED_FORWARD)
			GPIO_u8SetPinValue(LED_RED_PORT ,LED_RED_PIN, GPIO_u8HIGH);

		#elif (LED_RED_DIR == HLED_LED_REVERSE)
			GPIO_u8SetPinValue(LED_RED_PORT ,LED_RED_PIN, GPIO_u8LOW);

		#else
			#error "Wrong LED Direction in configuration"
		#endif
		break;

	case LED_GRN:
		#if (LED_GRN_DIR == HLED_LED_FORWARD)
			GPIO_u8SetPinValue(LED_GRN_PORT ,LED_GRN_PIN, GPIO_u8HIGH);

		#elif (LED_GRN_DIR == HLED_LED_REVERSE)
			GPIO_u8SetPinValue(LED_GRN_PORT ,LED_GRN_PIN, GPIO_u8LOW);

		#else
			#error "Wrong LED Direction in configuration"
		#endif
		break;

	case LED_BLUE:
		#if (LED_BLUE_DIR == HLED_LED_FORWARD)
			GPIO_u8SetPinValue(LED_BLUE_PORT ,LED_BLUE_PIN, GPIO_u8HIGH);

		#elif (LED_BLUE_DIR == HLED_LED_REVERSE)
			GPIO_u8SetPinValue(LED_BLUE_PORT ,LED_BLUE_PIN, GPIO_u8LOW);

		#else
			#error "Wrong LED Direction in configuration"
		#endif
		break;

	default:
		local_err = OUT_OF_RANGE_ERR;
		break;

	}

	return local_err;
}


ErrorState_t LED_enSetLEDOff(LED_t coppy_enLED)
{
	ErrorState_t local_err = OK;

		switch(coppy_enLED)
		{
		case LED_RED:
			#if (LED_RED_DIR == HLED_LED_FORWARD)
				GPIO_u8SetPinValue(LED_RED_PORT ,LED_RED_PIN, GPIO_u8LOW);

			#elif (LED_RED_DIR == HLED_LED_REVERSE)
				GPIO_u8SetPinValue(LED_RED_PORT ,LED_RED_PIN, GPIO_u8HIGH);

			#else
				#error "Wrong LED Direction in configuration"
			#endif
			break;

		case LED_GRN:
			#if (LED_GRN_DIR == HLED_LED_FORWARD)
				GPIO_u8SetPinValue(LED_GRN_PORT ,LED_GRN_PIN, GPIO_u8LOW);

			#elif (LED_GRN_DIR == HLED_LED_REVERSE)
				GPIO_u8SetPinValue(LED_GRN_PORT ,LED_GRN_PIN, GPIO_u8HIGH);

			#else
				#error "Wrong LED Direction in configuration"
			#endif
			break;

		case LED_BLUE:
			#if (LED_BLUE_DIR == HLED_LED_FORWARD)
				GPIO_u8SetPinValue(LED_BLUE_PORT ,LED_BLUE_PIN, GPIO_u8LOW);

			#elif (LED_BLUE_DIR == HLED_LED_REVERSE)
				GPIO_u8SetPinValue(LED_BLUE_PORT ,LED_BLUE_PIN, GPIO_u8HIGH);

			#else
				#error "Wrong LED Direction in configuration"
			#endif
			break;

		default:
			local_err = OUT_OF_RANGE_ERR;
			break;

		}

		return local_err;
}


ErrorState_t LED_enToggleLED(LED_t coppy_enLED)
{
	ErrorState_t local_err = OK;
	switch(coppy_enLED)
	{
	case LED_RED:
		GPIO_u8TogglePin(LED_RED_PORT, LED_RED_PIN);
		break;

	case LED_GRN:
		GPIO_u8TogglePin(LED_GRN_PORT, LED_GRN_PIN);
		break;

	case LED_BLUE:
		GPIO_u8TogglePin(LED_BLUE_PORT, LED_BLUE_PIN);
		break;

	default:
		local_err = OUT_OF_RANGE_ERR;
		break;

	}

	return local_err;
}
