/*******************************************************************************
* File Name: Touch_AMux.c
* Version 1.80
*
*  Description:
*    This file contains functions for the AMuxSeq.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "Touch_AMux.h"

uint8 Touch_AMux_initVar = 0u;


/*******************************************************************************
* Function Name: Touch_AMux_Start
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Touch_AMux_Start(void)
{
    Touch_AMux_DisconnectAll();
    Touch_AMux_initVar = 1u;
}


/*******************************************************************************
* Function Name: Touch_AMux_Init
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Touch_AMux_Init(void)
{
    Touch_AMux_DisconnectAll();
}


/*******************************************************************************
* Function Name: Touch_AMux_Stop
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Touch_AMux_Stop(void)
{
    Touch_AMux_DisconnectAll();
}

#if (Touch_AMux_MUXTYPE == Touch_AMux_MUX_DIFF)

/*******************************************************************************
* Function Name: Touch_AMux_Next
********************************************************************************
* Summary:
*  Disconnects the previous channel and connects the next one in the sequence.
*  When Next is called for the first time after Init, Start, Enable, Stop, or
*  DisconnectAll, it connects channel 0.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Touch_AMux_Next(void)
{
    Touch_AMux_CYAMUXSIDE_A_Next();
    Touch_AMux_CYAMUXSIDE_B_Next();
}


/*******************************************************************************
* Function Name: Touch_AMux_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels. The next time Next is called, channel
*  0 will be connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Touch_AMux_DisconnectAll(void)
{
    Touch_AMux_CYAMUXSIDE_A_DisconnectAll();
    Touch_AMux_CYAMUXSIDE_B_DisconnectAll();
}


/*******************************************************************************
* Function Name: Touch_AMux_GetChannel
********************************************************************************
* Summary:
*  The currently connected channel is retuned. If no channel is connected
*  returns -1.
*
* Parameters:
*  void
*
* Return:
*  The current channel or -1.
*
*******************************************************************************/
int8 Touch_AMux_GetChannel(void)
{
    return Touch_AMux_CYAMUXSIDE_A_curChannel;
}

#else

/*******************************************************************************
* Function Name: Touch_AMux_GetChannel
********************************************************************************
* Summary:
*  The currently connected channel is retuned. If no channel is connected
*  returns -1.
*
* Parameters:
*  void
*
* Return:
*  The current channel or -1.
*
*******************************************************************************/
int8 Touch_AMux_GetChannel(void)
{
    return Touch_AMux_curChannel;
}

#endif


/* [] END OF FILE */
