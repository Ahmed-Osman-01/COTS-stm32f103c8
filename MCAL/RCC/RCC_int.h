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
    DMA1  = 0,
    DMA2  = 1,
    SRAM  = 2,
    FLITF = 4,
    CRC   = 6,
    FSMC  = 8,
    SDIO  = 10,

    /*APB1 REG Peripherals (32 to 63)*/
    TIM2   = 32   /*0 + 32*/,
    TIM3   = 33   /*1 + 32*/,
    TIM4   = 34   /*2 + 32*/,
    TIM5   = 35   /*3 + 32*/,
    TIM6   = 36   /*4 + 32*/,
    TIM7   = 37   /*5 + 32*/,
    TIM12  = 38   /*6 + 32*/,
    TIM13  = 39   /*7 + 32*/,
    TIM14  = 40   /*8 + 32*/,
    WWDG   = 42   /*11 + 32*/,
    SPI2   = 46   /*14 + 32*/,
    SPI3   = 47   /*15 + 32*/,
    USART2 = 49   /*17 + 32*/,
    USART3 = 50   /*18 + 32*/,
    USART4 = 51   /*19 + 32*/,
    USART5 = 52   /*20 + 32*/,
    I2C1   = 53   /*21 + 32*/,
    I2C2   = 54   /*22 + 32*/,
    USB    = 55   /*23 + 32*/,
    CAN    = 57   /*25 + 32*/,
    BKP    = 59   /*27 + 32*/,
    PWR    = 60   /*28 + 32*/,
    DAC    = 61   /*29 + 32*/,

    /*APB2 REG Peripherals (64 to 95)*/
    AFIO   = 64   /*0 + 64*/,
    IOPA   = 66   /*2 + 64*/,
    IOPB   = 67   /*3 + 64*/,
    IOPC   = 68   /*4 + 64*/,
    IOPD   = 69   /*5 + 64*/,
    IOPE   = 70   /*6 + 64*/,
    IOPF   = 71   /*7 + 64*/,
    IOPG   = 72   /*8 + 64*/,
    ADC1   = 73   /*9 + 64*/,
    ADC2   = 74   /*10 + 64*/,
    TIM1   = 75   /*11 + 64*/,
    SPI1   = 76   /*12 + 64*/,
    TIM8   = 77   /*13 + 64*/,
    USART1 = 78   /*14 + 64*/,
    ADC3   = 79   /*15 + 64*/,
    TIM9   = 83   /*19 + 64*/,
    TIM10  = 84   /*20 + 64*/,
    TIM11  = 85   /*21 + 64*/,

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