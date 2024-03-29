/*******************************************************************************
* File Name: cyfittergnu.inc
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* LCD */
.set LCD_LCDPort__0__INTTYPE, CYREG_PICU2_INTTYPE0
.set LCD_LCDPort__0__MASK, 0x01
.set LCD_LCDPort__0__PC, CYREG_PRT2_PC0
.set LCD_LCDPort__0__PORT, 2
.set LCD_LCDPort__0__SHIFT, 0
.set LCD_LCDPort__1__INTTYPE, CYREG_PICU2_INTTYPE1
.set LCD_LCDPort__1__MASK, 0x02
.set LCD_LCDPort__1__PC, CYREG_PRT2_PC1
.set LCD_LCDPort__1__PORT, 2
.set LCD_LCDPort__1__SHIFT, 1
.set LCD_LCDPort__2__INTTYPE, CYREG_PICU2_INTTYPE2
.set LCD_LCDPort__2__MASK, 0x04
.set LCD_LCDPort__2__PC, CYREG_PRT2_PC2
.set LCD_LCDPort__2__PORT, 2
.set LCD_LCDPort__2__SHIFT, 2
.set LCD_LCDPort__3__INTTYPE, CYREG_PICU2_INTTYPE3
.set LCD_LCDPort__3__MASK, 0x08
.set LCD_LCDPort__3__PC, CYREG_PRT2_PC3
.set LCD_LCDPort__3__PORT, 2
.set LCD_LCDPort__3__SHIFT, 3
.set LCD_LCDPort__4__INTTYPE, CYREG_PICU2_INTTYPE4
.set LCD_LCDPort__4__MASK, 0x10
.set LCD_LCDPort__4__PC, CYREG_PRT2_PC4
.set LCD_LCDPort__4__PORT, 2
.set LCD_LCDPort__4__SHIFT, 4
.set LCD_LCDPort__5__INTTYPE, CYREG_PICU2_INTTYPE5
.set LCD_LCDPort__5__MASK, 0x20
.set LCD_LCDPort__5__PC, CYREG_PRT2_PC5
.set LCD_LCDPort__5__PORT, 2
.set LCD_LCDPort__5__SHIFT, 5
.set LCD_LCDPort__6__INTTYPE, CYREG_PICU2_INTTYPE6
.set LCD_LCDPort__6__MASK, 0x40
.set LCD_LCDPort__6__PC, CYREG_PRT2_PC6
.set LCD_LCDPort__6__PORT, 2
.set LCD_LCDPort__6__SHIFT, 6
.set LCD_LCDPort__AG, CYREG_PRT2_AG
.set LCD_LCDPort__AMUX, CYREG_PRT2_AMUX
.set LCD_LCDPort__BIE, CYREG_PRT2_BIE
.set LCD_LCDPort__BIT_MASK, CYREG_PRT2_BIT_MASK
.set LCD_LCDPort__BYP, CYREG_PRT2_BYP
.set LCD_LCDPort__CTL, CYREG_PRT2_CTL
.set LCD_LCDPort__DM0, CYREG_PRT2_DM0
.set LCD_LCDPort__DM1, CYREG_PRT2_DM1
.set LCD_LCDPort__DM2, CYREG_PRT2_DM2
.set LCD_LCDPort__DR, CYREG_PRT2_DR
.set LCD_LCDPort__INP_DIS, CYREG_PRT2_INP_DIS
.set LCD_LCDPort__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU2_BASE
.set LCD_LCDPort__LCD_COM_SEG, CYREG_PRT2_LCD_COM_SEG
.set LCD_LCDPort__LCD_EN, CYREG_PRT2_LCD_EN
.set LCD_LCDPort__MASK, 0x7F
.set LCD_LCDPort__PORT, 2
.set LCD_LCDPort__PRT, CYREG_PRT2_PRT
.set LCD_LCDPort__PRTDSI__CAPS_SEL, CYREG_PRT2_CAPS_SEL
.set LCD_LCDPort__PRTDSI__DBL_SYNC_IN, CYREG_PRT2_DBL_SYNC_IN
.set LCD_LCDPort__PRTDSI__OE_SEL0, CYREG_PRT2_OE_SEL0
.set LCD_LCDPort__PRTDSI__OE_SEL1, CYREG_PRT2_OE_SEL1
.set LCD_LCDPort__PRTDSI__OUT_SEL0, CYREG_PRT2_OUT_SEL0
.set LCD_LCDPort__PRTDSI__OUT_SEL1, CYREG_PRT2_OUT_SEL1
.set LCD_LCDPort__PRTDSI__SYNC_OUT, CYREG_PRT2_SYNC_OUT
.set LCD_LCDPort__PS, CYREG_PRT2_PS
.set LCD_LCDPort__SHIFT, 0
.set LCD_LCDPort__SLW, CYREG_PRT2_SLW

