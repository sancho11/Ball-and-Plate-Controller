/*******************************************************************************
* File Name: ClockServoControl.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_ClockServoControl_H)
#define CY_CLOCK_ClockServoControl_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void ClockServoControl_Start(void) ;
void ClockServoControl_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void ClockServoControl_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void ClockServoControl_StandbyPower(uint8 state) ;
void ClockServoControl_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 ClockServoControl_GetDividerRegister(void) ;
void ClockServoControl_SetModeRegister(uint8 modeBitMask) ;
void ClockServoControl_ClearModeRegister(uint8 modeBitMask) ;
uint8 ClockServoControl_GetModeRegister(void) ;
void ClockServoControl_SetSourceRegister(uint8 clkSource) ;
uint8 ClockServoControl_GetSourceRegister(void) ;
#if defined(ClockServoControl__CFG3)
void ClockServoControl_SetPhaseRegister(uint8 clkPhase) ;
uint8 ClockServoControl_GetPhaseRegister(void) ;
#endif /* defined(ClockServoControl__CFG3) */

#define ClockServoControl_Enable()                       ClockServoControl_Start()
#define ClockServoControl_Disable()                      ClockServoControl_Stop()
#define ClockServoControl_SetDivider(clkDivider)         ClockServoControl_SetDividerRegister(clkDivider, 1u)
#define ClockServoControl_SetDividerValue(clkDivider)    ClockServoControl_SetDividerRegister((clkDivider) - 1u, 1u)
#define ClockServoControl_SetMode(clkMode)               ClockServoControl_SetModeRegister(clkMode)
#define ClockServoControl_SetSource(clkSource)           ClockServoControl_SetSourceRegister(clkSource)
#if defined(ClockServoControl__CFG3)
#define ClockServoControl_SetPhase(clkPhase)             ClockServoControl_SetPhaseRegister(clkPhase)
#define ClockServoControl_SetPhaseValue(clkPhase)        ClockServoControl_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(ClockServoControl__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define ClockServoControl_CLKEN              (* (reg8 *) ClockServoControl__PM_ACT_CFG)
#define ClockServoControl_CLKEN_PTR          ((reg8 *) ClockServoControl__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define ClockServoControl_CLKSTBY            (* (reg8 *) ClockServoControl__PM_STBY_CFG)
#define ClockServoControl_CLKSTBY_PTR        ((reg8 *) ClockServoControl__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define ClockServoControl_DIV_LSB            (* (reg8 *) ClockServoControl__CFG0)
#define ClockServoControl_DIV_LSB_PTR        ((reg8 *) ClockServoControl__CFG0)
#define ClockServoControl_DIV_PTR            ((reg16 *) ClockServoControl__CFG0)

/* Clock MSB divider configuration register. */
#define ClockServoControl_DIV_MSB            (* (reg8 *) ClockServoControl__CFG1)
#define ClockServoControl_DIV_MSB_PTR        ((reg8 *) ClockServoControl__CFG1)

/* Mode and source configuration register */
#define ClockServoControl_MOD_SRC            (* (reg8 *) ClockServoControl__CFG2)
#define ClockServoControl_MOD_SRC_PTR        ((reg8 *) ClockServoControl__CFG2)

#if defined(ClockServoControl__CFG3)
/* Analog clock phase configuration register */
#define ClockServoControl_PHASE              (* (reg8 *) ClockServoControl__CFG3)
#define ClockServoControl_PHASE_PTR          ((reg8 *) ClockServoControl__CFG3)
#endif /* defined(ClockServoControl__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define ClockServoControl_CLKEN_MASK         ClockServoControl__PM_ACT_MSK
#define ClockServoControl_CLKSTBY_MASK       ClockServoControl__PM_STBY_MSK

/* CFG2 field masks */
#define ClockServoControl_SRC_SEL_MSK        ClockServoControl__CFG2_SRC_SEL_MASK
#define ClockServoControl_MODE_MASK          (~(ClockServoControl_SRC_SEL_MSK))

#if defined(ClockServoControl__CFG3)
/* CFG3 phase mask */
#define ClockServoControl_PHASE_MASK         ClockServoControl__CFG3_PHASE_DLY_MASK
#endif /* defined(ClockServoControl__CFG3) */

#endif /* CY_CLOCK_ClockServoControl_H */


/* [] END OF FILE */
