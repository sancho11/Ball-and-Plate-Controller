/*******************************************************************************
* File Name: ADC_PIN3_PM.c
* Version 3.10
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_PIN3.h"


/***************************************
* Local data allocation
***************************************/

static ADC_PIN3_BACKUP_STRUCT  ADC_PIN3_backup =
{
    ADC_PIN3_DISABLED
};


/*******************************************************************************
* Function Name: ADC_PIN3_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_PIN3_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_PIN3_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_PIN3_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_PIN3_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The ADC_PIN3_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_PIN3_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_PIN3_Sleep(void)
{
    if((ADC_PIN3_PWRMGR_SAR_REG  & ADC_PIN3_ACT_PWR_SAR_EN) != 0u)
    {
        if((ADC_PIN3_SAR_CSR0_REG & ADC_PIN3_SAR_SOF_START_CONV) != 0u)
        {
            ADC_PIN3_backup.enableState = ADC_PIN3_ENABLED | ADC_PIN3_STARTED;
        }
        else
        {
            ADC_PIN3_backup.enableState = ADC_PIN3_ENABLED;
        }
        ADC_PIN3_Stop();
    }
    else
    {
        ADC_PIN3_backup.enableState = ADC_PIN3_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_PIN3_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  ADC_PIN3_Sleep() was called. If the component was enabled before the
*  ADC_PIN3_Sleep() function was called, the
*  ADC_PIN3_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_PIN3_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_PIN3_Wakeup(void)
{
    if(ADC_PIN3_backup.enableState != ADC_PIN3_DISABLED)
    {
        ADC_PIN3_Enable();
        #if(ADC_PIN3_DEFAULT_CONV_MODE != ADC_PIN3__HARDWARE_TRIGGER)
            if((ADC_PIN3_backup.enableState & ADC_PIN3_STARTED) != 0u)
            {
                ADC_PIN3_StartConvert();
            }
        #endif /* End ADC_PIN3_DEFAULT_CONV_MODE != ADC_PIN3__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