/* PWM_X */
.set PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B0_UDB11_12_ACTL
.set PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG, CYREG_B0_UDB11_12_CTL
.set PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG, CYREG_B0_UDB11_12_CTL
.set PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG, CYREG_B0_UDB11_12_CTL
.set PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG, CYREG_B0_UDB11_12_CTL
.set PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG, CYREG_B0_UDB11_12_MSK
.set PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG, CYREG_B0_UDB11_12_MSK
.set PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG, CYREG_B0_UDB11_12_MSK
.set PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG, CYREG_B0_UDB11_12_MSK
.set PWM_X_PWMUDB_genblk1_ctrlreg__7__MASK, 0x80
.set PWM_X_PWMUDB_genblk1_ctrlreg__7__POS, 7
.set PWM_X_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG, CYREG_B0_UDB11_ACTL
.set PWM_X_PWMUDB_genblk1_ctrlreg__CONTROL_REG, CYREG_B0_UDB11_CTL
.set PWM_X_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG, CYREG_B0_UDB11_ST_CTL
.set PWM_X_PWMUDB_genblk1_ctrlreg__COUNT_REG, CYREG_B0_UDB11_CTL
.set PWM_X_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG, CYREG_B0_UDB11_ST_CTL
.set PWM_X_PWMUDB_genblk1_ctrlreg__MASK, 0x80
.set PWM_X_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG, CYREG_B0_UDB11_MSK_ACTL
.set PWM_X_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG, CYREG_B0_UDB11_MSK_ACTL
.set PWM_X_PWMUDB_genblk1_ctrlreg__PERIOD_REG, CYREG_B0_UDB11_MSK
.set PWM_X_PWMUDB_genblk8_stsreg__0__MASK, 0x01
.set PWM_X_PWMUDB_genblk8_stsreg__0__POS, 0
.set PWM_X_PWMUDB_genblk8_stsreg__1__MASK, 0x02
.set PWM_X_PWMUDB_genblk8_stsreg__1__POS, 1
.set PWM_X_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB11_12_ACTL
.set PWM_X_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG, CYREG_B0_UDB11_12_ST
.set PWM_X_PWMUDB_genblk8_stsreg__2__MASK, 0x04
.set PWM_X_PWMUDB_genblk8_stsreg__2__POS, 2
.set PWM_X_PWMUDB_genblk8_stsreg__3__MASK, 0x08
.set PWM_X_PWMUDB_genblk8_stsreg__3__POS, 3
.set PWM_X_PWMUDB_genblk8_stsreg__MASK, 0x0F
.set PWM_X_PWMUDB_genblk8_stsreg__MASK_REG, CYREG_B0_UDB11_MSK
.set PWM_X_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG, CYREG_B0_UDB11_MSK_ACTL
.set PWM_X_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG, CYREG_B0_UDB11_MSK_ACTL
.set PWM_X_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG, CYREG_B0_UDB11_ACTL
.set PWM_X_PWMUDB_genblk8_stsreg__STATUS_CNT_REG, CYREG_B0_UDB11_ST_CTL
.set PWM_X_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG, CYREG_B0_UDB11_ST_CTL
.set PWM_X_PWMUDB_genblk8_stsreg__STATUS_REG, CYREG_B0_UDB11_ST
.set PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG, CYREG_B0_UDB10_11_A0
.set PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG, CYREG_B0_UDB10_11_A1
.set PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG, CYREG_B0_UDB10_11_D0
.set PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG, CYREG_B0_UDB10_11_D1
.set PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB10_11_ACTL
.set PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG, CYREG_B0_UDB10_11_F0
.set PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG, CYREG_B0_UDB10_11_F1
.set PWM_X_PWMUDB_sP16_pwmdp_u0__A0_A1_REG, CYREG_B0_UDB10_A0_A1
.set PWM_X_PWMUDB_sP16_pwmdp_u0__A0_REG, CYREG_B0_UDB10_A0
.set PWM_X_PWMUDB_sP16_pwmdp_u0__A1_REG, CYREG_B0_UDB10_A1
.set PWM_X_PWMUDB_sP16_pwmdp_u0__D0_D1_REG, CYREG_B0_UDB10_D0_D1
.set PWM_X_PWMUDB_sP16_pwmdp_u0__D0_REG, CYREG_B0_UDB10_D0
.set PWM_X_PWMUDB_sP16_pwmdp_u0__D1_REG, CYREG_B0_UDB10_D1
.set PWM_X_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG, CYREG_B0_UDB10_ACTL
.set PWM_X_PWMUDB_sP16_pwmdp_u0__F0_F1_REG, CYREG_B0_UDB10_F0_F1
.set PWM_X_PWMUDB_sP16_pwmdp_u0__F0_REG, CYREG_B0_UDB10_F0
.set PWM_X_PWMUDB_sP16_pwmdp_u0__F1_REG, CYREG_B0_UDB10_F1
.set PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG, CYREG_B0_UDB11_12_A0
.set PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG, CYREG_B0_UDB11_12_A1
.set PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG, CYREG_B0_UDB11_12_D0
.set PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG, CYREG_B0_UDB11_12_D1
.set PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB11_12_ACTL
.set PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG, CYREG_B0_UDB11_12_F0
.set PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG, CYREG_B0_UDB11_12_F1
.set PWM_X_PWMUDB_sP16_pwmdp_u1__A0_A1_REG, CYREG_B0_UDB11_A0_A1
.set PWM_X_PWMUDB_sP16_pwmdp_u1__A0_REG, CYREG_B0_UDB11_A0
.set PWM_X_PWMUDB_sP16_pwmdp_u1__A1_REG, CYREG_B0_UDB11_A1
.set PWM_X_PWMUDB_sP16_pwmdp_u1__D0_D1_REG, CYREG_B0_UDB11_D0_D1
.set PWM_X_PWMUDB_sP16_pwmdp_u1__D0_REG, CYREG_B0_UDB11_D0
.set PWM_X_PWMUDB_sP16_pwmdp_u1__D1_REG, CYREG_B0_UDB11_D1
.set PWM_X_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG, CYREG_B0_UDB11_ACTL
.set PWM_X_PWMUDB_sP16_pwmdp_u1__F0_F1_REG, CYREG_B0_UDB11_F0_F1
.set PWM_X_PWMUDB_sP16_pwmdp_u1__F0_REG, CYREG_B0_UDB11_F0
.set PWM_X_PWMUDB_sP16_pwmdp_u1__F1_REG, CYREG_B0_UDB11_F1
.set PWM_X_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG, CYREG_B0_UDB11_MSK_ACTL
.set PWM_X_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG, CYREG_B0_UDB11_MSK_ACTL

