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