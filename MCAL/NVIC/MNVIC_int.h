/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     19/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     NVIC                                                                  */
/****************************************************************************************************/

#ifndef MNVIC_INT_H
#define MNVIC_INT_H

/****************************************************************************************************/
/* External interrupt number which is also called IRQ number and it is the default periority or     */
/* the "Hardware periority" for external interrupts                                                 */
/****************************************************************************************************/
typedef enum
{

    MNCIV_WWDG,
    MNCIV_PVD,
    MNCIV_TAMPER,
    MNCIV_RTC,
    MNCIV_FLASH,
    MNCIV_RCC,
    MNCIV_EXTI0,
    MNCIV_EXTI1,
    MNCIV_EXTI2,
    MNCIV_EXTI3,
    MNCIV_EXTI4,
    MNCIV_DMA1_Channel1,
    MNCIV_DMA1_Channel2,
    MNCIV_DMA1_Channel3,
    MNCIV_DMA1_Channel4,
    MNCIV_DMA1_Channel5,
    MNCIV_DMA1_Channel6,
    MNCIV_DMA1_Channel7,
    MNCIV_ADC1_2,
    MNCIV_USB_HP_CAN_TX,
    MNCIV_USB_LP_CAN_RX0,
    MNCIV_CAN_RX1,
    MNCIV_CAN_SCE,
    MNCIV_EXTI9_5,
    MNCIV_TIM1_BRK,
    MNCIV_TIM1_UP,
    MNCIV_TIM1_TRG_COM,
    MNCIV_TIM1_CC,
    MNCIV_TIM2,
    MNCIV_TIM3,
    MNCIV_TIM4,
    MNCIV_I2C1_EV,
    MNCIV_I2C1_ER,
    MNCIV_I2C2_EV,
    MNCIV_I2C2_ER,
    MNCIV_SPI1,
    MNCIV_SPI2,
    MNCIV_USART1,
    MNCIV_USART2,
    MNCIV_USART3,
    MNCIV_EXTI15_10,
    MNCIV_RTCAlarm,
    MNCIV_USBWakeup,
    MNCIV_TIM8_BRK,
    MNCIV_TIM8_UP,
    MNCIV_TIM8_TRG_COM,
    MNCIV_TIM8_CC,
    MNCIV_ADC3,
    MNCIV_FSMC,
    MNCIV_SDIO,
    MNCIV_TIM5,
    MNCIV_SPI3,
    MNCIV_UART4,
    MNCIV_UART5,
    MNCIV_TIM6,
    MNCIV_TIM7,
    MNCIV_DMA2_Channel1,
    MNCIV_DMA2_Channel2,
    MNCIV_DMA2_Channel3,
    MNCIV_DMA2_Channel4_5,

}MNVIC_External_Interrupt_Number_t;



/****************************************************************************************************/
/* Set the Number of group periotities and sub periotities bits (Binary Point) in SCB_AIRCR register*/
/* that can be configured in the NVIC_IPRx (Interrupt Periotity Registers) registers bank           */
/* @param copy_enBinaryPoint The maximum number of group periotities and sub periorities            */
/****************************************************************************************************/
ErrorState_t MNVIC_enInitNVIC(void);

/****************************************************************************************************/
/* Enables the specified external interrupt                                                         */
/* @param copy_enInterruptNumber The external interrupt number (IRQ number)                         */
/****************************************************************************************************/
ErrorState_t MNVIC_enEnableInterrupt(MNVIC_External_Interrupt_Number_t copy_enInterruptNumber);

/****************************************************************************************************/
/* Disables the specified external interrupt                                                        */
/* @param copy_enInterruptNumber The external interrupt number (IRQ number)                         */
/****************************************************************************************************/
ErrorState_t MNVIC_enDisableInterrupt(MNVIC_External_Interrupt_Number_t copy_enInterruptNumber);

/****************************************************************************************************/
/* Changes the state of external interrupt to pending (Sets the pending bit)                        */
/* @param copy_enInterruptNumber The external interrupt number (IRQ number)                         */
/****************************************************************************************************/
ErrorState_t MNVIC_enSetInterruptPending(MNVIC_External_Interrupt_Number_t copy_enInterruptNumber);

/****************************************************************************************************/
/* Changes the state of external interrupt to just non_pending (just inactive or active)            */
/* (Clears the pending bit)                                                                         */
/* @param copy_enInterruptNumber The external interrupt number (IRQ number)                         */
/****************************************************************************************************/
ErrorState_t MNVIC_enClearInterruptPending(MNVIC_External_Interrupt_Number_t copy_enInterruptNumber);

/****************************************************************************************************/
/* Checks whether the state of an external interrupt is active or inactive and returns this state   */
/* @param copy_enInterruptNumber The external interrupt number (IRQ number)                         */
/* @param ptr_ReturnState Pointer to the variable to store the state of the interrupt in            */
/****************************************************************************************************/
ErrorState_t MNVIC_enGetActiveStatus(MNVIC_External_Interrupt_Number_t copy_enInterruptNumber, u8 * ptr_ReturnState);

/* BAD DESIGN, NEEDS TO BE IMPLEMENTED AFTER IMPLEMENTING THE SCB MODULE*/
ErrorState_t MNCIV_enSetInterruptPeriority(MNVIC_External_Interrupt_Number_t copy_enInterruptNumber, u8 copy_u8Periotity, u8 copy_u8SubPeriority);


#endif
