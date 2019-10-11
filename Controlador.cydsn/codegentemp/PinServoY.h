/*******************************************************************************
* File Name: PinServoY.h  
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

#if !defined(CY_PINS_PinServoY_H) /* Pins PinServoY_H */
#define CY_PINS_PinServoY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PinServoY_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PinServoY__PORT == 15 && ((PinServoY__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PinServoY_Write(uint8 value);
void    PinServoY_SetDriveMode(uint8 mode);
uint8   PinServoY_ReadDataReg(void);
uint8   PinServoY_Read(void);
void    PinServoY_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinServoY_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PinServoY_SetDriveMode() function.
     *  @{
     */
        #define PinServoY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PinServoY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PinServoY_DM_RES_UP          PIN_DM_RES_UP
        #define PinServoY_DM_RES_DWN         PIN_DM_RES_DWN
        #define PinServoY_DM_OD_LO           PIN_DM_OD_LO
        #define PinServoY_DM_OD_HI           PIN_DM_OD_HI
        #define PinServoY_DM_STRONG          PIN_DM_STRONG
        #define PinServoY_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PinServoY_MASK               PinServoY__MASK
#define PinServoY_SHIFT              PinServoY__SHIFT
#define PinServoY_WIDTH              1u

/* Interrupt constants */
#if defined(PinServoY__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinServoY_SetInterruptMode() function.
     *  @{
     */
        #define PinServoY_INTR_NONE      (uint16)(0x0000u)
        #define PinServoY_INTR_RISING    (uint16)(0x0001u)
        #define PinServoY_INTR_FALLING   (uint16)(0x0002u)
        #define PinServoY_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PinServoY_INTR_MASK      (0x01u) 
#endif /* (PinServoY__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PinServoY_PS                     (* (reg8 *) PinServoY__PS)
/* Data Register */
#define PinServoY_DR                     (* (reg8 *) PinServoY__DR)
/* Port Number */
#define PinServoY_PRT_NUM                (* (reg8 *) PinServoY__PRT) 
/* Connect to Analog Globals */                                                  
#define PinServoY_AG                     (* (reg8 *) PinServoY__AG)                       
/* Analog MUX bux enable */
#define PinServoY_AMUX                   (* (reg8 *) PinServoY__AMUX) 
/* Bidirectional Enable */                                                        
#define PinServoY_BIE                    (* (reg8 *) PinServoY__BIE)
/* Bit-mask for Aliased Register Access */
#define PinServoY_BIT_MASK               (* (reg8 *) PinServoY__BIT_MASK)
/* Bypass Enable */
#define PinServoY_BYP                    (* (reg8 *) PinServoY__BYP)
/* Port wide control signals */                                                   
#define PinServoY_CTL                    (* (reg8 *) PinServoY__CTL)
/* Drive Modes */
#define PinServoY_DM0                    (* (reg8 *) PinServoY__DM0) 
#define PinServoY_DM1                    (* (reg8 *) PinServoY__DM1)
#define PinServoY_DM2                    (* (reg8 *) PinServoY__DM2) 
/* Input Buffer Disable Override */
#define PinServoY_INP_DIS                (* (reg8 *) PinServoY__INP_DIS)
/* LCD Common or Segment Drive */
#define PinServoY_LCD_COM_SEG            (* (reg8 *) PinServoY__LCD_COM_SEG)
/* Enable Segment LCD */
#define PinServoY_LCD_EN                 (* (reg8 *) PinServoY__LCD_EN)
/* Slew Rate Control */
#define PinServoY_SLW                    (* (reg8 *) PinServoY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PinServoY_PRTDSI__CAPS_SEL       (* (reg8 *) PinServoY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PinServoY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PinServoY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PinServoY_PRTDSI__OE_SEL0        (* (reg8 *) PinServoY__PRTDSI__OE_SEL0) 
#define PinServoY_PRTDSI__OE_SEL1        (* (reg8 *) PinServoY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PinServoY_PRTDSI__OUT_SEL0       (* (reg8 *) PinServoY__PRTDSI__OUT_SEL0) 
#define PinServoY_PRTDSI__OUT_SEL1       (* (reg8 *) PinServoY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PinServoY_PRTDSI__SYNC_OUT       (* (reg8 *) PinServoY__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PinServoY__SIO_CFG)
    #define PinServoY_SIO_HYST_EN        (* (reg8 *) PinServoY__SIO_HYST_EN)
    #define PinServoY_SIO_REG_HIFREQ     (* (reg8 *) PinServoY__SIO_REG_HIFREQ)
    #define PinServoY_SIO_CFG            (* (reg8 *) PinServoY__SIO_CFG)
    #define PinServoY_SIO_DIFF           (* (reg8 *) PinServoY__SIO_DIFF)
#endif /* (PinServoY__SIO_CFG) */

/* Interrupt Registers */
#if defined(PinServoY__INTSTAT)
    #define PinServoY_INTSTAT            (* (reg8 *) PinServoY__INTSTAT)
    #define PinServoY_SNAP               (* (reg8 *) PinServoY__SNAP)
    
	#define PinServoY_0_INTTYPE_REG 		(* (reg8 *) PinServoY__0__INTTYPE)
#endif /* (PinServoY__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PinServoY_H */


/* [] END OF FILE */
