/*******************************************************************************
* File Name: ResistiveTouch_1_ADC.c
* Version 3.20
*
* Description:
*  This file provides the source code to the API for the Delta-Sigma ADC
*  Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ResistiveTouch_1_ADC.h"

#if(ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK)
    #include "ResistiveTouch_1_ADC_theACLK.h"
#endif /* ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK */

#include "ResistiveTouch_1_ADC_Ext_CP_Clk.h"

#if(ResistiveTouch_1_ADC_DEFAULT_INPUT_MODE)
    #include "ResistiveTouch_1_ADC_AMux.h"
#endif /* ResistiveTouch_1_ADC_DEFAULT_INPUT_MODE */


/***************************************
* Global data allocation
***************************************/

/* Software flag for checking conversion completed or not */
volatile uint8 ResistiveTouch_1_ADC_convDone = 0u;

/* Software flag to stop conversion for single sample conversion mode
*   with resolution above 16 bits 
*/
volatile uint8 ResistiveTouch_1_ADC_stopConversion = 0u;

/* To run the initialization block only at the start up */
uint8 ResistiveTouch_1_ADC_initVar = 0u;

/* To check whether ADC started or not before switching the configuration */
volatile uint8 ResistiveTouch_1_ADC_started = 0u;

/* Flag to hold ADC config number. By default active config is 1. */
volatile uint8 ResistiveTouch_1_ADC_Config = 1u;

volatile int32 ResistiveTouch_1_ADC_Offset;
volatile int32 ResistiveTouch_1_ADC_CountsPerVolt;


/***************************************
* Local data allocation
***************************************/

/* The array with precalculated gain compensation coefficients */
static ResistiveTouch_1_ADC_GCOR_STRUCT ResistiveTouch_1_ADC_gcor[ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS];



/***************************************
* Forward function references
***************************************/
static void ResistiveTouch_1_ADC_InitConfig(uint8 config) ;
static void ResistiveTouch_1_ADC_GainCompensation(uint8 inputRange, uint16 idealDecGain, uint16 idealOddDecGain, 
                            uint8 resolution, uint8 config) ;
static void ResistiveTouch_1_ADC_SetDSMRef0Reg(uint8 value) ;


/******************************************************************************
* Function Name: ResistiveTouch_1_ADC_Init
*******************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
* ResistiveTouch_1_ADC_Start().
*
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_ADC_Init(void) 
{

    ResistiveTouch_1_ADC_Config = 1u;
    ResistiveTouch_1_ADC_convDone = 0u;

    ResistiveTouch_1_ADC_Ext_CP_Clk_SetMode(CYCLK_DUTY);

    /* This is only valid if there is an internal clock */
    #if(ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK)
        ResistiveTouch_1_ADC_theACLK_SetMode(CYCLK_DUTY);
    #endif /* ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK */

    #if(ResistiveTouch_1_ADC_IRQ_REMOVE == 0u)
        /* Set interrupt priority */
        CyIntSetPriority(ResistiveTouch_1_ADC_INTC_NUMBER, ResistiveTouch_1_ADC_INTC_PRIOR_NUMBER);
    #endif   /* End ResistiveTouch_1_ADC_IRQ_REMOVE */

    /* Init static registers with common configuration */
    ResistiveTouch_1_ADC_DSM_DEM0_REG    = ResistiveTouch_1_ADC_CFG1_DSM_DEM0;
    ResistiveTouch_1_ADC_DSM_DEM1_REG    = ResistiveTouch_1_ADC_CFG1_DSM_DEM1;
    ResistiveTouch_1_ADC_DSM_MISC_REG    = ResistiveTouch_1_ADC_CFG1_DSM_MISC;
    ResistiveTouch_1_ADC_DSM_CLK_REG    |= ResistiveTouch_1_ADC_CFG1_DSM_CLK;
    ResistiveTouch_1_ADC_DSM_REF1_REG    = ResistiveTouch_1_ADC_CFG1_DSM_REF1;

    ResistiveTouch_1_ADC_DSM_OUT0_REG    = ResistiveTouch_1_ADC_CFG1_DSM_OUT0;
    ResistiveTouch_1_ADC_DSM_OUT1_REG    = ResistiveTouch_1_ADC_CFG1_DSM_OUT1;

    ResistiveTouch_1_ADC_DSM_CR0_REG     = ResistiveTouch_1_ADC_CFG1_DSM_CR0;
    ResistiveTouch_1_ADC_DSM_CR1_REG     = ResistiveTouch_1_ADC_CFG1_DSM_CR1;
#if(ResistiveTouch_1_ADC_MI_ENABLE != 0u) /* Enable Modulator Input */
    ResistiveTouch_1_ADC_DSM_CR3_REG     |= ResistiveTouch_1_ADC_DSM_MODBIT_EN;
#else
    ResistiveTouch_1_ADC_DSM_CR3_REG     = ResistiveTouch_1_ADC_CFG1_DSM_CR3;
#endif /* ResistiveTouch_1_ADC_MI_ENABLE != 0u*/    
    ResistiveTouch_1_ADC_DSM_CR8_REG     = ResistiveTouch_1_ADC_CFG1_DSM_CR8;
    ResistiveTouch_1_ADC_DSM_CR9_REG     = ResistiveTouch_1_ADC_CFG1_DSM_CR9;
    ResistiveTouch_1_ADC_DSM_CR13_REG    = ResistiveTouch_1_ADC_CFG1_DSM_CR13;

    ResistiveTouch_1_ADC_DEC_SR_REG      = ResistiveTouch_1_ADC_CFG1_DEC_SR;

    /* Calculate Gain compensation coefficients for all configurations */
    ResistiveTouch_1_ADC_GainCompensation(ResistiveTouch_1_ADC_CFG1_INPUT_RANGE,
                                      ResistiveTouch_1_ADC_CFG1_IDEAL_DEC_GAIN,
                                      ResistiveTouch_1_ADC_CFG1_IDEAL_ODDDEC_GAIN,
                                      ResistiveTouch_1_ADC_CFG1_RESOLUTION,
                                      ResistiveTouch_1_ADC_CFG1);
    #if(ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 1)
        ResistiveTouch_1_ADC_GainCompensation(ResistiveTouch_1_ADC_CFG2_INPUT_RANGE,
                                          ResistiveTouch_1_ADC_CFG2_IDEAL_DEC_GAIN,
                                          ResistiveTouch_1_ADC_CFG2_IDEAL_ODDDEC_GAIN,
                                          ResistiveTouch_1_ADC_CFG2_RESOLUTION,
                                          ResistiveTouch_1_ADC_CFG2);
    #endif /* ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 1 */
    #if(ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 2)
        ResistiveTouch_1_ADC_GainCompensation(ResistiveTouch_1_ADC_CFG3_INPUT_RANGE,
                                          ResistiveTouch_1_ADC_CFG3_IDEAL_DEC_GAIN,
                                          ResistiveTouch_1_ADC_CFG3_IDEAL_ODDDEC_GAIN,
                                          ResistiveTouch_1_ADC_CFG3_RESOLUTION,
                                          ResistiveTouch_1_ADC_CFG3);
    #endif /* ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 2 */
    #if(ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 3)
        ResistiveTouch_1_ADC_GainCompensation(ResistiveTouch_1_ADC_CFG4_INPUT_RANGE,
                                          ResistiveTouch_1_ADC_CFG4_IDEAL_DEC_GAIN,
                                          ResistiveTouch_1_ADC_CFG4_IDEAL_ODDDEC_GAIN,
                                          ResistiveTouch_1_ADC_CFG4_RESOLUTION,
                                          ResistiveTouch_1_ADC_CFG4);
    #endif /* ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 3 */

    /* Set GCOR register for config1 */
    ResistiveTouch_1_ADC_DEC_GVAL_REG = ResistiveTouch_1_ADC_gcor[ResistiveTouch_1_ADC_Config - 1u].gval;
    CY_SET_REG16(ResistiveTouch_1_ADC_DEC_GCOR_16B_PTR, ResistiveTouch_1_ADC_gcor[ResistiveTouch_1_ADC_Config - 1u].gcor);

    /* Initialize the registers with default customizer settings for config1 */
    ResistiveTouch_1_ADC_InitConfig(ResistiveTouch_1_ADC_Config);
}


