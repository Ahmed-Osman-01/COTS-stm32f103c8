/****************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                               */
/* Origin Date          :     11/07/2023                                                */
/* Version              :     1.0.0                                                     */
/* Modification         :                                                               */
/*         1- 12/07/2023 -> Added InitSystemClock function and added peripherals ID enum*/
/* SWC                  :     RCC                                                       */
/****************************************************************************************/

#ifndef RCC_INT_H
#define RCC_INT_H

typedef enum
{
    /*AHB REG Peripherals (0 to 31)*/
    RCC_DMA1  = 0,
    RCC_DMA2  = 1,
    RCC_SRAM  = 2,
    RCC_FLITF = 4,
    RCC_CRC   = 6,
    RCC_FSMC  = 8,
    RCC_SDIO  = 10,

    /*APB1 REG Peripherals (32 to 63)*/
    RCC_TIM2   = 32   /*0 + 32*/,
    RCC_TIM3   = 33   /*1 + 32*/,
    RCC_TIM4   = 34   /*2 + 32*/,
    RCC_TIM5   = 35   /*3 + 32*/,
    RCC_TIM6   = 36   /*4 + 32*/,
    RCC_TIM7   = 37   /*5 + 32*/,
    RCC_TIM12  = 38   /*6 + 32*/,
    RCC_TIM13  = 39   /*7 + 32*/,
    RCC_TIM14  = 40   /*8 + 32*/,
    RCC_WWDG   = 42   /*11 + 32*/,
    RCC_SPI2   = 46   /*14 + 32*/,
    RCC_SPI3   = 47   /*15 + 32*/,
    RCC_USART2 = 49   /*17 + 32*/,
    RCC_USART3 = 50   /*18 + 32*/,
    RCC_USART4 = 51   /*19 + 32*/,
    RCC_USART5 = 52   /*20 + 32*/,
    RCC_I2C1   = 53   /*21 + 32*/,
    RCC_I2C2   = 54   /*22 + 32*/,
    RCC_USB    = 55   /*23 + 32*/,
    RCC_CAN    = 57   /*25 + 32*/,
    RCC_BKP    = 59   /*27 + 32*/,
    RCC_PWR    = 60   /*28 + 32*/,
    RCC_DAC    = 61   /*29 + 32*/,

    /*APB2 REG Peripherals (64 to 95)*/
    RCC_AFIO   = 64   /*0 + 64*/,
    RCC_IOPA   = 66   /*2 + 64*/,
    RCC_IOPB   = 67   /*3 + 64*/,
    RCC_IOPC   = 68   /*4 + 64*/,
    RCC_IOPD   = 69   /*5 + 64*/,
    RCC_IOPE   = 70   /*6 + 64*/,
    RCC_IOPF   = 71   /*7 + 64*/,
    RCC_IOPG   = 72   /*8 + 64*/,
    RCC_ADC1   = 73   /*9 + 64*/,
    RCC_ADC2   = 74   /*10 + 64*/,
    RCC_TIM1   = 75   /*11 + 64*/,
    RCC_SPI1   = 76   /*12 + 64*/,
    RCC_TIM8   = 77   /*13 + 64*/,
    RCC_USART1 = 78   /*14 + 64*/,
    RCC_ADC3   = 79   /*15 + 64*/,
    RCC_TIM9   = 83   /*19 + 64*/,
    RCC_TIM10  = 84   /*20 + 64*/,
    RCC_TIM11  = 85   /*21 + 64*/,

}RCC_PERIPHERALS_ID_t;


/****************************************************************************/
/* Initializes the system clock through the RCC CR & CFGR registers         */
/*                                                                          */
/* Chooses external high speed mechanical, external bypass high speed (RC), */
/* internal high speed or PLL as the system clock as configured in the      */
/* configuration file.                                                      */
/* If PLL is chosen, the input clock type and mult factor is also configured*/
/****************************************************************************/
void RCC_voidInitSystemClock(void);

/****************************************************************************/
/* Enables the clock of specified peripheral.                               */
/*                                                                          */
/* Peripheral id is mapped for each enable register                         */
/****************************************************************************/
u8 RCC_voidEnablePeripheralClk(RCC_PERIPHERALS_ID_t Copy_enPeripheral);


/****************************************************************************/
/* Disables the clock of specified peripheral.                              */
/*                                                                          */
/* Peripheral id is mapped for each enable register                         */
/****************************************************************************/
u8 RCC_voidDisablePeripheralClk(RCC_PERIPHERALS_ID_t Copy_enPeripheral);

#endif