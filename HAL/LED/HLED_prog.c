/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     18/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     LED                                                                   */
/****************************************************************************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "HLED_int.h"
#include "HLED_config.h"
#include "HLED_priv.h"

ErrorState_t HLED_enInitLED(HLED_t coppy_enLED)
{
	ErrorState_t local_err = OK;
	switch(coppy_enLED)
	{
	case HLED_RED:
		GPIO_u8SetPinMode(HLED_RED_PORT ,HLED_RED_PIN, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
		break;

	case HLED_GRN:
		GPIO_u8SetPinMode(HLED_GRN_PORT ,HLED_GRN_PIN, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
		break;

	case HLED_BLUE:
		GPIO_u8SetPinMode(HLED_BLUE_PORT ,HLED_BLUE_PIN, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
		break;

	default:
		local_err = OUT_OF_RANGE_ERR;
		break;

	}

	return local_err;
}


ErrorState_t HLED_enSetLEDOn(HLED_t coppy_enLED)
{
	ErrorState_t local_err = OK;

	switch(coppy_enLED)
	{
	case HLED_RED:
		#if (HLED_RED_DIR == HLED_FORWARD)
			GPIO_u8SetPinValue(HLED_RED_PORT ,HLED_RED_PIN, GPIO_u8HIGH);

		#elif (HLED_RED_DIR == HLED_REVERSE)
			GPIO_u8SetPinValue(HLED_RED_PORT ,HLED_RED_PIN, GPIO_u8LOW);

		#else
			#error "Wrong LED Direction in configuration"
		#endif
		break;

	case HLED_GRN:
		#if (HLED_GRN_DIR == HLED_FORWARD)
			GPIO_u8SetPinValue(HLED_GRN_PORT ,HLED_GRN_PIN, GPIO_u8HIGH);

		#elif (HLED_GRN_DIR == HLED_REVERSE)
			GPIO_u8SetPinValue(HLED_GRN_PORT ,HLED_GRN_PIN, GPIO_u8LOW);

		#else
			#error "Wrong LED Direction in configuration"
		#endif
		break;

	case HLED_BLUE:
		#if (HLED_BLUE_DIR == HLED_FORWARD)
			GPIO_u8SetPinValue(HLED_BLUE_PORT ,HLED_BLUE_PIN, GPIO_u8HIGH);

		#elif (HLED_BLUE_DIR == HLED_REVERSE)
			GPIO_u8SetPinValue(HLED_BLUE_PORT ,HLED_BLUE_PIN, GPIO_u8LOW);

		#else
			#error ("Wrong LED Direction in configuration")
		#endif
		break;

	default:
		local_err = OUT_OF_RANGE_ERR;
		break;

	}

	return local_err;
}


ErrorState_t HLED_enSetLEDOff(HLED_t coppy_enLED)
{
	ErrorState_t local_err = OK;

		switch(coppy_enLED)
		{
		case HLED_RED:
			#if (HLED_RED_DIR == HLED_FORWARD)
				GPIO_u8SetPinValue(HLED_RED_PORT ,HLED_RED_PIN, GPIO_u8LOW);

			#elif (HLED_RED_DIR == HLED_REVERSE)
				GPIO_u8SetPinValue(HLED_RED_PORT ,HLED_RED_PIN, GPIO_u8HIGH);

			#else
				#error "Wrong LED Direction in configuration"
			#endif
			break;

		case HLED_GRN:
			#if (HLED_GRN_DIR == HLED_FORWARD)
				GPIO_u8SetPinValue(HLED_GRN_PORT ,HLED_GRN_PIN, GPIO_u8LOW);

			#elif (HLED_GRN_DIR == HLED_REVERSE)
				GPIO_u8SetPinValue(HLED_GRN_PORT ,HLED_GRN_PIN, GPIO_u8HIGH);

			#else
				#error "Wrong LED Direction in configuration"
			#endif
			break;

		case HLED_BLUE:
			#if (HLED_BLUE_DIR == HLED_FORWARD)
				GPIO_u8SetPinValue(HLED_BLUE_PORT ,HLED_BLUE_PIN, GPIO_u8LOW);

			#elif (HLED_BLUE_DIR == HLED_REVERSE)
				GPIO_u8SetPinValue(HLED_BLUE_PORT ,HLED_BLUE_PIN, GPIO_u8HIGH);

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


ErrorState_t HLED_enToggleLED(HLED_t coppy_enLED)
{
	ErrorState_t local_err = OK;
	switch(coppy_enLED)
	{
	case HLED_RED:
		GPIO_u8TogglePin(HLED_RED_PORT, HLED_RED_PIN);
		break;

	case HLED_GRN:
		GPIO_u8TogglePin(HLED_GRN_PORT, HLED_GRN_PIN);
		break;

	case HLED_BLUE:
		GPIO_u8TogglePin(HLED_BLUE_PORT, HLED_BLUE_PIN);
		break;

	default:
		local_err = OUT_OF_RANGE_ERR;
		break;

	}

	return local_err;
}
