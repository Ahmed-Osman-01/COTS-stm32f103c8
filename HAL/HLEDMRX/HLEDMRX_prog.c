/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     26/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     8x8 LED Matrix Display                                                */
/****************************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STM32F103C8.h"
#include "../../LIB/BIT_MATH.h"


#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/MSTK/MSTK_int.h"

#include "HLEDMRX_int.h"
#include "HLEDMRX_priv.h"
#include "HLEDMRX_config.h"

void HLEDMRX_voidInit(void)
{
    GPIO_u8SetPinMode(HLEDMRX_u8ROW0, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8ROW1, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8ROW2, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8ROW3, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8ROW4, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8ROW5, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8ROW6, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8ROW7, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);

    GPIO_u8SetPinMode(HLEDMRX_u8COL0, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8COL1, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8COL2, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8COL3, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8COL4, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8COL5, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8COL6, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);
    GPIO_u8SetPinMode(HLEDMRX_u8COL7, GPIO_u8OUTPUT_PUSH_PULL_2MHZ);

}

void HLEDMRX_voidDisplayPattern(u8 * ptr_u8Patterns)
{
 
    /************** COLUMN [0] *************/
    /*DISABLE ALL COLUMNS*/
    HLEDMRX_voidDisableCols();
    /* SET ROWS VALUES*/
    LEDMRX_voidSetRowValues(ptr_u8Patterns[0]);
    /* ENABLE COLUMN[0]*/
    GPIO_u8SetPinValue(HLEDMRX_u8COL0, GPIO_u8LOW);
    /* ADD DELAY*/
    MSTK_SetBusyWait(2500);

    /************** COLUMN [1] *************/
    /*DISABLE ALL COLUMNS*/
    HLEDMRX_voidDisableCols();
    /* SET ROWS VALUES*/
    LEDMRX_voidSetRowValues(ptr_u8Patterns[1]);
    /* ENABLE COLUMN[1]*/
    GPIO_u8SetPinValue(HLEDMRX_u8COL1, GPIO_u8LOW);
    /* ADD DELAY*/
    MSTK_SetBusyWait(2500);

    /************** COLUMN [2] *************/
    /*DISABLE ALL COLUMNS*/
    HLEDMRX_voidDisableCols();
    /* SET ROWS VALUES*/
    LEDMRX_voidSetRowValues(ptr_u8Patterns[2]);
    /* ENABLE COLUMN[2]*/
    GPIO_u8SetPinValue(HLEDMRX_u8COL2, GPIO_u8LOW);
    /* ADD DELAY*/
    MSTK_SetBusyWait(2500);

    /************** COLUMN [3] *************/
    /*DISABLE ALL COLUMNS*/
    HLEDMRX_voidDisableCols();
    /* SET ROWS VALUES*/
    LEDMRX_voidSetRowValues(ptr_u8Patterns[3]);
    /* ENABLE COLUMN[3]*/
    GPIO_u8SetPinValue(HLEDMRX_u8COL3, GPIO_u8LOW);
    /* ADD DELAY*/
    MSTK_SetBusyWait(2500);

    /************** COLUMN [4] *************/
    /*DISABLE ALL COLUMNS*/
    HLEDMRX_voidDisableCols();
    /* SET ROWS VALUES*/
    LEDMRX_voidSetRowValues(ptr_u8Patterns[4]);
    /* ENABLE COLUMN[4]*/
    GPIO_u8SetPinValue(HLEDMRX_u8COL4, GPIO_u8LOW);
    /* ADD DELAY*/
    MSTK_SetBusyWait(2500);

    /************** COLUMN [5] *************/
    /*DISABLE ALL COLUMNS*/
    HLEDMRX_voidDisableCols();
    /* SET ROWS VALUES*/
    LEDMRX_voidSetRowValues(ptr_u8Patterns[5]);
    /* ENABLE COLUMN[5]*/
    GPIO_u8SetPinValue(HLEDMRX_u8COL5, GPIO_u8LOW);
    /* ADD DELAY*/
    MSTK_SetBusyWait(2500);

    /************** COLUMN [6] *************/
    /*DISABLE ALL COLUMNS*/
    HLEDMRX_voidDisableCols();
    /* SET ROWS VALUES*/
    LEDMRX_voidSetRowValues(ptr_u8Patterns[6]);
    /* ENABLE COLUMN[6]*/
    GPIO_u8SetPinValue(HLEDMRX_u8COL6, GPIO_u8LOW);
    /* ADD DELAY*/
    MSTK_SetBusyWait(2500);

    /************** COLUMN [7] *************/
    /*DISABLE ALL COLUMNS*/
    HLEDMRX_voidDisableCols();
    /* SET ROWS VALUES*/
    LEDMRX_voidSetRowValues(ptr_u8Patterns[7]);
    /* ENABLE COLUMN[7]*/
    GPIO_u8SetPinValue(HLEDMRX_u8COL7, GPIO_u8LOW);
    /* ADD DELAY*/
    MSTK_SetBusyWait(2500);

    
}


static void HLEDMRX_voidDisablAllColumns(void)
{
    /* disable all colums*/
    GPIO_u8SetPinValue(HLEDMRX_u8COL0, GPIO_u8HIGH);
    GPIO_u8SetPinValue(HLEDMRX_u8COL1, GPIO_u8HIGH);
    GPIO_u8SetPinValue(HLEDMRX_u8COL2, GPIO_u8HIGH);
    GPIO_u8SetPinValue(HLEDMRX_u8COL3, GPIO_u8HIGH);
    GPIO_u8SetPinValue(HLEDMRX_u8COL4, GPIO_u8HIGH);
    GPIO_u8SetPinValue(HLEDMRX_u8COL5, GPIO_u8HIGH);
    GPIO_u8SetPinValue(HLEDMRX_u8COL6, GPIO_u8HIGH);
    GPIO_u8SetPinValue(HLEDMRX_u8COL7, GPIO_u8HIGH);
}


static void LEDMRX_voidSetRowValues(u8 copy_u8RowPattern)
{
    GPIO_u8SetPinValue(HLEDMRX_u8ROW0, GET_BIT(copy_u8RowPattern, 0));
    GPIO_u8SetPinValue(HLEDMRX_u8ROW1, GET_BIT(copy_u8RowPattern, 1));
    GPIO_u8SetPinValue(HLEDMRX_u8ROW2, GET_BIT(copy_u8RowPattern, 2));
    GPIO_u8SetPinValue(HLEDMRX_u8ROW3, GET_BIT(copy_u8RowPattern, 3));
    GPIO_u8SetPinValue(HLEDMRX_u8ROW4, GET_BIT(copy_u8RowPattern, 4));
    GPIO_u8SetPinValue(HLEDMRX_u8ROW5, GET_BIT(copy_u8RowPattern, 5));
    GPIO_u8SetPinValue(HLEDMRX_u8ROW6, GET_BIT(copy_u8RowPattern, 6));
    GPIO_u8SetPinValue(HLEDMRX_u8ROW7, GET_BIT(copy_u8RowPattern, 7));
}