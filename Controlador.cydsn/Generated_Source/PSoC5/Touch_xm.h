/*******************************************************************************
* File Name: Touch_xm.h  
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

#if !defined(CY_PINS_Touch_xm_H) /* Pins Touch_xm_H */
#define CY_PINS_Touch_xm_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Touch_xm_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Touch_xm__PORT == 15 && ((Touch_xm__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Touch_xm_Write(uint8 value) ;
void    Touch_xm_SetDriveMode(uint8 mode) ;
uint8   Touch_xm_ReadDataReg(void) ;
uint8   Touch_xm_Read(void) ;
uint8   Touch_xm_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Touch_xm_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Touch_xm_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Touch_xm_DM_RES_UP          PIN_DM_RES_UP
#define Touch_xm_DM_RES_DWN         PIN_DM_RES_DWN
#define Touch_xm_DM_OD_LO           PIN_DM_OD_LO
#define Touch_xm_DM_OD_HI           PIN_DM_OD_HI
#define Touch_xm_DM_STRONG          PIN_DM_STRONG
#define Touch_xm_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Touch_xm_MASK               Touch_xm__MASK
#define Touch_xm_SHIFT              Touch_xm__SHIFT
#define Touch_xm_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Touch_xm_PS                     (* (reg8 *) Touch_xm__PS)
/* Data Register */
#define Touch_xm_DR                     (* (reg8 *) Touch_xm__DR)
/* Port Number */
#define Touch_xm_PRT_NUM                (* (reg8 *) Touch_xm__PRT) 
/* Connect to Analog Globals */                                                  
#define Touch_xm_AG                     (* (reg8 *) Touch_xm__AG)                       
/* Analog MUX bux enable */
#define Touch_xm_AMUX                   (* (reg8 *) Touch_xm__AMUX) 
/* Bidirectional Enable */                                                        
#define Touch_xm_BIE                    (* (reg8 *) Touch_xm__BIE)
/* Bit-mask for Aliased Register Access */
#define Touch_xm_BIT_MASK               (* (reg8 *) Touch_xm__BIT_MASK)
/* Bypass Enable */
#define Touch_xm_BYP                    (* (reg8 *) Touch_xm__BYP)
/* Port wide control signals */                                                   
#define Touch_xm_CTL                    (* (reg8 *) Touch_xm__CTL)
/* Drive Modes */
#define Touch_xm_DM0                    (* (reg8 *) Touch_xm__DM0) 
#define Touch_xm_DM1                    (* (reg8 *) Touch_xm__DM1)
#define Touch_xm_DM2                    (* (reg8 *) Touch_xm__DM2) 
/* Input Buffer Disable Override */
#define Touch_xm_INP_DIS                (* (reg8 *) Touch_xm__INP_DIS)
/* LCD Common or Segment Drive */
#define Touch_xm_LCD_COM_SEG            (* (reg8 *) Touch_xm__LCD_COM_SEG)
/* Enable Segment LCD */
#define Touch_xm_LCD_EN                 (* (reg8 *) Touch_xm__LCD_EN)
/* Slew Rate Control */
#define Touch_xm_SLW                    (* (reg8 *) Touch_xm__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Touch_xm_PRTDSI__CAPS_SEL       (* (reg8 *) Touch_xm__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Touch_xm_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Touch_xm__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Touch_xm_PRTDSI__OE_SEL0        (* (reg8 *) Touch_xm__PRTDSI__OE_SEL0) 
#define Touch_xm_PRTDSI__OE_SEL1        (* (reg8 *) Touch_xm__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Touch_xm_PRTDSI__OUT_SEL0       (* (reg8 *) Touch_xm__PRTDSI__OUT_SEL0) 
#define Touch_xm_PRTDSI__OUT_SEL1       (* (reg8 *) Touch_xm__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Touch_xm_PRTDSI__SYNC_OUT       (* (reg8 *) Touch_xm__PRTDSI__SYNC_OUT) 


#if defined(Touch_xm__INTSTAT)  /* Interrupt Registers */

    #define Touch_xm_INTSTAT                (* (reg8 *) Touch_xm__INTSTAT)
    #define Touch_xm_SNAP                   (* (reg8 *) Touch_xm__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Touch_xm_H */


/* [] END OF FILE */