/* PWM_Y */
.set PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B0_UDB13_14_ACTL
.set PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG, CYREG_B0_UDB13_14_CTL
.set PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG, CYREG_B0_UDB13_14_CTL
.set PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG, CYREG_B0_UDB13_14_CTL
.set PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG, CYREG_B0_UDB13_14_CTL
.set PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG, CYREG_B0_UDB13_14_MSK
.set PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG, CYREG_B0_UDB13_14_MSK
.set PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG, CYREG_B0_UDB13_14_MSK
.set PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG, CYREG_B0_UDB13_14_MSK
.set PWM_Y_PWMUDB_genblk1_ctrlreg__7__MASK, 0x80
.set PWM_Y_PWMUDB_genblk1_ctrlreg__7__POS, 7
.set PWM_Y_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG, CYREG_B0_UDB13_ACTL
.set PWM_Y_PWMUDB_genblk1_ctrlreg__CONTROL_REG, CYREG_B0_UDB13_CTL
.set PWM_Y_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG, CYREG_B0_UDB13_ST_CTL
.set PWM_Y_PWMUDB_genblk1_ctrlreg__COUNT_REG, CYREG_B0_UDB13_CTL
.set PWM_Y_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG, CYREG_B0_UDB13_ST_CTL
.set PWM_Y_PWMUDB_genblk1_ctrlreg__MASK, 0x80
.set PWM_Y_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG, CYREG_B0_UDB13_MSK_ACTL
.set PWM_Y_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG, CYREG_B0_UDB13_MSK_ACTL
.set PWM_Y_PWMUDB_genblk1_ctrlreg__PERIOD_REG, CYREG_B0_UDB13_MSK
.set PWM_Y_PWMUDB_genblk8_stsreg__0__MASK, 0x01
.set PWM_Y_PWMUDB_genblk8_stsreg__0__POS, 0
.set PWM_Y_PWMUDB_genblk8_stsreg__1__MASK, 0x02
.set PWM_Y_PWMUDB_genblk8_stsreg__1__POS, 1
.set PWM_Y_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB13_14_ACTL
.set PWM_Y_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG, CYREG_B0_UDB13_14_ST
.set PWM_Y_PWMUDB_genblk8_stsreg__2__MASK, 0x04
.set PWM_Y_PWMUDB_genblk8_stsreg__2__POS, 2
.set PWM_Y_PWMUDB_genblk8_stsreg__3__MASK, 0x08
.set PWM_Y_PWMUDB_genblk8_stsreg__3__POS, 3
.set PWM_Y_PWMUDB_genblk8_stsreg__MASK, 0x0F
.set PWM_Y_PWMUDB_genblk8_stsreg__MASK_REG, CYREG_B0_UDB13_MSK
.set PWM_Y_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG, CYREG_B0_UDB13_MSK_ACTL
.set PWM_Y_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG, CYREG_B0_UDB13_MSK_ACTL
.set PWM_Y_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG, CYREG_B0_UDB13_ACTL
.set PWM_Y_PWMUDB_genblk8_stsreg__STATUS_CNT_REG, CYREG_B0_UDB13_ST_CTL
.set PWM_Y_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG, CYREG_B0_UDB13_ST_CTL
.set PWM_Y_PWMUDB_genblk8_stsreg__STATUS_REG, CYREG_B0_UDB13_ST
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG, CYREG_B0_UDB12_13_A0
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG, CYREG_B0_UDB12_13_A1
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG, CYREG_B0_UDB12_13_D0
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG, CYREG_B0_UDB12_13_D1
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB12_13_ACTL
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG, CYREG_B0_UDB12_13_F0
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG, CYREG_B0_UDB12_13_F1
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__A0_A1_REG, CYREG_B0_UDB12_A0_A1
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__A0_REG, CYREG_B0_UDB12_A0
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__A1_REG, CYREG_B0_UDB12_A1
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__D0_D1_REG, CYREG_B0_UDB12_D0_D1
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__D0_REG, CYREG_B0_UDB12_D0
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__D1_REG, CYREG_B0_UDB12_D1
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG, CYREG_B0_UDB12_ACTL
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__F0_F1_REG, CYREG_B0_UDB12_F0_F1
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__F0_REG, CYREG_B0_UDB12_F0
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__F1_REG, CYREG_B0_UDB12_F1
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__MSK_DP_AUX_CTL_REG, CYREG_B0_UDB12_MSK_ACTL
.set PWM_Y_PWMUDB_sP16_pwmdp_u0__PER_DP_AUX_CTL_REG, CYREG_B0_UDB12_MSK_ACTL
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG, CYREG_B0_UDB13_14_A0
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG, CYREG_B0_UDB13_14_A1
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG, CYREG_B0_UDB13_14_D0
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG, CYREG_B0_UDB13_14_D1
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG, CYREG_B0_UDB13_14_ACTL
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG, CYREG_B0_UDB13_14_F0
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG, CYREG_B0_UDB13_14_F1
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__A0_A1_REG, CYREG_B0_UDB13_A0_A1
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__A0_REG, CYREG_B0_UDB13_A0
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__A1_REG, CYREG_B0_UDB13_A1
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__D0_D1_REG, CYREG_B0_UDB13_D0_D1
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__D0_REG, CYREG_B0_UDB13_D0
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__D1_REG, CYREG_B0_UDB13_D1
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG, CYREG_B0_UDB13_ACTL
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__F0_F1_REG, CYREG_B0_UDB13_F0_F1
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__F0_REG, CYREG_B0_UDB13_F0
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__F1_REG, CYREG_B0_UDB13_F1
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG, CYREG_B0_UDB13_MSK_ACTL
.set PWM_Y_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG, CYREG_B0_UDB13_MSK_ACTL

