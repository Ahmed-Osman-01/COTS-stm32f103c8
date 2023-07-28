/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     24/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     EXTI                                                                  */
/****************************************************************************************************/

#ifndef MEXTI_INT_H
#define MEXTI_INT_H


#define    MEXTI_LINE0    0
#define    MEXTI_LINE1    1
#define    MEXTI_LINE2    2   
#define    MEXTI_LINE3    3
#define    MEXTI_LINE4    4
#define    MEXTI_LINE5    5
#define    MEXTI_LINE6    6
#define    MEXTI_LINE7    7
#define    MEXTI_LINE8    8   
#define    MEXTI_LINE9    9
#define    MEXTI_LINE10   10
#define    MEXTI_LINE11   11
#define    MEXTI_LINE12   12
#define    MEXTI_LINE13   13
#define    MEXTI_LINE14   14
#define    MEXTI_LINE15   15


#define    MEXTI_RISING_EDGE             50
#define    MEXTI_FALLING_EDGE            60
#define    MEXTI_RISING_AND_FALLING_EDGE 70

/****************************************************************************************************/
/* Enables the specified Line in configuration with the selected trigger edge in configuration      */
/****************************************************************************************************/
void MEXTI_voidInit(void);

/****************************************************************************************************/
/* Enables the External interrupt line                                                              */
/* @param copy_u8Line The EXTI Line                                                                 */
/****************************************************************************************************/
ErrorState_t MEXTI_u8EnableInterrupt(u8 copy_u8Line);

/****************************************************************************************************/
/* Disables the External interrupt line                                                             */
/* @param copy_u8Line The EXTI Line                                                                 */
/****************************************************************************************************/
ErrorState_t MEXTI_u8DisableInterrupt(u8 copy_u8Line);

/****************************************************************************************************/
/* Fires an interrupt on the exti line by software                                                  */
/* @param copy_u8Line The EXTI Line                                                                 */
/****************************************************************************************************/
ErrorState_t MEXTI_u8SoftwareInterrupt(u8 copy_u8Line);

/****************************************************************************************************/
/* Configure the interrupt trigger edge for the specified line                                      */
/* @param copy_u8Line The EXTI Line                                                                 */
/* @param copy_u8TriggerEdge The edge to fire the interrupt at                                      */
/****************************************************************************************************/
ErrorState_t MEXTI_u8SetInterruptTrigger(u8 copy_u8Line, u8 copy_u8TriggerEdge);

/****************************************************************************************************/
/* Sets the callback function for the specified external interrupt line                             */
/* @param copy_u8Line The EXTI Line                                                                 */
/* @param ptrFn Pointer to the callback function                                                    */
/****************************************************************************************************/
ErrorState_t MEXTI_enSetCallBack(u8 copy_u8Line, void (*ptrFn)(void));

#endif