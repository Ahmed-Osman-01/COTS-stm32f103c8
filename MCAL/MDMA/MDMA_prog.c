/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     31/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     DMA                                                                   */
/****************************************************************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/STM32F103C8.h"
#include "../../LIB/BIT_MATH.h"

#include "MDMA_int.h"
#include "MDMA_priv.h"
#include "MDMA_config.h"

static void (*Callback[7])(void) = {NULL};


ErrorState_t MDMA_voidConfigureChannel(MDMA_ChannelData_t * ptr_Channel)
{
    ErrorState_t Local_ErrorState = OK;

    if(ptr_Channel != NULL)
    {

        switch(ptr_Channel->DMA_ChannelNumber)
        {
        case MDMA_CHANNEL1:
            /* Reset the config reg */
            MDMA->DMA_CHANNEL[MDMA_CHANNEL1].DMA_CCR = 0;
            MDMA->DMA_CHANNEL[MDMA_CHANNEL1].DMA_CCR = (ptr_Channel->DMA_TransfereCompleteInterrupt << MDMA_CCR_TCIE) |
                                                       (ptr_Channel->DMA_HalfTransfereInterrupt << MDMA_CCR_HTIE)     |
                                                       (ptr_Channel->DMA_TransfereErrorInterrupt << MDMA_CCR_TEIE)    |
                                                       (ptr_Channel->DMA_Direction << MDMA_CCR_DIR)                   |
                                                       (ptr_Channel->DMA_Mode << MDMA_CCR_CIRC)                       |
                                                       (ptr_Channel->DMA_PeripheralIncrement << MDMA_CCR_PINC)        |
                                                       (ptr_Channel->DMA_MemoryIncrement << MDMA_CCR_MINC)            |
                                                       (ptr_Channel->DMA_PeripheralDataSize << MDMA_CCR_PSIZE)        |
                                                       (ptr_Channel->DMA_MemoryDataSize << MDMA_CCR_MSIZE)            |
                                                       (ptr_Channel->DMA_Periority << MDMA_CCR_PL)                    |
                                                       (ptr_Channel->DMA_M2M << MDMA_CCR_MEM2MEM);
            break;

        case MDMA_CHANNEL2:
         /* Reset the config reg */
            MDMA->DMA_CHANNEL[MDMA_CHANNEL2].DMA_CCR = 0;
            MDMA->DMA_CHANNEL[MDMA_CHANNEL2].DMA_CCR = (ptr_Channel->DMA_TransfereCompleteInterrupt << MDMA_CCR_TCIE) |
                                                       (ptr_Channel->DMA_HalfTransfereInterrupt << MDMA_CCR_HTIE)     |
                                                       (ptr_Channel->DMA_TransfereErrorInterrupt << MDMA_CCR_TEIE)    |
                                                       (ptr_Channel->DMA_Direction << MDMA_CCR_DIR)                   |
                                                       (ptr_Channel->DMA_Mode << MDMA_CCR_CIRC)                       |
                                                       (ptr_Channel->DMA_PeripheralIncrement << MDMA_CCR_PINC)        |
                                                       (ptr_Channel->DMA_MemoryIncrement << MDMA_CCR_MINC)            |
                                                       (ptr_Channel->DMA_PeripheralDataSize << MDMA_CCR_PSIZE)        |
                                                       (ptr_Channel->DMA_MemoryDataSize << MDMA_CCR_MSIZE)            |
                                                       (ptr_Channel->DMA_Periority << MDMA_CCR_PL)                    |
                                                       (ptr_Channel->DMA_M2M << MDMA_CCR_MEM2MEM);
            break;

        case MDMA_CHANNEL3:
         /* Reset the config reg */
            MDMA->DMA_CHANNEL[MDMA_CHANNEL3].DMA_CCR = 0;
            MDMA->DMA_CHANNEL[MDMA_CHANNEL3].DMA_CCR = (ptr_Channel->DMA_TransfereCompleteInterrupt << MDMA_CCR_TCIE) |
                                                       (ptr_Channel->DMA_HalfTransfereInterrupt << MDMA_CCR_HTIE)     |
                                                       (ptr_Channel->DMA_TransfereErrorInterrupt << MDMA_CCR_TEIE)    |
                                                       (ptr_Channel->DMA_Direction << MDMA_CCR_DIR)                   |
                                                       (ptr_Channel->DMA_Mode << MDMA_CCR_CIRC)                       |
                                                       (ptr_Channel->DMA_PeripheralIncrement << MDMA_CCR_PINC)        |
                                                       (ptr_Channel->DMA_MemoryIncrement << MDMA_CCR_MINC)            |
                                                       (ptr_Channel->DMA_PeripheralDataSize << MDMA_CCR_PSIZE)        |
                                                       (ptr_Channel->DMA_MemoryDataSize << MDMA_CCR_MSIZE)            |
                                                       (ptr_Channel->DMA_Periority << MDMA_CCR_PL)                    |
                                                       (ptr_Channel->DMA_M2M << MDMA_CCR_MEM2MEM);
            break;

        case MDMA_CHANNEL4:
         /* Reset the config reg */
            MDMA->DMA_CHANNEL[MDMA_CHANNEL4].DMA_CCR = 0;
            MDMA->DMA_CHANNEL[MDMA_CHANNEL4].DMA_CCR = (ptr_Channel->DMA_TransfereCompleteInterrupt << MDMA_CCR_TCIE) |
                                                       (ptr_Channel->DMA_HalfTransfereInterrupt << MDMA_CCR_HTIE)     |
                                                       (ptr_Channel->DMA_TransfereErrorInterrupt << MDMA_CCR_TEIE)    |
                                                       (ptr_Channel->DMA_Direction << MDMA_CCR_DIR)                   |
                                                       (ptr_Channel->DMA_Mode << MDMA_CCR_CIRC)                       |
                                                       (ptr_Channel->DMA_PeripheralIncrement << MDMA_CCR_PINC)        |
                                                       (ptr_Channel->DMA_MemoryIncrement << MDMA_CCR_MINC)            |
                                                       (ptr_Channel->DMA_PeripheralDataSize << MDMA_CCR_PSIZE)        |
                                                       (ptr_Channel->DMA_MemoryDataSize << MDMA_CCR_MSIZE)            |
                                                       (ptr_Channel->DMA_Periority << MDMA_CCR_PL)                    |
                                                       (ptr_Channel->DMA_M2M << MDMA_CCR_MEM2MEM);
            break;

        case MDMA_CHANNEL5:
         /* Reset the config reg */
            MDMA->DMA_CHANNEL[MDMA_CHANNEL5].DMA_CCR = 0;
            MDMA->DMA_CHANNEL[MDMA_CHANNEL5].DMA_CCR = (ptr_Channel->DMA_TransfereCompleteInterrupt << MDMA_CCR_TCIE) |
                                                       (ptr_Channel->DMA_HalfTransfereInterrupt << MDMA_CCR_HTIE)     |
                                                       (ptr_Channel->DMA_TransfereErrorInterrupt << MDMA_CCR_TEIE)    |
                                                       (ptr_Channel->DMA_Direction << MDMA_CCR_DIR)                   |
                                                       (ptr_Channel->DMA_Mode << MDMA_CCR_CIRC)                       |
                                                       (ptr_Channel->DMA_PeripheralIncrement << MDMA_CCR_PINC)        |
                                                       (ptr_Channel->DMA_MemoryIncrement << MDMA_CCR_MINC)            |
                                                       (ptr_Channel->DMA_PeripheralDataSize << MDMA_CCR_PSIZE)        |
                                                       (ptr_Channel->DMA_MemoryDataSize << MDMA_CCR_MSIZE)            |
                                                       (ptr_Channel->DMA_Periority << MDMA_CCR_PL)                    |
                                                       (ptr_Channel->DMA_M2M << MDMA_CCR_MEM2MEM);
            break;

        case MDMA_CHANNEL6:
         /* Reset the config reg */
            MDMA->DMA_CHANNEL[MDMA_CHANNEL6].DMA_CCR = 0;
            MDMA->DMA_CHANNEL[MDMA_CHANNEL6].DMA_CCR = (ptr_Channel->DMA_TransfereCompleteInterrupt << MDMA_CCR_TCIE) |
                                                       (ptr_Channel->DMA_HalfTransfereInterrupt << MDMA_CCR_HTIE)     |
                                                       (ptr_Channel->DMA_TransfereErrorInterrupt << MDMA_CCR_TEIE)    |
                                                       (ptr_Channel->DMA_Direction << MDMA_CCR_DIR)                   |
                                                       (ptr_Channel->DMA_Mode << MDMA_CCR_CIRC)                       |
                                                       (ptr_Channel->DMA_PeripheralIncrement << MDMA_CCR_PINC)        |
                                                       (ptr_Channel->DMA_MemoryIncrement << MDMA_CCR_MINC)            |
                                                       (ptr_Channel->DMA_PeripheralDataSize << MDMA_CCR_PSIZE)        |
                                                       (ptr_Channel->DMA_MemoryDataSize << MDMA_CCR_MSIZE)            |
                                                       (ptr_Channel->DMA_Periority << MDMA_CCR_PL)                    |
                                                       (ptr_Channel->DMA_M2M << MDMA_CCR_MEM2MEM);
            break;

        case MDMA_CHANNEL7:
         /* Reset the config reg */
            MDMA->DMA_CHANNEL[MDMA_CHANNEL7].DMA_CCR = 0;
            MDMA->DMA_CHANNEL[MDMA_CHANNEL7].DMA_CCR = (ptr_Channel->DMA_TransfereCompleteInterrupt << MDMA_CCR_TCIE) |
                                                       (ptr_Channel->DMA_HalfTransfereInterrupt << MDMA_CCR_HTIE)     |
                                                       (ptr_Channel->DMA_TransfereErrorInterrupt << MDMA_CCR_TEIE)    |
                                                       (ptr_Channel->DMA_Direction << MDMA_CCR_DIR)                   |
                                                       (ptr_Channel->DMA_Mode << MDMA_CCR_CIRC)                       |
                                                       (ptr_Channel->DMA_PeripheralIncrement << MDMA_CCR_PINC)        |
                                                       (ptr_Channel->DMA_MemoryIncrement << MDMA_CCR_MINC)            |
                                                       (ptr_Channel->DMA_PeripheralDataSize << MDMA_CCR_PSIZE)        |
                                                       (ptr_Channel->DMA_MemoryDataSize << MDMA_CCR_MSIZE)            |
                                                       (ptr_Channel->DMA_Periority << MDMA_CCR_PL)                    |
                                                       (ptr_Channel->DMA_M2M << MDMA_CCR_MEM2MEM);
            break;

        default:
             Local_ErrorState = NOK;
        }/* end switch */
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }
   
    return Local_ErrorState;
}


