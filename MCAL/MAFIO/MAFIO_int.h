/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     24/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     AFIO                                                                  */
/****************************************************************************************************/


#ifndef MAFIO_INT_H
#define MAFIO_INT_H

typedef enum
{
    MAFIO_PORTA,
    MAFIO_PORTB,
    MAFIO_PORTC,
    MAFIO_MAX_PORT,

}MAFIO_PORT_MAP_t;

/****************************************************************************************************/
/* Disables the JTAG pins (PA15, PB3, PB4) so they can be used in I/O                               */
/* WARRNING: DO NOT MODIFY THIS FUNCTION AS IT CAN RESULT IN DIABLING SWD PINS WHICH WILL PREVENT   */
/* ACCESSING THE STM32F103C8 USING ST LINK WHICH USES THE SWD OR JTAG                               */
/****************************************************************************************************/
void MAFIO_voidDisableJTAG(void);

/****************************************************************************************************/
/* Maps the given EXTI Line to the given Port                                                       */
/* @param copy_u8EXTI_Line External Interrupt Line to be mapped                                     */
/* @param copy_enPortMap The port to map the Line to                                                */
/****************************************************************************************************/
ErrorState_t MAFIO_enEXTIMap(u8 copy_u8EXTI_Line, MAFIO_PORT_MAP_t copy_enPortMap);


#endif