/*******************************************************************************
* File Name: Potenciometro_SAR_PM.c
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

#include "Potenciometro_SAR.h"


/***************************************
* Local data allocation
***************************************/

static Potenciometro_SAR_BACKUP_STRUCT  Potenciometro_SAR_backup =
{
    Potenciometro_SAR_DISABLED
};


/*******************************************************************************
* Function Name: Potenciometro_SAR_SaveConfig
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
void Potenciometro_SAR_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Potenciometro_SAR_RestoreConfig
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
void Potenciometro_SAR_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Potenciometro_SAR_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The Potenciometro_SAR_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Potenciometro_SAR_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void Potenciometro_SAR_Sleep(void)
{
    if((Potenciometro_SAR_PWRMGR_SAR_REG  & Potenciometro_SAR_ACT_PWR_SAR_EN) != 0u)
    {
        if((Potenciometro_SAR_SAR_CSR0_REG & Potenciometro_SAR_SAR_SOF_START_CONV) != 0u)
        {
            Potenciometro_SAR_backup.enableState = Potenciometro_SAR_ENABLED | Potenciometro_SAR_STARTED;
        }
        else
        {
            Potenciometro_SAR_backup.enableState = Potenciometro_SAR_ENABLED;
        }
        Potenciometro_SAR_Stop();
    }
    else
    {
        Potenciometro_SAR_backup.enableState = Potenciometro_SAR_DISABLED;
    }
}


/*******************************************************************************
* Function Name: Potenciometro_SAR_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  Potenciometro_SAR_Sleep() was called. If the component was enabled before the
*  Potenciometro_SAR_Sleep() function was called, the
*  Potenciometro_SAR_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Potenciometro_SAR_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Potenciometro_SAR_Wakeup(void)
{
    if(Potenciometro_SAR_backup.enableState != Potenciometro_SAR_DISABLED)
    {
        Potenciometro_SAR_Enable();
        #if(Potenciometro_SAR_DEFAULT_CONV_MODE != Potenciometro_SAR__HARDWARE_TRIGGER)
            if((Potenciometro_SAR_backup.enableState & Potenciometro_SAR_STARTED) != 0u)
            {
                Potenciometro_SAR_StartConvert();
            }
        #endif /* End Potenciometro_SAR_DEFAULT_CONV_MODE != Potenciometro_SAR__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
