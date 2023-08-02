
/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     18/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     LED                                                                   */
/****************************************************************************************************/

#ifndef HLED_INT_H_
#define HLED_INT_H_



/****************************************************************************************************/
/* An enum for all LEDs in the system.                                                              */
/****************************************************************************************************/
typedef enum
{
	HLED_RED,
	HLED_GRN,
	HLED_BLUE,
    HLED_MAX

}HLED_t;


/****************************************************************************************************/
/* Sets the Mode of the LED pin as push/pull 2MHZ output                                            */
/* @param The LED                                                                                   */
/****************************************************************************************************/
ErrorState_t HLED_enInitLED(HLED_t coppy_enLED);

/****************************************************************************************************/
/* Turns The given LED ON                                                                           */
/* @param The LED                                                                                   */
/****************************************************************************************************/
ErrorState_t HLED_enSetLEDOn(HLED_t coppy_enLED);

/****************************************************************************************************/
/* Turns the given LED OFF                                                                          */
/* @param The LED                                                                                   */
/****************************************************************************************************/
ErrorState_t HLED_enSetLEDOff(HLED_t coppy_enLED);

/****************************************************************************************************/
/* Toggles the state of the LED                                                                     */
/* @param The LED                                                                                   */
/****************************************************************************************************/
ErrorState_t HLED_enToggleLED(HLED_t coppy_enLED);





#endif /* HLED_INT_H_ */