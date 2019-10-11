/*******************************************************************************
* File Name: Touch_xp.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Touch_xp_H) /* Pins Touch_xp_H */
#define CY_PINS_Touch_xp_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Touch_xp_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Touch_xp__PORT == 15 && ((Touch_xp__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Touch_xp_Write(uint8 value) ;
void    Touch_xp_SetDriveMode(uint8 mode) ;
uint8   Touch_xp_ReadDataReg(void) ;
uint8   Touch_xp_Read(void) ;
uint8   Touch_xp_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Touch_xp_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Touch_xp_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Touch_xp_DM_RES_UP          PIN_DM_RES_UP
#define Touch_xp_DM_RES_DWN         PIN_DM_RES_DWN
#define Touch_xp_DM_OD_LO           PIN_DM_OD_LO
#define Touch_xp_DM_OD_HI           PIN_DM_OD_HI
#define Touch_xp_DM_STRONG          PIN_DM_STRONG
#define Touch_xp_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Touch_xp_MASK               Touch_xp__MASK
#define Touch_xp_SHIFT              Touch_xp__SHIFT
#define Touch_xp_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Touch_xp_PS                     (* (reg8 *) Touch_xp__PS)
/* Data Register */
#define Touch_xp_DR                     (* (reg8 *) Touch_xp__DR)
/* Port Number */
#define Touch_xp_PRT_NUM                (* (reg8 *) Touch_xp__PRT) 
/* Connect to Analog Globals */                                                  
#define Touch_xp_AG                     (* (reg8 *) Touch_xp__AG)                       
/* Analog MUX bux enable */
#define Touch_xp_AMUX                   (* (reg8 *) Touch_xp__AMUX) 
/* Bidirectional Enable */                                                        
#define Touch_xp_BIE                    (* (reg8 *) Touch_xp__BIE)
/* Bit-mask for Aliased Register Access */
#define Touch_xp_BIT_MASK               (* (reg8 *) Touch_xp__BIT_MASK)
/* Bypass Enable */
#define Touch_xp_BYP                    (* (reg8 *) Touch_xp__BYP)
/* Port wide control signals */                                                   
#define Touch_xp_CTL                    (* (reg8 *) Touch_xp__CTL)
/* Drive Modes */
#define Touch_xp_DM0                    (* (reg8 *) Touch_xp__DM0) 
#define Touch_xp_DM1                    (* (reg8 *) Touch_xp__DM1)
#define Touch_xp_DM2                    (* (reg8 *) Touch_xp__DM2) 
/* Input Buffer Disable Override */
#define Touch_xp_INP_DIS                (* (reg8 *) Touch_xp__INP_DIS)
/* LCD Common or Segment Drive */
#define Touch_xp_LCD_COM_SEG            (* (reg8 *) Touch_xp__LCD_COM_SEG)
/* Enable Segment LCD */
#define Touch_xp_LCD_EN                 (* (reg8 *) Touch_xp__LCD_EN)
/* Slew Rate Control */
#define Touch_xp_SLW                    (* (reg8 *) Touch_xp__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Touch_xp_PRTDSI__CAPS_SEL       (* (reg8 *) Touch_xp__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Touch_xp_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Touch_xp__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Touch_xp_PRTDSI__OE_SEL0        (* (reg8 *) Touch_xp__PRTDSI__OE_SEL0) 
#define Touch_xp_PRTDSI__OE_SEL1        (* (reg8 *) Touch_xp__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Touch_xp_PRTDSI__OUT_SEL0       (* (reg8 *) Touch_xp__PRTDSI__OUT_SEL0) 
#define Touch_xp_PRTDSI__OUT_SEL1       (* (reg8 *) Touch_xp__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Touch_xp_PRTDSI__SYNC_OUT       (* (reg8 *) Touch_xp__PRTDSI__SYNC_OUT) 


#if defined(Touch_xp__INTSTAT)  /* Interrupt Registers */

    #define Touch_xp_INTSTAT                (* (reg8 *) Touch_xp__INTSTAT)
    #define Touch_xp_SNAP                   (* (reg8 *) Touch_xp__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Touch_xp_H */


/* [] END OF FILE */
