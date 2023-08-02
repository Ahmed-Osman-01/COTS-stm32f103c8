/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     31/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     DMA                                                                   */
/****************************************************************************************************/

#ifndef MDMA_INT_H
#define MDMA_INT_H

#define MDMA_M2M_DISABLE    0
#define MDMA_M2M_ENABLE     1

#define MDMA_INCREMENT_DISABLE   0
#define MDMA_INCREMENT_ENABLE    1

#define MDMA_MODE_NORMAL      0
#define MDMA_MODE_CIRCULAR    1

#define MDMA_PERIPHERAL_TO_MEMORY   0
#define MDMA_MEMORY_TO_PERIPHERAL   1

#define MDMA_INTERRUPT_DISABLE      0
#define MDMA_INTERRUPT_ENABLE       1

typedef enum
{
    MDMA_CHANNEL1,
    MDMA_CHANNEL2,
    MDMA_CHANNEL3,
    MDMA_CHANNEL4,
    MDMA_CHANNEL5,
    MDMA_CHANNEL6,
    MDMA_CHANNEL7,
    MDMA_CHANNEL_MAX,

}MDMA_ChannelNumber_t;

typedef enum
{
    MDMA_PERIORITY_LOW,
    MDMA_PERIORITY_MEDIUM,
    MDMA_PERIORITY_HIGH,
    MDMA_PERIORITY_VERY_HIGH

}MDMA_PERIORITY_LEVEL_t;

typedef enum
{
    MDMA_8_BITS,
    MDMA_16_BITS,
    MDMA_32_BITS,

}MDMA_DATA_SIZE_t;

typedef struct
{
    MDMA_ChannelNumber_t    DMA_ChannelNumber;
    u8                      DMA_M2M;
    MDMA_PERIORITY_LEVEL_t  DMA_Periority;
    MDMA_DATA_SIZE_t        DMA_PeripheralDataSize;
    MDMA_DATA_SIZE_t        DMA_MemoryDataSize;
    u8                      DMA_PeripheralIncrement;
    u8                      DMA_MemoryIncrement;
    u8                      DMA_Mode;
    u8                      DMA_Direction;
    u8                      DMA_TransfereErrorInterrupt;
    u8                      DMA_HalfTransfereInterrupt;
    u8                      DMA_TransfereCompleteInterrupt;


}MDMA_ChannelData_t;



ErrorState_t MDMA_voidConfigureChannel(MDMA_ChannelData_t * ptr_Channel);

ErrorState_t MDMA_enEnableChannel(MDMA_ChannelNumber_t copy_enChannel);

ErrorState_t MDMA_enDisableChannel(MDMA_ChannelNumber_t copy_enChannel);

ErrorState_t MDMA_enSetNumberOfData(MDMA_ChannelNumber_t copy_enChannel, u16 copy_u16NumberOfData);

ErrorState_t MDMA_enSetPeripheralAddress(MDMA_ChannelNumber_t copy_enChannel, u32 * ptr_Address);

ErrorState_t MDMA_enSetMemoryAddress(MDMA_ChannelNumber_t copy_enChannel, u32 * ptr_Address);

ErrorState_t MDMA_enSetCallback(MDMA_ChannelNumber_t copy_enChannel, void (*ptrFn)(void));

ErrorState_t MDMA_enGetGlobalInterruptFlag(MDMA_ChannelNumber_t copy_enChannel, u8 * ptr_ReturnValue);
ErrorState_t MDMA_enGetHalfTransfereInterruptFlag(MDMA_ChannelNumber_t copy_enChannel, u8 * ptr_ReturnValue);
ErrorState_t MDMA_enGetTransfereCompleteInterruptFlag(MDMA_ChannelNumber_t copy_enChannel, u8 * ptr_ReturnValue);
ErrorState_t MDMA_enGetTransfereErrorInterruptFlag(MDMA_ChannelNumber_t copy_enChannel, u8 * ptr_ReturnValue);

#endif