/*******************************************************************************
* File Name: ADC_YAxis_PM.c
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

#include "ADC_YAxis.h"


/***************************************
* Local data allocation
***************************************/

static ADC_YAxis_BACKUP_STRUCT  ADC_YAxis_backup =
{
    ADC_YAxis_DISABLED
};


/*******************************************************************************
* Function Name: ADC_YAxis_SaveConfig
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
void ADC_YAxis_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_YAxis_RestoreConfig
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
void ADC_YAxis_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_YAxis_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The ADC_YAxis_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_YAxis_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_YAxis_Sleep(void)
{
    if((ADC_YAxis_PWRMGR_SAR_REG  & ADC_YAxis_ACT_PWR_SAR_EN) != 0u)
    {
        if((ADC_YAxis_SAR_CSR0_REG & ADC_YAxis_SAR_SOF_START_CONV) != 0u)
        {
            ADC_YAxis_backup.enableState = ADC_YAxis_ENABLED | ADC_YAxis_STARTED;
        }
        else
        {
            ADC_YAxis_backup.enableState = ADC_YAxis_ENABLED;
        }
        ADC_YAxis_Stop();
    }
    else
    {
        ADC_YAxis_backup.enableState = ADC_YAxis_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_YAxis_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  ADC_YAxis_Sleep() was called. If the component was enabled before the
*  ADC_YAxis_Sleep() function was called, the
*  ADC_YAxis_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_YAxis_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_YAxis_Wakeup(void)
{
    if(ADC_YAxis_backup.enableState != ADC_YAxis_DISABLED)
    {
        ADC_YAxis_Enable();
        #if(ADC_YAxis_DEFAULT_CONV_MODE != ADC_YAxis__HARDWARE_TRIGGER)
            if((ADC_YAxis_backup.enableState & ADC_YAxis_STARTED) != 0u)
            {
                ADC_YAxis_StartConvert();
            }
        #endif /* End ADC_YAxis_DEFAULT_CONV_MODE != ADC_YAxis__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
