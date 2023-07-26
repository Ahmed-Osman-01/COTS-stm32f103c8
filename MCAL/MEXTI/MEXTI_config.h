/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     24/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     EXTI                                                                  */
/****************************************************************************************************/

#ifndef MEXTI_CONFIG_H
#define MEXTI_CONFIG_H

#define SET_ALL_LINES   0x00001111  
/* select from MEXTI_LINE0 to MEXTI_LINE15*/
#define INITIAL_SELECTED_LINE                   MEXTI_LINE0


/* choose EXTI_RISING_EDGE or EXTI_FALLING_EDGE or EXTI_RISING_AND_FALLING_EDGE*/
#define INITIAL_SELECTED_LINE_EDGE_TRIGGER      MEXTI_RISING_EDGE 



#endif