/******************************************************************************
* Function Name: ResistiveTouch_1_ADC_Enable
*******************************************************************************
*
* Summary:
*  Enables the ADC DelSig block operation.
*
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_ADC_Enable(void) 
{
	uint8 config;
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    /* Read volatile variable to the local variable */
    config = ResistiveTouch_1_ADC_Config;
    
    /* Enable active mode power for ADC */
    ResistiveTouch_1_ADC_PWRMGR_DEC_REG |= ResistiveTouch_1_ADC_ACT_PWR_DEC_EN;
    ResistiveTouch_1_ADC_PWRMGR_DSM_REG |= ResistiveTouch_1_ADC_ACT_PWR_DSM_EN;

     /* Enable alternative active mode power for ADC */
    ResistiveTouch_1_ADC_STBY_PWRMGR_DEC_REG |= ResistiveTouch_1_ADC_STBY_PWR_DEC_EN;
    ResistiveTouch_1_ADC_STBY_PWRMGR_DSM_REG |= ResistiveTouch_1_ADC_STBY_PWR_DSM_EN;

    /* Disable PRES, Enable power to VCMBUF0, REFBUF0 and REFBUF1, enable PRES */
    ResistiveTouch_1_ADC_RESET_CR4_REG |= ResistiveTouch_1_ADC_IGNORE_PRESA1;
    ResistiveTouch_1_ADC_RESET_CR5_REG |= ResistiveTouch_1_ADC_IGNORE_PRESA2;

    ResistiveTouch_1_ADC_DSM_CR17_REG |= (ResistiveTouch_1_ADC_DSM_EN_BUF_VREF | ResistiveTouch_1_ADC_DSM_EN_BUF_VCM);

    /* Code to disable the REFBUF0 if reference chosen is External ref */
    #if (((ResistiveTouch_1_ADC_CFG1_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P03) || \
          (ResistiveTouch_1_ADC_CFG1_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P32)) || \
         ((ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 1) && \
          ((ResistiveTouch_1_ADC_CFG2_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P03) ||  \
           (ResistiveTouch_1_ADC_CFG2_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P32))) || \
         ((ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 2) && \
          ((ResistiveTouch_1_ADC_CFG3_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P03) ||  \
           (ResistiveTouch_1_ADC_CFG3_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P32))) || \
         ((ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 3) && \
          ((ResistiveTouch_1_ADC_CFG4_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P03) || \
           (ResistiveTouch_1_ADC_CFG4_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P32))))
        if (((config == 1u) &&
            ((ResistiveTouch_1_ADC_CFG1_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P03) ||
             (ResistiveTouch_1_ADC_CFG1_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P32))) ||
            ((config == 2u) &&
            ((ResistiveTouch_1_ADC_CFG2_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P03) ||
             (ResistiveTouch_1_ADC_CFG2_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P32))) ||
            ((config == 3u) &&
            ((ResistiveTouch_1_ADC_CFG3_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P03) ||
             (ResistiveTouch_1_ADC_CFG3_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P32))) ||
            ((config == 4u) &&
            ((ResistiveTouch_1_ADC_CFG4_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P03) ||
             (ResistiveTouch_1_ADC_CFG4_REFERENCE == ResistiveTouch_1_ADC_EXT_REF_ON_P32))))
        {
            /* Disable the REFBUF0 */
            ResistiveTouch_1_ADC_DSM_CR17_REG &= (uint8)~ResistiveTouch_1_ADC_DSM_EN_BUF_VREF;
        }
    #endif /* External ref */

    #if (((ResistiveTouch_1_ADC_CFG1_INPUT_RANGE == ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF) || \
         ((ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 1) && \
          (ResistiveTouch_1_ADC_CFG2_INPUT_RANGE == ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF)) || \
         ((ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 2) && \
          (ResistiveTouch_1_ADC_CFG3_INPUT_RANGE == ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF)) || \
         ((ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 3) && \
          (ResistiveTouch_1_ADC_CFG4_INPUT_RANGE == ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF))))
        if(((config == 1u) &&
            (ResistiveTouch_1_ADC_CFG1_INPUT_RANGE == ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF) &&
            ((ResistiveTouch_1_ADC_CFG1_REFERENCE != ResistiveTouch_1_ADC_EXT_REF_ON_P03) &&
             (ResistiveTouch_1_ADC_CFG1_REFERENCE != ResistiveTouch_1_ADC_EXT_REF_ON_P32))) ||
             ((config == 2u) &&
              (ResistiveTouch_1_ADC_CFG2_INPUT_RANGE == ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF) &&
             ((ResistiveTouch_1_ADC_CFG2_REFERENCE != ResistiveTouch_1_ADC_EXT_REF_ON_P03) &&
             (ResistiveTouch_1_ADC_CFG2_REFERENCE != ResistiveTouch_1_ADC_EXT_REF_ON_P32))) ||
             ((config == 3u) &&
              (ResistiveTouch_1_ADC_CFG3_INPUT_RANGE == ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF) &&
             ((ResistiveTouch_1_ADC_CFG3_REFERENCE != ResistiveTouch_1_ADC_EXT_REF_ON_P03) &&
             (ResistiveTouch_1_ADC_CFG3_REFERENCE != ResistiveTouch_1_ADC_EXT_REF_ON_P32))) ||
             ((config == 4u) &&
              (ResistiveTouch_1_ADC_CFG4_INPUT_RANGE == ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF) &&
             ((ResistiveTouch_1_ADC_CFG4_REFERENCE != ResistiveTouch_1_ADC_EXT_REF_ON_P03) &&
             (ResistiveTouch_1_ADC_CFG4_REFERENCE != ResistiveTouch_1_ADC_EXT_REF_ON_P32))))
        {
            /* Enable the REFBUF1 */
            ResistiveTouch_1_ADC_DSM_REF0_REG |= ResistiveTouch_1_ADC_DSM_EN_BUF_VREF_INN;
        }
    #endif /* VSSA_TO_2VREF */
    if(config != 0u)
    {
        /* Suppress compiler warning */
    }

    /* Wait for 3 microseconds */
    CyDelayUs(ResistiveTouch_1_ADC_PRES_DELAY_TIME);

    /* Enable the press circuit */
    ResistiveTouch_1_ADC_RESET_CR4_REG &= (uint8)~ResistiveTouch_1_ADC_IGNORE_PRESA1;
    ResistiveTouch_1_ADC_RESET_CR5_REG &= (uint8)~ResistiveTouch_1_ADC_IGNORE_PRESA2;

    /* Enable negative pumps for DSM  */
    ResistiveTouch_1_ADC_PUMP_CR1_REG  |= ( ResistiveTouch_1_ADC_PUMP_CR1_CLKSEL | ResistiveTouch_1_ADC_PUMP_CR1_FORCE );

    /* Enable Modulator Chopping if required */
    ResistiveTouch_1_ADC_DSM_CR2_REG = ResistiveTouch_1_ADC_CFG1_DSM_CR2;

    /* This is only valid if there is an internal clock */
    #if(ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK)
        ResistiveTouch_1_ADC_PWRMGR_CLK_REG |= ResistiveTouch_1_ADC_ACT_PWR_CLK_EN;
        ResistiveTouch_1_ADC_STBY_PWRMGR_CLK_REG |= ResistiveTouch_1_ADC_STBY_PWR_CLK_EN;
    #endif /* ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK */

    /* Enable the active and alternate active power for charge pump clock */
    ResistiveTouch_1_ADC_PWRMGR_CHARGE_PUMP_CLK_REG |= ResistiveTouch_1_ADC_ACT_PWR_CHARGE_PUMP_CLK_EN;
    ResistiveTouch_1_ADC_STBY_PWRMGR_CHARGE_PUMP_CLK_REG |= ResistiveTouch_1_ADC_STBY_PWR_CHARGE_PUMP_CLK_EN;

    #if(ResistiveTouch_1_ADC_IRQ_REMOVE == 0u)
        /* Clear a pending interrupt */
        CyIntClearPending(ResistiveTouch_1_ADC_INTC_NUMBER);
        /* Enable interrupt */
        CyIntEnable(ResistiveTouch_1_ADC_INTC_NUMBER);
    #endif   /* End ResistiveTouch_1_ADC_IRQ_REMOVE */

    CyExitCriticalSection(enableInterrupts);

}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_Start
********************************************************************************
*
* Summary:
*  Performs all required initialization for this component and enables
*  the power. It configure all the register the first time it is called.
*  Subsequent calls of the Start function only enable the ADC and turn
*  on the power. If multiple configurations are selected, it will
*  configure the ADC for configuration 1 by default, unless the
*  ResistiveTouch_1_ADC_SelectConfiguration( ) function has been called to change
*  the default setting.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  ResistiveTouch_1_ADC_initVar:  Used to check the initial configuration,
*  modified when this function is called for the first time.
*
*******************************************************************************/
void ResistiveTouch_1_ADC_Start(void) 
{
    if(ResistiveTouch_1_ADC_initVar == 0u)
    {
        if(ResistiveTouch_1_ADC_started == 0u)
        {
            ResistiveTouch_1_ADC_Init();
        }
        ResistiveTouch_1_ADC_initVar = 1u;
    }

    /* Enable the ADC */
    ResistiveTouch_1_ADC_Enable();
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_Stop
********************************************************************************
*
* Summary:
*  This function stops and powers down the ADC component and the internal
*  clock if the external clock is not selected. If an external clock is
*  used, it is up to the designer to power down the external clock it
*  required.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_ADC_Stop(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    /* Stop conversions */
    ResistiveTouch_1_ADC_DEC_CR_REG &= (uint8)~ResistiveTouch_1_ADC_DEC_START_CONV;
    ResistiveTouch_1_ADC_DEC_SR_REG |=  ResistiveTouch_1_ADC_DEC_INTR_CLEAR;

    /* Disable PRES, Disable power to VCMBUF0, REFBUF0 and REFBUF1,
       enable PRES */
    ResistiveTouch_1_ADC_RESET_CR4_REG |= ResistiveTouch_1_ADC_IGNORE_PRESA1;
    ResistiveTouch_1_ADC_RESET_CR5_REG |= ResistiveTouch_1_ADC_IGNORE_PRESA2;

    ResistiveTouch_1_ADC_DSM_CR17_REG &= (uint8)~(ResistiveTouch_1_ADC_DSM_EN_BUF_VREF | ResistiveTouch_1_ADC_DSM_EN_BUF_VCM);
    ResistiveTouch_1_ADC_DSM_REF0_REG &= (uint8)~ResistiveTouch_1_ADC_DSM_EN_BUF_VREF_INN;

    /* Wait for 3 microseconds. */
    CyDelayUs(ResistiveTouch_1_ADC_PRES_DELAY_TIME);

    /* Enable the press circuit */
    ResistiveTouch_1_ADC_RESET_CR4_REG &= (uint8)~ResistiveTouch_1_ADC_IGNORE_PRESA1;
    ResistiveTouch_1_ADC_RESET_CR5_REG &= (uint8)~ResistiveTouch_1_ADC_IGNORE_PRESA2;

    /* Disable power to the ADC */
    ResistiveTouch_1_ADC_PWRMGR_DSM_REG &= (uint8)~ResistiveTouch_1_ADC_ACT_PWR_DSM_EN;

    /* Disable power to Decimator block */
    ResistiveTouch_1_ADC_PWRMGR_DEC_REG &= (uint8)~ResistiveTouch_1_ADC_ACT_PWR_DEC_EN;

    /* Disable alternative active power to the ADC */
    ResistiveTouch_1_ADC_STBY_PWRMGR_DEC_REG &= (uint8)~ResistiveTouch_1_ADC_STBY_PWR_DEC_EN;
    ResistiveTouch_1_ADC_STBY_PWRMGR_DSM_REG &= (uint8)~ResistiveTouch_1_ADC_STBY_PWR_DSM_EN;

   /* Disable negative pumps for DSM  */
    ResistiveTouch_1_ADC_PUMP_CR1_REG &= (uint8)~(ResistiveTouch_1_ADC_PUMP_CR1_CLKSEL | ResistiveTouch_1_ADC_PUMP_CR1_FORCE );

    /* This is only valid if there is an internal clock */
    #if(ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK)
        ResistiveTouch_1_ADC_PWRMGR_CLK_REG &= (uint8)~ResistiveTouch_1_ADC_ACT_PWR_CLK_EN;
        ResistiveTouch_1_ADC_STBY_PWRMGR_CLK_REG &= (uint8)~ResistiveTouch_1_ADC_STBY_PWR_CLK_EN;
    #endif /* ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK */

    /* Disable Modulator Chopping */
    ResistiveTouch_1_ADC_DSM_CR2_REG &= (uint8)~ResistiveTouch_1_ADC_DSM_MOD_CHOP_EN;
    /* Disable power to charge pump clock */
    ResistiveTouch_1_ADC_PWRMGR_CHARGE_PUMP_CLK_REG &= (uint8)~ResistiveTouch_1_ADC_ACT_PWR_CHARGE_PUMP_CLK_EN;
    ResistiveTouch_1_ADC_STBY_PWRMGR_CHARGE_PUMP_CLK_REG &= (uint8)~ResistiveTouch_1_ADC_STBY_PWR_CHARGE_PUMP_CLK_EN;
    
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_SetBufferGain
********************************************************************************
*
* Summary:
*  Sets input buffer gain.
*
* Parameters:
*  gain:  Two bit value to select a gain of 1, 2, 4, or 8.
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_ADC_SetBufferGain(uint8 gain) 
{
    uint8 tmpReg;
    tmpReg = ResistiveTouch_1_ADC_DSM_BUF1_REG & (uint8)~ResistiveTouch_1_ADC_DSM_GAIN_MASK;
    tmpReg |= (uint8)(gain << ResistiveTouch_1_ADC_DSM_GAIN_SHIFT) & ResistiveTouch_1_ADC_DSM_GAIN_MASK;
    ResistiveTouch_1_ADC_DSM_BUF1_REG = tmpReg;
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_SetCoherency
********************************************************************************
*
* Summary:
*  This function allows the user to change which of the ADC's 3 word
*  result will trigger a coherency unlock. The ADC's result will not be
*  updated until the set byte is read either by the ADC or DMA. 
*  By default the LSB is the coherency byte for right alignment data format. 
*  The middle or high byte is set automatically depend on left alignment 
*  configuration for DMA data transfer.
*  If DMA or if a custom API requires different byte to be read the last,
*  this API should be used to set the last byte of the ADC result that is read. 
*  If a multibyte read is performed either by DMA or the ARM processor, the
*  coherency can be set to any byte in the last word read.
*
* Parameters:
*  coherency:  Two bit value to set the coherency bit.
*           00-Coherency checking off
*           01-low byte is key byte
*           02-middle byte is the key byte
*           03-high byte is the key byte
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_ADC_SetCoherency(uint8 coherency) 
{
    uint8 tmpReg;

    tmpReg = ResistiveTouch_1_ADC_DEC_COHER_REG & (uint8)~ResistiveTouch_1_ADC_DEC_SAMP_KEY_MASK;
    tmpReg |= coherency & ResistiveTouch_1_ADC_DEC_SAMP_KEY_MASK;
    ResistiveTouch_1_ADC_DEC_COHER_REG = tmpReg;
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_SetGCOR
********************************************************************************
*
* Summary:
*  Calculates a new GCOR value and writes it into the GCOR register. 
*  The GCOR value is a 16-bit value that represents a gain of 0 to 2. 
*  The ADC result is multiplied by this value before it is placed in the ADC 
*  output registers. The numerical format for the GCOR value is:
*  0x0000 -> 0.000
*  0x8000 -> 1.000
*  0xFFFF -> 1.99997
*  When executing the function, the old GCOR value is multiplied by
*  gainAdjust and reloaded into the GCOR register.
*
* Parameters:
*  gainAdjust:  floating point value to set GCOR registers.
*
* Return:
*  uint8: 0 - if GCOR value is within the expected range.
*         1 - the correction value is outside GCOR value range of
*             0.00 to 1.9999.
*
* Side Effects:  The GVAL register is set to the amount of valid bits in the
*                GCOR  register minus one. If GVAL is 15 (0x0F), all 16 bits
*                of the GCOR registers will be valid. If for example GVAL is
*                11 (0x0B) only 12 bits will be valid. The least 4 bits will
*                be lost when the GCOR value is shifted 4 places to the right.
*
******************************************************************************/
uint8 ResistiveTouch_1_ADC_SetGCOR(float32 gainAdjust) 
{
    uint16 tmpReg;
    uint8 status;
    float32 tmpValue;

    tmpReg = ResistiveTouch_1_ADC_gcor[ResistiveTouch_1_ADC_Config - 1u].gcor;
    tmpValue = ((float32)tmpReg / (float32)ResistiveTouch_1_ADC_IDEAL_GAIN_CONST);
    tmpValue = tmpValue * gainAdjust;

    if (tmpValue > 1.9999)
    {
        status = 1u;
    }
    else
    {
        tmpValue *= (float32)ResistiveTouch_1_ADC_IDEAL_GAIN_CONST;
		tmpReg = (uint16)tmpValue;
        CY_SET_REG16(ResistiveTouch_1_ADC_DEC_GCOR_16B_PTR, tmpReg);
        /* Update gain array to be used by SelectConfiguration() API */
       ResistiveTouch_1_ADC_gcor[ResistiveTouch_1_ADC_Config - 1u].gcor = tmpReg;

        status = 0u;

    }
    return(status);
}


/******************************************************************************
* Function Name: ResistiveTouch_1_ADC_ReadGCOR
*******************************************************************************
*
* Summary:
*  This API returns the current GCOR register value, normalized based on the
*  GVAL register settings.
*  For example, if the GCOR value is 0x0812 and the GVAL register is set to 
*  11 (0x0B) then the returned value will be shifted by for bits to the left.
*  (Actual GCOR value = 0x0812, returned value = 0x8120)
*
* Parameters:
*  None
*
* Return:
*  uint16:  Normalized GCOR value.
*
*******************************************************************************/
uint16 ResistiveTouch_1_ADC_ReadGCOR(void) 
{
    uint8 gValue;
    uint16 gcorValue;

    gValue = ResistiveTouch_1_ADC_DEC_GVAL_REG;
    gcorValue = CY_GET_REG16(ResistiveTouch_1_ADC_DEC_GCOR_16B_PTR);

    if (gValue < ResistiveTouch_1_ADC_MAX_GVAL)
    {
        gcorValue <<= ResistiveTouch_1_ADC_MAX_GVAL - gValue;
    }

    return gcorValue;
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_StartConvert
********************************************************************************
*
* Summary:
*  Forces the ADC to initiate a conversion. If in the "Single Sample"
*  mode, one conversion will be performed then the ADC will halt. If in
*  one of the other three conversion modes, the ADC will run
*  continuously until the ADC_Stop() or ADC_StopConvert() is called.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_ADC_StartConvert(void) 
{
    /* Start the conversion */
    ResistiveTouch_1_ADC_DEC_CR_REG |= ResistiveTouch_1_ADC_DEC_START_CONV;
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_StopConvert
********************************************************************************
*
* Summary:
*  Forces the ADC to stop all conversions. If the ADC is in the middle of a
*  conversion, the ADC will be reset and not provide a result for that partial
*  conversion.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_ADC_StopConvert(void) 
{
    /* Stop all conversions */
    ResistiveTouch_1_ADC_DEC_CR_REG &= (uint8)~ResistiveTouch_1_ADC_DEC_START_CONV;
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_IsEndConversion
********************************************************************************
*
* Summary:
*  Checks the status that the most recently started conversion has completed.
*  The status is cleared by any of ADC_GetResult8(), ADC_GetResult16() or 
*  ADC_GetResult32() API.
*  This function provides the programmer with two options. In one mode this 
*  function immediately returns with the conversion status. In the other mode,
*  the function does not return (blocking) until the conversion has completed.
*
* Parameters:
*  retMode: Check conversion return mode. See the following table for options.
*   ResistiveTouch_1_ADC_RETURN_STATUS -   Immediately returns conversion result
*                                      status.
*   ResistiveTouch_1_ADC_WAIT_FOR_RESULT - Does not return until ADC conversion
*                                      is complete.
*
* Return:
*  If a nonzero value is returned, the last conversion has completed.
*  If the returned value is zero, the ADC is still calculating the last result.
*
* Global variables:
*  ResistiveTouch_1_ADC_convDone:  Used to check whether conversion is complete
*  or not for single sample mode with resolution is above 16
*
*******************************************************************************/
uint8 ResistiveTouch_1_ADC_IsEndConversion(uint8 retMode) 
{
    uint8 status;

    do
    {
        /* Check for stop convert if conversion mode is Single Sample with
        *   resolution above 16 bit
        */
        if(ResistiveTouch_1_ADC_stopConversion != 0u)
        {
            status = ResistiveTouch_1_ADC_convDone;
        }
        else
        {
            status = ResistiveTouch_1_ADC_DEC_SR_REG & ResistiveTouch_1_ADC_DEC_CONV_DONE;
        }
    }while((status != ResistiveTouch_1_ADC_DEC_CONV_DONE) && (retMode == ResistiveTouch_1_ADC_WAIT_FOR_RESULT));

    return(status);
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_GetResult8
********************************************************************************
*
* Summary:
*  This function returns the result of an 8-bit conversion. If the
*  resolution is set greater than 8-bits, the LSB of the result will be
*  returned. When the ADC is configured for 8-bit single ended mode,
*  the ADC_GetResult16() function should be used instead. This
*  function returns only signed 8-bit values. The maximum positive
*  signed 8-bit value is 127, but in singled ended 8-bit mode, the
*  maximum positive value is 255.
*
* Parameters:
*  None
*
* Return:
*  int8: The LSB of the last ADC conversion.
*
* Global variables:
*  ResistiveTouch_1_ADC_convDone:  Cleared in single sample mode with resolution
*                              above 16 bits
*
*******************************************************************************/
int8 ResistiveTouch_1_ADC_GetResult8( void ) 
{
    int8 result;
    uint8 coherency;

    /* Read active coherency configuration */
    coherency = ResistiveTouch_1_ADC_DEC_COHER_REG & ResistiveTouch_1_ADC_DEC_SAMP_KEY_MASK;

    result = (int8)ResistiveTouch_1_ADC_DEC_SAMP_REG;

    if(coherency == ResistiveTouch_1_ADC_DEC_SAMP_KEY_MID)
    {   /* Dummy read of the middle byte to unlock the coherency */
        (void)ResistiveTouch_1_ADC_DEC_SAMPM_REG;
    }
    else  if(coherency == ResistiveTouch_1_ADC_DEC_SAMP_KEY_HIGH)
    {   /* Dummy read of the MSB byte to unlock the coherency */
        (void)ResistiveTouch_1_ADC_DEC_SAMPH_REG;
    }
    else /*No action required for other coherency */
    {
    }
    /* Clear conversion complete status in Single Sample mode with resolution above 16 bit */
    if(ResistiveTouch_1_ADC_stopConversion != 0u)
    {
        ResistiveTouch_1_ADC_convDone = 0u;
    }
    return (result);
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_GetResult16
********************************************************************************
*
* Summary:
*  Returns a 16-bit result for a conversion with a result that has a
*  resolution of 8 to 16 bits. If the resolution is set greater than 16-bits,
*  it will return the 16 least significant bits of the result. When the ADC
*  is configured for 16-bit single ended mode, the ADC_GetResult32()
*  function should be used instead. This function returns only signed
*  16-bit result, which allows a maximum positive value of 32767, not 65535.
*  This function supports different coherency settings.
*
* Parameters:
*   void
*
* Return:
*  int16:  ADC result.
*
* Global variables:
*  ResistiveTouch_1_ADC_convDone:  Cleared in single sample mode with resolution
*                              above 16 bits
*
*******************************************************************************/
int16 ResistiveTouch_1_ADC_GetResult16(void) 
{
    uint16 result;
    uint8 coherency;

    /* Read active coherency configuration */
    coherency = ResistiveTouch_1_ADC_DEC_COHER_REG & ResistiveTouch_1_ADC_DEC_SAMP_KEY_MASK;

    if(coherency <= ResistiveTouch_1_ADC_DEC_SAMP_KEY_LOW)
    {   /*  Use default method to read result registers i.e. LSB byte read at the end*/
        #if (CY_PSOC3)
            result = ResistiveTouch_1_ADC_DEC_SAMPM_REG;
            result = (result << 8u) | ResistiveTouch_1_ADC_DEC_SAMP_REG;
        #else
            result = (CY_GET_REG16(ResistiveTouch_1_ADC_DEC_SAMP_16B_PTR));
        #endif /* CY_PSOC3 */
    }
    else /* MID or HIGH */
    {   /* Read middle byte at the end */
        #if (CY_PSOC3)
            result = (CY_GET_REG16(ResistiveTouch_1_ADC_DEC_SAMP_16B_PTR));
        #else
            result = ResistiveTouch_1_ADC_DEC_SAMP_REG;
            result |=  (uint16)((uint16)ResistiveTouch_1_ADC_DEC_SAMPM_REG << 8u);
        #endif /* CY_PSOC3 */
        if(coherency == ResistiveTouch_1_ADC_DEC_SAMP_KEY_HIGH)
        {   /* Dummy read of the MSB byte to unlock the coherency */
            (void)ResistiveTouch_1_ADC_DEC_SAMPH_REG;
        }
    }
    /* Clear conversion complete status in Single Sample mode with resolution above 16 bit */
    if(ResistiveTouch_1_ADC_stopConversion != 0u)
    {
        ResistiveTouch_1_ADC_convDone = 0u;
    }

    return ((int16)result);
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_GetResult32
********************************************************************************
*
* Summary:
*  Returns a 32-bit result for a conversion with a result that has a
*  resolution of 8 to 20 bits.
*  This function supports different coherency settings.
*
* Parameters:
*  None
*
* Return:
*  int32: Result of the last ADC conversion.
*
* Global variables:
*  ResistiveTouch_1_ADC_convDone:  Cleared in single sample mode with resolution
*                              above 16 bits
*
*******************************************************************************/
int32 ResistiveTouch_1_ADC_GetResult32(void) 
{
    uint32 result;
    uint8 coherency;
    #if (CY_PSOC3)
	    uint16 tmp;
    #endif /* CY_PSOC3 */

    /* Read active coherency configuration */
    coherency = ResistiveTouch_1_ADC_DEC_COHER_REG & ResistiveTouch_1_ADC_DEC_SAMP_KEY_MASK;

    if(coherency <= ResistiveTouch_1_ADC_DEC_SAMP_KEY_LOW)
    {   /*  Use default method to read result registers i.e. LSB byte read at the end*/
        #if (CY_PSOC3)
            result = ResistiveTouch_1_ADC_DEC_SAMPH_REG;
            if((result & 0x80u) != 0u)
            {   /* Sign extend */
                result |= 0xFF00u;
            }
            result = (result << 8u) | ResistiveTouch_1_ADC_DEC_SAMPM_REG;
            result = (result << 8u) | ResistiveTouch_1_ADC_DEC_SAMP_REG;
        #else
            result = CY_GET_REG16(ResistiveTouch_1_ADC_DEC_SAMPH_16B_PTR);
            result = (result << 16u) | (CY_GET_REG16(ResistiveTouch_1_ADC_DEC_SAMP_16B_PTR));
        #endif /* CY_PSOC3 */
    }
    else if(coherency == ResistiveTouch_1_ADC_DEC_SAMP_KEY_MID)
    {   /* Read middle byte at the end */
        #if (CY_PSOC3)
            result = ResistiveTouch_1_ADC_DEC_SAMPH_REG;
            if((result & 0x80u) != 0u)
            {   /* Sign extend */
                result |= 0xFF00u;
            }
            result = (result << 16u) | (CY_GET_REG16(ResistiveTouch_1_ADC_DEC_SAMP_16B_PTR));
        #else
            result = CY_GET_REG16(ResistiveTouch_1_ADC_DEC_SAMPH_16B_PTR);
            result = (result << 16u) | ResistiveTouch_1_ADC_DEC_SAMP_REG;
            result |=  (uint32)((uint32)ResistiveTouch_1_ADC_DEC_SAMPM_REG << 8u);
        #endif /* CY_PSOC3 */
    }
    else /*ResistiveTouch_1_ADC_DEC_SAMP_KEY_HIGH */
    {
        /* Read MSB byte at the end */
        #if (CY_PSOC3)
            result = CY_GET_REG16(ResistiveTouch_1_ADC_DEC_SAMP_16B_PTR);
			tmp = ResistiveTouch_1_ADC_DEC_SAMPH_REG;
            if((tmp & 0x80u) != 0u)
            {   /* Sign extend */
                tmp |= 0xFF00u;
            }
            result |= (uint32)tmp << 16u;
        #else
            result = CY_GET_REG16(ResistiveTouch_1_ADC_DEC_SAMP_16B_PTR);
            result |= (uint32)((uint32)CY_GET_REG16(ResistiveTouch_1_ADC_DEC_SAMPH_16B_PTR) << 16u);
        #endif /* CY_PSOC3 */
    }
    /* Clear conversion complete status in Single Sample mode with resolution above 16 bit */
    if(ResistiveTouch_1_ADC_stopConversion != 0u)
    {
        ResistiveTouch_1_ADC_convDone = 0u;
    }

    return ((int32)result);
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_SetOffset
********************************************************************************
*
* Summary:
*  Sets the ADC offset which is used by the functions ADC_CountsTo_uVolts, 
*  ADC_CountsTo_mVolts, and ADC_CountsTo_Volts to subtract the offset from the 
*  given reading before calculating the voltage conversion.
*
* Parameters:
*  int32:  This value is a measured value when the inputs are shorted or 
*          connected to the same input voltage.
*
* Return:
*  None
*
* Global variables:
*  ResistiveTouch_1_ADC_Offset:  Modified to set the user provided offset. This
*  variable is used for offset calibration purpose.
*
* Side Effects:
*  Affects the ResistiveTouch_1_ADC_CountsTo_Volts,
*  ResistiveTouch_1_ADC_CountsTo_mVolts, ResistiveTouch_1_ADC_CountsTo_uVolts functions
*  by subtracting the given offset.
*
*******************************************************************************/
void ResistiveTouch_1_ADC_SetOffset(int32 offset) 
{

    ResistiveTouch_1_ADC_Offset = offset;
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_SetGain
********************************************************************************
*
* Summary:
*  Sets the ADC gain in counts per volt for the voltage conversion
*  functions below. This value is set by default by the reference and
*  input range settings. It should only be used to further calibrate the
*  ADC with a known input or if an external reference is used. This
*  function may also be used to calibrate an entire signal chain, not
*  just the ADC.
*
* Parameters:
*  int32: ADC gain in counts per volt.
*
* Return:
*  None
*
* Global variables:
*  ResistiveTouch_1_ADC_CountsPerVolt:  modified to set the ADC gain in counts
*   per volt.
*
* Side Effects:
*  Affects the ResistiveTouch_1_ADC_CountsTo_Volts,
*  ResistiveTouch_1_ADC_CountsTo_mVolts, ResistiveTouch_1_ADC_CountsTo_uVolts functions
*  supplying the correct conversion between ADC counts and voltage.
*
*******************************************************************************/
void ResistiveTouch_1_ADC_SetGain(int32 adcGain) 
{
    ResistiveTouch_1_ADC_CountsPerVolt = adcGain;
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_CountsTo_mVolts
********************************************************************************
*
* Summary:
*  Converts the ADC counts output to mVolts as a 16-bit integer. For
*  example, if the ADC measured 0.534 volts, the return value would
*  be 534 mVolts.
*
* Parameters:
*  int32: adcCounts Result from the ADC conversion.
*
* Return:
*  int16:  Result in mVolts
*
* Global variables:
*  ResistiveTouch_1_ADC_CountsPerVolt:  used to convert ADC counts to mVolts.
*  ResistiveTouch_1_ADC_Offset:  Used as the offset while converting ADC counts
*   to mVolts.
*
*******************************************************************************/
int16 ResistiveTouch_1_ADC_CountsTo_mVolts(int32 adcCounts) 
{

    int16 mVolts;

    /* Convert adcCounts to the right align if left option selected */
    #if(ResistiveTouch_1_ADC_CFG1_DEC_DIV != 0)
        if(ResistiveTouch_1_ADC_Config == ResistiveTouch_1_ADC_CFG1)
        {
            adcCounts /= ResistiveTouch_1_ADC_CFG1_DEC_DIV;
        }
    #endif /* ResistiveTouch_1_ADC_CFG1_DEC_DIV */
    #if((ResistiveTouch_1_ADC_CFG2_DEC_DIV != 0) && (ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 1))
        if(ResistiveTouch_1_ADC_Config == ResistiveTouch_1_ADC_CFG2)
        {
            adcCounts /= ResistiveTouch_1_ADC_CFG2_DEC_DIV;
        }
    #endif /* ResistiveTouch_1_ADC_CFG2_DEC_DIV */
    #if((ResistiveTouch_1_ADC_CFG3_DEC_DIV != 0) && (ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 2))
        if(ResistiveTouch_1_ADC_Config == ResistiveTouch_1_ADC_CFG3)
        {
            adcCounts /= ResistiveTouch_1_ADC_CFG3_DEC_DIV;
        }
    #endif /* ResistiveTouch_1_ADC_CFG2_DEC_DIV */
    #if((ResistiveTouch_1_ADC_CFG4_DEC_DIV != 0) && (ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 3))
        if(ResistiveTouch_1_ADC_Config == ResistiveTouch_1_ADC_CFG4)
        {
            adcCounts /= ResistiveTouch_1_ADC_CFG4_DEC_DIV;
        }
    #endif /* ResistiveTouch_1_ADC_CFG2_DEC_DIV */

    /* Subtract ADC offset */
    adcCounts -= ResistiveTouch_1_ADC_Offset;

    mVolts = (int16)(( adcCounts * ResistiveTouch_1_ADC_1MV_COUNTS ) / ResistiveTouch_1_ADC_CountsPerVolt) ;

    return(mVolts);
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_CountsTo_Volts
********************************************************************************
*
* Summary:
*  Converts the ADC output to Volts as a floating point number. For
*  example, if the ADC measure a voltage of 1.2345 Volts, the
*  returned result would be +1.2345 Volts.
*
* Parameters:
*  int32 adcCounts:  Result from the ADC conversion.
*
* Return:
*  float32: Result in Volts
*
* Global variables:
*  ResistiveTouch_1_ADC_CountsPerVolt:  used to convert to Volts.
*  ResistiveTouch_1_ADC_Offset:  Used as the offset while converting ADC counts
*   to Volts.
*
*******************************************************************************/
float32 ResistiveTouch_1_ADC_CountsTo_Volts(int32 adcCounts) 
{

    float32 Volts;

    /* Convert adcCounts to the right align if left option selected */
    #if(ResistiveTouch_1_ADC_CFG1_DEC_DIV != 0)
        if(ResistiveTouch_1_ADC_Config == ResistiveTouch_1_ADC_CFG1)
        {
            adcCounts /= ResistiveTouch_1_ADC_CFG1_DEC_DIV;
        }
    #endif /* ResistiveTouch_1_ADC_CFG1_DEC_DIV */
    #if((ResistiveTouch_1_ADC_CFG2_DEC_DIV != 0) && (ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 1))
        if(ResistiveTouch_1_ADC_Config == ResistiveTouch_1_ADC_CFG2)
        {
            adcCounts /= ResistiveTouch_1_ADC_CFG2_DEC_DIV;
        }
    #endif /* ResistiveTouch_1_ADC_CFG2_DEC_DIV */
    #if((ResistiveTouch_1_ADC_CFG3_DEC_DIV != 0) && (ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 2))
        if(ResistiveTouch_1_ADC_Config == ResistiveTouch_1_ADC_CFG3)
        {
            adcCounts /= ResistiveTouch_1_ADC_CFG3_DEC_DIV;
        }
    #endif /* ResistiveTouch_1_ADC_CFG2_DEC_DIV */
    #if((ResistiveTouch_1_ADC_CFG4_DEC_DIV != 0) && (ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 3))
        if(ResistiveTouch_1_ADC_Config == ResistiveTouch_1_ADC_CFG4)
        {
            adcCounts /= ResistiveTouch_1_ADC_CFG4_DEC_DIV;
        }
    #endif /* ResistiveTouch_1_ADC_CFG2_DEC_DIV */

    /* Subtract ADC offset */
    adcCounts -= ResistiveTouch_1_ADC_Offset;

    Volts = (float32)adcCounts / (float32)ResistiveTouch_1_ADC_CountsPerVolt;

    return( Volts );
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_CountsTo_uVolts
********************************************************************************
*
* Summary:
*  Converts the ADC output to uVolts as a 32-bit integer. For example,
*  if the ADC measured -0.02345 Volts, the return value would be -23450 uVolts.
*
* Parameters:
*  int32 adcCounts: Result from the ADC conversion.
*
* Return:
*  int32:  Result in uVolts
*
* Global variables:
*  ResistiveTouch_1_ADC_CountsPerVolt:  used to convert ADC counts to mVolts.
*  ResistiveTouch_1_ADC_Offset:  Used as the offset while converting ADC counts
*   to mVolts.
*
* Theory:
*  Care must be taken to not exceed the maximum value for a 31 bit signed
*  number in the conversion to uVolts and at the same time not lose resolution.
*
*  uVolts = ((A * adcCounts) / ((int32)ResistiveTouch_1_ADC_CountsPerVolt / B));
*
*******************************************************************************/
int32 ResistiveTouch_1_ADC_CountsTo_uVolts(int32 adcCounts) 
{

    int32 uVolts;
    int32 coefA;
    int32 coefB;
    uint8 resolution;

    /* Set the resolution based on the configuration */
    /* Convert adcCounts to the right align if left option selected */
    if (ResistiveTouch_1_ADC_Config == ResistiveTouch_1_ADC_CFG1)
    {
        resolution = ResistiveTouch_1_ADC_CFG1_RESOLUTION;
        #if(ResistiveTouch_1_ADC_CFG1_DEC_DIV != 0)
            adcCounts /= ResistiveTouch_1_ADC_CFG1_DEC_DIV;
        #endif /* ResistiveTouch_1_ADC_CFG1_DEC_DIV */
    }
    else if (ResistiveTouch_1_ADC_Config == ResistiveTouch_1_ADC_CFG2)
    {
        resolution = ResistiveTouch_1_ADC_CFG2_RESOLUTION;
        #if(ResistiveTouch_1_ADC_CFG2_DEC_DIV != 0)
            adcCounts /= ResistiveTouch_1_ADC_CFG2_DEC_DIV;
        #endif /* ResistiveTouch_1_ADC_CFG2_DEC_DIV */
    }
    else if (ResistiveTouch_1_ADC_Config == ResistiveTouch_1_ADC_CFG3)
    {
        resolution = ResistiveTouch_1_ADC_CFG3_RESOLUTION;
        #if(ResistiveTouch_1_ADC_CFG3_DEC_DIV != 0)
            adcCounts /= ResistiveTouch_1_ADC_CFG3_DEC_DIV;
        #endif /* ResistiveTouch_1_ADC_CFG3_DEC_DIV */
    }
    else
    {
        resolution = ResistiveTouch_1_ADC_CFG4_RESOLUTION;
        #if(ResistiveTouch_1_ADC_CFG4_DEC_DIV != 0)
            adcCounts /= ResistiveTouch_1_ADC_CFG4_DEC_DIV;
        #endif /* ResistiveTouch_1_ADC_CFG4_DEC_DIV */
    }

    switch (resolution)
    {
        #if( (ResistiveTouch_1_ADC_CFG1_RESOLUTION == ResistiveTouch_1_ADC__BITS_12) || \
             (ResistiveTouch_1_ADC_CFG2_RESOLUTION == ResistiveTouch_1_ADC__BITS_12) || \
             (ResistiveTouch_1_ADC_CFG3_RESOLUTION == ResistiveTouch_1_ADC__BITS_12) || \
             (ResistiveTouch_1_ADC_CFG4_RESOLUTION == ResistiveTouch_1_ADC__BITS_12) )
            case (uint8)ResistiveTouch_1_ADC__BITS_12:
                coefA = ResistiveTouch_1_ADC_1UV_COUNTS / ResistiveTouch_1_ADC_DIVISOR_2;
                coefB = ResistiveTouch_1_ADC_DIVISOR_2;
                break;
        #endif /* ResistiveTouch_1_ADC__BITS_12 */    
        #if( (ResistiveTouch_1_ADC_CFG1_RESOLUTION == ResistiveTouch_1_ADC__BITS_13) || \
             (ResistiveTouch_1_ADC_CFG2_RESOLUTION == ResistiveTouch_1_ADC__BITS_13) || \
             (ResistiveTouch_1_ADC_CFG3_RESOLUTION == ResistiveTouch_1_ADC__BITS_13) || \
             (ResistiveTouch_1_ADC_CFG4_RESOLUTION == ResistiveTouch_1_ADC__BITS_13) )
            case (uint8)ResistiveTouch_1_ADC__BITS_13:
                coefA = ResistiveTouch_1_ADC_1UV_COUNTS / ResistiveTouch_1_ADC_DIVISOR_4;
                coefB = ResistiveTouch_1_ADC_DIVISOR_4;
                break;
        #endif /* ResistiveTouch_1_ADC__BITS_13 */    
        #if( (ResistiveTouch_1_ADC_CFG1_RESOLUTION == ResistiveTouch_1_ADC__BITS_14) || \
             (ResistiveTouch_1_ADC_CFG2_RESOLUTION == ResistiveTouch_1_ADC__BITS_14) || \
             (ResistiveTouch_1_ADC_CFG3_RESOLUTION == ResistiveTouch_1_ADC__BITS_14) || \
             (ResistiveTouch_1_ADC_CFG4_RESOLUTION == ResistiveTouch_1_ADC__BITS_14) )
            case (uint8)ResistiveTouch_1_ADC__BITS_14:
                coefA = ResistiveTouch_1_ADC_1UV_COUNTS / ResistiveTouch_1_ADC_DIVISOR_8;
                coefB = ResistiveTouch_1_ADC_DIVISOR_8;
                break;
        #endif /* ResistiveTouch_1_ADC__BITS_14 */    
        #if( (ResistiveTouch_1_ADC_CFG1_RESOLUTION == ResistiveTouch_1_ADC__BITS_15) || \
             (ResistiveTouch_1_ADC_CFG2_RESOLUTION == ResistiveTouch_1_ADC__BITS_15) || \
             (ResistiveTouch_1_ADC_CFG3_RESOLUTION == ResistiveTouch_1_ADC__BITS_15) || \
             (ResistiveTouch_1_ADC_CFG4_RESOLUTION == ResistiveTouch_1_ADC__BITS_15) )
            case (uint8)ResistiveTouch_1_ADC__BITS_15:
                coefA = ResistiveTouch_1_ADC_1UV_COUNTS / ResistiveTouch_1_ADC_DIVISOR_16;
                coefB = ResistiveTouch_1_ADC_DIVISOR_16;
                break;
        #endif /* ResistiveTouch_1_ADC__BITS_15 */    
        #if( (ResistiveTouch_1_ADC_CFG1_RESOLUTION == ResistiveTouch_1_ADC__BITS_16) || \
             (ResistiveTouch_1_ADC_CFG2_RESOLUTION == ResistiveTouch_1_ADC__BITS_16) || \
             (ResistiveTouch_1_ADC_CFG3_RESOLUTION == ResistiveTouch_1_ADC__BITS_16) || \
             (ResistiveTouch_1_ADC_CFG4_RESOLUTION == ResistiveTouch_1_ADC__BITS_16) )
            case (uint8)ResistiveTouch_1_ADC__BITS_16:
                coefA = ResistiveTouch_1_ADC_1UV_COUNTS / ResistiveTouch_1_ADC_DIVISOR_32;
                coefB = ResistiveTouch_1_ADC_DIVISOR_32;
                break;
        #endif /* ResistiveTouch_1_ADC__BITS_16 */    
        #if( (ResistiveTouch_1_ADC_CFG1_RESOLUTION == ResistiveTouch_1_ADC__BITS_17) || \
             (ResistiveTouch_1_ADC_CFG2_RESOLUTION == ResistiveTouch_1_ADC__BITS_17) || \
             (ResistiveTouch_1_ADC_CFG3_RESOLUTION == ResistiveTouch_1_ADC__BITS_17) || \
             (ResistiveTouch_1_ADC_CFG4_RESOLUTION == ResistiveTouch_1_ADC__BITS_17) )
            case (uint8)ResistiveTouch_1_ADC__BITS_17:
                coefA = ResistiveTouch_1_ADC_1UV_COUNTS / ResistiveTouch_1_ADC_DIVISOR_64;
                coefB = ResistiveTouch_1_ADC_DIVISOR_64;
                break;
        #endif /* ResistiveTouch_1_ADC__BITS_17 */    
        #if( (ResistiveTouch_1_ADC_CFG1_RESOLUTION == ResistiveTouch_1_ADC__BITS_18) || \
             (ResistiveTouch_1_ADC_CFG2_RESOLUTION == ResistiveTouch_1_ADC__BITS_18) || \
             (ResistiveTouch_1_ADC_CFG3_RESOLUTION == ResistiveTouch_1_ADC__BITS_18) || \
             (ResistiveTouch_1_ADC_CFG4_RESOLUTION == ResistiveTouch_1_ADC__BITS_18) )
            case (uint8)ResistiveTouch_1_ADC__BITS_18:
                coefA = ResistiveTouch_1_ADC_1UV_COUNTS / ResistiveTouch_1_ADC_DIVISOR_125;
                coefB = ResistiveTouch_1_ADC_DIVISOR_125;
                break;
        #endif /* ResistiveTouch_1_ADC__BITS_18 */    
        #if( (ResistiveTouch_1_ADC_CFG1_RESOLUTION == ResistiveTouch_1_ADC__BITS_19) || \
             (ResistiveTouch_1_ADC_CFG2_RESOLUTION == ResistiveTouch_1_ADC__BITS_19) || \
             (ResistiveTouch_1_ADC_CFG3_RESOLUTION == ResistiveTouch_1_ADC__BITS_19) || \
             (ResistiveTouch_1_ADC_CFG4_RESOLUTION == ResistiveTouch_1_ADC__BITS_19) )
            case (uint8)ResistiveTouch_1_ADC__BITS_19:
                coefA = ResistiveTouch_1_ADC_1UV_COUNTS / ResistiveTouch_1_ADC_DIVISOR_250;
                coefB = ResistiveTouch_1_ADC_DIVISOR_250;
                break;
        #endif /* ResistiveTouch_1_ADC__BITS_19 */    
        #if( (ResistiveTouch_1_ADC_CFG1_RESOLUTION == ResistiveTouch_1_ADC__BITS_20) || \
             (ResistiveTouch_1_ADC_CFG2_RESOLUTION == ResistiveTouch_1_ADC__BITS_20) || \
             (ResistiveTouch_1_ADC_CFG3_RESOLUTION == ResistiveTouch_1_ADC__BITS_20) || \
             (ResistiveTouch_1_ADC_CFG4_RESOLUTION == ResistiveTouch_1_ADC__BITS_20) )
            case (uint8)ResistiveTouch_1_ADC__BITS_20:
                coefA = ResistiveTouch_1_ADC_1UV_COUNTS / ResistiveTouch_1_ADC_DIVISOR_500;
                coefB = ResistiveTouch_1_ADC_DIVISOR_500;
                break;
        #endif /* ResistiveTouch_1_ADC__BITS_20 */    
        default:    /* resolution < 12 */
            /* 11 bits ADC + 2^20(1048576) = 31 bits */
            coefA = ResistiveTouch_1_ADC_1UV_COUNTS;
            coefB = ResistiveTouch_1_ADC_DIVISOR_1;
            break;
    }
    coefB = ResistiveTouch_1_ADC_CountsPerVolt / coefB;
    uVolts = ((coefA * adcCounts) / coefB) - ((coefA * ResistiveTouch_1_ADC_Offset) / coefB);

    return( uVolts );
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_InitConfig(uint8 config)
********************************************************************************
*
* Summary:
*  Initializes all registers based on customizer settings
*
* Parameters:
*   void
*
* Return:
*  None
*
* Global variables:
*  ResistiveTouch_1_ADC_CountsPerVolt:  Used to set the default counts per volt.
*
* Side Effects: Rewrites the coherency set by ResistiveTouch_1_ADC_SetCoherency()
*   API to the default value.
*
*******************************************************************************/
static void ResistiveTouch_1_ADC_InitConfig(uint8 config) 
{
    ResistiveTouch_1_ADC_stopConversion = 0u;

    if (config == 1u)
    {
        /* Default Config */
        ResistiveTouch_1_ADC_DEC_CR_REG      = ResistiveTouch_1_ADC_CFG1_DEC_CR;
        ResistiveTouch_1_ADC_DEC_SHIFT1_REG  = ResistiveTouch_1_ADC_CFG1_DEC_SHIFT1;
        ResistiveTouch_1_ADC_DEC_SHIFT2_REG  = ResistiveTouch_1_ADC_CFG1_DEC_SHIFT2;
        ResistiveTouch_1_ADC_DEC_DR2_REG     = ResistiveTouch_1_ADC_CFG1_DEC_DR2;
        ResistiveTouch_1_ADC_DEC_DR2H_REG    = ResistiveTouch_1_ADC_CFG1_DEC_DR2H;
        ResistiveTouch_1_ADC_DEC_DR1_REG     = ResistiveTouch_1_ADC_CFG1_DEC_DR1;
        ResistiveTouch_1_ADC_DEC_OCOR_REG    = ResistiveTouch_1_ADC_CFG1_DEC_OCOR;
        ResistiveTouch_1_ADC_DEC_OCORM_REG   = ResistiveTouch_1_ADC_CFG1_DEC_OCORM;
        ResistiveTouch_1_ADC_DEC_OCORH_REG   = ResistiveTouch_1_ADC_CFG1_DEC_OCORH;
        ResistiveTouch_1_ADC_DEC_COHER_REG   = ResistiveTouch_1_ADC_CFG1_DEC_COHER;

        ResistiveTouch_1_ADC_DSM_CR4_REG     = ResistiveTouch_1_ADC_CFG1_DSM_CR4;
        ResistiveTouch_1_ADC_DSM_CR5_REG     = ResistiveTouch_1_ADC_CFG1_DSM_CR5;
        ResistiveTouch_1_ADC_DSM_CR6_REG     = ResistiveTouch_1_ADC_CFG1_DSM_CR6;
        ResistiveTouch_1_ADC_DSM_CR7_REG     = ResistiveTouch_1_ADC_CFG1_DSM_CR7;
        ResistiveTouch_1_ADC_DSM_CR10_REG    = ResistiveTouch_1_ADC_CFG1_DSM_CR10;
        ResistiveTouch_1_ADC_DSM_CR11_REG    = ResistiveTouch_1_ADC_CFG1_DSM_CR11;
        ResistiveTouch_1_ADC_DSM_CR12_REG    = ResistiveTouch_1_ADC_CFG1_DSM_CR12;
        ResistiveTouch_1_ADC_DSM_CR14_REG    = ResistiveTouch_1_ADC_CFG1_DSM_CR14;
        ResistiveTouch_1_ADC_DSM_CR15_REG    = ResistiveTouch_1_ADC_CFG1_DSM_CR15;
        ResistiveTouch_1_ADC_DSM_CR16_REG    = ResistiveTouch_1_ADC_CFG1_DSM_CR16;
        ResistiveTouch_1_ADC_DSM_CR17_REG    = ResistiveTouch_1_ADC_CFG1_DSM_CR17;
        /* Set DSM_REF0_REG by disabling and enabling the PRESS circuit */
        ResistiveTouch_1_ADC_SetDSMRef0Reg(ResistiveTouch_1_ADC_CFG1_DSM_REF0);
        ResistiveTouch_1_ADC_DSM_REF2_REG    = ResistiveTouch_1_ADC_CFG1_DSM_REF2;
        ResistiveTouch_1_ADC_DSM_REF3_REG    = ResistiveTouch_1_ADC_CFG1_DSM_REF3;

        ResistiveTouch_1_ADC_DSM_BUF0_REG    = ResistiveTouch_1_ADC_CFG1_DSM_BUF0;
        ResistiveTouch_1_ADC_DSM_BUF1_REG    = ResistiveTouch_1_ADC_CFG1_DSM_BUF1;
        ResistiveTouch_1_ADC_DSM_BUF2_REG    = ResistiveTouch_1_ADC_CFG1_DSM_BUF2;
        ResistiveTouch_1_ADC_DSM_BUF3_REG    = ResistiveTouch_1_ADC_CFG1_DSM_BUF3;

        /* To select either Vssa or Vref to -ve input of DSM depending on
        *  the input  range selected.
        */
        #if(ResistiveTouch_1_ADC_DEFAULT_INPUT_MODE)
            #if (ResistiveTouch_1_ADC_CFG1_INPUT_RANGE == ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF)
                ResistiveTouch_1_ADC_AMux_Select(1u);
            #else
                ResistiveTouch_1_ADC_AMux_Select(0u);
            #endif /* ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF) */
        #endif /* ResistiveTouch_1_ADC_DEFAULT_INPUT_MODE */

        /* Set the Conversion stop if resolution is above 16 bit and conversion
        *   mode is Single sample
        */
        #if(ResistiveTouch_1_ADC_CFG1_RESOLUTION > 16 && \
            ResistiveTouch_1_ADC_CFG1_CONV_MODE == ResistiveTouch_1_ADC_MODE_SINGLE_SAMPLE)
            ResistiveTouch_1_ADC_stopConversion = 1u;
        #endif /* Single sample with resolution above 16 bits. */

        ResistiveTouch_1_ADC_CountsPerVolt = (int32)ResistiveTouch_1_ADC_CFG1_COUNTS_PER_VOLT;

        ResistiveTouch_1_ADC_Ext_CP_Clk_SetDividerRegister(ResistiveTouch_1_ADC_CFG1_CP_CLK_DIVIDER, 1u);

        /* This is only valid if there is an internal clock */
        #if(ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK)
            ResistiveTouch_1_ADC_theACLK_SetDividerRegister(ResistiveTouch_1_ADC_CFG1_ADC_CLK_DIVIDER, 1u);
        #endif /* ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK */

        #if(ResistiveTouch_1_ADC_IRQ_REMOVE == 0u)
            /* Set interrupt vector */
            (void)CyIntSetVector(ResistiveTouch_1_ADC_INTC_NUMBER, &ResistiveTouch_1_ADC_ISR1);
        #endif   /* End ResistiveTouch_1_ADC_IRQ_REMOVE */
    }

    #if(ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 1)
        if(config == 2u)
        {
            /* Second Config */
            ResistiveTouch_1_ADC_DEC_CR_REG      = ResistiveTouch_1_ADC_CFG2_DEC_CR;
            ResistiveTouch_1_ADC_DEC_SHIFT1_REG  = ResistiveTouch_1_ADC_CFG2_DEC_SHIFT1;
            ResistiveTouch_1_ADC_DEC_SHIFT2_REG  = ResistiveTouch_1_ADC_CFG2_DEC_SHIFT2;
            ResistiveTouch_1_ADC_DEC_DR2_REG     = ResistiveTouch_1_ADC_CFG2_DEC_DR2;
            ResistiveTouch_1_ADC_DEC_DR2H_REG    = ResistiveTouch_1_ADC_CFG2_DEC_DR2H;
            ResistiveTouch_1_ADC_DEC_DR1_REG     = ResistiveTouch_1_ADC_CFG2_DEC_DR1;
            ResistiveTouch_1_ADC_DEC_OCOR_REG    = ResistiveTouch_1_ADC_CFG2_DEC_OCOR;
            ResistiveTouch_1_ADC_DEC_OCORM_REG   = ResistiveTouch_1_ADC_CFG2_DEC_OCORM;
            ResistiveTouch_1_ADC_DEC_OCORH_REG   = ResistiveTouch_1_ADC_CFG2_DEC_OCORH;
            ResistiveTouch_1_ADC_DEC_COHER_REG   = ResistiveTouch_1_ADC_CFG2_DEC_COHER;

            ResistiveTouch_1_ADC_DSM_CR4_REG     = ResistiveTouch_1_ADC_CFG2_DSM_CR4;
            ResistiveTouch_1_ADC_DSM_CR5_REG     = ResistiveTouch_1_ADC_CFG2_DSM_CR5;
            ResistiveTouch_1_ADC_DSM_CR6_REG     = ResistiveTouch_1_ADC_CFG2_DSM_CR6;
            ResistiveTouch_1_ADC_DSM_CR7_REG     = ResistiveTouch_1_ADC_CFG2_DSM_CR7;
            ResistiveTouch_1_ADC_DSM_CR10_REG    = ResistiveTouch_1_ADC_CFG2_DSM_CR10;
            ResistiveTouch_1_ADC_DSM_CR11_REG    = ResistiveTouch_1_ADC_CFG2_DSM_CR11;
            ResistiveTouch_1_ADC_DSM_CR12_REG    = ResistiveTouch_1_ADC_CFG2_DSM_CR12;
            ResistiveTouch_1_ADC_DSM_CR14_REG    = ResistiveTouch_1_ADC_CFG2_DSM_CR14;
            ResistiveTouch_1_ADC_DSM_CR15_REG    = ResistiveTouch_1_ADC_CFG2_DSM_CR15;
            ResistiveTouch_1_ADC_DSM_CR16_REG    = ResistiveTouch_1_ADC_CFG2_DSM_CR16;
            ResistiveTouch_1_ADC_DSM_CR17_REG    = ResistiveTouch_1_ADC_CFG2_DSM_CR17;
            /* Set DSM_REF0_REG by disabling and enabling the PRESS cirucit */
            ResistiveTouch_1_ADC_SetDSMRef0Reg(ResistiveTouch_1_ADC_CFG2_DSM_REF0);
            ResistiveTouch_1_ADC_DSM_REF2_REG    = ResistiveTouch_1_ADC_CFG2_DSM_REF2;
            ResistiveTouch_1_ADC_DSM_REF3_REG    = ResistiveTouch_1_ADC_CFG2_DSM_REF3;

            ResistiveTouch_1_ADC_DSM_BUF0_REG    = ResistiveTouch_1_ADC_CFG2_DSM_BUF0;
            ResistiveTouch_1_ADC_DSM_BUF1_REG    = ResistiveTouch_1_ADC_CFG2_DSM_BUF1;
            ResistiveTouch_1_ADC_DSM_BUF2_REG    = ResistiveTouch_1_ADC_CFG2_DSM_BUF2;
            ResistiveTouch_1_ADC_DSM_BUF3_REG    = ResistiveTouch_1_ADC_CFG2_DSM_BUF3;

            /* To select either Vssa or Vref to -ve input of DSM depending on
            *  the input range selected.
            */

            #if(ResistiveTouch_1_ADC_DEFAULT_INPUT_MODE)
                #if (ResistiveTouch_1_ADC_CFG2_INPUT_RANGE == ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF)
                    ResistiveTouch_1_ADC_AMux_Select(1u);
                #else
                    ResistiveTouch_1_ADC_AMux_Select(0u);
                #endif /* ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF) */
            #endif /* ResistiveTouch_1_ADC_DEFAULT_INPUT_MODE */

            /* Set the Conversion stop if resolution is above 16 bit and
            *   conversion mode is Single sample
            */
            #if(ResistiveTouch_1_ADC_CFG2_RESOLUTION > 16 && \
                ResistiveTouch_1_ADC_CFG2_CONV_MODE == ResistiveTouch_1_ADC_MODE_SINGLE_SAMPLE)
                ResistiveTouch_1_ADC_stopConversion = 1u;
            #endif /* Single sample with resolution above 16 bits. */

            ResistiveTouch_1_ADC_CountsPerVolt = (int32)ResistiveTouch_1_ADC_CFG2_COUNTS_PER_VOLT;

            ResistiveTouch_1_ADC_Ext_CP_Clk_SetDividerRegister(ResistiveTouch_1_ADC_CFG2_CP_CLK_DIVIDER, 1u);

            /* This is only valid if there is an internal clock */
            #if(ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK)
                ResistiveTouch_1_ADC_theACLK_SetDividerRegister(ResistiveTouch_1_ADC_CFG2_ADC_CLK_DIVIDER, 1u);
            #endif /* ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK */

            #if(ResistiveTouch_1_ADC_IRQ_REMOVE == 0u)
                /* Set interrupt vector */
                (void)CyIntSetVector(ResistiveTouch_1_ADC_INTC_NUMBER, &ResistiveTouch_1_ADC_ISR2);
            #endif   /* End ResistiveTouch_1_ADC_IRQ_REMOVE */
        }
    #endif /* ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 1 */

    #if(ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 2)
        if(config == 3u)
        {
            /* Third Config */
            ResistiveTouch_1_ADC_DEC_CR_REG      = ResistiveTouch_1_ADC_CFG3_DEC_CR;
            ResistiveTouch_1_ADC_DEC_SHIFT1_REG  = ResistiveTouch_1_ADC_CFG3_DEC_SHIFT1;
            ResistiveTouch_1_ADC_DEC_SHIFT2_REG  = ResistiveTouch_1_ADC_CFG3_DEC_SHIFT2;
            ResistiveTouch_1_ADC_DEC_DR2_REG     = ResistiveTouch_1_ADC_CFG3_DEC_DR2;
            ResistiveTouch_1_ADC_DEC_DR2H_REG    = ResistiveTouch_1_ADC_CFG3_DEC_DR2H;
            ResistiveTouch_1_ADC_DEC_DR1_REG     = ResistiveTouch_1_ADC_CFG3_DEC_DR1;
            ResistiveTouch_1_ADC_DEC_OCOR_REG    = ResistiveTouch_1_ADC_CFG3_DEC_OCOR;
            ResistiveTouch_1_ADC_DEC_OCORM_REG   = ResistiveTouch_1_ADC_CFG3_DEC_OCORM;
            ResistiveTouch_1_ADC_DEC_OCORH_REG   = ResistiveTouch_1_ADC_CFG3_DEC_OCORH;
            ResistiveTouch_1_ADC_DEC_COHER_REG   = ResistiveTouch_1_ADC_CFG3_DEC_COHER;

            ResistiveTouch_1_ADC_DSM_CR4_REG     = ResistiveTouch_1_ADC_CFG3_DSM_CR4;
            ResistiveTouch_1_ADC_DSM_CR5_REG     = ResistiveTouch_1_ADC_CFG3_DSM_CR5;
            ResistiveTouch_1_ADC_DSM_CR6_REG     = ResistiveTouch_1_ADC_CFG3_DSM_CR6;
            ResistiveTouch_1_ADC_DSM_CR7_REG     = ResistiveTouch_1_ADC_CFG3_DSM_CR7;
            ResistiveTouch_1_ADC_DSM_CR10_REG    = ResistiveTouch_1_ADC_CFG3_DSM_CR10;
            ResistiveTouch_1_ADC_DSM_CR11_REG    = ResistiveTouch_1_ADC_CFG3_DSM_CR11;
            ResistiveTouch_1_ADC_DSM_CR12_REG    = ResistiveTouch_1_ADC_CFG3_DSM_CR12;
            ResistiveTouch_1_ADC_DSM_CR14_REG    = ResistiveTouch_1_ADC_CFG3_DSM_CR14;
            ResistiveTouch_1_ADC_DSM_CR15_REG    = ResistiveTouch_1_ADC_CFG3_DSM_CR15;
            ResistiveTouch_1_ADC_DSM_CR16_REG    = ResistiveTouch_1_ADC_CFG3_DSM_CR16;
            ResistiveTouch_1_ADC_DSM_CR17_REG    = ResistiveTouch_1_ADC_CFG3_DSM_CR17;
            /* Set DSM_REF0_REG by disabling and enabling the PRESS circuit */
            ResistiveTouch_1_ADC_SetDSMRef0Reg(ResistiveTouch_1_ADC_CFG3_DSM_REF0);
            ResistiveTouch_1_ADC_DSM_REF2_REG    = ResistiveTouch_1_ADC_CFG3_DSM_REF2;
            ResistiveTouch_1_ADC_DSM_REF3_REG    = ResistiveTouch_1_ADC_CFG3_DSM_REF3;

            ResistiveTouch_1_ADC_DSM_BUF0_REG    = ResistiveTouch_1_ADC_CFG3_DSM_BUF0;
            ResistiveTouch_1_ADC_DSM_BUF1_REG    = ResistiveTouch_1_ADC_CFG3_DSM_BUF1;
            ResistiveTouch_1_ADC_DSM_BUF2_REG    = ResistiveTouch_1_ADC_CFG3_DSM_BUF2;
            ResistiveTouch_1_ADC_DSM_BUF3_REG    = ResistiveTouch_1_ADC_CFG3_DSM_BUF3;

            /* To select either Vssa or Vref to -ve input of DSM depending on
            *  the input range selected.
            */
            #if(ResistiveTouch_1_ADC_DEFAULT_INPUT_MODE)
                #if (ResistiveTouch_1_ADC_CFG3_INPUT_RANGE == ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF)
                    ResistiveTouch_1_ADC_AMux_Select(1u);
                #else
                    ResistiveTouch_1_ADC_AMux_Select(0u);
                #endif /* ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF) */
            #endif /* ResistiveTouch_1_ADC_DEFAULT_INPUT_MODE */

            /* Set the Conversion stop if resolution is above 16 bit and
               conversion  mode is Single sample */
            #if(ResistiveTouch_1_ADC_CFG3_RESOLUTION > 16 && \
                ResistiveTouch_1_ADC_CFG3_CONV_MODE == ResistiveTouch_1_ADC_MODE_SINGLE_SAMPLE)
                ResistiveTouch_1_ADC_stopConversion = 1u;
            #endif /* Single sample with resolution above 16 bits */

            ResistiveTouch_1_ADC_CountsPerVolt = (int32)ResistiveTouch_1_ADC_CFG3_COUNTS_PER_VOLT;

            ResistiveTouch_1_ADC_Ext_CP_Clk_SetDividerRegister(ResistiveTouch_1_ADC_CFG3_CP_CLK_DIVIDER, 1u);

            /* This is only valid if there is an internal clock */
            #if(ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK)
                ResistiveTouch_1_ADC_theACLK_SetDividerRegister(ResistiveTouch_1_ADC_CFG3_ADC_CLK_DIVIDER, 1u);
            #endif /* ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK */

            #if(ResistiveTouch_1_ADC_IRQ_REMOVE == 0u)
                /* Set interrupt vector */
                (void)CyIntSetVector(ResistiveTouch_1_ADC_INTC_NUMBER, &ResistiveTouch_1_ADC_ISR3);
            #endif   /* End ResistiveTouch_1_ADC_IRQ_REMOVE */
        }
    #endif /* ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 2 */

    #if(ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 3)
        if (config == 4u)
        {
            /* Fourth Config */
            ResistiveTouch_1_ADC_DEC_CR_REG      = ResistiveTouch_1_ADC_CFG4_DEC_CR;
            ResistiveTouch_1_ADC_DEC_SHIFT1_REG  = ResistiveTouch_1_ADC_CFG4_DEC_SHIFT1;
            ResistiveTouch_1_ADC_DEC_SHIFT2_REG  = ResistiveTouch_1_ADC_CFG4_DEC_SHIFT2;
            ResistiveTouch_1_ADC_DEC_DR2_REG     = ResistiveTouch_1_ADC_CFG4_DEC_DR2;
            ResistiveTouch_1_ADC_DEC_DR2H_REG    = ResistiveTouch_1_ADC_CFG4_DEC_DR2H;
            ResistiveTouch_1_ADC_DEC_DR1_REG     = ResistiveTouch_1_ADC_CFG4_DEC_DR1;
            ResistiveTouch_1_ADC_DEC_OCOR_REG    = ResistiveTouch_1_ADC_CFG4_DEC_OCOR;
            ResistiveTouch_1_ADC_DEC_OCORM_REG   = ResistiveTouch_1_ADC_CFG4_DEC_OCORM;
            ResistiveTouch_1_ADC_DEC_OCORH_REG   = ResistiveTouch_1_ADC_CFG4_DEC_OCORH;
            ResistiveTouch_1_ADC_DEC_COHER_REG   = ResistiveTouch_1_ADC_CFG4_DEC_COHER;

            ResistiveTouch_1_ADC_DSM_CR4_REG     = ResistiveTouch_1_ADC_CFG4_DSM_CR4;
            ResistiveTouch_1_ADC_DSM_CR5_REG     = ResistiveTouch_1_ADC_CFG4_DSM_CR5;
            ResistiveTouch_1_ADC_DSM_CR6_REG     = ResistiveTouch_1_ADC_CFG4_DSM_CR6;
            ResistiveTouch_1_ADC_DSM_CR7_REG     = ResistiveTouch_1_ADC_CFG4_DSM_CR7;
            ResistiveTouch_1_ADC_DSM_CR10_REG    = ResistiveTouch_1_ADC_CFG4_DSM_CR10;
            ResistiveTouch_1_ADC_DSM_CR11_REG    = ResistiveTouch_1_ADC_CFG4_DSM_CR11;
            ResistiveTouch_1_ADC_DSM_CR12_REG    = ResistiveTouch_1_ADC_CFG4_DSM_CR12;
            ResistiveTouch_1_ADC_DSM_CR14_REG    = ResistiveTouch_1_ADC_CFG4_DSM_CR14;
            ResistiveTouch_1_ADC_DSM_CR15_REG    = ResistiveTouch_1_ADC_CFG4_DSM_CR15;
            ResistiveTouch_1_ADC_DSM_CR16_REG    = ResistiveTouch_1_ADC_CFG4_DSM_CR16;
            ResistiveTouch_1_ADC_DSM_CR17_REG    = ResistiveTouch_1_ADC_CFG4_DSM_CR17;
            /* Set DSM_REF0_REG by disabling and enabling the PRESS circuit */
            ResistiveTouch_1_ADC_SetDSMRef0Reg(ResistiveTouch_1_ADC_CFG4_DSM_REF0);
            ResistiveTouch_1_ADC_DSM_REF2_REG    = ResistiveTouch_1_ADC_CFG4_DSM_REF2;
            ResistiveTouch_1_ADC_DSM_REF3_REG    = ResistiveTouch_1_ADC_CFG4_DSM_REF3;

            ResistiveTouch_1_ADC_DSM_BUF0_REG    = ResistiveTouch_1_ADC_CFG4_DSM_BUF0;
            ResistiveTouch_1_ADC_DSM_BUF1_REG    = ResistiveTouch_1_ADC_CFG4_DSM_BUF1;
            ResistiveTouch_1_ADC_DSM_BUF2_REG    = ResistiveTouch_1_ADC_CFG4_DSM_BUF2;
            ResistiveTouch_1_ADC_DSM_BUF3_REG    = ResistiveTouch_1_ADC_CFG4_DSM_BUF3;

            /* To select either Vssa or Vref to -ve input of DSM depending on
            *  the input range selected.
            */
            #if(ResistiveTouch_1_ADC_DEFAULT_INPUT_MODE)
                #if (ResistiveTouch_1_ADC_CFG4_INPUT_RANGE == ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF)
                    ResistiveTouch_1_ADC_AMux_Select(1u);
                #else
                    ResistiveTouch_1_ADC_AMux_Select(0u);
                #endif /* ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF) */
            #endif /* ResistiveTouch_1_ADC_DEFAULT_INPUT_MODE */

            /* Set the Conversion stop if resolution is above 16 bit and
               conversion mode is Single sample */
            #if(ResistiveTouch_1_ADC_CFG4_RESOLUTION > 16 && \
                ResistiveTouch_1_ADC_CFG4_CONV_MODE == ResistiveTouch_1_ADC_MODE_SINGLE_SAMPLE)
                ResistiveTouch_1_ADC_stopConversion = 1u;
            #endif /* Single sample with resolution above 16 bits */

            ResistiveTouch_1_ADC_CountsPerVolt = (int32)ResistiveTouch_1_ADC_CFG4_COUNTS_PER_VOLT;

            ResistiveTouch_1_ADC_Ext_CP_Clk_SetDividerRegister(ResistiveTouch_1_ADC_CFG4_CP_CLK_DIVIDER, 1u);

            /* This is only valid if there is an internal clock */
            #if(ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK)
                ResistiveTouch_1_ADC_theACLK_SetDividerRegister(ResistiveTouch_1_ADC_CFG4_ADC_CLK_DIVIDER, 1u);
            #endif /* ResistiveTouch_1_ADC_DEFAULT_INTERNAL_CLK */

            #if(ResistiveTouch_1_ADC_IRQ_REMOVE == 0u)
                /* Set interrupt vector */
                (void)CyIntSetVector(ResistiveTouch_1_ADC_INTC_NUMBER, &ResistiveTouch_1_ADC_ISR4);
            #endif   /* End ResistiveTouch_1_ADC_IRQ_REMOVE */
        }
    #endif /* ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS > 3 */
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_SelectCofiguration
********************************************************************************
*
* Summary:
*  Sets one of up to four ADC configurations. Before setting the new
*  configuration, the ADC is stopped and powered down. After setting
*  the new configuration, the ADC can be powered and conversion
*  can be restarted depending up on the value of second parameter
*  restart. If the value of this parameter is 1, then ADC will be
*  restarted. If this value is zero, then user must call ResistiveTouch_1_ADC_Start
*  and ResistiveTouch_1_ADC_StartConvert() to restart the conversion.
*
* Parameters:
*  config:  configuration user wants to select.
*           Valid range: 1..4
*  restart:  Restart option. 1 means start the ADC and restart the conversion.
*                            0 means do not start the ADC and conversion.
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_ADC_SelectConfiguration(uint8 config, uint8 restart)
                                              
{
    /* Check whether the configuration number is valid or not */
    if((config > 0u) && (config <= ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS))
    {
        /* Set the flag to ensure Start() API doesn't override the 
		*  selected configuration
		*/
        if(ResistiveTouch_1_ADC_initVar == 0u)
        {
            ResistiveTouch_1_ADC_started = 1u;
        }

        /* Update the config flag */
        ResistiveTouch_1_ADC_Config = config;

        /* Stop the ADC  */
        ResistiveTouch_1_ADC_Stop();

        /* Set the  ADC registers based on the configuration */
        ResistiveTouch_1_ADC_InitConfig(config);

        /* Compensate the gain */
        ResistiveTouch_1_ADC_DEC_GVAL_REG = ResistiveTouch_1_ADC_gcor[config - 1u].gval;
        CY_SET_REG16(ResistiveTouch_1_ADC_DEC_GCOR_16B_PTR, ResistiveTouch_1_ADC_gcor[config - 1u].gcor);

        if(restart == 1u)
        {
            /* Restart the ADC */
            ResistiveTouch_1_ADC_Start();

            /* Restart the ADC conversion */
            ResistiveTouch_1_ADC_StartConvert();
        }
    }
    else
    {
        /* Halt CPU in debug mode if config is out of valid range */
        CYASSERT(0u != 0u);
    }
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_GainCompensation
********************************************************************************
*
* Summary:
*  This API calculates the trim value and then store this to gcor structure.
*
* Parameters:
*  inputRange:  input range for which trim value is to be calculated.
*  IdealDecGain:  Ideal Decimator gain for the selected resolution and
*                 conversion  mode.
*  IdealOddDecGain:  Ideal odd decimation gain for the selected resolution and
                     conversion mode.
*  resolution:  Resolution to select the proper flash location for trim value.
*  config:      Specifies the configuration number
*               Valid range: 1..4
*
* Return:
*  None
*
*******************************************************************************/
static void ResistiveTouch_1_ADC_GainCompensation(uint8 inputRange, uint16 idealDecGain, uint16 idealOddDecGain,
                              uint8 resolution, uint8 config) 
{
    int8 flash;
	int32 normalised;
	uint16 gcorValue;
    uint32 gcorTmp;

    if((config > 0u) && (config <= ResistiveTouch_1_ADC_DEFAULT_NUM_CONFIGS))
    {
        switch(inputRange)
        {
            case ResistiveTouch_1_ADC_IR_VNEG_VREF_DIFF:
            case ResistiveTouch_1_ADC_IR_VSSA_TO_2VREF:
                /* Normalize the flash Value */
                if(resolution > 15u)
                {
                    flash = ResistiveTouch_1_ADC_DEC_TRIM_VREF_DIFF_16_20;
                }
                else
                {
                    flash = ResistiveTouch_1_ADC_DEC_TRIM_VREF_DIFF_8_15;
                }
                break;

            case ResistiveTouch_1_ADC_IR_VNEG_VREF_2_DIFF:
                /* Normalize the flash Value */
                if(resolution > 15u)
                {
                    flash = ResistiveTouch_1_ADC_DEC_TRIM_VREF_2_DIFF_16_20;
                }
                else
                {
                    flash = ResistiveTouch_1_ADC_DEC_TRIM_VREF_2_DIFF_8_15;
                }
                break;

            case ResistiveTouch_1_ADC_IR_VNEG_VREF_4_DIFF:
                /* Normalize the flash Value */
                if(resolution > 15u)
                {
                    flash = ResistiveTouch_1_ADC_DEC_TRIM_VREF_4_DIFF_16_20;
                }
                else
                {
                    flash = ResistiveTouch_1_ADC_DEC_TRIM_VREF_4_DIFF_8_15;
                }
                break;

            case ResistiveTouch_1_ADC_IR_VNEG_VREF_16_DIFF:
                /* Normalize the flash Value */
                if(resolution > 15u)
                {
                    flash = ResistiveTouch_1_ADC_DEC_TRIM_VREF_16_DIFF_16_20;
                }
                else
                {
                    flash = ResistiveTouch_1_ADC_DEC_TRIM_VREF_16_DIFF_8_15;
                }
                break;

            default:
                flash = 0;
                break;
        }

        /* Add two values */
		normalised = (int32)idealDecGain + ((int32)flash * 32);
        gcorTmp = (uint32)normalised * (uint32)idealOddDecGain;
        gcorValue = (uint16)(gcorTmp / ResistiveTouch_1_ADC_IDEAL_GAIN_CONST);

        if (resolution < (ResistiveTouch_1_ADC_MAX_GVAL - 1u))
        {
            gcorValue = (gcorValue >> (ResistiveTouch_1_ADC_MAX_GVAL - (resolution + 1u)));
            ResistiveTouch_1_ADC_gcor[config - 1u].gval = (resolution + 1u);
        }
        else
        {
            /* Use all 16 bits */
            ResistiveTouch_1_ADC_gcor[config - 1u].gval = ResistiveTouch_1_ADC_MAX_GVAL;
        }

        /* Save the gain correction register value */
        ResistiveTouch_1_ADC_gcor[config - 1u].gcor = gcorValue;
    }
    else
    {
        /* Halt CPU in debug mode if config is out of valid range */
        CYASSERT(0u != 0u);
    }
}


/******************************************************************************
* Function Name: ResistiveTouch_1_ADC_SetDSMRef0Reg(uint8)
******************************************************************************
*
* Summary:
*  This API sets the DSM_REF0 register. This is written for internal use.
*
* Parameters:
*  value:  Value to be written to DSM_REF0 register.
*
* Return:
*  None
*
******************************************************************************/
static void ResistiveTouch_1_ADC_SetDSMRef0Reg(uint8 value) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    /* Disable PRES, Enable power to VCMBUF0, REFBUF0 and REFBUF1, enable PRES */
    ResistiveTouch_1_ADC_RESET_CR4_REG |= (ResistiveTouch_1_ADC_IGNORE_PRESA1 | ResistiveTouch_1_ADC_IGNORE_PRESD1);
    ResistiveTouch_1_ADC_RESET_CR5_REG |= (ResistiveTouch_1_ADC_IGNORE_PRESA2 | ResistiveTouch_1_ADC_IGNORE_PRESD2);
    ResistiveTouch_1_ADC_DSM_REF0_REG = value;

    /* Wait for 3 microseconds */
    CyDelayUs(ResistiveTouch_1_ADC_PRES_DELAY_TIME);
    /* Enable the press circuit */
    ResistiveTouch_1_ADC_RESET_CR4_REG &= (uint8)~(ResistiveTouch_1_ADC_IGNORE_PRESA1 | ResistiveTouch_1_ADC_IGNORE_PRESD1);
    ResistiveTouch_1_ADC_RESET_CR5_REG &= (uint8)~(ResistiveTouch_1_ADC_IGNORE_PRESA2 | ResistiveTouch_1_ADC_IGNORE_PRESD2);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_Read8
********************************************************************************
*
* Summary:
*  This function simplifies getting results from the ADC when only a
*  single reading is required. When called, it will start ADC
*  conversions, wait for the conversion to be complete, stop ADC
*  conversion and return the result. This is a blocking function and will
*  not return until the result is ready.
*
* Parameters:
*  None
*
* Return:
*  int8:  ADC result.
*
*******************************************************************************/
int8 ResistiveTouch_1_ADC_Read8(void) 
{
    int8 result;

    /* Clear pending conversion done status */
    ResistiveTouch_1_ADC_DEC_SR_REG |= ResistiveTouch_1_ADC_DEC_INTR_CLEAR;
    ResistiveTouch_1_ADC_StartConvert();
    (void)ResistiveTouch_1_ADC_IsEndConversion(ResistiveTouch_1_ADC_WAIT_FOR_RESULT);
     result = ResistiveTouch_1_ADC_GetResult8();
    ResistiveTouch_1_ADC_StopConvert();
    
     return(result);
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_Read16
********************************************************************************
*
* Summary:
*  This function simplifies getting results from the ADC when only a
*  single reading is required. When called, it will start ADC
*  conversions, wait for the conversion to be complete, stop ADC
*  conversion and return the result. This is a blocking function and will
*  not return until the result is ready.
*
* Parameters:
*   void
*
* Return:
*  int16:  ADC result.
*
*******************************************************************************/
int16 ResistiveTouch_1_ADC_Read16(void) 
{
    int16 result;

    /* Clear pending conversion done status */
    ResistiveTouch_1_ADC_DEC_SR_REG |= ResistiveTouch_1_ADC_DEC_INTR_CLEAR;
    ResistiveTouch_1_ADC_StartConvert();
    (void)ResistiveTouch_1_ADC_IsEndConversion(ResistiveTouch_1_ADC_WAIT_FOR_RESULT);
     result = ResistiveTouch_1_ADC_GetResult16();
    ResistiveTouch_1_ADC_StopConvert();
    
     return(result);
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_Read32
********************************************************************************
*
* Summary:
*  This function simplifies getting results from the ADC when only a
*  single reading is required. When called, it will start ADC
*  conversions, wait for the conversion to be complete, stop ADC
*  conversion and return the result. This is a blocking function and will
*  not return until the result is ready.
*
* Parameters:
*  None
*
* Return:
*  int32: ADC result.
*
*******************************************************************************/
int32 ResistiveTouch_1_ADC_Read32(void) 
{
    int32 result;
    
    /* Clear pending conversion done status */
    ResistiveTouch_1_ADC_DEC_SR_REG |= ResistiveTouch_1_ADC_DEC_INTR_CLEAR;
    ResistiveTouch_1_ADC_StartConvert();
    (void)ResistiveTouch_1_ADC_IsEndConversion(ResistiveTouch_1_ADC_WAIT_FOR_RESULT);
     result = ResistiveTouch_1_ADC_GetResult32();
    ResistiveTouch_1_ADC_StopConvert();
    
     return(result);
}


/* [] END OF FILE */
