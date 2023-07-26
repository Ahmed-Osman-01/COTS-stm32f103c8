/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     24/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     AFIO                                                                  */
/****************************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STM32F103C8.h"
#include "../../LIB/BIT_MATH.h"

#include "MAFIO_int.h"
#include "MAFIO_priv.h"
#include "MAFIO_config.h"


void MAFIO_voidDisableJTAG(void)
{
    MAFIO->AFIO_MAPR |= 2 << 24;
}


ErrorState_t MAFIO_enEXTIMap(u8 copy_u8EXTI_Line, MAFIO_PORT_MAP_t copy_enPortMap)
{
    /* THE COMMENTED PART IS AN IMPLEMENTATION THAT NEEDS TO BE TESTED FIRST*/

    // ErrorState_t Local_ErrorState = OK;

    // u8 Local_u8RegisterIndex;
    // u8 Local_u8LinePosistion;

    // if(copy_u8EXTI_Line < 16)
    // {
    //     Local_u8RegisterIndex = copy_u8EXTI_Line / 4;
    //     Local_u8LinePosistion = copy_u8EXTI_Line % 4;

    //     MAFIO->AFIO_EXTICR[Local_u8RegisterIndex] |= copy_enPortMap << (Local_u8LinePosistion * 4);
    // }
    // else
    // {
    //     Local_ErrorState = OUT_OF_RANGE_ERR;
    // }

    // return Local_ErrorState;



    u8 Local_u8RegIndex   = 0 ;
	u8 Local_u8ErrorState = OK;

	if(copy_u8EXTI_Line <= 3)
	{
		Local_u8RegIndex = 0;
	}
	else if(copy_u8EXTI_Line <= 7)
	{
		Local_u8RegIndex = 1;
		copy_u8EXTI_Line = copy_u8EXTI_Line - 4;
	}
	else if(copy_u8EXTI_Line <= 11)
	{
		Local_u8RegIndex = 2;
		copy_u8EXTI_Line = copy_u8EXTI_Line - 8;
	}
	else if(copy_u8EXTI_Line <= 15)
	{
		Local_u8RegIndex = 3;
		copy_u8EXTI_Line = copy_u8EXTI_Line - 12;

	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	MAFIO->AFIO_EXTICR[Local_u8RegIndex] &= ~((0b1111) << (copy_u8EXTI_Line * 4));
	MAFIO->AFIO_EXTICR[Local_u8RegIndex] |=  ((copy_enPortMap) << (copy_u8EXTI_Line * 4));

	return Local_u8ErrorState;
}