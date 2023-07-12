/****************************************************************************/
/* AUTHOR               :     Ahmed Osman                                   */
/* Origin Date          :     11/07/2023                                    */
/* Version              :     1.0.0                                         */
/* SWC                  :     RCC                                           */
/****************************************************************************/

#ifndef RCC_INT_H
#define RCC_INT_H

typedef enum
{

    RCC_AHB_ID,
    RCC_APB2_ID,
    RCC_APB1_ID,

}RCC_BUSS_ID_t;

/****************************************************************************/
/* Enables the clock of specified peripheral.                               */
/*                                                                          */
/* Choose one of the three busses (AHB, APB2, APB1) ID and the pin          */
/* corresponding to the desired perihperal as defined in STM32F103C8 file   */
/****************************************************************************/
void RCC_enablePeripheral(RCC_BUSS_ID_t copy_enBuss, u8 copy_u8Peripheral);


/****************************************************************************/
/* Disables the clock of specified peripheral.                              */
/*                                                                          */
/* Choose one of the three busses (AHB, APB2, APB1) ID and the pin          */
/* corresponding to the desired perihperal as defined in STM32F103C8 file   */
/****************************************************************************/
void RCC_disablePeripheral(RCC_BUSS_ID_t copy_enBussID, u8 copy_u8Peripheral);

#endif