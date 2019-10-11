/*******************************************************************************
* File Name: AxisSelector_PM.c
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

#include "AxisSelector.h"

/* Check for removal by optimization */
#if !defined(AxisSelector_Sync_ctrl_reg__REMOVED)

static AxisSelector_BACKUP_STRUCT  AxisSelector_backup = {0u};

    
/*******************************************************************************
* Function Name: AxisSelector_SaveConfig
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
void AxisSelector_SaveConfig(void) 
{
    AxisSelector_backup.controlState = AxisSelector_Control;
}


/*******************************************************************************
* Function Name: AxisSelector_RestoreConfig
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
void AxisSelector_RestoreConfig(void) 
{
     AxisSelector_Control = AxisSelector_backup.controlState;
}


/*******************************************************************************
* Function Name: AxisSelector_Sleep
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
void AxisSelector_Sleep(void) 
{
    AxisSelector_SaveConfig();
}


/*******************************************************************************
* Function Name: AxisSelector_Wakeup
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
void AxisSelector_Wakeup(void)  
{
    AxisSelector_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