/* Touch */
.set Touch_ADC_DEC__COHER, CYREG_DEC_COHER
.set Touch_ADC_DEC__CR, CYREG_DEC_CR
.set Touch_ADC_DEC__DR1, CYREG_DEC_DR1
.set Touch_ADC_DEC__DR2, CYREG_DEC_DR2
.set Touch_ADC_DEC__DR2H, CYREG_DEC_DR2H
.set Touch_ADC_DEC__GCOR, CYREG_DEC_GCOR
.set Touch_ADC_DEC__GCORH, CYREG_DEC_GCORH
.set Touch_ADC_DEC__GVAL, CYREG_DEC_GVAL
.set Touch_ADC_DEC__OCOR, CYREG_DEC_OCOR
.set Touch_ADC_DEC__OCORH, CYREG_DEC_OCORH
.set Touch_ADC_DEC__OCORM, CYREG_DEC_OCORM
.set Touch_ADC_DEC__OUTSAMP, CYREG_DEC_OUTSAMP
.set Touch_ADC_DEC__OUTSAMPH, CYREG_DEC_OUTSAMPH
.set Touch_ADC_DEC__OUTSAMPM, CYREG_DEC_OUTSAMPM
.set Touch_ADC_DEC__OUTSAMPS, CYREG_DEC_OUTSAMPS
.set Touch_ADC_DEC__PM_ACT_CFG, CYREG_PM_ACT_CFG10
.set Touch_ADC_DEC__PM_ACT_MSK, 0x01
.set Touch_ADC_DEC__PM_STBY_CFG, CYREG_PM_STBY_CFG10
.set Touch_ADC_DEC__PM_STBY_MSK, 0x01
.set Touch_ADC_DEC__SHIFT1, CYREG_DEC_SHIFT1
.set Touch_ADC_DEC__SHIFT2, CYREG_DEC_SHIFT2
.set Touch_ADC_DEC__SR, CYREG_DEC_SR
.set Touch_ADC_DEC__TRIM__M1, CYREG_FLSHID_CUST_TABLES_DEC_M1
.set Touch_ADC_DEC__TRIM__M2, CYREG_FLSHID_CUST_TABLES_DEC_M2
.set Touch_ADC_DEC__TRIM__M3, CYREG_FLSHID_CUST_TABLES_DEC_M3
.set Touch_ADC_DEC__TRIM__M4, CYREG_FLSHID_CUST_TABLES_DEC_M4
.set Touch_ADC_DEC__TRIM__M5, CYREG_FLSHID_CUST_TABLES_DEC_M5
.set Touch_ADC_DEC__TRIM__M6, CYREG_FLSHID_CUST_TABLES_DEC_M6
.set Touch_ADC_DEC__TRIM__M7, CYREG_FLSHID_CUST_TABLES_DEC_M7
.set Touch_ADC_DEC__TRIM__M8, CYREG_FLSHID_CUST_TABLES_DEC_M8
.set Touch_ADC_DSM__BUF0, CYREG_DSM0_BUF0
.set Touch_ADC_DSM__BUF1, CYREG_DSM0_BUF1
.set Touch_ADC_DSM__BUF2, CYREG_DSM0_BUF2
.set Touch_ADC_DSM__BUF3, CYREG_DSM0_BUF3
.set Touch_ADC_DSM__CLK, CYREG_DSM0_CLK
.set Touch_ADC_DSM__CR0, CYREG_DSM0_CR0
.set Touch_ADC_DSM__CR1, CYREG_DSM0_CR1
.set Touch_ADC_DSM__CR10, CYREG_DSM0_CR10
.set Touch_ADC_DSM__CR11, CYREG_DSM0_CR11
.set Touch_ADC_DSM__CR12, CYREG_DSM0_CR12
.set Touch_ADC_DSM__CR13, CYREG_DSM0_CR13
.set Touch_ADC_DSM__CR14, CYREG_DSM0_CR14
.set Touch_ADC_DSM__CR15, CYREG_DSM0_CR15
.set Touch_ADC_DSM__CR16, CYREG_DSM0_CR16
.set Touch_ADC_DSM__CR17, CYREG_DSM0_CR17
.set Touch_ADC_DSM__CR2, CYREG_DSM0_CR2
.set Touch_ADC_DSM__CR3, CYREG_DSM0_CR3
.set Touch_ADC_DSM__CR4, CYREG_DSM0_CR4
.set Touch_ADC_DSM__CR5, CYREG_DSM0_CR5
.set Touch_ADC_DSM__CR6, CYREG_DSM0_CR6
.set Touch_ADC_DSM__CR7, CYREG_DSM0_CR7
.set Touch_ADC_DSM__CR8, CYREG_DSM0_CR8
.set Touch_ADC_DSM__CR9, CYREG_DSM0_CR9
.set Touch_ADC_DSM__DEM0, CYREG_DSM0_DEM0
.set Touch_ADC_DSM__DEM1, CYREG_DSM0_DEM1
.set Touch_ADC_DSM__MISC, CYREG_DSM0_MISC
.set Touch_ADC_DSM__OUT0, CYREG_DSM0_OUT0
.set Touch_ADC_DSM__OUT1, CYREG_DSM0_OUT1
.set Touch_ADC_DSM__REF0, CYREG_DSM0_REF0
.set Touch_ADC_DSM__REF1, CYREG_DSM0_REF1
.set Touch_ADC_DSM__REF2, CYREG_DSM0_REF2
.set Touch_ADC_DSM__REF3, CYREG_DSM0_REF3
.set Touch_ADC_DSM__RSVD1, CYREG_DSM0_RSVD1
.set Touch_ADC_DSM__SW0, CYREG_DSM0_SW0
.set Touch_ADC_DSM__SW2, CYREG_DSM0_SW2
.set Touch_ADC_DSM__SW3, CYREG_DSM0_SW3
.set Touch_ADC_DSM__SW4, CYREG_DSM0_SW4
.set Touch_ADC_DSM__SW6, CYREG_DSM0_SW6
.set Touch_ADC_DSM__TR0, CYREG_NPUMP_DSM_TR0
.set Touch_ADC_DSM__TST0, CYREG_DSM0_TST0
.set Touch_ADC_DSM__TST1, CYREG_DSM0_TST1
.set Touch_ADC_Ext_CP_Clk__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set Touch_ADC_Ext_CP_Clk__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set Touch_ADC_Ext_CP_Clk__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set Touch_ADC_Ext_CP_Clk__CFG2_SRC_SEL_MASK, 0x07
.set Touch_ADC_Ext_CP_Clk__INDEX, 0x00
.set Touch_ADC_Ext_CP_Clk__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set Touch_ADC_Ext_CP_Clk__PM_ACT_MSK, 0x01
.set Touch_ADC_Ext_CP_Clk__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set Touch_ADC_Ext_CP_Clk__PM_STBY_MSK, 0x01
.set Touch_ADC_IRQ__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set Touch_ADC_IRQ__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set Touch_ADC_IRQ__INTC_MASK, 0x20000000
.set Touch_ADC_IRQ__INTC_NUMBER, 29
.set Touch_ADC_IRQ__INTC_PRIOR_NUM, 7
.set Touch_ADC_IRQ__INTC_PRIOR_REG, CYREG_NVIC_PRI_29
.set Touch_ADC_IRQ__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set Touch_ADC_IRQ__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0
.set Touch_ADC_theACLK__CFG0, CYREG_CLKDIST_ACFG0_CFG0
.set Touch_ADC_theACLK__CFG1, CYREG_CLKDIST_ACFG0_CFG1
.set Touch_ADC_theACLK__CFG2, CYREG_CLKDIST_ACFG0_CFG2
.set Touch_ADC_theACLK__CFG2_SRC_SEL_MASK, 0x07
.set Touch_ADC_theACLK__CFG3, CYREG_CLKDIST_ACFG0_CFG3
.set Touch_ADC_theACLK__CFG3_PHASE_DLY_MASK, 0x0F
.set Touch_ADC_theACLK__INDEX, 0x00
.set Touch_ADC_theACLK__PM_ACT_CFG, CYREG_PM_ACT_CFG1
.set Touch_ADC_theACLK__PM_ACT_MSK, 0x01
.set Touch_ADC_theACLK__PM_STBY_CFG, CYREG_PM_STBY_CFG1
.set Touch_ADC_theACLK__PM_STBY_MSK, 0x01
.set Touch_xm__0__INTTYPE, CYREG_PICU4_INTTYPE2
.set Touch_xm__0__MASK, 0x04
.set Touch_xm__0__PC, CYREG_PRT4_PC2
.set Touch_xm__0__PORT, 4
.set Touch_xm__0__SHIFT, 2
.set Touch_xm__AG, CYREG_PRT4_AG
.set Touch_xm__AMUX, CYREG_PRT4_AMUX
.set Touch_xm__BIE, CYREG_PRT4_BIE
.set Touch_xm__BIT_MASK, CYREG_PRT4_BIT_MASK
.set Touch_xm__BYP, CYREG_PRT4_BYP
.set Touch_xm__CTL, CYREG_PRT4_CTL
.set Touch_xm__DM0, CYREG_PRT4_DM0
.set Touch_xm__DM1, CYREG_PRT4_DM1
.set Touch_xm__DM2, CYREG_PRT4_DM2
.set Touch_xm__DR, CYREG_PRT4_DR
.set Touch_xm__INP_DIS, CYREG_PRT4_INP_DIS
.set Touch_xm__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU4_BASE
.set Touch_xm__LCD_COM_SEG, CYREG_PRT4_LCD_COM_SEG
.set Touch_xm__LCD_EN, CYREG_PRT4_LCD_EN
.set Touch_xm__MASK, 0x04
.set Touch_xm__PORT, 4
.set Touch_xm__PRT, CYREG_PRT4_PRT
.set Touch_xm__PRTDSI__CAPS_SEL, CYREG_PRT4_CAPS_SEL
.set Touch_xm__PRTDSI__DBL_SYNC_IN, CYREG_PRT4_DBL_SYNC_IN
.set Touch_xm__PRTDSI__OE_SEL0, CYREG_PRT4_OE_SEL0
.set Touch_xm__PRTDSI__OE_SEL1, CYREG_PRT4_OE_SEL1
.set Touch_xm__PRTDSI__OUT_SEL0, CYREG_PRT4_OUT_SEL0
.set Touch_xm__PRTDSI__OUT_SEL1, CYREG_PRT4_OUT_SEL1
.set Touch_xm__PRTDSI__SYNC_OUT, CYREG_PRT4_SYNC_OUT
.set Touch_xm__PS, CYREG_PRT4_PS
.set Touch_xm__SHIFT, 2
.set Touch_xm__SLW, CYREG_PRT4_SLW
.set Touch_xp__0__INTTYPE, CYREG_PICU4_INTTYPE0
.set Touch_xp__0__MASK, 0x01
.set Touch_xp__0__PC, CYREG_PRT4_PC0
.set Touch_xp__0__PORT, 4
.set Touch_xp__0__SHIFT, 0
.set Touch_xp__AG, CYREG_PRT4_AG
.set Touch_xp__AMUX, CYREG_PRT4_AMUX
.set Touch_xp__BIE, CYREG_PRT4_BIE
.set Touch_xp__BIT_MASK, CYREG_PRT4_BIT_MASK
.set Touch_xp__BYP, CYREG_PRT4_BYP
.set Touch_xp__CTL, CYREG_PRT4_CTL
.set Touch_xp__DM0, CYREG_PRT4_DM0
.set Touch_xp__DM1, CYREG_PRT4_DM1
.set Touch_xp__DM2, CYREG_PRT4_DM2
.set Touch_xp__DR, CYREG_PRT4_DR
.set Touch_xp__INP_DIS, CYREG_PRT4_INP_DIS
.set Touch_xp__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU4_BASE
.set Touch_xp__LCD_COM_SEG, CYREG_PRT4_LCD_COM_SEG
.set Touch_xp__LCD_EN, CYREG_PRT4_LCD_EN
.set Touch_xp__MASK, 0x01
.set Touch_xp__PORT, 4
.set Touch_xp__PRT, CYREG_PRT4_PRT
.set Touch_xp__PRTDSI__CAPS_SEL, CYREG_PRT4_CAPS_SEL
.set Touch_xp__PRTDSI__DBL_SYNC_IN, CYREG_PRT4_DBL_SYNC_IN
.set Touch_xp__PRTDSI__OE_SEL0, CYREG_PRT4_OE_SEL0
.set Touch_xp__PRTDSI__OE_SEL1, CYREG_PRT4_OE_SEL1
.set Touch_xp__PRTDSI__OUT_SEL0, CYREG_PRT4_OUT_SEL0
.set Touch_xp__PRTDSI__OUT_SEL1, CYREG_PRT4_OUT_SEL1
.set Touch_xp__PRTDSI__SYNC_OUT, CYREG_PRT4_SYNC_OUT
.set Touch_xp__PS, CYREG_PRT4_PS
.set Touch_xp__SHIFT, 0
.set Touch_xp__SLW, CYREG_PRT4_SLW
.set Touch_ym__0__INTTYPE, CYREG_PICU4_INTTYPE1
.set Touch_ym__0__MASK, 0x02
.set Touch_ym__0__PC, CYREG_PRT4_PC1
.set Touch_ym__0__PORT, 4
.set Touch_ym__0__SHIFT, 1
.set Touch_ym__AG, CYREG_PRT4_AG
.set Touch_ym__AMUX, CYREG_PRT4_AMUX
.set Touch_ym__BIE, CYREG_PRT4_BIE
.set Touch_ym__BIT_MASK, CYREG_PRT4_BIT_MASK
.set Touch_ym__BYP, CYREG_PRT4_BYP
.set Touch_ym__CTL, CYREG_PRT4_CTL
.set Touch_ym__DM0, CYREG_PRT4_DM0
.set Touch_ym__DM1, CYREG_PRT4_DM1
.set Touch_ym__DM2, CYREG_PRT4_DM2
.set Touch_ym__DR, CYREG_PRT4_DR
.set Touch_ym__INP_DIS, CYREG_PRT4_INP_DIS
.set Touch_ym__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU4_BASE
.set Touch_ym__LCD_COM_SEG, CYREG_PRT4_LCD_COM_SEG
.set Touch_ym__LCD_EN, CYREG_PRT4_LCD_EN
.set Touch_ym__MASK, 0x02
.set Touch_ym__PORT, 4
.set Touch_ym__PRT, CYREG_PRT4_PRT
.set Touch_ym__PRTDSI__CAPS_SEL, CYREG_PRT4_CAPS_SEL
.set Touch_ym__PRTDSI__DBL_SYNC_IN, CYREG_PRT4_DBL_SYNC_IN
.set Touch_ym__PRTDSI__OE_SEL0, CYREG_PRT4_OE_SEL0
.set Touch_ym__PRTDSI__OE_SEL1, CYREG_PRT4_OE_SEL1
.set Touch_ym__PRTDSI__OUT_SEL0, CYREG_PRT4_OUT_SEL0
.set Touch_ym__PRTDSI__OUT_SEL1, CYREG_PRT4_OUT_SEL1
.set Touch_ym__PRTDSI__SYNC_OUT, CYREG_PRT4_SYNC_OUT
.set Touch_ym__PS, CYREG_PRT4_PS
.set Touch_ym__SHIFT, 1
.set Touch_ym__SLW, CYREG_PRT4_SLW
.set Touch_yp__0__INTTYPE, CYREG_PICU4_INTTYPE3
.set Touch_yp__0__MASK, 0x08
.set Touch_yp__0__PC, CYREG_PRT4_PC3
.set Touch_yp__0__PORT, 4
.set Touch_yp__0__SHIFT, 3
.set Touch_yp__AG, CYREG_PRT4_AG
.set Touch_yp__AMUX, CYREG_PRT4_AMUX
.set Touch_yp__BIE, CYREG_PRT4_BIE
.set Touch_yp__BIT_MASK, CYREG_PRT4_BIT_MASK
.set Touch_yp__BYP, CYREG_PRT4_BYP
.set Touch_yp__CTL, CYREG_PRT4_CTL
.set Touch_yp__DM0, CYREG_PRT4_DM0
.set Touch_yp__DM1, CYREG_PRT4_DM1
.set Touch_yp__DM2, CYREG_PRT4_DM2
.set Touch_yp__DR, CYREG_PRT4_DR
.set Touch_yp__INP_DIS, CYREG_PRT4_INP_DIS
.set Touch_yp__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU4_BASE
.set Touch_yp__LCD_COM_SEG, CYREG_PRT4_LCD_COM_SEG
.set Touch_yp__LCD_EN, CYREG_PRT4_LCD_EN
.set Touch_yp__MASK, 0x08
.set Touch_yp__PORT, 4
.set Touch_yp__PRT, CYREG_PRT4_PRT
.set Touch_yp__PRTDSI__CAPS_SEL, CYREG_PRT4_CAPS_SEL
.set Touch_yp__PRTDSI__DBL_SYNC_IN, CYREG_PRT4_DBL_SYNC_IN
.set Touch_yp__PRTDSI__OE_SEL0, CYREG_PRT4_OE_SEL0
.set Touch_yp__PRTDSI__OE_SEL1, CYREG_PRT4_OE_SEL1
.set Touch_yp__PRTDSI__OUT_SEL0, CYREG_PRT4_OUT_SEL0
.set Touch_yp__PRTDSI__OUT_SEL1, CYREG_PRT4_OUT_SEL1
.set Touch_yp__PRTDSI__SYNC_OUT, CYREG_PRT4_SYNC_OUT
.set Touch_yp__PS, CYREG_PRT4_PS
.set Touch_yp__SHIFT, 3
.set Touch_yp__SLW, CYREG_PRT4_SLW

