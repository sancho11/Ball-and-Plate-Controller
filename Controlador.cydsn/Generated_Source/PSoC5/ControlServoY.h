/*******************************************************************************
* File Name: ControlServoY.h  
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

#if !defined(CY_PINS_ControlServoY_H) /* Pins ControlServoY_H */
#define CY_PINS_ControlServoY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ControlServoY_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ControlServoY__PORT == 15 && ((ControlServoY__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ControlServoY_Write(uint8 value);
void    ControlServoY_SetDriveMode(uint8 mode);
uint8   ControlServoY_ReadDataReg(void);
uint8   ControlServoY_Read(void);
void    ControlServoY_SetInterruptMode(uint16 position, uint16 mode);
uint8   ControlServoY_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ControlServoY_SetDriveMode() function.
     *  @{
     */
        #define ControlServoY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ControlServoY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ControlServoY_DM_RES_UP          PIN_DM_RES_UP
        #define ControlServoY_DM_RES_DWN         PIN_DM_RES_DWN
        #define ControlServoY_DM_OD_LO           PIN_DM_OD_LO
        #define ControlServoY_DM_OD_HI           PIN_DM_OD_HI
        #define ControlServoY_DM_STRONG          PIN_DM_STRONG
        #define ControlServoY_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ControlServoY_MASK               ControlServoY__MASK
#define ControlServoY_SHIFT              ControlServoY__SHIFT
#define ControlServoY_WIDTH              1u

/* Interrupt constants */
#if defined(ControlServoY__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ControlServoY_SetInterruptMode() function.
     *  @{
     */
        #define ControlServoY_INTR_NONE      (uint16)(0x0000u)
        #define ControlServoY_INTR_RISING    (uint16)(0x0001u)
        #define ControlServoY_INTR_FALLING   (uint16)(0x0002u)
        #define ControlServoY_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ControlServoY_INTR_MASK      (0x01u) 
#endif /* (ControlServoY__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ControlServoY_PS                     (* (reg8 *) ControlServoY__PS)
/* Data Register */
#define ControlServoY_DR                     (* (reg8 *) ControlServoY__DR)
/* Port Number */
#define ControlServoY_PRT_NUM                (* (reg8 *) ControlServoY__PRT) 
/* Connect to Analog Globals */                                                  
#define ControlServoY_AG                     (* (reg8 *) ControlServoY__AG)                       
/* Analog MUX bux enable */
#define ControlServoY_AMUX                   (* (reg8 *) ControlServoY__AMUX) 
/* Bidirectional Enable */                                                        
#define ControlServoY_BIE                    (* (reg8 *) ControlServoY__BIE)
/* Bit-mask for Aliased Register Access */
#define ControlServoY_BIT_MASK               (* (reg8 *) ControlServoY__BIT_MASK)
/* Bypass Enable */
#define ControlServoY_BYP                    (* (reg8 *) ControlServoY__BYP)
/* Port wide control signals */                                                   
#define ControlServoY_CTL                    (* (reg8 *) ControlServoY__CTL)
/* Drive Modes */
#define ControlServoY_DM0                    (* (reg8 *) ControlServoY__DM0) 
#define ControlServoY_DM1                    (* (reg8 *) ControlServoY__DM1)
#define ControlServoY_DM2                    (* (reg8 *) ControlServoY__DM2) 
/* Input Buffer Disable Override */
#define ControlServoY_INP_DIS                (* (reg8 *) ControlServoY__INP_DIS)
/* LCD Common or Segment Drive */
#define ControlServoY_LCD_COM_SEG            (* (reg8 *) ControlServoY__LCD_COM_SEG)
/* Enable Segment LCD */
#define ControlServoY_LCD_EN                 (* (reg8 *) ControlServoY__LCD_EN)
/* Slew Rate Control */
#define ControlServoY_SLW                    (* (reg8 *) ControlServoY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ControlServoY_PRTDSI__CAPS_SEL       (* (reg8 *) ControlServoY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ControlServoY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ControlServoY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ControlServoY_PRTDSI__OE_SEL0        (* (reg8 *) ControlServoY__PRTDSI__OE_SEL0) 
#define ControlServoY_PRTDSI__OE_SEL1        (* (reg8 *) ControlServoY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ControlServoY_PRTDSI__OUT_SEL0       (* (reg8 *) ControlServoY__PRTDSI__OUT_SEL0) 
#define ControlServoY_PRTDSI__OUT_SEL1       (* (reg8 *) ControlServoY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ControlServoY_PRTDSI__SYNC_OUT       (* (reg8 *) ControlServoY__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ControlServoY__SIO_CFG)
    #define ControlServoY_SIO_HYST_EN        (* (reg8 *) ControlServoY__SIO_HYST_EN)
    #define ControlServoY_SIO_REG_HIFREQ     (* (reg8 *) ControlServoY__SIO_REG_HIFREQ)
    #define ControlServoY_SIO_CFG            (* (reg8 *) ControlServoY__SIO_CFG)
    #define ControlServoY_SIO_DIFF           (* (reg8 *) ControlServoY__SIO_DIFF)
#endif /* (ControlServoY__SIO_CFG) */

/* Interrupt Registers */
#if defined(ControlServoY__INTSTAT)
    #define ControlServoY_INTSTAT            (* (reg8 *) ControlServoY__INTSTAT)
    #define ControlServoY_SNAP               (* (reg8 *) ControlServoY__SNAP)
    
	#define ControlServoY_0_INTTYPE_REG 		(* (reg8 *) ControlServoY__0__INTTYPE)
#endif /* (ControlServoY__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ControlServoY_H */


/* [] END OF FILE */
