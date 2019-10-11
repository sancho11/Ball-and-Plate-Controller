/*******************************************************************************
* File Name: ResistiveBoardPin.h  
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

#if !defined(CY_PINS_ResistiveBoardPin_ALIASES_H) /* Pins ResistiveBoardPin_ALIASES_H */
#define CY_PINS_ResistiveBoardPin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define ResistiveBoardPin_0			(ResistiveBoardPin__0__PC)
#define ResistiveBoardPin_0_INTR	((uint16)((uint16)0x0001u << ResistiveBoardPin__0__SHIFT))

#define ResistiveBoardPin_1			(ResistiveBoardPin__1__PC)
#define ResistiveBoardPin_1_INTR	((uint16)((uint16)0x0001u << ResistiveBoardPin__1__SHIFT))

#define ResistiveBoardPin_2			(ResistiveBoardPin__2__PC)
#define ResistiveBoardPin_2_INTR	((uint16)((uint16)0x0001u << ResistiveBoardPin__2__SHIFT))

#define ResistiveBoardPin_3			(ResistiveBoardPin__3__PC)
#define ResistiveBoardPin_3_INTR	((uint16)((uint16)0x0001u << ResistiveBoardPin__3__SHIFT))

#define ResistiveBoardPin_INTR_ALL	 ((uint16)(ResistiveBoardPin_0_INTR| ResistiveBoardPin_1_INTR| ResistiveBoardPin_2_INTR| ResistiveBoardPin_3_INTR))

#endif /* End Pins ResistiveBoardPin_ALIASES_H */


/* [] END OF FILE */
