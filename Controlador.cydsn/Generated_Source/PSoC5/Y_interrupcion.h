/*******************************************************************************
* File Name: Y_interrupcion.h
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
#if !defined(CY_ISR_Y_interrupcion_H)
#define CY_ISR_Y_interrupcion_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Y_interrupcion_Start(void);
void Y_interrupcion_StartEx(cyisraddress address);
void Y_interrupcion_Stop(void);

CY_ISR_PROTO(Y_interrupcion_Interrupt);

void Y_interrupcion_SetVector(cyisraddress address);
cyisraddress Y_interrupcion_GetVector(void);

void Y_interrupcion_SetPriority(uint8 priority);
uint8 Y_interrupcion_GetPriority(void);

void Y_interrupcion_Enable(void);
uint8 Y_interrupcion_GetState(void);
void Y_interrupcion_Disable(void);

void Y_interrupcion_SetPending(void);
void Y_interrupcion_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Y_interrupcion ISR. */
#define Y_interrupcion_INTC_VECTOR            ((reg32 *) Y_interrupcion__INTC_VECT)

/* Address of the Y_interrupcion ISR priority. */
#define Y_interrupcion_INTC_PRIOR             ((reg8 *) Y_interrupcion__INTC_PRIOR_REG)

/* Priority of the Y_interrupcion interrupt. */
#define Y_interrupcion_INTC_PRIOR_NUMBER      Y_interrupcion__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Y_interrupcion interrupt. */
#define Y_interrupcion_INTC_SET_EN            ((reg32 *) Y_interrupcion__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Y_interrupcion interrupt. */
#define Y_interrupcion_INTC_CLR_EN            ((reg32 *) Y_interrupcion__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Y_interrupcion interrupt state to pending. */
#define Y_interrupcion_INTC_SET_PD            ((reg32 *) Y_interrupcion__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Y_interrupcion interrupt. */
#define Y_interrupcion_INTC_CLR_PD            ((reg32 *) Y_interrupcion__INTC_CLR_PD_REG)


#endif /* CY_ISR_Y_interrupcion_H */


/* [] END OF FILE */
