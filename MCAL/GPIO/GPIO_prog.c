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

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STM32F103C8.h"

#include "GPIO_int.h"
#include "GPIO_config.h"
#include "GPIO_priv.h"


u8 GPIO_u8SetPinMode(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Mode)
{
    u8 Local_u8ErrorState = OK;

    if(Copy_u8PinID < GPIO_LOWER_PINS_RANGE )
    {
        switch(Copy_u8PortID)
        {
            case GPIO_u8PORTA:
                GPIOA->GPIO_CRL &= ~( (GPIO_MODE_MASK) << Copy_u8PinID * GPIO_MODE_BITS_COUNT ); 
                GPIOA->GPIO_CRL |=  ( (Copy_u8Mode   ) << Copy_u8PinID * GPIO_MODE_BITS_COUNT ); 
            break;

            case GPIO_u8PORTB:
                GPIOB->GPIO_CRL &= ~( (GPIO_MODE_MASK) << Copy_u8PinID * GPIO_MODE_BITS_COUNT ); 
                GPIOB->GPIO_CRL |=  ( (Copy_u8Mode   ) << Copy_u8PinID * GPIO_MODE_BITS_COUNT ); 
            break;

            case GPIO_u8PORTC:
                GPIOC->GPIO_CRL &= ~( (GPIO_MODE_MASK) << Copy_u8PinID * GPIO_MODE_BITS_COUNT ); 
                GPIOC->GPIO_CRL |=  ( (Copy_u8Mode   ) << Copy_u8PinID * GPIO_MODE_BITS_COUNT ); 
            break;

            default:
                Local_u8ErrorState = NOK;
                break;
        } 
    }
    else if(Copy_u8PinID < GPIO_HIGHER_PINS_RANGE)
    {
        Copy_u8PinID = Copy_u8PinID - GPIO_LOWER_PINS_RANGE;    /*Shift the pins values to start from 0 to 7 to use with CRH regsiter*/

        switch(Copy_u8PortID)
        {
            case GPIO_u8PORTA:
                GPIOA->GPIO_CRH &= ~( (GPIO_MODE_MASK) << Copy_u8PinID * GPIO_MODE_BITS_COUNT ); 
                GPIOA->GPIO_CRH |=  ( (Copy_u8Mode   ) << Copy_u8PinID * GPIO_MODE_BITS_COUNT ); 
                break;

            case GPIO_u8PORTB:
                GPIOB->GPIO_CRH &= ~( (GPIO_MODE_MASK) << Copy_u8PinID * GPIO_MODE_BITS_COUNT ); 
                GPIOB->GPIO_CRH |=  ( (Copy_u8Mode   ) << Copy_u8PinID * GPIO_MODE_BITS_COUNT ); 
                break;

            case GPIO_u8PORTC:
                GPIOC->GPIO_CRH &= ~( (GPIO_MODE_MASK) << Copy_u8PinID * GPIO_MODE_BITS_COUNT ); 
                GPIOC->GPIO_CRH |=  ( (Copy_u8Mode   ) << Copy_u8PinID * GPIO_MODE_BITS_COUNT ); 
                break;

            default:
                Local_u8ErrorState = NOK;
                break;
        }
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}


u8 GPIO_u8SetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
    u8 Local_u8ErrorState = OK;

    switch(Copy_u8PortID)
    {
        case GPIO_u8PORTA:
            if(Copy_u8Value == GPIO_u8HIGH)
            {
                SET_BIT(GPIOA->GPIO_ODR, Copy_u8PinID);
            }
            else if(Copy_u8Value == GPIO_u8LOW)
            {
                CLR_BIT(GPIOA->GPIO_ODR, Copy_u8PinID);
            }
            else
            {
                Local_u8ErrorState = NOK;
            }
            break;

        case GPIO_u8PORTB:
            if(Copy_u8Value == GPIO_u8HIGH)
            {
                SET_BIT(GPIOB->GPIO_ODR, Copy_u8PinID);
            }
            else if(Copy_u8Value == GPIO_u8LOW)
            {
                CLR_BIT(GPIOB->GPIO_ODR, Copy_u8PinID);
            }
            else
            {
                Local_u8ErrorState = NOK;
            }
            break;

        case GPIO_u8PORTC:
            if(Copy_u8Value == GPIO_u8HIGH)
            {
                SET_BIT(GPIOC->GPIO_ODR, Copy_u8PinID);
            }
            else if(Copy_u8Value == GPIO_u8LOW)
            {
                CLR_BIT(GPIOC->GPIO_ODR, Copy_u8PinID);
            }
            else
            {
                Local_u8ErrorState = NOK;
            }
            break;

        default:
            Local_u8ErrorState = NOK;
            break;
    }

    return Local_u8ErrorState;
}