/* PWM_reset */
.set PWM_reset_Sync_ctrl_reg__0__MASK, 0x01
.set PWM_reset_Sync_ctrl_reg__0__POS, 0
.set PWM_reset_Sync_ctrl_reg__1__MASK, 0x02
.set PWM_reset_Sync_ctrl_reg__1__POS, 1
.set PWM_reset_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B0_UDB12_13_ACTL
.set PWM_reset_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG, CYREG_B0_UDB12_13_CTL
.set PWM_reset_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG, CYREG_B0_UDB12_13_CTL
.set PWM_reset_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG, CYREG_B0_UDB12_13_CTL
.set PWM_reset_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG, CYREG_B0_UDB12_13_CTL
.set PWM_reset_Sync_ctrl_reg__16BIT_MASK_MASK_REG, CYREG_B0_UDB12_13_MSK
.set PWM_reset_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG, CYREG_B0_UDB12_13_MSK
.set PWM_reset_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG, CYREG_B0_UDB12_13_MSK
.set PWM_reset_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG, CYREG_B0_UDB12_13_MSK
.set PWM_reset_Sync_ctrl_reg__CONTROL_AUX_CTL_REG, CYREG_B0_UDB12_ACTL
.set PWM_reset_Sync_ctrl_reg__CONTROL_REG, CYREG_B0_UDB12_CTL
.set PWM_reset_Sync_ctrl_reg__CONTROL_ST_REG, CYREG_B0_UDB12_ST_CTL
.set PWM_reset_Sync_ctrl_reg__COUNT_REG, CYREG_B0_UDB12_CTL
.set PWM_reset_Sync_ctrl_reg__COUNT_ST_REG, CYREG_B0_UDB12_ST_CTL
.set PWM_reset_Sync_ctrl_reg__MASK, 0x03
.set PWM_reset_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG, CYREG_B0_UDB12_MSK_ACTL
.set PWM_reset_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG, CYREG_B0_UDB12_MSK_ACTL
.set PWM_reset_Sync_ctrl_reg__PERIOD_REG, CYREG_B0_UDB12_MSK