ErrorState_t MDMA_enEnableChannel(MDMA_ChannelNumber_t copy_enChannel)
{
    ErrorState_t Local_ErrorState = OK;

    if( (copy_enChannel >= MDMA_CHANNEL1) && (copy_enChannel <= MDMA_CHANNEL7) )
    {
        SET_BIT(MDMA->DMA_CHANNEL[copy_enChannel].DMA_CCR, MDMA_CCR_EN);
    }
    else
    {
        Local_ErrorState = NOK;
    }

    return Local_ErrorState;
}


ErrorState_t MDMA_enDisableChannel(MDMA_ChannelNumber_t copy_enChannel)
{
      ErrorState_t Local_ErrorState = OK;

    if( (copy_enChannel >= MDMA_CHANNEL1) && (copy_enChannel <= MDMA_CHANNEL7) )
    {
        CLR_BIT(MDMA->DMA_CHANNEL[copy_enChannel].DMA_CCR, MDMA_CCR_EN);
    }
    else
    {
        Local_ErrorState = NOK;
    }
    
    return Local_ErrorState;
}


ErrorState_t MDMA_enSetNumberOfData(MDMA_ChannelNumber_t copy_enChannel, u16 copy_u16NumberOfData)
{
    ErrorState_t Local_ErrorState = OK;

    /* The number of data can only be set when the channel is disabled */
    MDMA_enDisableChannel(copy_enChannel);

   if( (copy_enChannel >= MDMA_CHANNEL1) && (copy_enChannel <= MDMA_CHANNEL7) )
    {
        MDMA->DMA_CHANNEL[copy_enChannel].DMA_CNDTR = copy_u16NumberOfData;
    }
    else
    {
        Local_ErrorState = NOK;
    }

    return Local_ErrorState;
}


