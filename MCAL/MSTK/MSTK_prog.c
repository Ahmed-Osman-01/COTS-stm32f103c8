/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     25/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     SysTick                                                               */
/****************************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STM32F103C8.h"
#include "../../LIB/BIT_MATH.h"

#include "MSTK_int.h"
#include "MSTK_priv.h"
#include "MSTK_config.h"


static u8 g_u8TimerMode;

static void (*Callback)(void) = NULL;


void MSTK_Init(void)
{
    MSTK->STK_CTRL = STK_MODE;
}

ErrorState_t MSTK_SetBusyWait(u32 copy_u32DelayMicroSec)
{
    u8 Local_ErrorState = OK;

    /* Disable interrupt */
    CLR_BIT(MSTK->STK_CTRL, 1);

    if(copy_u32DelayMicroSec < MAX_TICK_COUNT)
    {
        /* Set the load register value */
        #if STK_MODE == STK_CLK_AHB_DIV_8
            MSTK->STK_LOAD = copy_u32DelayMicroSec - 1;
        #elif STK_MODE == STK_CLK_AHB
            MSTK->STK_LOAD = (8 * copy_u32DelayMicroSec) - 1;
        #endif

        /* Start timer */
        SET_BIT(MSTK->STK_CTRL, 0);

        /* Busy wait till the counting finish */
        while( GET_BIT(MSTK->STK_CTRL, 16) == 0){};

        /* Stop the timer after time elapses */
        MSTK_StopTimer();
    }
    else
    {
        Local_ErrorState = NOK;
    }

    return Local_ErrorState;
}


ErrorState_t MSTK_SetIntervalSingle(u32 copy_u32DelayMicroSec, void (*ptrFn)(void) )
{

    ErrorState_t Local_ErrorState = OK;

    /* Stop the timer first in case it was already working */
    MSTK_StopTimer();

    Callback = ptrFn;
    g_u8TimerMode = SINGLE;

    /* Enable interrupt */
    SET_BIT(MSTK->STK_CTRL, 1);

    if(copy_u32DelayMicroSec <= MAX_TICK_COUNT)
    {
       /* Set the load register value */
        #if STK_MODE == STK_CLK_AHB_DIV_8
            MSTK->STK_LOAD = copy_u32DelayMicroSec - 1;
        #elif STK_MODE == STK_CLK_AHB
            MSTK->STK_LOAD = (8 * copy_u32DelayMicroSec) - 1;
        #endif
    }
    else
    {
        Local_ErrorState = NOK;
    }

    /* Start timer */
    SET_BIT(MSTK->STK_CTRL, 0);

    return Local_ErrorState;

}

ErrorState_t MSTK_SetIntervalPeriodic(u32 copy_u32DelayMicroSec, void (*ptrFn)(void) )
{
    ErrorState_t Local_ErrorState = OK;

    Callback = ptrFn;
    g_u8TimerMode = PERIODIC;

    /* Enable interrupt */
    SET_BIT(MSTK->STK_CTRL, 1);

    if(copy_u32DelayMicroSec <= MAX_TICK_COUNT)
    {
       /* Set the load register value */
        #if STK_MODE == STK_CLK_AHB_DIV_8
            MSTK->STK_LOAD = copy_u32DelayMicroSec - 1;
        #elif STK_MODE == STK_CLK_AHB
            MSTK->STK_LOAD = (8 * copy_u32DelayMicroSec) - 1;
        #endif
    }
    else
    {
        Local_ErrorState = NOK;
    }

    /* Start timer */
    SET_BIT(MSTK->STK_CTRL, 0);

    return Local_ErrorState;
}

void MSTK_StopTimer(void)
{
    CLR_BIT(MSTK->STK_CTRL, 0);
    MSTK->STK_LOAD = 0;
    MSTK->STK_VAL = 0;
}

ErrorState_t MSTK_GetElapsedTicks(u32 * ptr_ReturnValue)
{
    ErrorState_t Local_ErrorState = OK;

    if( ptr_ReturnValue != NULL)
    {
        *ptr_ReturnValue = MSTK->STK_LOAD - MSTK->STK_VAL;
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}

ErrorState_t MSTK_GetRemainingTicks(u32 * ptr_ReturnValue)
{
   ErrorState_t Local_ErrorState = OK;

    if( ptr_ReturnValue != NULL)
    {
        *ptr_ReturnValue = MSTK->STK_VAL;
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}


void SysTick_Handler(void)
{    
    Callback();

    if(g_u8TimerMode == SINGLE)
    {
        MSTK_StopTimer();
    }
    else{/* do nothing */}
   
}