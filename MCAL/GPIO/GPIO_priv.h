/****************************************************************************/
/* AUTHOR               :     Ahmed Osman                                   */
/* Origin Date          :     15/07/2023                                    */
/* Version              :     1.0.2                                         */
/* SWC                  :     GPIO                                          */
/****************************************************************************/

#ifndef GPIO_PRIV_H
#define GPIO_PRIV_H


#define GPIO_LOWER_PINS_RANGE       8   /* 8 lower pins of port (0-7)*/
#define GPIO_HIGHER_PINS_RANGE      16  /* The range of the higher port pins is wihtin (8-15 so it's smaller than 16)*/

#define GPIO_MODE_MASK              0b1111  /*Mask to reset the value of mode bits for each pin*/

#define GPIO_MODE_BITS_COUNT        4   /*Number of bits for each pin in CRL or CRH registers*/

#define GPIO_LAST_PIN_START_BIT       28  /* The position of the first bit of the last pin in a CRL or CRH register*/

#define GPIO_PORT_VALUE_MASK            0b11111111 /*Mask used to apply the value for the first 8 pins or last 8 pins of port to high or low*/

#define GPIO_LCKK_PIN          16

#endif