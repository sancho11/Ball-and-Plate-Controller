/*******************************************************************************
* File Name: Touch_ym.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Touch_ym.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Touch_ym__PORT == 15 && ((Touch_ym__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Touch_ym_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void Touch_ym_Write(uint8 value) 
{
    uint8 staticBits = (Touch_ym_DR & (uint8)(~Touch_ym_MASK));
    Touch_ym_DR = staticBits | ((uint8)(value << Touch_ym_SHIFT) & Touch_ym_MASK);
}


/*******************************************************************************
* Function Name: Touch_ym_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Touch_ym_DM_STRONG     Strong Drive 
*  Touch_ym_DM_OD_HI      Open Drain, Drives High 
*  Touch_ym_DM_OD_LO      Open Drain, Drives Low 
*  Touch_ym_DM_RES_UP     Resistive Pull Up 
*  Touch_ym_DM_RES_DWN    Resistive Pull Down 
*  Touch_ym_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Touch_ym_DM_DIG_HIZ    High Impedance Digital 
*  Touch_ym_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Touch_ym_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Touch_ym_0, mode);
}


/*******************************************************************************
* Function Name: Touch_ym_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Touch_ym_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Touch_ym_Read(void) 
{
    return (Touch_ym_PS & Touch_ym_MASK) >> Touch_ym_SHIFT;
}


/*******************************************************************************
* Function Name: Touch_ym_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Touch_ym_ReadDataReg(void) 
{
    return (Touch_ym_DR & Touch_ym_MASK) >> Touch_ym_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Touch_ym_INTSTAT) 

    /*******************************************************************************
    * Function Name: Touch_ym_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Touch_ym_ClearInterrupt(void) 
    {
        return (Touch_ym_INTSTAT & Touch_ym_MASK) >> Touch_ym_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
