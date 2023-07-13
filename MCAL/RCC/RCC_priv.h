/****************************************************************************/
/* AUTHOR               :     Ahmed Osman                                   */
/* Origin Date          :     12/07/2023                                    */
/* Version              :     1.0.0                                         */
/* SWC                  :     RCC                                           */
/****************************************************************************/


#ifndef RCC_PRIV_H
#define RCC_PRIV_H


/*System clock*/
#define RCC_u8HSE_CRYSTAL   0
#define RCC_u8HSE_RC        1
#define RCC_u8HSI           2
#define RCC_u8PLL           3

/*PLL input clocks*/
#define RCC_u8PLL_HSI_DIV_2  0
#define RCC_u8PLL_HSE        1
#define RCC_u8PLL_HSE_DIV_2  3

/* PLL external clock type*/
#define RCC_u8PLL_HSE_RC          10
#define RCC_u8PLL_HSE_CRYSTAL     20

/*PLL mul values*/
#define RCC_u8PLL_MUL_2      0
#define RCC_u8PLL_MUL_3      1
#define RCC_u8PLL_MUL_4      2
#define RCC_u8PLL_MUL_5      3
#define RCC_u8PLL_MUL_6      4
#define RCC_u8PLL_MUL_7      5
#define RCC_u8PLL_MUL_8      6
#define RCC_u8PLL_MUL_9      7
#define RCC_u8PLL_MUL_10     8
#define RCC_u8PLL_MUL_11     9
#define RCC_u8PLL_MUL_12     10
#define RCC_u8PLL_MUL_13     11
#define RCC_u8PLL_MUL_14     12
#define RCC_u8PLL_MUL_15     13
#define RCC_u8PLL_MUL_16     14
#define RCC_u8PLL_MUL_16     15

/*Mask for clearing PLL MUL bits in CFGR*/
#define RCC_u8PLL_MUL_MSK   0xFFC3FFFF

#endif