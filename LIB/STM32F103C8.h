/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     11/07/2023                                                            */
/* Version              :     1.0.1                                                                 */
/* Modifications        :                                                                           */
/*      1- 15/07/2023 -> Added GPIO                                                                 */
/* SWC                  :     STMF103C8                                                             */
/****************************************************************************************************/

#ifndef STM32F103C8_H
#define STM32F103C8_H

/****************************************************************************************************/
/******************************************RCC Register**********************************************/
/****************************************************************************************************/

#define     RCC_u32BASE_ADDRESS         0x40021000

typedef struct 
{
   u32 RCC_CR;
   u32 RCC_CFGR;
   u32 RCC_CIR;
   u32 RCC_APB2RSTR;
   u32 RCC_APB1RSTR;
   u32 RCC_AHBENR;
   u32 RCC_APB2ENR;
   u32 RCC_APB1ENR;
   u32 RCC_BCDR;
   u32 RCC_CSR;

}RCC_REG_DEF_t;

typedef enum
{
    RCC_CR_HSION,
    RCC_CR_HSIRDY,
    RCC_CR_HSITRIM0 = 3,
    RCC_CR_HSITRIM_1,
    RCC_CR_HSITRIM_2,
    RCC_CR_HSITRIM_3,
    RCC_CR_HSITRIM_4,
    RCC_CR_HSICAL_0,
    RCC_CR_HSICAL_1,
    RCC_CR_HSICAL_2,
    RCC_CR_HSICAL_3,
    RCC_CR_HSICAL_4,
    RCC_CR_HSICAL_5,
    RCC_CR_HSICAL_6,
    RCC_CR_HSICAL_7,
    RCC_CR_HSEON,
    RCC_CR_HSERDY,
    RCC_CR_HSEBYP,
    RCC_CR_CSSON,
    RCC_CR_PLLON = 24,
    RCC_CR_PLLRDY,

}RCC_CR_REG_t;


typedef enum
{
    RCC_CFGR_SW_0,
    RCC_CFGR_SW_1,
    RCC_CFGR_SWS_0,
    RCC_CFGR_SWS_1,
    RCC_CFGR_HPRE_0,
    RCC_CFGR_HPRE_1,
    RCC_CFGR_HPRE_2,
    RCC_CFGR_HPRE_3,
    RCC_CFGR_PPRE1_0,
    RCC_CFGR_PPRE1_1,
    RCC_CFGR_PPRE1_2,
    RCC_CFGR_PPRE2_0,
    RCC_CFGR_PPRE2_1,
    RCC_CFGR_PPRE2_2,
    RCC_CFGR_ADCPRE_0,
    RCC_CFGR_ADCPRE_1,
    RCC_CFGR_PLLSRC,
    RCC_CFGR_PLLXTPRE,
    RCC_CFGR_PLLMUL_0,
    RCC_CFGR_PLLMUL_1,
    RCC_CFGR_PLLMUL_2,
    RCC_CFGR_PLLMUL_3,
    RCC_CFGR_USBPRE,
    RCC_CFGR_MCO_0 = 24,
    RCC_CFGR_MCO_1,
    RCC_CFGR_MCO_2,
    
}RCC_CFGR_REG_t;

typedef enum
{
    RCC_CIR_LSIRDYF,
    RCC_CIR_LSERDYF,
    RCC_CIR_HSIRDYF,
    RCC_CIR_HSERDYF,
    RCC_CIR_PLLRDYF,
    RCC_CIR_CSSF = 7,
    RCC_CIR_LSIRDYIE,
    RCC_CIR_LSERDYIE,
    RCC_CIR_HSIRDYIE,
    RCC_CIR_HSERDYIE,
    RCC_CIR_PLLRDYIE,
    RCC_CIR_LSIRDYC = 16,
    RCC_CIR_LSERDYC,
    RCC_CIR_HSIRDYC,
    RCC_CIR_HSERDYC,
    RCC_CIR_PLLRDYC,
    RCC_CIR_CSSC = 23,

}RCC_CIR_REG_t;

typedef enum
{
    RCC_APB2RSTR_AFIORST,
    RCC_APB2RSTR_IOPARST = 2,
    RCC_APB2RSTR_IOPBRST,
    RCC_APB2RSTR_IOPCRST,
    RCC_APB2RSTR_IOPDRST,
    RCC_APB2RSTR_IOPERST,
    RCC_APB2RSTR_IOPFRST,
    RCC_APB2RSTR_IOPGRST,
    RCC_APB2RSTR_ADC1RST,
    RCC_APB2RSTR_ADC2RST,
    RCC_APB2RSTR_TIM1RST,
    RCC_APB2RSTR_SPI1RST,
    RCC_APB2RSTR_TIM8RST,
    RCC_APB2RSTR_USART1RST,
    RCC_APB2RSTR_ADC3RST,
    RCC_APB2RSTR_TIM9RST = 19,
    RCC_APB2RSTR_TIM10RST,
    RCC_APB2RSTR_TIM11RST,

}RCC_APB2RSTR_REG_t;