/* PinServoX */
.set PinServoX__0__INTTYPE, CYREG_PICU12_INTTYPE2
.set PinServoX__0__MASK, 0x04
.set PinServoX__0__PC, CYREG_PRT12_PC2
.set PinServoX__0__PORT, 12
.set PinServoX__0__SHIFT, 2
.set PinServoX__AG, CYREG_PRT12_AG
.set PinServoX__BIE, CYREG_PRT12_BIE
.set PinServoX__BIT_MASK, CYREG_PRT12_BIT_MASK
.set PinServoX__BYP, CYREG_PRT12_BYP
.set PinServoX__DM0, CYREG_PRT12_DM0
.set PinServoX__DM1, CYREG_PRT12_DM1
.set PinServoX__DM2, CYREG_PRT12_DM2
.set PinServoX__DR, CYREG_PRT12_DR
.set PinServoX__INP_DIS, CYREG_PRT12_INP_DIS
.set PinServoX__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set PinServoX__MASK, 0x04
.set PinServoX__PORT, 12
.set PinServoX__PRT, CYREG_PRT12_PRT
.set PinServoX__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set PinServoX__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set PinServoX__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set PinServoX__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set PinServoX__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set PinServoX__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set PinServoX__PS, CYREG_PRT12_PS
.set PinServoX__SHIFT, 2
.set PinServoX__SIO_CFG, CYREG_PRT12_SIO_CFG
.set PinServoX__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set PinServoX__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set PinServoX__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set PinServoX__SLW, CYREG_PRT12_SLW

