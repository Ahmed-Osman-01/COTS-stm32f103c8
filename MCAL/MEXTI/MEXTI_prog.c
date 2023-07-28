/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     24/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     EXTI                                                                  */
/****************************************************************************************************/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STM32F103C8.h"
#include "../../LIB/BIT_MATH.h"

#include "MEXTI_int.h"
#include "MEXTI_config.h"
#include "MEXTI_priv.h"


void (*g_CallBacks[16])(void) = {NULL};

void MEXTI_voidInit(void)
{
   #if INITIAL_SELECTED_LINE_EDGE_TRIGGER == EXTI_RISING_EDGE
       MEXTI->EXTI_RTSR = 1 << INITIAL_SELECTED_LINE;

    #elif  INITIAL_SELECTED_LINE_EDGE_TRIGGER == EXTI_FALLING_EDGE
        MEXTI->EXTI_FTSR = 1 << INITIAL_SELECTED_LINE;

    #elif  INITIAL_SELECTED_LINE_EDGE_TRIGGER == EXTI_RISING_AND_FALLING_EDGE
        MEXTI->EXTI_RTSR = 1 << INITIAL_SELECTED_LINE;
        MEXTI->EXTI_FTSR = 1 << INITIAL_SELECTED_LINE;

    #endif

    MEXTI->EXTI_IMR = 1 << INITIAL_SELECTED_LINE;
}


ErrorState_t MEXTI_u8EnableInterrupt(u8 copy_u8Line)
{
    ErrorState_t Local_ErrorState = OK;

    if( (copy_u8Line >= 0) && (copy_u8Line < 16) )
    {
        SET_BIT(MEXTI->EXTI_IMR, copy_u8Line);
    }
    else
    {
        Local_ErrorState = OUT_OF_RANGE_ERR;
    }

    return Local_ErrorState;
}


ErrorState_t MEXTI_u8DisableInterrupt(u8 copy_u8Line)
{
    ErrorState_t Local_ErrorState = OK;

    if( (copy_u8Line >= 0) && (copy_u8Line < 16) )
    {
        CLR_BIT(MEXTI->EXTI_IMR, copy_u8Line);
    }
    else
    {
        Local_ErrorState = OUT_OF_RANGE_ERR;
    }

    return Local_ErrorState;
}


ErrorState_t MEXTI_u8SoftwareInterrupt(u8 copy_u8Line)
{
    ErrorState_t Local_ErrorState = OK;

    if( (copy_u8Line >= 0) && (copy_u8Line < 16) )
    {
        SET_BIT(MEXTI->EXTI_SWIER, copy_u8Line);
    }
    else
    {
        Local_ErrorState = OUT_OF_RANGE_ERR;
    }

    return Local_ErrorState;
}


ErrorState_t MEXTI_u8SetInterruptTrigger(u8 copy_u8Line, u8 copy_u8TriggerEdge)
{
    ErrorState_t Local_ErrorState = OK;

    if( (copy_u8Line >= 0) && (copy_u8Line < 16) )
    {
        switch(copy_u8TriggerEdge)
        {
        case MEXTI_RISING_EDGE:
            SET_BIT(MEXTI->EXTI_RTSR, copy_u8Line);
            break;

        case MEXTI_FALLING_EDGE:
            SET_BIT(MEXTI->EXTI_FTSR, copy_u8Line);
            break;

        case MEXTI_RISING_AND_FALLING_EDGE:
            SET_BIT(MEXTI->EXTI_RTSR, copy_u8Line);
            SET_BIT(MEXTI->EXTI_FTSR, copy_u8Line);
            break;

        default:
            Local_ErrorState = NOK;
            break;
        }
    }
    else
    {
        Local_ErrorState = OUT_OF_RANGE_ERR;
    }
    

    return Local_ErrorState;
}


ErrorState_t MEXTI_enSetCallBack(u8 copy_u8Line, void (*ptrFn)(void))
{
	ErrorState_t Local_ErrorState = OK;

	if (ptrFn != NULL)
	{
		g_CallBacks[copy_u8Line] = ptrFn;
	}
	else
	{
		Local_ErrorState = NULL_POINTER_ERR;
	}

	return Local_ErrorState;
}


void EXTI0_IRQHandler(void)
{
	g_CallBacks[MEXTI_LINE0]();
	SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE0);
}


void EXTI1_IRQHandler(void)
{
	g_CallBacks[MEXTI_LINE1]();
	SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE1);
}


void EXTI2_IRQHandler(void)
{
	g_CallBacks[MEXTI_LINE2]();
	SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE2);
}


void EXTI3_IRQHandler(void)
{
	g_CallBacks[MEXTI_LINE3]();
	SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE3);
}


void EXTI4_IRQHandler(void)
{
	g_CallBacks[MEXTI_LINE4]();
	SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE4);
}

void EXTI9_5_IRQHandler(void)
{
	if( GET_BIT(MEXTI->EXTI_PR, 5) == 1 )
	{
		g_CallBacks[MEXTI_LINE5]();
		SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE5);
	}

	if( GET_BIT(MEXTI->EXTI_PR, 6) == 1 )
	{
		g_CallBacks[MEXTI_LINE6]();
		SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE6);
	}

	if( GET_BIT(MEXTI->EXTI_PR, 7) == 1 )
	{
		g_CallBacks[MEXTI_LINE7]();
		SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE7);
	}

	if( GET_BIT(MEXTI->EXTI_PR, 8) == 1 )
	{
		g_CallBacks[MEXTI_LINE8]();
		SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE8);
	}

	if( GET_BIT(MEXTI->EXTI_PR, 9) == 1 )
	{
		g_CallBacks[MEXTI_LINE9]();
		SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE9);
	}

}

void EXTI15_10_IRQHandler(void)
{
	if( GET_BIT(MEXTI->EXTI_PR, 10) == 1 )
	{
		g_CallBacks[MEXTI_LINE10]();
		SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE10);
	}

	if( GET_BIT(MEXTI->EXTI_PR, 11) == 1 )
	{
		g_CallBacks[MEXTI_LINE11]();
		SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE11);
	}

	if( GET_BIT(MEXTI->EXTI_PR, 12) == 1 )
	{
		g_CallBacks[MEXTI_LINE12]();
		SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE12);
	}

	if( GET_BIT(MEXTI->EXTI_PR, 13) == 1 )
	{
		g_CallBacks[MEXTI_LINE13]();
		SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE13);
	}

	if( GET_BIT(MEXTI->EXTI_PR, 14) == 1 )
	{
		g_CallBacks[MEXTI_LINE14]();
		SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE14);
	}

	if( GET_BIT(MEXTI->EXTI_PR, 15) == 1 )
	{
		g_CallBacks[MEXTI_LINE15]();
		SET_BIT(MEXTI->EXTI_PR, MEXTI_LINE15);
	}

}