typedef enum
{
   RCC_APB1RSTR_TIM2RST,
   RCC_APB1RSTR_TIM3RST,
   RCC_APB1RSTR_TIM4RST,
   RCC_APB1RSTR_TIM5RST,
   RCC_APB1RSTR_TIM6RST,
   RCC_APB1RSTR_TIM7RST,
   RCC_APB1RSTR_TIM12RST,
   RCC_APB1RSTR_TIM13RST,
   RCC_APB1RSTR_TIM14RST,
   RCC_APB1RSTR_WWDGRST = 11,
   RCC_APB1RSTR_SPI2RST = 14,
   RCC_APB1RSTR_SPI3RST,
   RCC_APB1RSTR_USART2RST = 17,
   RCC_APB1RSTR_USART3RST,
   RCC_APB1RSTR_USART4RST,
   RCC_APB1RSTR_USART5RST,
   RCC_APB1RSTR_I2C1RST,
   RCC_APB1RSTR_I2C2RST,
   RCC_APB1RSTR_USBRST,
   RCC_APB1RSTR_CANRST = 25,
   RCC_APB1RSTR_BKPRST = 27,
   RCC_APB1RSTR_PWRRST,
   RCC_APB1RSTR_DACRST,

}RCC_APB1RSTR_REG_t;

typedef enum
{

    RCC_AHBENR_DMA1EN,
    RCC_AHBENR_DMA2EN,
    RCC_AHBENR_SRAMEN,
    RCC_AHBENR_FLITFEN = 4,
    RCC_AHBENR_CRCEN = 6,
    RCC_AHBENR_FSMCEN = 8,
    RCC_AHBENR_SDIOEN = 10,

}RCC_AHBENR_REG_t;

typedef enum
{

    RCC_APB2ENR_AFIOEN,
    RCC_APB2ENR_IOPAEN = 2,
    RCC_APB2ENR_IOPBEN,
    RCC_APB2ENR_IOPCEN,
    RCC_APB2ENR_IOPDEN,
    RCC_APB2ENR_IOPEEN,
    RCC_APB2ENR_IOPFEN,
    RCC_APB2ENR_IOPGEN,
    RCC_APB2ENR_ADC1EN,
    RCC_APB2ENR_ADC2EN,
    RCC_APB2ENR_TIM1EN,
    RCC_APB2ENR_SPI1EN,
    RCC_APB2ENR_TIM8EN,
    RCC_APB2ENR_USART1EN,
    RCC_APB2ENR_ADC3EN,
    RCC_APB2ENR_TIM9EN = 19,
    RCC_APB2ENR_TIM10EN,
    RCC_APB2ENR_TIM11EN,

}RCC_APB2ENR_REG_t;

typedef enum
{

    RCC_APB1ENR_TIM2EN,
    RCC_APB1ENR_TIM3EN,
    RCC_APB1ENR_TIM4EN,
    RCC_APB1ENR_TIM5EN,
    RCC_APB1ENR_TIM6EN,
    RCC_APB1ENR_TIM7EN,
    RCC_APB1ENR_TIM12EN,
    RCC_APB1ENR_TIM13EN,
    RCC_APB1ENR_TIM14EN,
    RCC_APB1ENR_WWDGEN = 11,
    RCC_APB1ENR_SPI2EN = 14,
    RCC_APB1ENR_SPI3EN,
    RCC_APB1ENR_USART2EN = 16,
    RCC_APB1ENR_USART3EN,
    RCC_APB1ENR_USART4EN,
    RCC_APB1ENR_USART5EN,
    RCC_APB1ENR_I2C1EN,
    RCC_APB1ENR_I2C2EN,
    RCC_APB1ENR_USBEN,
    RCC_APB1ENR_CANEN = 25,
    RCC_APB1ENR_BKPEN = 27,
    RCC_APB1ENR_PWREN,
    RCC_APB1ENR_DACEN,

}RCC_APB1ENR_REG_t;

typedef enum
{

    RCC_BDCR_LSEON,
    RCC_BDCR_LSERDY,
    RCC_BDCR_LSEBYP,
    RCC_BDCR_RTCSEL_0 = 8,
    RCC_BDCR_RTCSEL_1,
    RCC_BDCR_RTCSEN = 15,
    RCC_BDCR_BDRST,

}RCC_BDCR_REG_t;

typedef enum
{

    RCC_CSR_LSION,
    RCC_CSR_LSIRDY,
    RCC_CSR_RMVF = 24,
    RCC_CSR_PINRSTF = 26,
    RCC_CSR_PORRSTF,
    RCC_CSR_SFTRSTF,
    RCC_CSR_IWDGRSTF,
    RCC_CSR_WWDGRSTF,
    RCC_CSR_LPWSTF,

}RCC_CSR_REG_t;

#define     RCC         ((RCC_REG_DEF_t *)RCC_u32BASE_ADDRESS)




/****************************************************************************************************/
/********************************************GPIO Registers******************************************/
/****************************************************************************************************/

#define GPIOA_u32BASE_ADDRESS      0x40010800
#define GPIOB_u32BASE_ADDRESS      0x40010C00
#define GPIOC_u32BASE_ADDRESS      0x40011000

