/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     26/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     LED Matrix Display                                                    */
/****************************************************************************************************/

#ifndef HLEDMRX_INT_H
#define HLEDMRX_INT_H

/****************************************************************************************************/
/* Sets the Mode of the 16 pins specified for the led matrix in the config file to push/pull output */
/****************************************************************************************************/
void HLEDMRX_voidInit(void);

/****************************************************************************************************/
/* Displays the given pattern on the led matrix                                                     */
/* @param ptr_u8Patterns Array of bytes representing the pattern to display                         */
/****************************************************************************************************/
void HLEDMRX_voidDisplayPattern(u8 * ptr_u8Patterns);

#endif