/*******************************************************************************
* File Name: ADC_XAxys_PM.c
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

#include "ADC_XAxys.h"


/***************************************
* Local data allocation
***************************************/

static ADC_XAxys_BACKUP_STRUCT  ADC_XAxys_backup =
{
    ADC_XAxys_DISABLED
};


/*******************************************************************************
* Function Name: ADC_XAxys_SaveConfig
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
void ADC_XAxys_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_XAxys_RestoreConfig
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
void ADC_XAxys_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_XAxys_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The ADC_XAxys_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_XAxys_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_XAxys_Sleep(void)
{
    if((ADC_XAxys_PWRMGR_SAR_REG  & ADC_XAxys_ACT_PWR_SAR_EN) != 0u)
    {
        if((ADC_XAxys_SAR_CSR0_REG & ADC_XAxys_SAR_SOF_START_CONV) != 0u)
        {
            ADC_XAxys_backup.enableState = ADC_XAxys_ENABLED | ADC_XAxys_STARTED;
        }
        else
        {
            ADC_XAxys_backup.enableState = ADC_XAxys_ENABLED;
        }
        ADC_XAxys_Stop();
    }
    else
    {
        ADC_XAxys_backup.enableState = ADC_XAxys_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_XAxys_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  ADC_XAxys_Sleep() was called. If the component was enabled before the
*  ADC_XAxys_Sleep() function was called, the
*  ADC_XAxys_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_XAxys_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_XAxys_Wakeup(void)
{
    if(ADC_XAxys_backup.enableState != ADC_XAxys_DISABLED)
    {
        ADC_XAxys_Enable();
        #if(ADC_XAxys_DEFAULT_CONV_MODE != ADC_XAxys__HARDWARE_TRIGGER)
            if((ADC_XAxys_backup.enableState & ADC_XAxys_STARTED) != 0u)
            {
                ADC_XAxys_StartConvert();
            }
        #endif /* End ADC_XAxys_DEFAULT_CONV_MODE != ADC_XAxys__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
