/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     19/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     NVIC                                                                  */
/****************************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STM32F103C8.h"

#include "MNVIC_int.h"
#include "MNVIC_config.h"
#include "MNVIC_priv.h"


ErrorState_t MNVIC_enInitNVIC(void)
{
    ErrorState_t Local_ErrorState = OK;

    #if( (BINARY_POINT >= 3) && (BINARY_POINT <= 7) )
    
        MSCB->SCB_AIRCR = (MSCB_AIRCR_KEY) | (BINARY_POINT << MSCB_AIRCR_PRIGROUP_START_BIT);
    
    #else
    
       #error ("Binary point out of range") 
    
    #endif

    return Local_ErrorState;
}

ErrorState_t MNVIC_enEnableInterrupt(MNVIC_External_Interrupt_Number_t copy_enInterruptNumber)
{
    // ErrorState_t Local_ErrorState = OK;

    // if (copy_enInterruptNumber < 32)
    // {
    //     MNVIC->NVIC_ISER[0] = 1 << copy_enInterruptNumber;
    // }
    // else if (copy_enInterruptNumber < 64)
    // {
    //     copy_enInterruptNumber -= 32;
    //     MNVIC->NVIC_ISER[1] = 1 << copy_enInterruptNumber;
    // }
    // else if (copy_enInterruptNumber < 68)
    // {
    //     copy_enInterruptNumber -= 64;
    //     MNVIC->NVIC_ISER[2] = 1 << copy_enInterruptNumber;
    // }
    // else
    // {
    //     Local_ErrorState = OUT_OF_RANGE_ERR;
    // }


    u8 Local_u8RegisterNumber = copy_enInterruptNumber / 32;
    copy_enInterruptNumber = copy_enInterruptNumber % 32;  /* Map it into the bit number of the register */

    if(copy_enInterruptNumber >= 0 && copy_enInterruptNumber < 68)
    {
       MNVIC->NVIC_ISER[Local_u8RegisterNumber] = 1 << copy_enInterruptNumber;
    }
    else
    {
        Local_ErrorState = OUT_OF_RANGE_ERR;
    }


    return Local_ErrorState;
}


ErrorState_t MNVIC_enDisableInterrupt(MNVIC_External_Interrupt_Number_t copy_enInterruptNumber)
{
    // ErrorState_t Local_ErrorState = OK;

    // if (copy_enInterruptNumber < 32)
    // {
    //     MNVIC->NVIC_ICER[0] = 1 << copy_enInterruptNumber;
    // }
    // else if (copy_enInterruptNumber < 64)
    // {
    //     copy_enInterruptNumber -= 32;
    //     MNVIC->NVIC_ICER[1] = 1 << copy_enInterruptNumber;
    // }
    // else if (copy_enInterruptNumber < 68)
    // {
    //     copy_enInterruptNumber -= 64;
    //     MNVIC->NVIC_ICER[2] = 1 << copy_enInterruptNumber;
    // }
    // else
    // {
    //     Local_ErrorState = OUT_OF_RANGE_ERR;
    // }


    u8 Local_u8RegisterNumber = copy_enInterruptNumber / 32;
    copy_enInterruptNumber = copy_enInterruptNumber % 32;  /* Map it into the bit number of the register */

    if(copy_enInterruptNumber >= 0 && copy_enInterruptNumber < 68)
    {
       MNVIC->NVIC_ICER[Local_u8RegisterNumber] = 1 << copy_enInterruptNumber;
    }
    else
    {
        Local_ErrorState = OUT_OF_RANGE_ERR;
    }


    return Local_ErrorState;
}


ErrorState_t MNVIC_enSetInterruptPending(MNVIC_External_Interrupt_Number_t copy_enInterruptNumber)
{
    ErrorState_t Local_ErrorState = OK;

    // if (copy_enInterruptNumber < 32)
    // {
    //     MNVIC->NVIC_ISPR[0] = 1 << copy_enInterruptNumber;
    // }
    // else if (copy_enInterruptNumber < 64)
    // {
    //     copy_enInterruptNumber -= 32;
    //     MNVIC->NVIC_ISPR[1] = 1 << copy_enInterruptNumber;
    // }
    // else if (copy_enInterruptNumber < 68)
    // {
    //     copy_enInterruptNumber -= 64;
    //     MNVIC->NVIC_ISPR[2] = 1 << copy_enInterruptNumber;
    // }
    // else
    // {
    //     Local_ErrorState = OUT_OF_RANGE_ERR;
    // }


    u8 Local_u8RegisterNumber = copy_enInterruptNumber / 32;
    copy_enInterruptNumber = copy_enInterruptNumber % 32;  /* Map it into the bit number of the register */

    if(copy_enInterruptNumber >= 0 && copy_enInterruptNumber < 68)
    {
       MNVIC->NVIC_ISPR[Local_u8RegisterNumber] = 1 << copy_enInterruptNumber;
    }
    else
    {
        Local_ErrorState = OUT_OF_RANGE_ERR;
    }


    return Local_ErrorState;
}


