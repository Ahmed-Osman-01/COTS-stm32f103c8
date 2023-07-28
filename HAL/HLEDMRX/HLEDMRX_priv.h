/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     26/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     8x8 LED Matrix Display                                                */
/****************************************************************************************************/

#ifndef HLEDMRX_PRIV_H
#define HLEDMRX_PRIV_H

/****************************************************************************************************/
/* Utility function to disable all columns at once                                                  */
/****************************************************************************************************/
static void HLEDMRX_voidDisablAllColumns(void);

/****************************************************************************************************/
/* Utility function to set the values of led matrix rows from a given byte of data                  */
/* @param copy_u8RowPattern Byte representing the row values                                        */
/****************************************************************************************************/
static void LEDMRX_voidSetRowValues(u8 copy_u8RowPattern);

#endif