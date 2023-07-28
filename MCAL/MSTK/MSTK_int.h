/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     25/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     SysTick                                                               */
/****************************************************************************************************/

#ifndef MSTK_INT_H
#define MSTK_INT_H


/****************************************************************************************************/
/* Sets the clock of the systick timer as configured in config file (Either AHB or AHB/8)           */
/****************************************************************************************************/
void MSTK_Init(void);

/****************************************************************************************************/
/* Sets a busy wait delay for the specified time                                                    */
/* @param copy_u32DelayMicroSec Delay time in Micro Seconds                                         */
/****************************************************************************************************/
ErrorState_t MSTK_SetBusyWait(u32 copy_u32DelayMicroSec);

/****************************************************************************************************/
/* Sets a delay for an action that occurs only one time after the specified time has elapsed        */
/* @param copy_u32DelayMicroSec Delay time in Micro Seconds                                         */
/* @param ptrFn The action to do only one time                                                      */
/****************************************************************************************************/
ErrorState_t MSTK_SetIntervalSingle(u32 copy_u32DelayMicroSec, void (*ptrFn)(void) );

/****************************************************************************************************/
/* Sets a periodic delay for an action that occurs periodically                                     */
/* @param copy_u32DelayMicroSec Delay time in Micro Seconds                                         */
/* @param ptrFn The action to do perdiodically                                                      */
/****************************************************************************************************/
ErrorState_t MSTK_SetIntervalPeriodic(u32 copy_u32DelayMicroSec, void (*ptrFn)(void) );

/****************************************************************************************************/
/* Disables the timer and sets the Load and Value registers to 0                                    */
/****************************************************************************************************/
void MSTK_StopTimer(void);

/****************************************************************************************************/
/* Calculates the Elapsed (The time in Load reg - time in Value reg) and returns it                 */
/* @param ptr_ReturnValue A pointer to return the value through                                     */
/****************************************************************************************************/
ErrorState_t MSTK_GetElapsedTicks(u32 * ptr_ReturnValue);

/****************************************************************************************************/
/* Returns the time remaining till the Value register (timer) reaches 0                             */
/* @param ptr_ReturnValue A pointer to return the value through                                     */
/****************************************************************************************************/
ErrorState_t MSTK_GetRemainingTicks(u32 * ptr_ReturnValue);

#endif