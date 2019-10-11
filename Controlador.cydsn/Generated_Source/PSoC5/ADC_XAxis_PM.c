/*******************************************************************************
* File Name: ADC_XAxis_PM.c
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

#include "ADC_XAxis.h"


/***************************************
* Local data allocation
***************************************/

static ADC_XAxis_BACKUP_STRUCT  ADC_XAxis_backup =
{
    ADC_XAxis_DISABLED
};


/*******************************************************************************
* Function Name: ADC_XAxis_SaveConfig
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
void ADC_XAxis_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_XAxis_RestoreConfig
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
void ADC_XAxis_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_XAxis_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The ADC_XAxis_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_XAxis_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_XAxis_Sleep(void)
{
    if((ADC_XAxis_PWRMGR_SAR_REG  & ADC_XAxis_ACT_PWR_SAR_EN) != 0u)
    {
        if((ADC_XAxis_SAR_CSR0_REG & ADC_XAxis_SAR_SOF_START_CONV) != 0u)
        {
            ADC_XAxis_backup.enableState = ADC_XAxis_ENABLED | ADC_XAxis_STARTED;
        }
        else
        {
            ADC_XAxis_backup.enableState = ADC_XAxis_ENABLED;
        }
        ADC_XAxis_Stop();
    }
    else
    {
        ADC_XAxis_backup.enableState = ADC_XAxis_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_XAxis_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  ADC_XAxis_Sleep() was called. If the component was enabled before the
*  ADC_XAxis_Sleep() function was called, the
*  ADC_XAxis_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_XAxis_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_XAxis_Wakeup(void)
{
    if(ADC_XAxis_backup.enableState != ADC_XAxis_DISABLED)
    {
        ADC_XAxis_Enable();
        #if(ADC_XAxis_DEFAULT_CONV_MODE != ADC_XAxis__HARDWARE_TRIGGER)
            if((ADC_XAxis_backup.enableState & ADC_XAxis_STARTED) != 0u)
            {
                ADC_XAxis_StartConvert();
            }
        #endif /* End ADC_XAxis_DEFAULT_CONV_MODE != ADC_XAxis__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
