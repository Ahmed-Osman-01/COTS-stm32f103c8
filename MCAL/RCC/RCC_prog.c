/****************************************************************************/
/* AUTHOR               :     Ahmed Osman                                   */
/* Origin Date          :     11/07/2023                                    */
/* Version              :     1.0.0                                         */
/* SWC                  :     RCC                                           */
/****************************************************************************/



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STM32F103C8.h"
#include "RCC_int.h"
#include "RCC_priv.h"
#include "RCC_config.h"

/**
 * @brief Enables the clock of specified peripheral
 * 
 * @param copy_enBussID The ID of the buss containing the peripheral
 * @param copy_u8Peripheral The pin of the peripheral as defined in the STM32F103C8 file
 */
void RCC_enablePeripheral(RCC_BUSS_ID_t copy_enBussID, u8 copy_u8Peripheral)
{
    if(copy_enBussID == RCC_AHB_ID)
    {
        SET_BIT(RCC->RCC_AHBENR, copy_u8Peripheral);
    }
    else if(copy_enBussID == RCC_APB2_ID)
    {
        SET_BIT(RCC->RCC_APB2ENR, copy_u8Peripheral);
    }
    else if(copy_enBussID == RCC_APB1_ID)
    {
        SET_BIT(RCC->RCC_APB1ENR, copy_u8Peripheral);
    }
}

/**
 * @brief Disables the clock of specified peripheral
 * 
 * @param copy_enBussID The ID of the buss containing the peripheral
 * @param copy_u8Peripheral The pin of the peripheral as defined in the STM32F103C8 file
 */
void RCC_disablePeripheral(RCC_BUSS_ID_t copy_enBussID, u8 copy_u8Peripheral)
{
    if(copy_enBussID == RCC_AHB_ID)
    {
        CLR_BIT(RCC->RCC_AHBENR, copy_u8Peripheral);
    }
    else if(copy_enBussID == RCC_APB2_ID)
    {
        CLR_BIT(RCC->RCC_APB2ENR, copy_u8Peripheral);
    }
    else if(copy_enBussID == RCC_APB1_ID)
    {
        CLR_BIT(RCC->RCC_APB1ENR, copy_u8Peripheral);
    }
}