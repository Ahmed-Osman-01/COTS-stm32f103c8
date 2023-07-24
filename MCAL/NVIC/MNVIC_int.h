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

    WWDG_Int_Num,
    PVD_Int_Num,
    TAMPER_Int_Num,
    RTC_Int_Num,
    FLASH_Int_Num,
    RCC_Int_Num,
    EXTI0_Int_Num,
    EXTI1_Int_Num,
    EXTI2_Int_Num,
    EXTI3_Int_Num,
    EXTI4_Int_Num,
    DMA1_Channel1_Int_Num,
    DMA1_Channel2_Int_Num,
    DMA1_Channel3_Int_Num,
    DMA1_Channel4_Int_Num,
    DMA1_Channel5_Int_Num,
    DMA1_Channel6_Int_Num,
    DMA1_Channel7_Int_Num,
    ADC1_2_Int_Num,
    USB_HP_CAN_TX_Int_Num,
    USB_LP_CAN_RX0_Int_Num,
    CAN_RX1_Int_Num,
    CAN_SCE_Int_Num,
    EXTI9_5_Int_Num,
    TIM1_BRK_Int_Num,
    TIM1_UP_Int_Num,
    TIM1_TRG_COM_Int_Num,
    TIM1_CC_Int_Num,
    TIM2_Int_Num,
    TIM3_Int_Num,
    TIM4_Int_Num,
    I2C1_EV_Int_Num,
    I2C1_ER_Int_Num,
    I2C2_EV_Int_Num,
    I2C2_ER_Int_Num,
    SPI1_Int_Num,
    SPI2_Int_Num,
    USART1_Int_Num,
    USART2_Int_Num,
    USART3_Int_Num,
    EXTI15_10_Int_Num,
    RTCAlarm_Int_Num,
    USBWakeup_Int_Num,
    TIM8_BRK_Int_Num,
    TIM8_UP_Int_Num,
    TIM8_TRG_COM_Int_Num,
    TIM8_CC_Int_Num,
    ADC3_Int_Num,
    FSMC_Int_Num,
    SDIO_Int_Num,
    TIM5_Int_Num,
    SPI3_Int_Num,
    UART4_Int_Num,
    UART5_Int_Num,
    TIM6_Int_Num,
    TIM7_Int_Num,
    DMA2_Channel1_Int_Num,
    DMA2_Channel2_Int_Num,
    DMA2_Channel3_Int_Num,
    DMA2_Channel4_5_Int_Num,

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

ErrorState_t MNCIV_enSetInterruptPeriority(MNVIC_External_Interrupt_Number_t copy_enInterruptNumber, u8 copy_u8Periotity, u8 copy_u8SubPeriority);


#endif
