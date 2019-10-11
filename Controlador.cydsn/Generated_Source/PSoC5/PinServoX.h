/*******************************************************************************
* File Name: PinServoX.h  
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

#if !defined(CY_PINS_PinServoX_H) /* Pins PinServoX_H */
#define CY_PINS_PinServoX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PinServoX_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PinServoX__PORT == 15 && ((PinServoX__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PinServoX_Write(uint8 value);
void    PinServoX_SetDriveMode(uint8 mode);
uint8   PinServoX_ReadDataReg(void);
uint8   PinServoX_Read(void);
void    PinServoX_SetInterruptMode(uint16 position, uint16 mode);
uint8   PinServoX_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PinServoX_SetDriveMode() function.
     *  @{
     */
        #define PinServoX_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PinServoX_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PinServoX_DM_RES_UP          PIN_DM_RES_UP
        #define PinServoX_DM_RES_DWN         PIN_DM_RES_DWN
        #define PinServoX_DM_OD_LO           PIN_DM_OD_LO
        #define PinServoX_DM_OD_HI           PIN_DM_OD_HI
        #define PinServoX_DM_STRONG          PIN_DM_STRONG
        #define PinServoX_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PinServoX_MASK               PinServoX__MASK
#define PinServoX_SHIFT              PinServoX__SHIFT
#define PinServoX_WIDTH              1u

/* Interrupt constants */
#if defined(PinServoX__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PinServoX_SetInterruptMode() function.
     *  @{
     */
        #define PinServoX_INTR_NONE      (uint16)(0x0000u)
        #define PinServoX_INTR_RISING    (uint16)(0x0001u)
        #define PinServoX_INTR_FALLING   (uint16)(0x0002u)
        #define PinServoX_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PinServoX_INTR_MASK      (0x01u) 
#endif /* (PinServoX__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PinServoX_PS                     (* (reg8 *) PinServoX__PS)
/* Data Register */
#define PinServoX_DR                     (* (reg8 *) PinServoX__DR)
/* Port Number */
#define PinServoX_PRT_NUM                (* (reg8 *) PinServoX__PRT) 
/* Connect to Analog Globals */                                                  
#define PinServoX_AG                     (* (reg8 *) PinServoX__AG)                       
/* Analog MUX bux enable */
#define PinServoX_AMUX                   (* (reg8 *) PinServoX__AMUX) 
/* Bidirectional Enable */                                                        
#define PinServoX_BIE                    (* (reg8 *) PinServoX__BIE)
/* Bit-mask for Aliased Register Access */
#define PinServoX_BIT_MASK               (* (reg8 *) PinServoX__BIT_MASK)
/* Bypass Enable */
#define PinServoX_BYP                    (* (reg8 *) PinServoX__BYP)
/* Port wide control signals */                                                   
#define PinServoX_CTL                    (* (reg8 *) PinServoX__CTL)
/* Drive Modes */
#define PinServoX_DM0                    (* (reg8 *) PinServoX__DM0) 
#define PinServoX_DM1                    (* (reg8 *) PinServoX__DM1)
#define PinServoX_DM2                    (* (reg8 *) PinServoX__DM2) 
/* Input Buffer Disable Override */
#define PinServoX_INP_DIS                (* (reg8 *) PinServoX__INP_DIS)
/* LCD Common or Segment Drive */
#define PinServoX_LCD_COM_SEG            (* (reg8 *) PinServoX__LCD_COM_SEG)
/* Enable Segment LCD */
#define PinServoX_LCD_EN                 (* (reg8 *) PinServoX__LCD_EN)
/* Slew Rate Control */
#define PinServoX_SLW                    (* (reg8 *) PinServoX__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PinServoX_PRTDSI__CAPS_SEL       (* (reg8 *) PinServoX__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PinServoX_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PinServoX__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PinServoX_PRTDSI__OE_SEL0        (* (reg8 *) PinServoX__PRTDSI__OE_SEL0) 
#define PinServoX_PRTDSI__OE_SEL1        (* (reg8 *) PinServoX__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PinServoX_PRTDSI__OUT_SEL0       (* (reg8 *) PinServoX__PRTDSI__OUT_SEL0) 
#define PinServoX_PRTDSI__OUT_SEL1       (* (reg8 *) PinServoX__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PinServoX_PRTDSI__SYNC_OUT       (* (reg8 *) PinServoX__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PinServoX__SIO_CFG)
    #define PinServoX_SIO_HYST_EN        (* (reg8 *) PinServoX__SIO_HYST_EN)
    #define PinServoX_SIO_REG_HIFREQ     (* (reg8 *) PinServoX__SIO_REG_HIFREQ)
    #define PinServoX_SIO_CFG            (* (reg8 *) PinServoX__SIO_CFG)
    #define PinServoX_SIO_DIFF           (* (reg8 *) PinServoX__SIO_DIFF)
#endif /* (PinServoX__SIO_CFG) */

/* Interrupt Registers */
#if defined(PinServoX__INTSTAT)
    #define PinServoX_INTSTAT            (* (reg8 *) PinServoX__INTSTAT)
    #define PinServoX_SNAP               (* (reg8 *) PinServoX__SNAP)
    
	#define PinServoX_0_INTTYPE_REG 		(* (reg8 *) PinServoX__0__INTTYPE)
#endif /* (PinServoX__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PinServoX_H */


/* [] END OF FILE */