/* PinServoY */
.set PinServoY__0__INTTYPE, CYREG_PICU12_INTTYPE3
.set PinServoY__0__MASK, 0x08
.set PinServoY__0__PC, CYREG_PRT12_PC3
.set PinServoY__0__PORT, 12
.set PinServoY__0__SHIFT, 3
.set PinServoY__AG, CYREG_PRT12_AG
.set PinServoY__BIE, CYREG_PRT12_BIE
.set PinServoY__BIT_MASK, CYREG_PRT12_BIT_MASK
.set PinServoY__BYP, CYREG_PRT12_BYP
.set PinServoY__DM0, CYREG_PRT12_DM0
.set PinServoY__DM1, CYREG_PRT12_DM1
.set PinServoY__DM2, CYREG_PRT12_DM2
.set PinServoY__DR, CYREG_PRT12_DR
.set PinServoY__INP_DIS, CYREG_PRT12_INP_DIS
.set PinServoY__INTTYPE_BASE, CYDEV_PICU_INTTYPE_PICU12_BASE
.set PinServoY__MASK, 0x08
.set PinServoY__PORT, 12
.set PinServoY__PRT, CYREG_PRT12_PRT
.set PinServoY__PRTDSI__DBL_SYNC_IN, CYREG_PRT12_DBL_SYNC_IN
.set PinServoY__PRTDSI__OE_SEL0, CYREG_PRT12_OE_SEL0
.set PinServoY__PRTDSI__OE_SEL1, CYREG_PRT12_OE_SEL1
.set PinServoY__PRTDSI__OUT_SEL0, CYREG_PRT12_OUT_SEL0
.set PinServoY__PRTDSI__OUT_SEL1, CYREG_PRT12_OUT_SEL1
.set PinServoY__PRTDSI__SYNC_OUT, CYREG_PRT12_SYNC_OUT
.set PinServoY__PS, CYREG_PRT12_PS
.set PinServoY__SHIFT, 3
.set PinServoY__SIO_CFG, CYREG_PRT12_SIO_CFG
.set PinServoY__SIO_DIFF, CYREG_PRT12_SIO_DIFF
.set PinServoY__SIO_HYST_EN, CYREG_PRT12_SIO_HYST_EN
.set PinServoY__SIO_REG_HIFREQ, CYREG_PRT12_SIO_REG_HIFREQ
.set PinServoY__SLW, CYREG_PRT12_SLW

