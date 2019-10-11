/*******************************************************************************
* File Name: X_interrupcion.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_X_interrupcion_H)
#define CY_ISR_X_interrupcion_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void X_interrupcion_Start(void);
void X_interrupcion_StartEx(cyisraddress address);
void X_interrupcion_Stop(void);

CY_ISR_PROTO(X_interrupcion_Interrupt);

void X_interrupcion_SetVector(cyisraddress address);
cyisraddress X_interrupcion_GetVector(void);

void X_interrupcion_SetPriority(uint8 priority);
uint8 X_interrupcion_GetPriority(void);

void X_interrupcion_Enable(void);
uint8 X_interrupcion_GetState(void);
void X_interrupcion_Disable(void);

void X_interrupcion_SetPending(void);
void X_interrupcion_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the X_interrupcion ISR. */
#define X_interrupcion_INTC_VECTOR            ((reg32 *) X_interrupcion__INTC_VECT)

/* Address of the X_interrupcion ISR priority. */
#define X_interrupcion_INTC_PRIOR             ((reg8 *) X_interrupcion__INTC_PRIOR_REG)

/* Priority of the X_interrupcion interrupt. */
#define X_interrupcion_INTC_PRIOR_NUMBER      X_interrupcion__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable X_interrupcion interrupt. */
#define X_interrupcion_INTC_SET_EN            ((reg32 *) X_interrupcion__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the X_interrupcion interrupt. */
#define X_interrupcion_INTC_CLR_EN            ((reg32 *) X_interrupcion__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the X_interrupcion interrupt state to pending. */
#define X_interrupcion_INTC_SET_PD            ((reg32 *) X_interrupcion__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the X_interrupcion interrupt. */
#define X_interrupcion_INTC_CLR_PD            ((reg32 *) X_interrupcion__INTC_CLR_PD_REG)


#endif /* CY_ISR_X_interrupcion_H */


/* [] END OF FILE */
