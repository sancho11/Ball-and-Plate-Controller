/*******************************************************************************
* File Name: Touch_ADC_PM.c
* Version 3.20
*
* Description:
*  This file provides the power manager source code to the API for the
*  Delta-Sigma ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Touch_ADC.h"

static Touch_ADC_BACKUP_STRUCT Touch_ADC_backup =
{
    Touch_ADC_DISABLED,
    Touch_ADC_CFG1_DEC_CR
};


/*******************************************************************************
* Function Name: Touch_ADC_SaveConfig
********************************************************************************
*
* Summary:
*  Save the register configuration which are not retention.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Touch_ADC_backup:  This global structure variable is used to store
*  configuration registers which are non retention whenever user wants to go
*  sleep mode by calling Sleep() API.
*
*******************************************************************************/
void Touch_ADC_SaveConfig(void) 
{
    Touch_ADC_backup.deccr = Touch_ADC_DEC_CR_REG;
}


/*******************************************************************************
* Function Name: Touch_ADC_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations which are not retention.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Touch_ADC_backup:  This global structure variable is used to restore
*  configuration registers which are non retention whenever user wants to switch
*  to active power mode by calling Wakeup() API.
*
*******************************************************************************/
void Touch_ADC_RestoreConfig(void) 
{
    Touch_ADC_DEC_CR_REG = Touch_ADC_backup.deccr;
}


/*******************************************************************************
* Function Name: Touch_ADC_Sleep
********************************************************************************
*
* Summary:
*  Stops the operation of the block and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Touch_ADC_backup:  The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void Touch_ADC_Sleep(void) 
{
    /* Save ADC enable state */
    if((Touch_ADC_ACT_PWR_DEC_EN == (Touch_ADC_PWRMGR_DEC_REG & Touch_ADC_ACT_PWR_DEC_EN)) &&
       (Touch_ADC_ACT_PWR_DSM_EN == (Touch_ADC_PWRMGR_DSM_REG & Touch_ADC_ACT_PWR_DSM_EN)))
    {
        /* Component is enabled */
        Touch_ADC_backup.enableState = Touch_ADC_ENABLED;
        if((Touch_ADC_DEC_CR_REG & Touch_ADC_DEC_START_CONV) != 0u)
        {   
            /* Conversion is started */
            Touch_ADC_backup.enableState |= Touch_ADC_STARTED;
        }
		
        /* Stop the configuration */
        Touch_ADC_Stop();
    }
    else
    {
        /* Component is disabled */
        Touch_ADC_backup.enableState = Touch_ADC_DISABLED;
    }

    /* Save the user configuration */
    Touch_ADC_SaveConfig();
}


/*******************************************************************************
* Function Name: Touch_ADC_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and enables the power to the block.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Touch_ADC_backup:  The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Touch_ADC_Wakeup(void) 
{
    /* Restore the configuration */
    Touch_ADC_RestoreConfig();

    /* Enables the component operation */
    if(Touch_ADC_backup.enableState != Touch_ADC_DISABLED)
    {
        Touch_ADC_Enable();
        if((Touch_ADC_backup.enableState & Touch_ADC_STARTED) != 0u)
        {
            Touch_ADC_StartConvert();
        }
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
