/*******************************************************************************
* File Name: ControlServoX.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ControlServoX_ALIASES_H) /* Pins ControlServoX_ALIASES_H */
#define CY_PINS_ControlServoX_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define ControlServoX_0			(ControlServoX__0__PC)
#define ControlServoX_0_INTR	((uint16)((uint16)0x0001u << ControlServoX__0__SHIFT))

#define ControlServoX_INTR_ALL	 ((uint16)(ControlServoX_0_INTR))

#endif /* End Pins ControlServoX_ALIASES_H */


/* [] END OF FILE */
