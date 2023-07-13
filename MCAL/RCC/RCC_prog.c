/****************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                               */
/* Origin Date          :     11/07/2023                                                */
/* Version              :     1.0.1                                                     */
/* Modification         :                                                               */
/*      1- 12/07/2023 -> Implemented InitSystemClock and modified enablePeripheralClk   */
/*                     to take only peripheral ID as argument.                          */
/* SWC                  :     RCC                                                       */
/****************************************************************************************/



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STM32F103C8.h"
#include "RCC_int.h"
#include "RCC_priv.h"
#include "RCC_config.h"



void RCC_voidInitSystemClock(void)
{
    #if RCC_u8CLK_TYPE == RCC_u8HSE_CRYSTAL
        RCC-> RCC_CR = 0x00010080;
        RCC -> RCC_CFGR = 0x00000001;

    #elif RCC_u8CLK_TYPE == RCC_u8HSE_RC
        RCC-> RCC_CR = 0x00050080;
        RCC -> RCC_CFGR = 0x00000001;

    #elif RCC_u8CLK_TYPE == RCC_u8HSI
        RCC-> RCC_CR = 0x00000081;
        RCC -> RCC_CFGR = 0x00000000;

    #elif RCC_u8CLK_TYPE == RCC_u8PLL

        /************************************************************************************************
        * Set the PLL clock input and mul value bits in CFGR first before enabling PLL from CS register
        * as told in the datasheet
        ************************************************************************************************/

        /* Select PLL as system clock*/
        RCC -> RCC_CFGR = 0x00000002;

        /* Clear the PLLSRC & PLLXTPRE bits */
        RCC -> RCC_CFGR &= (0xFFFFFFFC << 16);
        /*Aplly the configured PLL input values (PLLSRC & PLLXTPRE) bits*/
        RCC -> RCC_CFGR |= (RCC_u8PLL_INPUT << 16);

        // ########## which method for clearing bits is better? ###############

        /* Clear the mul bits by applying mask */
        RCC -> RCC_CFGR &= RCC_u8PLL_MUL_MSK;
        /* Apply the configured mul value */
        RCC -> RCC_CFGR |= (RCC_u8PLL_MUL_VAL << 18);

        /* Enable PLL */
        #if RCC_u8PLL_INPUT == RCC_u8PLL_HSI_DIV_2
            RCC-> RCC_CR = 0x01000081;
            
        #else
            // is there a better way to check for external clock type for pll ?
            #if RCC_u8PLL_EXTERNAL_CLK_TYPE == RCC_u8PLL_HSE_CRYSTAL
                RCC-> RCC_CR = 0x01010080;

            #elif RCC_u8PLL_EXTERNAL_CLK_TYPE == RCC_u8PLL_HSE_RC
                 RCC-> RCC_CR = 0x01050080;

            #endif

        #endif

    #else
        #error ("Wrong CLK type")
    #endif
}



/**
 * @brief Enables the clock of specified peripheral
 * 
 * @param copy_enPeripheral The peripheral id.
 */
u8 RCC_voidEnablePeripheralClk(RCC_PERIPHERALS_ID_t Copy_enPeripheralID)
{
    u8 Local_u8ErrorState = OK;

   /****************************************************************************
     * The three registers AHB, APB1 & APB2 are 32 bits each so in order to 
     * use only the pepipheral id as parameter we imagine as if the 3 registers
     * are one big 96 bits imaginary register.
     * AHB bits ranges from 0 to 31
     * APB1 bits ranges from 32 to 63
     * APB2 bits ranges from 64 to 95
     * 
     * The peripheral id maps to the corresponding periheral bit
     *      in case of AHB  Copy_enPeripheralID        = peripheral bit
     *      in case of APB1 (Copy_enPeripheralID - 32) = peripheral bit
     *      in case of APB2 (Copy_enPeripheralID - 64) = peripheral bit
    ****************************************************************************/
    if( (Copy_enPeripheralID >= 0) && (Copy_enPeripheralID <= 31) )
    {
        SET_BIT(RCC->RCC_AHBENR, Copy_enPeripheralID); 
    }
    else if( (Copy_enPeripheralID >= 32) && (Copy_enPeripheralID <= 63) )
    {
        SET_BIT(RCC->RCC_APB1ENR, Copy_enPeripheralID - 32); 
    }
    else if( (Copy_enPeripheralID >= 64) && (Copy_enPeripheralID <= 95) )
    {
        SET_BIT(RCC->RCC_APB2ENR, Copy_enPeripheralID - 64); 
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}

/**
 * @brief Disables the clock of specified peripheral
 * 
 * @param copy_enPeripheral The peripheral id.
 */
u8 RCC_voidDisablePeripheralClk(RCC_PERIPHERALS_ID_t Copy_enPeripheralID)
{
    u8 Local_u8ErrorState = OK;

   /****************************************************************************
     * The three registers AHB, APB1 & APB2 are 32 bits each so in order to 
     * use only the pepipheral id as parameter we imagine as if the 3 registers
     * are one big 96 bits imaginary register.
     * AHB bits ranges from 0 to 31
     * APB1 bits ranges from 32 to 63
     * APB2 bits ranges from 64 to 95
     * 
     * The peripheral id maps to the corresponding periheral bit
     *      in case of AHB  Copy_enPeripheralID        = peripheral bit
     *      in case of APB1 (Copy_enPeripheralID - 32) = peripheral bit
     *      in case of APB2 (Copy_enPeripheralID - 64) = peripheral bit
    ****************************************************************************/
    if( (Copy_enPeripheralID >= 0) && (Copy_enPeripheralID <= 31) )
    {
        CLR_BIT(RCC->RCC_AHBENR, Copy_enPeripheralID); 
    }
    else if( (Copy_enPeripheralID >= 32) && (Copy_enPeripheralID <= 63) )
    {
        CLR_BIT(RCC->RCC_APB1ENR, Copy_enPeripheralID - 32); 
    }
    else if( (Copy_enPeripheralID >= 64) && (Copy_enPeripheralID <= 95) )
    {
        CLR_BIT(RCC->RCC_APB2ENR, Copy_enPeripheralID - 64); 
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}