ErrorState_t MNVIC_enClearInterruptPending(MNVIC_External_Interrupt_Number_t copy_enInterruptNumber)
{
    ErrorState_t Local_ErrorState = OK;

    // if (copy_enInterruptNumber < 32)
    // {
    //     MNVIC->NVIC_ICPR[0] = 1 << copy_enInterruptNumber;
    // }
    // else if (copy_enInterruptNumber < 64)
    // {
    //     copy_enInterruptNumber -= 32;
    //     MNVIC->NVIC_ICPR[1] = 1 << copy_enInterruptNumber;
    // }
    // else if (copy_enInterruptNumber < 68)
    // {
    //     copy_enInterruptNumber -= 64;
    //     MNVIC->NVIC_ICPR[2] = 1 << copy_enInterruptNumber;
    // }
    // else
    // {
    //     Local_ErrorState = OUT_OF_RANGE_ERR;
    // }


    u8 Local_u8RegisterNumber = copy_enInterruptNumber / 32;
    copy_enInterruptNumber = copy_enInterruptNumber % 32;  /* Map it into the bit number of the register */

    if(copy_enInterruptNumber >= 0 && copy_enInterruptNumber < 68)
    {
       MNVIC->NVIC_ICPR[Local_u8RegisterNumber] = 1 << copy_enInterruptNumber;
    }
    else
    {
        Local_ErrorState = OUT_OF_RANGE_ERR;
    }

    return Local_ErrorState;
}

ErrorState_t MNVIC_enGetActiveStatus(MNVIC_External_Interrupt_Number_t copy_enInterruptNumber, u8 * ptr_ReturnState)
{
    ErrorState_t Local_ErrorState = OK;

    // if (copy_enInterruptNumber < 32)
    // {
    //     *ptr_ReturnState = GET_BIT(MNVIC-> NVIC_IABR[0], copy_enInterruptNumber);
    // }
    // else if (copy_enInterruptNumber < 64)
    // {
    //     copy_enInterruptNumber -= 32;
    //     *ptr_ReturnState = GET_BIT(MNVIC-> NVIC_IABR[1], copy_enInterruptNumber);
    // }
    // else if (copy_enInterruptNumber < 68)
    // {
    //     copy_enInterruptNumber -= 64;
    //     *ptr_ReturnState = GET_BIT(MNVIC-> NVIC_IABR[2], copy_enInterruptNumber);
    // }
    // else
    // {
    //     Local_ErrorState = OUT_OF_RANGE_ERR;
    // }


    u8 Local_u8RegisterNumber = copy_enInterruptNumber / 32;
    copy_enInterruptNumber = copy_enInterruptNumber % 32;  /* Map it into the bit number of the register */

    if(copy_enInterruptNumber >= 0 && copy_enInterruptNumber < 68)
    {
       *ptr_ReturnState = GET_BIT(MNVIC-> NVIC_IABR[Local_u8RegisterNumber], copy_enInterruptNumber);
    }
    else
    {
        Local_ErrorState = OUT_OF_RANGE_ERR;
    }


    return Local_ErrorState;
}


ErrorState_t MNCIV_enSetInterruptPeriority( MNVIC_External_Interrupt_Number_t copy_enInterruptNumber,
                                            u8 copy_u8GroupPeriotity,
                                            u8 copy_u8SubPeriority )
{
    ErrorState_t Local_ErrorState = OK;

    if( (copy_enInterruptNumber >= 0) && (copy_enInterruptNumber < 68) )
    {
        #if BINARY_POINT == GROUP_4_SUB_0

            if( (copy_u8GroupPeriotity >= 0) && (copy_u8GroupPeriotity < 16) 
                    &&
                copy_u8SubPeriority == 0 )
            {
                MNVIC->NVIC_IPR[copy_enInterruptNumber] = copy_u8GroupPeriotity << 4;
            }
            else
            {
                Local_ErrorState = NOK;
            }

        #elif BINARY_POINT == GROUP_3_SUB_1

            if( (copy_u8GroupPeriotity >= 0) && (copy_u8GroupPeriotity < 8 )
                    &&
                (copy_u8SubPeriority   >= 0) && (copy_u8SubPeriority   < 2) )
            {
                MNVIC->NVIC_IPR[copy_enInterruptNumber] = (copy_u8GroupPeriotity << 5) | (copy_u8SubPeriority << 4);
            }
            else
            {
                Local_ErrorState = NOK;
            }

        #elif BINARY_POINT == GROUP_2_SUB_2

            if( (copy_u8GroupPeriotity >= 0) && (copy_u8GroupPeriotity < 4) 
                    &&
                (copy_u8SubPeriority   >= 0) && (copy_u8SubPeriority   < 4) )
            {
                MNVIC->NVIC_IPR[copy_enInterruptNumber] = (copy_u8GroupPeriotity << 6) | (copy_u8SubPeriority << 4);
            }
            else
            {
                Local_ErrorState = NOK;
            }

        #elif BINARY_POINT == GROUP_1_SUB_3

          if( (copy_u8GroupPeriotity >= 0) && (copy_u8GroupPeriotity < 2) 
                    &&
              (copy_u8SubPeriority   >= 0) && (copy_u8SubPeriority   < 8) )
            {
                MNVIC->NVIC_IPR[copy_enInterruptNumber] = (copy_u8GroupPeriotity << 7) | (copy_u8SubPeriority << 4);
            }
            else
            {
                Local_ErrorState = NOK;
            }  

        #elif BINARY_POINT == GROUP_0_SUB_4

            if( (copy_u8GroupPeriotity == 0)
                    &&
                (copy_u8SubPeriority   >= 0) && (copy_u8SubPeriority   < 16) )
            {
                MNVIC->NVIC_IPR[copy_enInterruptNumber] = (copy_u8SubPeriority << 4);
            }
            else
            {
                Local_ErrorState = NOK;
            }

        #endif
    }
    else
    {
        Local_ErrorState = OUT_OF_RANGE_ERR;
    }

    return Local_ErrorState;
}