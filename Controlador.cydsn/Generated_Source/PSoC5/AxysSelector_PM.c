/*******************************************************************************
* File Name: AxysSelector_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "AxysSelector.h"

/* Check for removal by optimization */
#if !defined(AxysSelector_Sync_ctrl_reg__REMOVED)

static AxysSelector_BACKUP_STRUCT  AxysSelector_backup = {0u};

    
/*******************************************************************************
* Function Name: AxysSelector_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void AxysSelector_SaveConfig(void) 
{
    AxysSelector_backup.controlState = AxysSelector_Control;
}


/*******************************************************************************
* Function Name: AxysSelector_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void AxysSelector_RestoreConfig(void) 
{
     AxysSelector_Control = AxysSelector_backup.controlState;
}


/*******************************************************************************
* Function Name: AxysSelector_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void AxysSelector_Sleep(void) 
{
    AxysSelector_SaveConfig();
}


/*******************************************************************************
* Function Name: AxysSelector_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void AxysSelector_Wakeup(void)  
{
    AxysSelector_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
