/****************************************************************************/
/* AUTHOR               :     Ahmed Osman                                   */
/* Origin Date          :     12/07/2023                                    */
/* Version              :     1.0.0                                         */
/* SWC                  :     RCC                                           */
/****************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/****************************************************************************
 * @brief Configure the system clock type
 * 
 * Options:
 *      1- RCC_u8HSE_CRYSTAL
 *      2- RCC_u8HSE_RC
 *      3- RCC_u8HSI
 *      4- RCC_u8PLL
****************************************************************************/
#define RCC_u8CLK_TYPE  RCC_u8HSI


#if RCC_u8CLK_TYPE == RCC_u8PLL

/****************************************************************************
 * @brief Configure the pll input clock
 * 
 * Options:
 *      1- RCC_u8PLL_HSI_DIV_2
 *      2- RCC_u8PLL_HSE
 *      3- RCC_u8PLL_HSE_DIV_2
****************************************************************************/
#define RCC_u8PLL_INPUT  RCC_u8PLL_HSI_DIV_2


/****************************************************************************
 * @brief Configure the pll Multiplication value
 * 
 * Options:
 *     1- RCC_u8PLL_MUL_2    
 *     2- RCC_u8PLL_MUL_3    
 *     3- RCC_u8PLL_MUL_4    
 *     4- RCC_u8PLL_MUL_5    
 *     5- RCC_u8PLL_MUL_6    
 *     6- RCC_u8PLL_MUL_7    
 *     7- RCC_u8PLL_MUL_8    
 *     8- RCC_u8PLL_MUL_9    
 *     9- RCC_u8PLL_MUL_10   
 *     10- RCC_u8PLL_MUL_11   
 *     11- RCC_u8PLL_MUL_12   
 *     12- RCC_u8PLL_MUL_13   
 *     13- RCC_u8PLL_MUL_14   
 *     14- RCC_u8PLL_MUL_15   
 *     15- RCC_u8PLL_MUL_16   
 *     16- RCC_u8PLL_MUL_16   
****************************************************************************/
#define RCC_u8PLL_MUL_VAL  RCC_u8PLL_MUL_4

#if RCC_u8PLL_INPUT != RCC_u8PLL_HSI_DIV_2
/****************************************************************************
 * In case External clock is choses as PLL input clock
 * 
 * Options:
 *      1- RCC_u8PLL_HSE_RC
 *      2- RCC_u8PLL_HSE_CRYSTAL
 ****************************************************************************/
#define RCC_u8PLL_EXTERNAL_CLK_TYPE     RCC_u8PLL_HSE_CRYSTAL

#endif /*End of External clock type check for PLL*/

#endif /*End of check for PLL is the system clock*/



#endif 