ErrorState_t MDMA_enSetPeripheralAddress(MDMA_ChannelNumber_t copy_enChannel ,u32 * ptr_Address)
{
    ErrorState_t Local_ErrorState = OK;

     /* The address can only be set when the channel is disabled */
    MDMA_enDisableChannel(copy_enChannel);

    if(ptr_Address != NULL)
    {       
        if( (copy_enChannel >= MDMA_CHANNEL1) && (copy_enChannel <= MDMA_CHANNEL7) )
        {
            MDMA->DMA_CHANNEL[copy_enChannel].DMA_CPAR = (u32)ptr_Address;
        }
        else
        {
            Local_ErrorState = NOK;
        }
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}


ErrorState_t MDMA_enSetMemoryAddress(MDMA_ChannelNumber_t copy_enChannel, u32 * ptr_Address)
{
    ErrorState_t Local_ErrorState = OK;

     /* The address can only be set when the channel is disabled */
    MDMA_enDisableChannel(copy_enChannel);

    if(ptr_Address != NULL)
    {       
        if( (copy_enChannel >= MDMA_CHANNEL1) && (copy_enChannel <= MDMA_CHANNEL7) )
        {
            MDMA->DMA_CHANNEL[copy_enChannel].DMA_CMAR = (u32)ptr_Address;
        }
        else
        {
            Local_ErrorState = NOK;
        }
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}


ErrorState_t MDMA_enSetCallback(MDMA_ChannelNumber_t copy_enChannel, void (*ptrFn)(void))
{
    ErrorState_t Local_ErrorState = OK;

    if( ptrFn != NULL )
    {
        if( (copy_enChannel >= MDMA_CHANNEL1) && (copy_enChannel <= MDMA_CHANNEL7) )
        {
            Callback[copy_enChannel] = ptrFn;
        }
        else
        {
            Local_ErrorState = NOK;
        }
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}


ErrorState_t MDMA_enGetGlobalInterruptFlag(MDMA_ChannelNumber_t copy_enChannel, u8 * ptr_ReturnValue)
{
    ErrorState_t Local_ErrorState = OK;

    if( ptr_ReturnValue != NULL )
    {
        if( (copy_enChannel >= MDMA_CHANNEL1) && (copy_enChannel <= MDMA_CHANNEL7) )
        {
            *ptr_ReturnValue = GET_BIT(MDMA->DMA_ISR, (copy_enChannel * 4) << MDMA_GI);
        }
        else
        {
            Local_ErrorState = NOK;
        }
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}


ErrorState_t MDMA_enGetHalfTransfereInterruptFlag(MDMA_ChannelNumber_t copy_enChannel, u8 * ptr_ReturnValue)
{
    ErrorState_t Local_ErrorState = OK;

    if( ptr_ReturnValue != NULL )
    {
        if( (copy_enChannel >= MDMA_CHANNEL1) && (copy_enChannel <= MDMA_CHANNEL7) )
        {
            *ptr_ReturnValue = GET_BIT(MDMA->DMA_ISR, (copy_enChannel * 4) << MDMA_HTI);
        }
        else
        {
            Local_ErrorState = NOK;
        }
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}


ErrorState_t MDMA_enGetTransfereCompleteInterruptFlag(MDMA_ChannelNumber_t copy_enChannel, u8 * ptr_ReturnValue)
{
    ErrorState_t Local_ErrorState = OK;

    if( ptr_ReturnValue != NULL )
    {
        if( (copy_enChannel >= MDMA_CHANNEL1) && (copy_enChannel <= MDMA_CHANNEL7) )
        {
            *ptr_ReturnValue = GET_BIT(MDMA->DMA_ISR, (copy_enChannel * 4) << MDMA_TCI);
        }
        else
        {
            Local_ErrorState = NOK;
        }
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}


ErrorState_t MDMA_enGetTransfereErrorInterruptFlag(MDMA_ChannelNumber_t copy_enChannel, u8 * ptr_ReturnValue)
{
    ErrorState_t Local_ErrorState = OK;

    if( ptr_ReturnValue != NULL )
    {
        if( (copy_enChannel >= MDMA_CHANNEL1) && (copy_enChannel <= MDMA_CHANNEL7) )
        {
            *ptr_ReturnValue = GET_BIT(MDMA->DMA_ISR, (copy_enChannel * 4) << MDMA_TEI);
        }
        else
        {
            Local_ErrorState = NOK;
        }
    }
    else
    {
        Local_ErrorState = NULL_POINTER_ERR;
    }

    return Local_ErrorState;
}



void DMA1_Channel1_IRQHandler(void)
{
    if(Callback[MDMA_CHANNEL1] != NULL)
    {
        Callback[MDMA_CHANNEL1]();

        /* clear all flags */
        MDMA->DMA_IFCR = (0xF) << (MDMA_CHANNEL1 * 4);

    }else{/* do nothing */}
}


void DMA1_Channel2_IRQHandler(void)
{
    if(Callback[MDMA_CHANNEL2] != NULL)
    {
        Callback[MDMA_CHANNEL2]();

        /* clear all flags */
        MDMA->DMA_IFCR = (0xF) << (MDMA_CHANNEL2 * 4);

    }else{/* do nothing */}
}


void DMA1_Channel3_IRQHandler(void)
{
    if(Callback[MDMA_CHANNEL3] != NULL)
    {
        Callback[MDMA_CHANNEL3]();

        /* clear all flags */
        MDMA->DMA_IFCR = (0xF) << (MDMA_CHANNEL3 * 4);

    }else{/* do nothing */}
}


void DMA1_Channel4_IRQHandler(void)
{
    if(Callback[MDMA_CHANNEL4] != NULL)
    {
        Callback[MDMA_CHANNEL4]();

        /* clear all flags */
        MDMA->DMA_IFCR = (0xF) << (MDMA_CHANNEL4 * 4);

    }else{/* do nothing */}
}


void DMA1_Channel5_IRQHandler(void)
{
    if(Callback[MDMA_CHANNEL5] != NULL)
    {
        Callback[MDMA_CHANNEL5]();

        /* clear all flags */
        MDMA->DMA_IFCR = (0xF) << (MDMA_CHANNEL5 * 4);

    }else{/* do nothing */}
}


void DMA1_Channel6_IRQHandler(void)
{
    if(Callback[MDMA_CHANNEL6] != NULL)
    {
        Callback[MDMA_CHANNEL6]();

        /* clear all flags */
        MDMA->DMA_IFCR = (0xF) << (MDMA_CHANNEL6 * 4);

    }else{/* do nothing */}
}


void DMA1_Channel7_IRQHandler(void)
{
    if(Callback[MDMA_CHANNEL7] != NULL)
    {
        Callback[MDMA_CHANNEL7]();

        /* clear all flags */
        MDMA->DMA_IFCR = (0xF) << (MDMA_CHANNEL7 * 4);

    }else{/* do nothing */}
}