/* X_interrupcion */
.set X_interrupcion__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set X_interrupcion__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set X_interrupcion__INTC_MASK, 0x01
.set X_interrupcion__INTC_NUMBER, 0
.set X_interrupcion__INTC_PRIOR_NUM, 7
.set X_interrupcion__INTC_PRIOR_REG, CYREG_NVIC_PRI_0
.set X_interrupcion__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set X_interrupcion__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* Y_interrupcion */
.set Y_interrupcion__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set Y_interrupcion__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set Y_interrupcion__INTC_MASK, 0x02
.set Y_interrupcion__INTC_NUMBER, 1
.set Y_interrupcion__INTC_PRIOR_NUM, 7
.set Y_interrupcion__INTC_PRIOR_REG, CYREG_NVIC_PRI_1
.set Y_interrupcion__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set Y_interrupcion__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* ClockServoControl */
.set ClockServoControl__CFG0, CYREG_CLKDIST_DCFG1_CFG0
.set ClockServoControl__CFG1, CYREG_CLKDIST_DCFG1_CFG1
.set ClockServoControl__CFG2, CYREG_CLKDIST_DCFG1_CFG2
.set ClockServoControl__CFG2_SRC_SEL_MASK, 0x07
.set ClockServoControl__INDEX, 0x01
.set ClockServoControl__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set ClockServoControl__PM_ACT_MSK, 0x02
.set ClockServoControl__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set ClockServoControl__PM_STBY_MSK, 0x02

/* Miscellaneous */
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PSOC4A, 18
.set CYDEV_CHIP_DIE_PSOC5LP, 2
.set CYDEV_CHIP_DIE_PSOC5TM, 3
.set CYDEV_CHIP_DIE_TMA4, 4
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_FM0P, 5
.set CYDEV_CHIP_FAMILY_FM3, 6
.set CYDEV_CHIP_FAMILY_FM4, 7
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_PSOC6, 4
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E123069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 18
.set CYDEV_CHIP_MEMBER_4D, 13
.set CYDEV_CHIP_MEMBER_4E, 6
.set CYDEV_CHIP_MEMBER_4F, 19
.set CYDEV_CHIP_MEMBER_4G, 4
.set CYDEV_CHIP_MEMBER_4H, 17
.set CYDEV_CHIP_MEMBER_4I, 23
.set CYDEV_CHIP_MEMBER_4J, 14
.set CYDEV_CHIP_MEMBER_4K, 15
.set CYDEV_CHIP_MEMBER_4L, 22
.set CYDEV_CHIP_MEMBER_4M, 21
.set CYDEV_CHIP_MEMBER_4N, 10
.set CYDEV_CHIP_MEMBER_4O, 7
.set CYDEV_CHIP_MEMBER_4P, 20
.set CYDEV_CHIP_MEMBER_4Q, 12
.set CYDEV_CHIP_MEMBER_4R, 8
.set CYDEV_CHIP_MEMBER_4S, 11
.set CYDEV_CHIP_MEMBER_4T, 9
.set CYDEV_CHIP_MEMBER_4U, 5
.set CYDEV_CHIP_MEMBER_4V, 16
.set CYDEV_CHIP_MEMBER_5A, 3
.set CYDEV_CHIP_MEMBER_5B, 2
.set CYDEV_CHIP_MEMBER_6A, 24
.set CYDEV_CHIP_MEMBER_FM3, 28
.set CYDEV_CHIP_MEMBER_FM4, 29
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1, 25
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2, 26
.set CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3, 27
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES0, 0
.set CYDEV_CHIP_REV_PSOC5TM_ES1, 1
.set CYDEV_CHIP_REV_PSOC5TM_PRODUCTION, 1
.set CYDEV_CHIP_REV_TMA4_ES, 17
.set CYDEV_CHIP_REV_TMA4_ES2, 33
.set CYDEV_CHIP_REV_TMA4_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4H_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4I_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4J_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4K_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4N_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4O_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4P_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4Q_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4R_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4S_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4T_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4U_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4V_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_6A_ES, 17
.set CYDEV_CHIP_REVISION_6A_NO_UDB, 33
.set CYDEV_CHIP_REVISION_6A_PRODUCTION, 33
.set CYDEV_CHIP_REVISION_FM3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_FM4_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD_SWV
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x00000003
.set CYDEV_IS_EXPORTING_CODE, 0
.set CYDEV_IS_IMPORTING_CODE, 0
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3_MV, 5000
.set CYIPBLOCK_ARM_CM3_VERSION, 0
.set CYIPBLOCK_P3_ANAIF_VERSION, 0
.set CYIPBLOCK_P3_CAN_VERSION, 0
.set CYIPBLOCK_P3_CAPSENSE_VERSION, 0
.set CYIPBLOCK_P3_COMP_VERSION, 0
.set CYIPBLOCK_P3_DECIMATOR_VERSION, 0
.set CYIPBLOCK_P3_DFB_VERSION, 0
.set CYIPBLOCK_P3_DMA_VERSION, 0
.set CYIPBLOCK_P3_DRQ_VERSION, 0
.set CYIPBLOCK_P3_DSM_VERSION, 0
.set CYIPBLOCK_P3_EMIF_VERSION, 0
.set CYIPBLOCK_P3_I2C_VERSION, 0
.set CYIPBLOCK_P3_LCD_VERSION, 0
.set CYIPBLOCK_P3_LPF_VERSION, 0
.set CYIPBLOCK_P3_OPAMP_VERSION, 0
.set CYIPBLOCK_P3_PM_VERSION, 0
.set CYIPBLOCK_P3_SCCT_VERSION, 0
.set CYIPBLOCK_P3_TIMER_VERSION, 0
.set CYIPBLOCK_P3_USB_VERSION, 0
.set CYIPBLOCK_P3_VIDAC_VERSION, 0
.set CYIPBLOCK_P3_VREF_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 0
.set CYIPBLOCK_S8_IRQ_VERSION, 0
.set CYIPBLOCK_S8_SAR_VERSION, 0
.set CYIPBLOCK_S8_SIO_VERSION, 0
.set CYIPBLOCK_S8_UDB_VERSION, 0
.set DMA_CHANNELS_USED__MASK0, 0x00000000
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