u8 GPIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 * Ptr_u8ReturnValue)
{
  u8 Local_u8ErrorState = OK;

    switch(Copy_u8PortID)
    {
    case GPIO_u8PORTA: 
        *Ptr_u8ReturnValue = GET_BIT(GPIOA->GPIO_IDR, Copy_u8PinID);
        break;

    case GPIO_u8PORTB:
        *Ptr_u8ReturnValue = GET_BIT(GPIOB->GPIO_IDR, Copy_u8PinID); 
        break;

    case GPIO_u8PORTC:
        *Ptr_u8ReturnValue = GET_BIT(GPIOC->GPIO_IDR, Copy_u8PinID);
        break; 

    default:
        Local_u8ErrorState = NOK;
        break;
    }

    return Local_u8ErrorState;
}



u8 GPIO_u8SetPortMode(u8 Copy_u8PortID, u8 Copy_u8PortPins, u8 Copy_u8Mode)
{
    u8 Local_ErrorState  = OK;
    u8 i;

    switch (Copy_u8PortID)
    {
    case GPIO_u8PORTA:
        
        switch (Copy_u8PortPins)
        {
        case GPIO_u8PORT_LOWER_PINS:
             GPIOA->GPIO_CRL = 0;
            for(i = 0; i <= GPIO_LAST_PIN_START_BIT; i += GPIO_MODE_BITS_COUNT)
            {
                GPIOA->GPIO_CRL |= (Copy_u8Mode << i); 
            }
            break;

        case GPIO_u8PORT_HIGHER_PINS:
            GPIOA->GPIO_CRH = 0;
            for(i = 0; i <= GPIO_LAST_PIN_START_BIT; i += GPIO_MODE_BITS_COUNT)
            {
                GPIOA->GPIO_CRH |= (Copy_u8Mode << i); 
            }

            break;
        
        default:
            Local_ErrorState  = NOK;
            break;
        }

        break;

    case GPIO_u8PORTB:

        switch (Copy_u8PortPins)
        {
        case GPIO_u8PORT_LOWER_PINS:
            GPIOB->GPIO_CRL = 0;
            for(i = 0; i <= GPIO_LAST_PIN_START_BIT; i += GPIO_MODE_BITS_COUNT)
            {
                GPIOB->GPIO_CRL |= (Copy_u8Mode << i); 
            }
            break;

        case GPIO_u8PORT_HIGHER_PINS:
            GPIOB->GPIO_CRH = 0;
            for(i = 0; i <= GPIO_LAST_PIN_START_BIT; i += GPIO_MODE_BITS_COUNT)
            {
                GPIOB->GPIO_CRH |= (Copy_u8Mode << i); 
            }
        
        default:
            Local_ErrorState  = NOK;
            break;
        }
        break;

    case GPIO_u8PORTC:

        switch (Copy_u8PortPins)
        {
        case GPIO_u8PORT_LOWER_PINS:
            GPIOC->GPIO_CRL = 0;
            for(i = 0; i <= GPIO_LAST_PIN_START_BIT; i += GPIO_MODE_BITS_COUNT)
            {
                GPIOC->GPIO_CRL |= (Copy_u8Mode << i); 
            }
            break;

        case GPIO_u8PORT_HIGHER_PINS:
            GPIOC->GPIO_CRH = 0;
            for(i = 0; i <= GPIO_LAST_PIN_START_BIT; i += GPIO_MODE_BITS_COUNT)
            {
                GPIOC->GPIO_CRH |= (Copy_u8Mode << i); 
            }
            break;
        
        default:
            Local_ErrorState  = NOK;
            break;
        }
        break;
    
    default:
        Local_ErrorState  = NOK;
        break;
    }

    return Local_ErrorState;
}


