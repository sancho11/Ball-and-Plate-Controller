/*******************************************************************************
* File Name: PWM_X_PM.c
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

#include "PWM_X.h"

static PWM_X_backupStruct PWM_X_backup;


/*******************************************************************************
* Function Name: PWM_X_SaveConfig
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
*  PWM_X_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_X_SaveConfig(void) 
{

    #if(!PWM_X_UsingFixedFunction)
        #if(!PWM_X_PWMModeIsCenterAligned)
            PWM_X_backup.PWMPeriod = PWM_X_ReadPeriod();
        #endif /* (!PWM_X_PWMModeIsCenterAligned) */
        PWM_X_backup.PWMUdb = PWM_X_ReadCounter();
        #if (PWM_X_UseStatus)
            PWM_X_backup.InterruptMaskValue = PWM_X_STATUS_MASK;
        #endif /* (PWM_X_UseStatus) */

        #if(PWM_X_DeadBandMode == PWM_X__B_PWM__DBM_256_CLOCKS || \
            PWM_X_DeadBandMode == PWM_X__B_PWM__DBM_2_4_CLOCKS)
            PWM_X_backup.PWMdeadBandValue = PWM_X_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_X_KillModeMinTime)
             PWM_X_backup.PWMKillCounterPeriod = PWM_X_ReadKillTime();
        #endif /* (PWM_X_KillModeMinTime) */

        #if(PWM_X_UseControl)
            PWM_X_backup.PWMControlRegister = PWM_X_ReadControlRegister();
        #endif /* (PWM_X_UseControl) */
    #endif  /* (!PWM_X_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_X_RestoreConfig
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
*  PWM_X_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_X_RestoreConfig(void) 
{
        #if(!PWM_X_UsingFixedFunction)
            #if(!PWM_X_PWMModeIsCenterAligned)
                PWM_X_WritePeriod(PWM_X_backup.PWMPeriod);
            #endif /* (!PWM_X_PWMModeIsCenterAligned) */

            PWM_X_WriteCounter(PWM_X_backup.PWMUdb);

            #if (PWM_X_UseStatus)
                PWM_X_STATUS_MASK = PWM_X_backup.InterruptMaskValue;
            #endif /* (PWM_X_UseStatus) */

            #if(PWM_X_DeadBandMode == PWM_X__B_PWM__DBM_256_CLOCKS || \
                PWM_X_DeadBandMode == PWM_X__B_PWM__DBM_2_4_CLOCKS)
                PWM_X_WriteDeadTime(PWM_X_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_X_KillModeMinTime)
                PWM_X_WriteKillTime(PWM_X_backup.PWMKillCounterPeriod);
            #endif /* (PWM_X_KillModeMinTime) */

            #if(PWM_X_UseControl)
                PWM_X_WriteControlRegister(PWM_X_backup.PWMControlRegister);
            #endif /* (PWM_X_UseControl) */
        #endif  /* (!PWM_X_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_X_Sleep
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
*  PWM_X_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_X_Sleep(void) 
{
    #if(PWM_X_UseControl)
        if(PWM_X_CTRL_ENABLE == (PWM_X_CONTROL & PWM_X_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_X_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_X_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_X_UseControl) */

    /* Stop component */
    PWM_X_Stop();

    /* Save registers configuration */
    PWM_X_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_X_Wakeup
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
*  PWM_X_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_X_Wakeup(void) 
{
     /* Restore registers values */
    PWM_X_RestoreConfig();

    if(PWM_X_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_X_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
