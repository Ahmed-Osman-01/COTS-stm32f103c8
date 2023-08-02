/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     1/08/2023                                                             */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     IR Reciever                                                           */
/****************************************************************************************************/

#ifndef HIR_INT_H
#define HIR_INT_H

#define HIR_GARBAGE_NUMBER  255     /* Indicates that address or data are corrupted */

/****************************************************************************************************/
/* Initializes the IR Reciever sensor by setting the mode of its pin to input floating , Maps the   */
/* external interrupt of the pin it is connected to which is also the external interrupt  line into */
/* the port it is connected to, And initializes the external interrupt line (which is the pin numer)*/
/* by setting a callback function (BuildFrame), Setting the trigger edge, And enabling this         */
/* interrupt line.                                                                                  */
/* Sets the pin Mode, Maps the external interrupt to the correct port, And initializes the external */
/* interrupt to trigger at falling edge and sets a callback function (BuildFrame) and enables the   */
/* external interrupt.                                                                              */
/* @param  copy_u8Port The port it is connected to                                                  */
/* @param  copy_u8Pin The pin it is connected to (It is also the Line number of external interrupt) */
/****************************************************************************************************/
void HIR_enInit(u8 copy_u8Port, u8 copy_u8Pin);

/****************************************************************************************************/
/* Returns the address extracted from the frame sent by the IR transmitter                          */
/* @param ptr_ReturnValue Pointer to return the address through                                     */
/****************************************************************************************************/
ErrorState_t HIR_enGetAddress(u8 * ptr_ReturnValue);

/****************************************************************************************************/
/* Returns the data extracted from the frame sent by the IR transmitter                             */
/* @param ptr_ReturnValue Pointer to return the data through                                        */
/****************************************************************************************************/
ErrorState_t HIR_enGetData(u8 * ptr_ReturnValue);

/****************************************************************************************************/
/* Sets the callback function to be called after the frame is transmitted                           */
/* @param  ptrFn Pointer to the callback function                                                   */
/****************************************************************************************************/
ErrorState_t HIR_SetCallback(void (*ptrFn)(void));

#endif