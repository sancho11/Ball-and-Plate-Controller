/*******************************************************************************
* File Name: Touch_AMux.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the AMuxSeq.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUXSEQ_Touch_AMux_H)
#define CY_AMUXSEQ_Touch_AMux_H

#include "cyfitter.h"
#include "cyfitter_cfg.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))    
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif /* ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define Touch_AMux_MUX_SINGLE 1
#define Touch_AMux_MUX_DIFF   2
#define Touch_AMux_MUXTYPE    1


/***************************************
*        Function Prototypes
***************************************/

void Touch_AMux_Start(void);
void Touch_AMux_Init(void);
void Touch_AMux_Stop(void);
#if (Touch_AMux_MUXTYPE == Touch_AMux_MUX_DIFF)
void Touch_AMux_Next(void);
void Touch_AMux_DisconnectAll(void);
#else
/* The Next and DisconnectAll functions are declared in cyfitter_cfg.h. */
/* void Touch_AMux_Next(void); */
/* void Touch_AMux_DisconnectAll(void); */
#endif
int8 Touch_AMux_GetChannel(void);


/***************************************
*           Global Variables
***************************************/

extern uint8 Touch_AMux_initVar;


/***************************************
*         Parameter Constants
***************************************/
#define Touch_AMux_CHANNELS 2


#endif /* CY_AMUXSEQ_Touch_AMux_H */


/* [] END OF FILE */
