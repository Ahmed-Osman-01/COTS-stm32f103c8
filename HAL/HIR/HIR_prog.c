/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     1/08/2023                                                             */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     IR Reciever                                                           */
/****************************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STM32F103C8.h"
#include "../../LIB/BIT_MATH.h"


#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/MAFIO/MAFIO_int.h"
#include "../../MCAL/MSTK/MSTK_int.h"
#include "../../MCAL/MEXTI/MEXTI_int.h"

#include "HIR_int.h"
#include "HIR_priv.h"
#include "HIR_config.h"

static u8 g_u8StartBitFlag = 0;                             /* Indicates that starting bit is detected                      */
static volatile u16 g_u16Frame[50] = {0};                   /* Array of times corresponding to the sent frame which later
                                                                is translated into 0s and 1s                                */
static volatile u8 g_u8FrameIndex = 0;                      /* Index to keep track where to add the next frame element      */
static volatile u8 g_u8Data = HIR_GARBAGE_NUMBER;           /* Data extracted from the frame                                */
static volatile u8 g_u8ReverseData = HIR_GARBAGE_NUMBER;    /* Reverse Data extracted from the frame                        */
static volatile u8 g_u8Address = HIR_GARBAGE_NUMBER;        /* Address extracted from the frame                             */
static volatile u8 g_u8ReverseAddress = HIR_GARBAGE_NUMBER; /* Reverse Address extracted from the frame                     */
static void (*Callback)(void) = NULL;                       /* Function to be called after frame transmission completes     */


void HIR_enInit(u8 copy_u8Port, u8 copy_u8Pin)
{
    GPIO_u8SetPinMode(copy_u8Port, copy_u8Pin, GPIO_u8INPUT_FLOATING);

    MAFIO_enEXTIMap(copy_u8Pin, copy_u8Port);


    MEXTI_enSetCallBack(copy_u8Pin ,HIR_voidBuildFrame);
    MEXTI_u8EnableInterrupt(copy_u8Pin);
    MEXTI_u8SetInterruptTrigger(copy_u8Pin, MEXTI_FALLING_EDGE);

}

static void HIR_voidBuildFrame(void)
{
    if(g_u8StartBitFlag == 0)
    {
        MSTK_SetIntervalSingle(100000, HIR_voidTakeAction);
        g_u8StartBitFlag = 1;
    }
    else
    {
        MSTK_GetElapsedTicks(&g_u16Frame[g_u8FrameIndex]);
        MSTK_SetIntervalSingle(100000, HIR_voidTakeAction);
        g_u8FrameIndex++;
    }

}

ErrorState_t HIR_enGetAddress(u8 * ptr_ReturnValue)
{
    ErrorState_t Local_ErrorState = OK;

    if(ptr_ReturnValue != NULL)
    {
        *ptr_ReturnValue = g_u8Address;
        // g_u8Address = HIR_GARBAGE_NUMBER;
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }
    return Local_ErrorState;
}


ErrorState_t HIR_enGetData(u8 * ptr_ReturnValue)
{
    ErrorState_t Local_ErrorState = OK;

    if(ptr_ReturnValue != NULL)
    {
        *ptr_ReturnValue = g_u8Data;
        // g_u8Data = HIR_GARBAGE_NUMBER;
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}


ErrorState_t HIR_SetCallback(void (*ptrFn)(void))
{
    ErrorState_t Local_ErrorState = OK;

    if(ptrFn != NULL)
    {
        Callback = ptrFn;
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}

static void HIR_voidTakeAction(void)
{
    u8 i;

    if( (g_u16Frame[0] >= 10000) && (g_u16Frame[0] < 15000) )
    {
        HIR_voidExtractAddress();
        HIR_voidExtractReverseAddress();

        HIR_voidExtractData();
        HIR_voidExtractReverseData();

        HIR_voidCheckAddressAndData();

        if(Callback != NULL)
        {
            Callback();
        }else{/* do nothing */}

    }
    else
    {
        /* do nothing */
    }

   g_u8FrameIndex = 0;
   g_u8StartBitFlag = 0;
}


static void HIR_voidExtractAddress(void)
{
    u8 i;

    for(i = 0; i < 8; i ++)
    {
        if( (g_u16Frame[1 + i] >= 2000) && (g_u16Frame[1 + i] < 2300 ) )
        {
            SET_BIT(g_u8Address, i);
        }
        else
        {
            CLR_BIT(g_u8Address, i);
        }
    }
}

static void HIR_voidExtractReverseAddress(void)
{
    u8 i;

    for(i = 0; i < 8; i ++)
    {
        if( (g_u16Frame[9 + i] >= 2000) && (g_u16Frame[9 + i] < 2300 ) )
        {
            SET_BIT(g_u8ReverseAddress, i);
        }
        else
        {
            CLR_BIT(g_u8ReverseAddress, i);
        }
    }
}


static void HIR_voidExtractData(void)
{
    u8 i;

    for(i = 0; i < 8; i ++)
    {
        if( (g_u16Frame[17 + i] >= 2000) && (g_u16Frame[17 + i] < 2300 ) )
        {
            SET_BIT(g_u8Data, i);
        }
        else
        {
            CLR_BIT(g_u8Data, i);
        }
    }
}

static void HIR_voidExtractReverseData(void)
{
    u8 i;

    for(i = 0; i < 8; i ++)
    {
        if( (g_u16Frame[25 + i] >= 2000) && (g_u16Frame[25 + i] < 2300 ) )
        {
            SET_BIT(g_u8ReverseData, i);
        }
        else
        {
            CLR_BIT(g_u8ReverseData, i);
        }
    }
}


static void HIR_voidCheckAddressAndData(void)
{
    if( (g_u8Address & g_u8ReverseAddress) != 0)
    {
        g_u8Address = HIR_GARBAGE_NUMBER;
        g_u8Data = HIR_GARBAGE_NUMBER;
    }
    else if( (g_u8Data & g_u8ReverseData) != 0)
    {
        g_u8Data = HIR_GARBAGE_NUMBER;
    }
    else
    {
        /* do nothing */
    }
}