u8 GPIO_u8SetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortPins, u8 Copy_u8Value)
{
    u8 Local_ErrorState  = OK;

    switch (Copy_u8PortID)
    {
    case GPIO_u8PORTA:
        
        switch (Copy_u8PortPins)
        {
        case GPIO_u8PORT_LOWER_PINS:
           
            switch(Copy_u8Value)
            {
                case GPIO_u8LOW:
                    GPIOA->GPIO_ODR &= ~(GPIO_PORT_VALUE_MASK);
                    break;

                case GPIO_u8HIGH:
                    GPIOA->GPIO_ODR |= (GPIO_PORT_VALUE_MASK);
                    break;

                default:
                    Local_ErrorState  = NOK;
                    break;
            }

            break;

        case GPIO_u8PORT_HIGHER_PINS:
            switch(Copy_u8Value)
            {
                case GPIO_u8LOW:
                    GPIOA->GPIO_ODR &= ~((GPIO_PORT_VALUE_MASK) << GPIO_LOWER_PINS_RANGE); 
                    break;

                case GPIO_u8HIGH:
                    GPIOA->GPIO_ODR |= (GPIO_PORT_VALUE_MASK) << GPIO_LOWER_PINS_RANGE;
                    break;

                default:
                    Local_ErrorState  = NOK;
                    break;
            }
        
        default:
            Local_ErrorState  = NOK;
            break;
        }

        break;

    case GPIO_u8PORTB:

        switch (Copy_u8PortPins)
        {
        case GPIO_u8PORT_LOWER_PINS:
             switch(Copy_u8Value)
            {
                case GPIO_u8LOW:
                    GPIOB->GPIO_ODR &= ~(GPIO_PORT_VALUE_MASK);
                    break;

                case GPIO_u8HIGH:
                    GPIOB->GPIO_ODR |= (GPIO_PORT_VALUE_MASK);
                    break;

                default:
                    Local_ErrorState  = NOK;
                    break;
            }
            break;

        case GPIO_u8PORT_HIGHER_PINS:
            switch(Copy_u8Value)
            {
                case GPIO_u8LOW:
                    GPIOB->GPIO_ODR &= ~((GPIO_PORT_VALUE_MASK) << GPIO_LOWER_PINS_RANGE);
                    break;

                case GPIO_u8HIGH:
                    GPIOB->GPIO_ODR |= (GPIO_PORT_VALUE_MASK) << GPIO_LOWER_PINS_RANGE;
                    break;

                default:
                    Local_ErrorState  = NOK;
                    break;
            }
            break;
        
        default:
            Local_ErrorState  = NOK;
            break;
        }
        break;

    case GPIO_u8PORTC:

        switch (Copy_u8PortPins)
        {
        case GPIO_u8PORT_LOWER_PINS:
             switch(Copy_u8Value)
            {
                case GPIO_u8LOW:
                    GPIOC->GPIO_ODR &= ~(GPIO_PORT_VALUE_MASK);
                    break;

                case GPIO_u8HIGH:
                    GPIOC->GPIO_ODR |= (GPIO_PORT_VALUE_MASK);
                    break;

                default:
                    Local_ErrorState  = NOK;
                    break;
            }
            break;

        case GPIO_u8PORT_HIGHER_PINS:
            switch(Copy_u8Value)
            {
                case GPIO_u8LOW:
                    GPIOC->GPIO_ODR &= ~((GPIO_PORT_VALUE_MASK) << GPIO_LOWER_PINS_RANGE);
                    break;

                case GPIO_u8HIGH:
                    GPIOC->GPIO_ODR |= (GPIO_PORT_VALUE_MASK) << GPIO_LOWER_PINS_RANGE;
                    break;

                default:
                    Local_ErrorState  = NOK;
                    break;
            }
            break;
        
        default:
            Local_ErrorState  = NOK;
            break;
        }
        break;
    
    default:
        Local_ErrorState  = NOK;
        break;
    }

    return Local_ErrorState;
}


