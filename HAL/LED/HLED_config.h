/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     18/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     LED                                                                   */
/****************************************************************************************************/


#ifndef HLED_HLED_CONFIG_H_
#define HLED_HLED_CONFIG_H_

/****************************************************************************************************/
/* Configure the LEDs pins as connected in your project                                             */
/****************************************************************************************************/
#define HLED_RED_PIN     GPIO_u8PIN0
#define HLED_RED_PORT    GPIO_u8PORTA

#define HLED_GRN_PIN     GPIO_u8PIN1
#define HLED_GRN_PORT    GPIO_u8PORTA

#define HLED_BLUE_PIN    GPIO_u8PIN2
#define HLED_BLUE_PORT   GPIO_u8PORTA


/****************************************************************************************************/
/* Set the direction to either FORWARD or REVERSE                                                   */
/****************************************************************************************************/
#define HLED_RED_DIR	    HLED_FORWARD
#define HLED_GRN_DIR	    HLED_FORWARD
#define HLED_BLUE_DIR       HLED_FORWARD

#endif /* HLED_HLED_CONFIG_H_ */