typedef struct
{
    u32 GPIO_CRL ;
    u32 GPIO_CRH ;
    u32 GPIO_IDR ;
    u32 GPIO_ODR ;
    u32 GPIO_BSRR;
    u32 GPIO_BRR ;
    u32 GPIO_LCKR;
    
}GPIO_REG_DEF_t;


#define GPIOA   ((GPIO_REG_DEF_t *) GPIOA_u32BASE_ADDRESS)
#define GPIOB   ((GPIO_REG_DEF_t *) GPIOB_u32BASE_ADDRESS)
#define GPIOC   ((GPIO_REG_DEF_t *) GPIOC_u32BASE_ADDRESS)



/****************************************************************************************************/
/******************************************** NVIC Registers ****************************************/
/****************************************************************************************************/

#define NVIC_u32BASE_ADDRESS    0xE000E100

typedef struct
{
    u32 NVIC_ISER[3];

    u32 NVIC_RESERVED1[29];

    u32 NVIC_ICER[3];

    u32 NVIC_RESERVED2[29];

    u32 NVIC_ISPR[3];

    u32 NVIC_RESERVED3[29];

    u32 NVIC_ICPR[3];

    u32 NVIC_RESERVED4[29];

    volatile u32 NVIC_IABR[3];

    u32 RESERVED5[61];

    u8 NVIC_IPR[81];

}NVIC_REG_DEF_t;

#define MNVIC    ((NVIC_REG_DEF_t *) NVIC_u32BASE_ADDRESS)

/****************************************************************************************************/
/******************************************** SCB Registers *****************************************/
/****************************************************************************************************/

#define SCB_u32BASE_ADDRESS    0xE000ED00

typedef struct
{
    u32 SCB_CPUID;
    u32 SCB_ICSR;
    u32 SCB_VTOR;
    u32 SCB_AIRCR;
    u32 SCB_SCR;
    u32 SCB_CCR;
    u32 SCB_SHPR1;
    u32 SCB_SHPR2;
    u32 SCB_SHPR3;
    u32 SCB_SHCRS;
    u32 SCB_CFSR;
    u32 SCB_HFSR;
    u32 SCB_MMAR;
    u32 SCB_BFAR;

}SCB_REG_DEF_t;

#define MSCB     ((SCB_REG_DEF_t *) SCB_u32BASE_ADDRESS)

/****************************************************************************************************/
/************************************ AFIO Registers ************************************************/
/****************************************************************************************************/

#define AFIO_BASE_ADDRESS   0x40010000


typedef struct
{
    u32 AFIO_EVCR;
    u32 AFIO_MAPR;
    u32 AFIO_EXTICR[4];
    u32 AFIO_MAPR2;

}AFIO_REG_DEF_t;

#define MAFIO   ((AFIO_REG_DEF_t *) AFIO_BASE_ADDRESS)


/****************************************************************************************************/
/************************************ EXTI Registers ************************************************/
/****************************************************************************************************/

#define EXTI_BASE_ADDRESS   0x40010400

typedef struct
{
    u32 EXTI_IMR;
    u32 EXTI_EMR;
    u32 EXTI_RTSR;
    u32 EXTI_FTSR;
    u32 EXTI_SWIER;
    u32 EXTI_PR;

}EXTI_REG_DEF_t;

#define MEXTI   ((EXTI_REG_DEF_t *) EXTI_BASE_ADDRESS)



/****************************************************************************************************/
/************************************ SysTick Registers *********************************************/
/****************************************************************************************************/

#define STK_BASE_ADDRESS    0xE000E010

typedef struct
{
    u32 STK_CTRL;
    u32 STK_LOAD;
    u32 STK_VAL;
    u32 STK_CALIB;

}STK_REG_DEF_t;

#define MSTK    ((STK_REG_DEF_t *) STK_BASE_ADDRESS)



/****************************************************************************************************/
/**************************************** DMA Registers *********************************************/
/****************************************************************************************************/

#define MDMA_BASE_ADDRESS   0x40020000

typedef struct
{
   volatile u32 DMA_CCR;
   volatile u32 DMA_CNDTR;
   volatile u32 DMA_CPAR;
   volatile u32 DMA_CMAR;
   volatile u32 RESERVED; 

}MDMA_CHANNEL_t;


typedef struct
{
  volatile u32 DMA_ISR;
  volatile u32 DMA_IFCR;

    MDMA_CHANNEL_t DMA_CHANNEL[7];

}MDMA_REG_DEF_t;

/* DMA_CCR Register */
#define   MDMA_CCR_EN          0
#define   MDMA_CCR_TCIE        1
#define   MDMA_CCR_HTIE        2
#define   MDMA_CCR_TEIE        3
#define   MDMA_CCR_DIR         4
#define   MDMA_CCR_CIRC        5
#define   MDMA_CCR_PINC        6
#define   MDMA_CCR_MINC        7
#define   MDMA_CCR_PSIZE       8
#define   MDMA_CCR_MSIZE       10
#define   MDMA_CCR_PL          12
#define   MDMA_CCR_MEM2MEM     14



#define MDMA    ((MDMA_REG_DEF_t *) MDMA_BASE_ADDRESS)

#endif