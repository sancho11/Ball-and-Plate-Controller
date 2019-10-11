/*******************************************************************************
* File Name: PWM_Y_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_Y.h"

static PWM_Y_backupStruct PWM_Y_backup;


/*******************************************************************************
* Function Name: PWM_Y_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Y_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Y_SaveConfig(void) 
{

    #if(!PWM_Y_UsingFixedFunction)
        #if(!PWM_Y_PWMModeIsCenterAligned)
            PWM_Y_backup.PWMPeriod = PWM_Y_ReadPeriod();
        #endif /* (!PWM_Y_PWMModeIsCenterAligned) */
        PWM_Y_backup.PWMUdb = PWM_Y_ReadCounter();
        #if (PWM_Y_UseStatus)
            PWM_Y_backup.InterruptMaskValue = PWM_Y_STATUS_MASK;
        #endif /* (PWM_Y_UseStatus) */

        #if(PWM_Y_DeadBandMode == PWM_Y__B_PWM__DBM_256_CLOCKS || \
            PWM_Y_DeadBandMode == PWM_Y__B_PWM__DBM_2_4_CLOCKS)
            PWM_Y_backup.PWMdeadBandValue = PWM_Y_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Y_KillModeMinTime)
             PWM_Y_backup.PWMKillCounterPeriod = PWM_Y_ReadKillTime();
        #endif /* (PWM_Y_KillModeMinTime) */

        #if(PWM_Y_UseControl)
            PWM_Y_backup.PWMControlRegister = PWM_Y_ReadControlRegister();
        #endif /* (PWM_Y_UseControl) */
    #endif  /* (!PWM_Y_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Y_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Y_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Y_RestoreConfig(void) 
{
        #if(!PWM_Y_UsingFixedFunction)
            #if(!PWM_Y_PWMModeIsCenterAligned)
                PWM_Y_WritePeriod(PWM_Y_backup.PWMPeriod);
            #endif /* (!PWM_Y_PWMModeIsCenterAligned) */

            PWM_Y_WriteCounter(PWM_Y_backup.PWMUdb);

            #if (PWM_Y_UseStatus)
                PWM_Y_STATUS_MASK = PWM_Y_backup.InterruptMaskValue;
            #endif /* (PWM_Y_UseStatus) */

            #if(PWM_Y_DeadBandMode == PWM_Y__B_PWM__DBM_256_CLOCKS || \
                PWM_Y_DeadBandMode == PWM_Y__B_PWM__DBM_2_4_CLOCKS)
                PWM_Y_WriteDeadTime(PWM_Y_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Y_KillModeMinTime)
                PWM_Y_WriteKillTime(PWM_Y_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Y_KillModeMinTime) */

            #if(PWM_Y_UseControl)
                PWM_Y_WriteControlRegister(PWM_Y_backup.PWMControlRegister);
            #endif /* (PWM_Y_UseControl) */
        #endif  /* (!PWM_Y_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Y_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Y_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Y_Sleep(void) 
{
    #if(PWM_Y_UseControl)
        if(PWM_Y_CTRL_ENABLE == (PWM_Y_CONTROL & PWM_Y_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Y_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Y_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Y_UseControl) */

    /* Stop component */
    PWM_Y_Stop();

    /* Save registers configuration */
    PWM_Y_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Y_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Y_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Y_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Y_RestoreConfig();

    if(PWM_Y_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Y_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
