/*******************************************************************************
* File Name: Potenciometro.h
* Version 2.10
*
* Description:
*  Contains the function prototypes, constants and register definition of the
*  ADC SAR Sequencer Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_Potenciometro_H)
    #define CY_Potenciometro_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"
#include "Potenciometro_TempBuf_dma.h"
#include "Potenciometro_FinalBuf_dma.h"
#include "Potenciometro_SAR.h"

#define Potenciometro_NUMBER_OF_CHANNELS    (1u)
#define Potenciometro_SAMPLE_MODE           (0u)
#define Potenciometro_CLOCK_SOURCE          (0u)

extern int16  Potenciometro_finalArray[Potenciometro_NUMBER_OF_CHANNELS];
extern uint32 Potenciometro_initVar;

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component ADC_SAR_SEQ_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */


/***************************************
*        Function Prototypes
***************************************/
void Potenciometro_Init(void);
void Potenciometro_Enable(void);
void Potenciometro_Disable(void);
void Potenciometro_Start(void);
void Potenciometro_Stop(void);

uint32 Potenciometro_IsEndConversion(uint8 retMode);
int16 Potenciometro_GetResult16(uint16 chan);
int16 Potenciometro_GetAdcResult(void);
void Potenciometro_SetOffset(int32 offset);
void Potenciometro_SetResolution(uint8 resolution);
void Potenciometro_SetScaledGain(int32 adcGain);
int32 Potenciometro_CountsTo_mVolts(int16 adcCounts);
int32 Potenciometro_CountsTo_uVolts(int16 adcCounts);
float32 Potenciometro_CountsTo_Volts(int16 adcCounts);
void Potenciometro_Sleep(void);
void Potenciometro_Wakeup(void);
void Potenciometro_SaveConfig(void);
void Potenciometro_RestoreConfig(void);

CY_ISR_PROTO( Potenciometro_ISR );

/* Obsolete API for backward compatibility.
*  Should not be used in new designs.
*/
void Potenciometro_SetGain(int32 adcGain);


/**************************************
*    Initial Parameter Constants
**************************************/
#define Potenciometro_IRQ_REMOVE             (0u)                /* Removes internal interrupt */


/***************************************
*             Registers
***************************************/
#define Potenciometro_CYCLE_COUNTER_AUX_CONTROL_REG \
                                               (*(reg8 *) Potenciometro_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG)
#define Potenciometro_CYCLE_COUNTER_AUX_CONTROL_PTR \
                                               ( (reg8 *) Potenciometro_bSAR_SEQ_ChannelCounter__CONTROL_AUX_CTL_REG)
#define Potenciometro_CONTROL_REG    (*(reg8 *) \
                                             Potenciometro_bSAR_SEQ_CtrlReg__CONTROL_REG)
#define Potenciometro_CONTROL_PTR    ( (reg8 *) \
                                             Potenciometro_bSAR_SEQ_CtrlReg__CONTROL_REG)
#define Potenciometro_COUNT_REG      (*(reg8 *) \
                                             Potenciometro_bSAR_SEQ_ChannelCounter__COUNT_REG)
#define Potenciometro_COUNT_PTR      ( (reg8 *) \
                                             Potenciometro_bSAR_SEQ_ChannelCounter__COUNT_REG)
#define Potenciometro_STATUS_REG     (*(reg8 *) Potenciometro_bSAR_SEQ_EOCSts__STATUS_REG)
#define Potenciometro_STATUS_PTR     ( (reg8 *) Potenciometro_bSAR_SEQ_EOCSts__STATUS_REG)

#define Potenciometro_SAR_DATA_ADDR_0 (Potenciometro_SAR_ADC_SAR__WRK0)
#define Potenciometro_SAR_DATA_ADDR_1 (Potenciometro_SAR_ADC_SAR__WRK1)
#define Potenciometro_SAR_DATA_ADDR_0_REG (*(reg8 *) \
                                              Potenciometro_SAR_ADC_SAR__WRK0)
#define Potenciometro_SAR_DATA_ADDR_1_REG (*(reg8 *) \
                                              Potenciometro_SAR_ADC_SAR__WRK1)


/**************************************
*       Register Constants
**************************************/

#if(Potenciometro_IRQ_REMOVE == 0u)

    /* Priority of the ADC_SAR_IRQ interrupt. */
    #define Potenciometro_INTC_PRIOR_NUMBER          (uint8)(Potenciometro_IRQ__INTC_PRIOR_NUM)

    /* ADC_SAR_IRQ interrupt number */
    #define Potenciometro_INTC_NUMBER                (uint8)(Potenciometro_IRQ__INTC_NUMBER)

#endif   /* End Potenciometro_IRQ_REMOVE */


/***************************************
*       API Constants
***************************************/

/* Constants for IsEndConversion() "retMode" parameter */
#define Potenciometro_RETURN_STATUS              (0x01u)
#define Potenciometro_WAIT_FOR_RESULT            (0x00u)

/* Defines for the Resolution parameter */
#define Potenciometro_BITS_12    Potenciometro_SAR__BITS_12
#define Potenciometro_BITS_10    Potenciometro_SAR__BITS_10
#define Potenciometro_BITS_8     Potenciometro_SAR__BITS_8

#define Potenciometro_CYCLE_COUNTER_ENABLE    (0x20u)
#define Potenciometro_BASE_COMPONENT_ENABLE   (0x01u)
#define Potenciometro_LOAD_COUNTER_PERIOD     (0x02u)
#define Potenciometro_SOFTWARE_SOC_PULSE      (0x04u)

/* Generic DMA Configuration parameters */
#define Potenciometro_TEMP_BYTES_PER_BURST     (uint8)(2u)
#define Potenciometro_TEMP_TRANSFER_COUNT      ((uint16)Potenciometro_NUMBER_OF_CHANNELS << 1u)
#define Potenciometro_FINAL_BYTES_PER_BURST    ((uint16)Potenciometro_NUMBER_OF_CHANNELS << 1u)
#define Potenciometro_REQUEST_PER_BURST        (uint8)(1u)

#define Potenciometro_GET_RESULT_INDEX_OFFSET    ((uint8)Potenciometro_NUMBER_OF_CHANNELS - 1u)

/* Define for Sample Mode  */
#define Potenciometro_SAMPLE_MODE_FREE_RUNNING    (0x00u)
#define Potenciometro_SAMPLE_MODE_SW_TRIGGERED    (0x01u)
#define Potenciometro_SAMPLE_MODE_HW_TRIGGERED    (0x02u)

/* Define for Clock Source  */
#define Potenciometro_CLOCK_INTERNAL              (0x00u)
#define Potenciometro_CLOCK_EXTERNAL              (0x01u)


/***************************************
*        Optional Function Prototypes
***************************************/
#if(Potenciometro_SAMPLE_MODE != Potenciometro_SAMPLE_MODE_HW_TRIGGERED)
    void Potenciometro_StartConvert(void);
    void Potenciometro_StopConvert(void);
#endif /* Potenciometro_SAMPLE_MODE != Potenciometro_SAMPLE_MODE_HW_TRIGGERED */

#endif  /* !defined(CY_Potenciometro_H) */

/* [] END OF FILE */
