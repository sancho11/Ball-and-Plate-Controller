/*******************************************************************************
* File Name: Touch_ADC_AMux.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_Touch_ADC_AMux_H)
#define CY_AMUX_Touch_ADC_AMux_H

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
*        Function Prototypes
***************************************/

void Touch_ADC_AMux_Start(void) ;
#define Touch_ADC_AMux_Init() Touch_ADC_AMux_Start()
void Touch_ADC_AMux_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void Touch_ADC_AMux_Stop(void); */
/* void Touch_ADC_AMux_Select(uint8 channel); */
/* void Touch_ADC_AMux_Connect(uint8 channel); */
/* void Touch_ADC_AMux_Disconnect(uint8 channel); */
/* void Touch_ADC_AMux_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define Touch_ADC_AMux_CHANNELS  2u
#define Touch_ADC_AMux_MUXTYPE   1
#define Touch_ADC_AMux_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define Touch_ADC_AMux_NULL_CHANNEL 0xFFu
#define Touch_ADC_AMux_MUX_SINGLE   1
#define Touch_ADC_AMux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if Touch_ADC_AMux_MUXTYPE == Touch_ADC_AMux_MUX_SINGLE
# if !Touch_ADC_AMux_ATMOSTONE
#  define Touch_ADC_AMux_Connect(channel) Touch_ADC_AMux_Set(channel)
# endif
# define Touch_ADC_AMux_Disconnect(channel) Touch_ADC_AMux_Unset(channel)
#else
# if !Touch_ADC_AMux_ATMOSTONE
void Touch_ADC_AMux_Connect(uint8 channel) ;
# endif
void Touch_ADC_AMux_Disconnect(uint8 channel) ;
#endif

#if Touch_ADC_AMux_ATMOSTONE
# define Touch_ADC_AMux_Stop() Touch_ADC_AMux_DisconnectAll()
# define Touch_ADC_AMux_Select(channel) Touch_ADC_AMux_FastSelect(channel)
void Touch_ADC_AMux_DisconnectAll(void) ;
#else
# define Touch_ADC_AMux_Stop() Touch_ADC_AMux_Start()
void Touch_ADC_AMux_Select(uint8 channel) ;
# define Touch_ADC_AMux_DisconnectAll() Touch_ADC_AMux_Start()
#endif

#endif /* CY_AMUX_Touch_ADC_AMux_H */


/* [] END OF FILE */
