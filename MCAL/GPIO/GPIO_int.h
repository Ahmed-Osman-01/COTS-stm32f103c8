/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     15/07/2023                                                            */
/* Version              :     1.0.2                                                                 */
/* Modifications        :                                                                           */
/*      1- 16/07/2023 -> Added Atomic set/reset pin value function                                  */
/*      2- 16/07/2023 -> Added pin lock function                                                    */
/*      3- 18/07/2023 -> Added pin toggle function                                                  */
/* SWC                  :     GPIO                                                                  */
/****************************************************************************************************/

#ifndef GPIO_INT_H
#define GPIO_INT_H

#define GPIO_u8PORTA  1
#define GPIO_u8PORTB  2
#define GPIO_u8PORTC  3

#define GPIO_u8PIN0    0
#define GPIO_u8PIN1    1
#define GPIO_u8PIN2    2
#define GPIO_u8PIN3    3
#define GPIO_u8PIN4    4
#define GPIO_u8PIN5    5
#define GPIO_u8PIN6    6
#define GPIO_u8PIN7    7
#define GPIO_u8PIN8    8
#define GPIO_u8PIN9    9
#define GPIO_u8PIN10    10
#define GPIO_u8PIN11    11
#define GPIO_u8PIN12    12
#define GPIO_u8PIN13    13
#define GPIO_u8PIN14    14
#define GPIO_u8PIN15    15

/* Modes */
    /*Input:*/
#define GIO_u8INPUT_ANALOG              0b0000
#define GIO_u8INPUT_FLOATING            0b0100
#define GIO_u8INPUT_PULL_UP_DOWN        0b1000

    /*Output*/
#define GPIO_u8OUTPUT_PUSH_PULL_2MHZ              0b0010
#define GPIO_u8OUTPUT_PUSH_PULL_10MHZ             0b0011
#define GPIO_u8OUTPUT_PUSH_PULL_50MHZ             0b0011

#define GPIO_u8OUTPUT_OPEN_DRAIN_2MHZ             0b0110
#define GPIO_u8OUTPUT_OPEN_DRAIN_10MHZ            0b0101
#define GPIO_u8OUTPUT_OPEN_DRAIN_50MHZ            0b0111

#define GPIO_u8OUTPUT_AF_PUSH_PULL_2MHZ           0b1010
#define GPIO_u8OUTPUT_AF_PUSH_PULL_10MHZ          0b1001
#define GPIO_u8OUTPUT_AF_PUSH_PULL_50MHZ          0b1011

#define GPIO_u8OUTPUT_AF_OPEN_DRAIN_2MHZ          0b1110
#define GPIO_u8OUTPUT_AF_OPEN_DRAIN_10MHZ         0b1101
#define GPIO_u8OUTPUT_AF_OPEN_DRAIN_50MHZ         0b1111

#define GPIO_u8HIGH         1
#define GPIO_u8LOW          0

#define GPIO_u8PORT_LOWER_PINS      5
#define GPIO_u8PORT_HIGHER_PINS     6


/****************************************************************************************************/
/* Sets the given Mode to the given Pin number in the given Port                                    */
/* @param Copy_u8PortID Port of the pin.                                                            */
/* @param Copy_u8PortPins The pin number.                                                           */
/* @param Copy_u8Mode Mode to be set to.                                                            */
/****************************************************************************************************/
u8 GPIO_u8SetPinMode(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode);

/****************************************************************************************************/
/* Sets the given value to the given Pin number in the given Port                                   */
/* @param Copy_u8PortID Port of the pin.                                                            */
/* @param Copy_u8PortPins The pin number.                                                           */
/* @param Copy_u8Mode Value of the pin.                                                             */
/****************************************************************************************************/
u8 GPIO_u8SetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);

/****************************************************************************************************/
/* Gets the value of the given Pin number in the given Port                                         */
/* @param Copy_u8PortID Port of the pin.                                                            */
/* @param Copy_u8PortPins The pin number.                                                           */
/* @param Ptr_u8ReturnValue Pointer to return the value of the pin through.                         */
/****************************************************************************************************/
u8 GPIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 * Ptr_u8ReturnValue);

/****************************************************************************************************/
/* Sets the Mode of Lower 8 (0-7) pins or Higher 8 pins (8-15)                                      */
/* @param Copy_u8PortID Port of the pin.                                                            */
/* @param Copy_u8PortPins The Lower port pins (0-7) or Higher port pins (8-15).                     */
/* @param Copy_u8Mode Mode to be set to.                                                            */
/****************************************************************************************************/
u8 GPIO_u8SetPortMode(u8 Copy_u8PortID, u8 Copy_u8PortPins, u8 Copy_u8Mode);

/****************************************************************************************************/
/* Sets the Value of Lower 8 (0-7) pins or Higher 8 pins (8-15)                                     */
/* @param Copy_u8PortID Port of the pin.                                                            */
/* @param Copy_u8PortPins The Lower port pins (0-7) or Higher port pins (8-15).                     */
/* @param Copy_u8Mode The value of the port.                                                        */
/****************************************************************************************************/
u8 GPIO_u8SetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortPins, u8 Copy_u8Value);

/****************************************************************************************************/
/* Sets the Value of a pin (More efficient)(Atomic)                                                 */
/* @param Copy_u8PortID Port of the pin.                                                            */
/* @param Copy_u8PortPins The Lower port pins (0-7) or Higher port pins (8-15).                     */
/* @param Copy_u8Mode The value of the port.                                                        */
/****************************************************************************************************/
u8 GPIO_u8SetResetPin(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value);

/****************************************************************************************************/
/* Toggles the Value of a pin (More efficient)(Atomic)                                              */
/* @param Copy_u8PortID Port of the pin.                                                            */
/* @param Copy_u8PortPins The Lower port pins (0-7) or Higher port pins (8-15).                     */
/****************************************************************************************************/
u8 GPIO_u8TogglePin(u8 Copy_u8PortID, u8 Copy_u8PinID);

/****************************************************************************************************/
/* Locks the pin Configuration not allowing to change its Mode or Value later until reset           */
/* @param Copy_u8PortID Port of the pin.                                                            */
/* @param Copy_u8PortPins The Lower port pins (0-7) or Higher port pins (8-15).                     */
/****************************************************************************************************/
u8 GPIO_u8LockPin(u8 Copy_u8PortID, u8 Copy_u8PinID);



#endif