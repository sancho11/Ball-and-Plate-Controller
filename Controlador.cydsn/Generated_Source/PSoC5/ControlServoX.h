/*******************************************************************************
* File Name: ControlServoX.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ControlServoX_H) /* Pins ControlServoX_H */
#define CY_PINS_ControlServoX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ControlServoX_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ControlServoX__PORT == 15 && ((ControlServoX__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ControlServoX_Write(uint8 value);
void    ControlServoX_SetDriveMode(uint8 mode);
uint8   ControlServoX_ReadDataReg(void);
uint8   ControlServoX_Read(void);
void    ControlServoX_SetInterruptMode(uint16 position, uint16 mode);
uint8   ControlServoX_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ControlServoX_SetDriveMode() function.
     *  @{
     */
        #define ControlServoX_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ControlServoX_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ControlServoX_DM_RES_UP          PIN_DM_RES_UP
        #define ControlServoX_DM_RES_DWN         PIN_DM_RES_DWN
        #define ControlServoX_DM_OD_LO           PIN_DM_OD_LO
        #define ControlServoX_DM_OD_HI           PIN_DM_OD_HI
        #define ControlServoX_DM_STRONG          PIN_DM_STRONG
        #define ControlServoX_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ControlServoX_MASK               ControlServoX__MASK
#define ControlServoX_SHIFT              ControlServoX__SHIFT
#define ControlServoX_WIDTH              1u

/* Interrupt constants */
#if defined(ControlServoX__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ControlServoX_SetInterruptMode() function.
     *  @{
     */
        #define ControlServoX_INTR_NONE      (uint16)(0x0000u)
        #define ControlServoX_INTR_RISING    (uint16)(0x0001u)
        #define ControlServoX_INTR_FALLING   (uint16)(0x0002u)
        #define ControlServoX_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ControlServoX_INTR_MASK      (0x01u) 
#endif /* (ControlServoX__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ControlServoX_PS                     (* (reg8 *) ControlServoX__PS)
/* Data Register */
#define ControlServoX_DR                     (* (reg8 *) ControlServoX__DR)
/* Port Number */
#define ControlServoX_PRT_NUM                (* (reg8 *) ControlServoX__PRT) 
/* Connect to Analog Globals */                                                  
#define ControlServoX_AG                     (* (reg8 *) ControlServoX__AG)                       
/* Analog MUX bux enable */
#define ControlServoX_AMUX                   (* (reg8 *) ControlServoX__AMUX) 
/* Bidirectional Enable */                                                        
#define ControlServoX_BIE                    (* (reg8 *) ControlServoX__BIE)
/* Bit-mask for Aliased Register Access */
#define ControlServoX_BIT_MASK               (* (reg8 *) ControlServoX__BIT_MASK)
/* Bypass Enable */
#define ControlServoX_BYP                    (* (reg8 *) ControlServoX__BYP)
/* Port wide control signals */                                                   
#define ControlServoX_CTL                    (* (reg8 *) ControlServoX__CTL)
/* Drive Modes */
#define ControlServoX_DM0                    (* (reg8 *) ControlServoX__DM0) 
#define ControlServoX_DM1                    (* (reg8 *) ControlServoX__DM1)
#define ControlServoX_DM2                    (* (reg8 *) ControlServoX__DM2) 
/* Input Buffer Disable Override */
#define ControlServoX_INP_DIS                (* (reg8 *) ControlServoX__INP_DIS)
/* LCD Common or Segment Drive */
#define ControlServoX_LCD_COM_SEG            (* (reg8 *) ControlServoX__LCD_COM_SEG)
/* Enable Segment LCD */
#define ControlServoX_LCD_EN                 (* (reg8 *) ControlServoX__LCD_EN)
/* Slew Rate Control */
#define ControlServoX_SLW                    (* (reg8 *) ControlServoX__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ControlServoX_PRTDSI__CAPS_SEL       (* (reg8 *) ControlServoX__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ControlServoX_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ControlServoX__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ControlServoX_PRTDSI__OE_SEL0        (* (reg8 *) ControlServoX__PRTDSI__OE_SEL0) 
#define ControlServoX_PRTDSI__OE_SEL1        (* (reg8 *) ControlServoX__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ControlServoX_PRTDSI__OUT_SEL0       (* (reg8 *) ControlServoX__PRTDSI__OUT_SEL0) 
#define ControlServoX_PRTDSI__OUT_SEL1       (* (reg8 *) ControlServoX__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ControlServoX_PRTDSI__SYNC_OUT       (* (reg8 *) ControlServoX__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ControlServoX__SIO_CFG)
    #define ControlServoX_SIO_HYST_EN        (* (reg8 *) ControlServoX__SIO_HYST_EN)
    #define ControlServoX_SIO_REG_HIFREQ     (* (reg8 *) ControlServoX__SIO_REG_HIFREQ)
    #define ControlServoX_SIO_CFG            (* (reg8 *) ControlServoX__SIO_CFG)
    #define ControlServoX_SIO_DIFF           (* (reg8 *) ControlServoX__SIO_DIFF)
#endif /* (ControlServoX__SIO_CFG) */

/* Interrupt Registers */
#if defined(ControlServoX__INTSTAT)
    #define ControlServoX_INTSTAT            (* (reg8 *) ControlServoX__INTSTAT)
    #define ControlServoX_SNAP               (* (reg8 *) ControlServoX__SNAP)
    
	#define ControlServoX_0_INTTYPE_REG 		(* (reg8 *) ControlServoX__0__INTTYPE)
#endif /* (ControlServoX__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ControlServoX_H */


/* [] END OF FILE */
