/*******************************************************************************
* File Name: Touch_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Touch.h"


/*******************************************************************************
* Function Name: Touch_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the ADC configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Touch_SaveConfig(void) 
{
    Touch_ADC_SaveConfig();   
}


/*******************************************************************************
* Function Name: Touch_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the ADC configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Touch_RestoreConfig(void) 
{
    Touch_ADC_RestoreConfig();  
}


/*******************************************************************************
* Function Name: Touch_Sleep
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
void Touch_Sleep(void) 
{
    Touch_ADC_Sleep();
    Touch_AMux_Stop();
}


/*******************************************************************************
* Function Name: Touch_Wakeup
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
void Touch_Wakeup(void)  
{
    Touch_ADC_Wakeup();
}


/* [] END OF FILE */
