/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     18/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     LED                                                                   */
/****************************************************************************************************/

/*
 * HLED_config.h
 *
 *  Created on: May 29, 2023
 *      Author: Osman
 */

#ifndef HLED_HLED_CONFIG_H_
#define HLED_HLED_CONFIG_H_

#define LED_RED_PIN     GPIO_u8PIN0
#define LED_RED_PORT    GPIO_u8PORTA

#define LED_GRN_PIN     GPIO_u8PIN1
#define LED_GRN_PORT    GPIO_u8PORTA

#define LED_BLUE_PIN    GPIO_u8PIN2
#define LED_BLUE_PORT   GPIO_u8PORTA


/*
 * Set the direction to either FORWARD or REVERSE
 */
#define LED_RED_DIR	   HLED_LED_FORWARD
#define LED_GRN_DIR	   HLED_LED_FORWARD
#define LED_BLUE_DIR   HLED_LED_FORWARD

#endif /* HLED_HLED_CONFIG_H_ */
