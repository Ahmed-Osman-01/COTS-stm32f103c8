/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     26/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     8x8 LED Matrix Display                                                */
/****************************************************************************************************/

#ifndef HLEDMRX_INT_H
#define HLEDMRX_INT_H


typedef enum
{
    HLEDMRX_LEVEL1 = 25,
    HLEDMRX_LEVEL2 = 20,
    HLEDMRX_LEVEL3 = 15,
    HLEDMRX_LEVEL4 = 10,

}HLEDMRX_Speeds_t;

/****************************************************************************************************/
/* Sets the Mode of the 16 pins specified for the led matrix in the config file to push/pull output */
/****************************************************************************************************/
void HLEDMRX_voidInit(void);

/****************************************************************************************************/
/* Displays the given pattern on the led matrix                                                     */
/* @param ptr_u8Patterns Array of bytes representing the pattern to display                         */
/****************************************************************************************************/
void HLEDMRX_voidDisplayPattern(u8 * ptr_u8Patterns);

/****************************************************************************************************/
/* Displays a dynamic (moving) long pattern (string) from left to right with a certain speed        */
/* Note: the long patterns should start and end with eight zeros for a better visual effect         */
/* @param ptr_u8LongPattern The long pattern (string) to be displayed dynamically                   */
/* @param copy_u8PatternLength The length of the long pattern (Number of columns)                   */
/* @param copy_enSpeed The moving speed of the display (HLEDMRX_LEVEL1 -> HLEDMRX_LEVEL4)           */
/****************************************************************************************************/
void HLEDMRX_voidDisplayMovingLongPattern(u8 * ptr_u8LongPattern, u8 copy_u8PatternLength, HLEDMRX_Speeds_t copy_enSpeed);

#endif