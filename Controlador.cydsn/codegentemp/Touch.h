/*******************************************************************************
* File Name: Touch.h
* Version 2.0
*
* Description:
*  This file provides the constants and parameter values for the ResistiveTouch
*  component.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_RESISTIVE_TOUCH_Touch_H)
#define CY_RESISTIVE_TOUCH_Touch_H

#include "cytypes.h"
#include "Touch_ADC.h"
#include "Touch_AMux.h"


/***************************************
*        Function Prototypes
****************************************/

void Touch_Start(void) ;
void Touch_Stop(void) ;
void Touch_Init(void) ; 
void Touch_Enable(void) ;
void Touch_ActivateX(void) ;
void Touch_ActivateY(void);
int16 Touch_Measure(void) ;
uint8 Touch_TouchDetect(void) ;

void Touch_SaveConfig(void) ;
void Touch_RestoreConfig(void) ;
void Touch_Sleep(void) ; 
void Touch_Wakeup(void) ; 

/* Macros for emWinGraphics Library */
#define CYTOUCH_START()         Touch_Start() 
#define CYTOUCH_STOP()          Touch_Stop()
#define CYTOUCH_MEASURE()       Touch_Measure()
#define CYTOUCH_ACTIVATE_X()    Touch_ActivateX()
#define CYTOUCH_ACTIVATE_Y()    Touch_ActivateY()
#define CYTOUCH_TOUCHED()       Touch_TouchDetect()


/***************************************
*   Variable with external linkage
***************************************/

extern uint8 Touch_initVar;


/***************************************
*       Constants
***************************************/

/* AMUX channel definitions */
#define Touch_AMUX_XP_CHAN   (0)
#define Touch_AMUX_YP_CHAN   (1)
#define Touch_AMUX_NO_CHAN   (-1)

/* The screen is touched if the measured value is lower than the specified
* threshold.
*/
#define Touch_TOUCH_THRESHOLD        (0x778)


#endif /* CY_RESIST_TOUCH_Touch_H */


/* [] END OF FILE */
