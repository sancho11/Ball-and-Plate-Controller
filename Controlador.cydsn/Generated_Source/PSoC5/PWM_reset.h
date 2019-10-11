/*******************************************************************************
* File Name: PWM_reset.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_PWM_reset_H) /* CY_CONTROL_REG_PWM_reset_H */
#define CY_CONTROL_REG_PWM_reset_H

#include "cyfitter.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} PWM_reset_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    PWM_reset_Write(uint8 control) ;
uint8   PWM_reset_Read(void) ;

void PWM_reset_SaveConfig(void) ;
void PWM_reset_RestoreConfig(void) ;
void PWM_reset_Sleep(void) ; 
void PWM_reset_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define PWM_reset_Control        (* (reg8 *) PWM_reset_Sync_ctrl_reg__CONTROL_REG )
#define PWM_reset_Control_PTR    (  (reg8 *) PWM_reset_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_PWM_reset_H */


/* [] END OF FILE */
