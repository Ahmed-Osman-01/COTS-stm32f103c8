/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     26/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     8x8 LED Matrix Display                                                */
/****************************************************************************************************/

#ifndef HLEDMRX_CONFIG_H
#define HLEDMRX_CONFIG_H


/****************************************************************************************************/
/* NOTE: DON'T SET PINS A13, A14, A15, B3, B4 as they are used by default by JTAG/SWD               */
/****************************************************************************************************/

/****************************************************************************************************/
/* Configure the GPIO_PORT & GPIO_PIN pair for each Row to be used it in the GPIO Functions directly*/
/****************************************************************************************************/
#define HLEDMRX_u8ROW0      GPIO_u8PORTA, GPIO_u8PIN0
#define HLEDMRX_u8ROW1      GPIO_u8PORTA, GPIO_u8PIN1
#define HLEDMRX_u8ROW2      GPIO_u8PORTA, GPIO_u8PIN2
#define HLEDMRX_u8ROW3      GPIO_u8PORTA, GPIO_u8PIN3
#define HLEDMRX_u8ROW4      GPIO_u8PORTA, GPIO_u8PIN4
#define HLEDMRX_u8ROW5      GPIO_u8PORTA, GPIO_u8PIN5
#define HLEDMRX_u8ROW6      GPIO_u8PORTA, GPIO_u8PIN6
#define HLEDMRX_u8ROW7      GPIO_u8PORTA, GPIO_u8PIN7

/****************************************************************************************************/
/* Configure the GPIO_PORT & GPIO_PIN pair for each Col to be used it in the GPIO Functions directly*/
/****************************************************************************************************/
#define HLEDMRX_u8COL0      GPIO_u8PORTB, GPIO_u8PIN0
#define HLEDMRX_u8COL1      GPIO_u8PORTB, GPIO_u8PIN1
#define HLEDMRX_u8COL2      GPIO_u8PORTB, GPIO_u8PIN5
#define HLEDMRX_u8COL3      GPIO_u8PORTB, GPIO_u8PIN6
#define HLEDMRX_u8COL4      GPIO_u8PORTB, GPIO_u8PIN7
#define HLEDMRX_u8COL5      GPIO_u8PORTB, GPIO_u8PIN8
#define HLEDMRX_u8COL6      GPIO_u8PORTB, GPIO_u8PIN9
#define HLEDMRX_u8COL7      GPIO_u8PORTB, GPIO_u8PIN10

#endif