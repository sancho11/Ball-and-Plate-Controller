/*******************************************************************************
* File Name: Potenciometro_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Potenciometro.h"
#include "Potenciometro_SAR.h"
#if(Potenciometro_CLOCK_SOURCE == Potenciometro_CLOCK_INTERNAL)
    #include "Potenciometro_IntClock.h"
#endif   /* Potenciometro_CLOCK_SOURCE == Potenciometro_CLOCK_INTERNAL */


/*******************************************************************************
* Function Name: Potenciometro_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Potenciometro_Sleep(void)
{
    Potenciometro_SAR_Stop();
    Potenciometro_SAR_Sleep();
    Potenciometro_Disable();

    #if(Potenciometro_CLOCK_SOURCE == Potenciometro_CLOCK_INTERNAL)
        Potenciometro_IntClock_Stop();
    #endif   /* Potenciometro_CLOCK_SOURCE == Potenciometro_CLOCK_INTERNAL */
}


/*******************************************************************************
* Function Name: Potenciometro_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers. This should
*  be called just after awaking from sleep mode
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Potenciometro_Wakeup(void)
{
    Potenciometro_SAR_Wakeup();
    Potenciometro_SAR_Enable();

    #if(Potenciometro_CLOCK_SOURCE == Potenciometro_CLOCK_INTERNAL)
        Potenciometro_IntClock_Start();
    #endif   /* Potenciometro_CLOCK_SOURCE == Potenciometro_CLOCK_INTERNAL */

    /* The block is ready to use 10 us after the SAR enable signal is set high. */
    CyDelayUs(10u);
    
    Potenciometro_Enable();

    #if(Potenciometro_SAMPLE_MODE == Potenciometro_SAMPLE_MODE_FREE_RUNNING)
        Potenciometro_SAR_StartConvert();
    #endif /* (Potenciometro_SAMPLE_MODE == Potenciometro_SAMPLE_MODE_FREE_RUNNING) */

    (void) CY_GET_REG8(Potenciometro_STATUS_PTR);
}


/*******************************************************************************
* Function Name: Potenciometro_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Potenciometro_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Potenciometro_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void Potenciometro_RestoreConfig(void)
{

}


/* [] END OF FILE */