u8 GPIO_u8SetResetPin(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8Value)
{
    u8 Local_ErrorState = OK;

    if(Copy_u8PinID < 16)
    {
        switch(Copy_u8PortID)
        {
        case GPIO_u8PORTA:

            switch(Copy_u8Value)
            {
                case GPIO_u8LOW:
                    GPIOA->GPIO_BRR = 1 << Copy_u8PinID;
                    break;

                case GPIO_u8HIGH:
                    GPIOA->GPIO_BSRR = 1 << Copy_u8PinID;
                    break;

                default:
                    Local_ErrorState = NOK;
                    break;
            }
            break;

        case GPIO_u8PORTB:
            switch(Copy_u8Value)
            {
                case GPIO_u8LOW:
                    GPIOB->GPIO_BRR = 1 << Copy_u8PinID;
                    break;

                case GPIO_u8HIGH:
                    GPIOB->GPIO_BSRR = 1 << Copy_u8PinID;
                    break;

                default:
                    Local_ErrorState = NOK;
                    break;
            }
            break;

        case GPIO_u8PORTC:
            switch(Copy_u8Value)
            {
                case GPIO_u8LOW:
                    GPIOC->GPIO_BRR = 1 << Copy_u8PinID;
                    break;

                case GPIO_u8HIGH:
                    GPIOC->GPIO_BSRR = 1 << Copy_u8PinID;
                    break;

                default:
                    Local_ErrorState = NOK;
                    break;
            }
            break;

            default:
                Local_ErrorState = NOK;
                break;

        } /* end port switch*/

    } /* end if*/
    else
    {
        Local_ErrorState = NOK;
    }

    return Local_ErrorState;
}

u8 GPIO_u8TogglePin(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
    u8 Local_ErrorState = OK;

    switch(Copy_u8PortID)
    {
        case GPIO_u8PORTA:
            TOG_BIT(GPIOA->GPIO_ODR, Copy_u8PinID);
            break;

        case GPIO_u8PORTB:
            TOG_BIT(GPIOB->GPIO_ODR, Copy_u8PinID);
            break;

        case GPIO_u8PORTC:
            TOG_BIT(GPIOC->GPIO_ODR, Copy_u8PinID);
            break;

        default:
            Local_ErrorState = NOK;
    }

    return Local_ErrorState;

}


u8 GPIO_u8LockPin(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
    u8 Local_ErrorState = OK;

    if(Copy_u8PinID < GPIO_LOWER_PINS_RANGE)
    {
        switch (Copy_u8PortID)
        {
        case GPIO_u8PORTA:
                /* LCKK Pin sequence*/
            GPIOA->GPIO_LCKR = 1 << GPIO_LCKK_PIN;
            GPIOA->GPIO_LCKR = 0 << GPIO_LCKK_PIN;
            GPIOA->GPIO_LCKR = 1 << GPIO_LCKK_PIN;

            while( GET_BIT(GPIOA->GPIO_LCKR, GPIO_LCKK_PIN) != 0 );
            while( GET_BIT(GPIOA->GPIO_LCKR, GPIO_LCKK_PIN) != 1 );

            GPIOA->GPIO_LCKR = 1 << Copy_u8PinID;
            break;

        case GPIO_u8PORTB:
            GPIOB->GPIO_LCKR = 1 << GPIO_LCKK_PIN;
            GPIOB->GPIO_LCKR = 0 << GPIO_LCKK_PIN;
            GPIOB->GPIO_LCKR = 1 << GPIO_LCKK_PIN;

            while( GET_BIT(GPIOB->GPIO_LCKR, GPIO_LCKK_PIN) != 0 );
            while( GET_BIT(GPIOB->GPIO_LCKR, GPIO_LCKK_PIN) != 1 );
            GPIOB->GPIO_LCKR = 1 << Copy_u8PinID;
            break;

        case GPIO_u8PORTC:
            GPIOC->GPIO_LCKR = 1 << GPIO_LCKK_PIN;
            GPIOC->GPIO_LCKR = 0 << GPIO_LCKK_PIN;
            GPIOC->GPIO_LCKR = 1 << GPIO_LCKK_PIN;

            while( GET_BIT(GPIOC->GPIO_LCKR, GPIO_LCKK_PIN) != 0 );
            while( GET_BIT(GPIOC->GPIO_LCKR, GPIO_LCKK_PIN) != 1 );
            GPIOC->GPIO_LCKR = 1 << Copy_u8PinID;
            break;
        
        default:
            Local_ErrorState = NOK;
            break;
        }
    }
    else
    {
        Local_ErrorState = NOK;
    }

    return Local_ErrorState;
}
