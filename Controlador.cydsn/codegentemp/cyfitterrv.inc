;
; File Name: cyfitterrv.inc
; 
; PSoC Creator  4.2
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; LCD
LCD_LCDPort__0__INTTYPE EQU CYREG_PICU2_INTTYPE0
LCD_LCDPort__0__MASK EQU 0x01
LCD_LCDPort__0__PC EQU CYREG_PRT2_PC0
LCD_LCDPort__0__PORT EQU 2
LCD_LCDPort__0__SHIFT EQU 0
LCD_LCDPort__1__INTTYPE EQU CYREG_PICU2_INTTYPE1
LCD_LCDPort__1__MASK EQU 0x02
LCD_LCDPort__1__PC EQU CYREG_PRT2_PC1
LCD_LCDPort__1__PORT EQU 2
LCD_LCDPort__1__SHIFT EQU 1
LCD_LCDPort__2__INTTYPE EQU CYREG_PICU2_INTTYPE2
LCD_LCDPort__2__MASK EQU 0x04
LCD_LCDPort__2__PC EQU CYREG_PRT2_PC2
LCD_LCDPort__2__PORT EQU 2
LCD_LCDPort__2__SHIFT EQU 2
LCD_LCDPort__3__INTTYPE EQU CYREG_PICU2_INTTYPE3
LCD_LCDPort__3__MASK EQU 0x08
LCD_LCDPort__3__PC EQU CYREG_PRT2_PC3
LCD_LCDPort__3__PORT EQU 2
LCD_LCDPort__3__SHIFT EQU 3
LCD_LCDPort__4__INTTYPE EQU CYREG_PICU2_INTTYPE4
LCD_LCDPort__4__MASK EQU 0x10
LCD_LCDPort__4__PC EQU CYREG_PRT2_PC4
LCD_LCDPort__4__PORT EQU 2
LCD_LCDPort__4__SHIFT EQU 4
LCD_LCDPort__5__INTTYPE EQU CYREG_PICU2_INTTYPE5
LCD_LCDPort__5__MASK EQU 0x20
LCD_LCDPort__5__PC EQU CYREG_PRT2_PC5
LCD_LCDPort__5__PORT EQU 2
LCD_LCDPort__5__SHIFT EQU 5
LCD_LCDPort__6__INTTYPE EQU CYREG_PICU2_INTTYPE6
LCD_LCDPort__6__MASK EQU 0x40
LCD_LCDPort__6__PC EQU CYREG_PRT2_PC6
LCD_LCDPort__6__PORT EQU 2
LCD_LCDPort__6__SHIFT EQU 6
LCD_LCDPort__AG EQU CYREG_PRT2_AG
LCD_LCDPort__AMUX EQU CYREG_PRT2_AMUX
LCD_LCDPort__BIE EQU CYREG_PRT2_BIE
LCD_LCDPort__BIT_MASK EQU CYREG_PRT2_BIT_MASK
LCD_LCDPort__BYP EQU CYREG_PRT2_BYP
LCD_LCDPort__CTL EQU CYREG_PRT2_CTL
LCD_LCDPort__DM0 EQU CYREG_PRT2_DM0
LCD_LCDPort__DM1 EQU CYREG_PRT2_DM1
LCD_LCDPort__DM2 EQU CYREG_PRT2_DM2
LCD_LCDPort__DR EQU CYREG_PRT2_DR
LCD_LCDPort__INP_DIS EQU CYREG_PRT2_INP_DIS
LCD_LCDPort__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
LCD_LCDPort__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
LCD_LCDPort__LCD_EN EQU CYREG_PRT2_LCD_EN
LCD_LCDPort__MASK EQU 0x7F
LCD_LCDPort__PORT EQU 2
LCD_LCDPort__PRT EQU CYREG_PRT2_PRT
LCD_LCDPort__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
LCD_LCDPort__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
LCD_LCDPort__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
LCD_LCDPort__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
LCD_LCDPort__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
LCD_LCDPort__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
LCD_LCDPort__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
LCD_LCDPort__PS EQU CYREG_PRT2_PS
LCD_LCDPort__SHIFT EQU 0
LCD_LCDPort__SLW EQU CYREG_PRT2_SLW

; PWM_X
PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB11_12_ACTL
PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB11_12_CTL
PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB11_12_CTL
PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB11_12_CTL
PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB11_12_CTL
PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB11_12_MSK
PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB11_12_MSK
PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB11_12_MSK
PWM_X_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB11_12_MSK
PWM_X_PWMUDB_genblk1_ctrlreg__7__MASK EQU 0x80
PWM_X_PWMUDB_genblk1_ctrlreg__7__POS EQU 7
PWM_X_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB11_ACTL
PWM_X_PWMUDB_genblk1_ctrlreg__CONTROL_REG EQU CYREG_B0_UDB11_CTL
PWM_X_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG EQU CYREG_B0_UDB11_ST_CTL
PWM_X_PWMUDB_genblk1_ctrlreg__COUNT_REG EQU CYREG_B0_UDB11_CTL
PWM_X_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG EQU CYREG_B0_UDB11_ST_CTL
PWM_X_PWMUDB_genblk1_ctrlreg__MASK EQU 0x80
PWM_X_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB11_MSK_ACTL
PWM_X_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB11_MSK_ACTL
PWM_X_PWMUDB_genblk1_ctrlreg__PERIOD_REG EQU CYREG_B0_UDB11_MSK
PWM_X_PWMUDB_genblk8_stsreg__0__MASK EQU 0x01
PWM_X_PWMUDB_genblk8_stsreg__0__POS EQU 0
PWM_X_PWMUDB_genblk8_stsreg__1__MASK EQU 0x02
PWM_X_PWMUDB_genblk8_stsreg__1__POS EQU 1
PWM_X_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB11_12_ACTL
PWM_X_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB11_12_ST
PWM_X_PWMUDB_genblk8_stsreg__2__MASK EQU 0x04
PWM_X_PWMUDB_genblk8_stsreg__2__POS EQU 2
PWM_X_PWMUDB_genblk8_stsreg__3__MASK EQU 0x08
PWM_X_PWMUDB_genblk8_stsreg__3__POS EQU 3
PWM_X_PWMUDB_genblk8_stsreg__MASK EQU 0x0F
PWM_X_PWMUDB_genblk8_stsreg__MASK_REG EQU CYREG_B0_UDB11_MSK
PWM_X_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB11_MSK_ACTL
PWM_X_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB11_MSK_ACTL
PWM_X_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB11_ACTL
PWM_X_PWMUDB_genblk8_stsreg__STATUS_CNT_REG EQU CYREG_B0_UDB11_ST_CTL
PWM_X_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG EQU CYREG_B0_UDB11_ST_CTL
PWM_X_PWMUDB_genblk8_stsreg__STATUS_REG EQU CYREG_B0_UDB11_ST
PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB10_11_A0
PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB10_11_A1
PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB10_11_D0
PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB10_11_D1
PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB10_11_ACTL
PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB10_11_F0
PWM_X_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB10_11_F1
PWM_X_PWMUDB_sP16_pwmdp_u0__A0_A1_REG EQU CYREG_B0_UDB10_A0_A1
PWM_X_PWMUDB_sP16_pwmdp_u0__A0_REG EQU CYREG_B0_UDB10_A0
PWM_X_PWMUDB_sP16_pwmdp_u0__A1_REG EQU CYREG_B0_UDB10_A1
PWM_X_PWMUDB_sP16_pwmdp_u0__D0_D1_REG EQU CYREG_B0_UDB10_D0_D1
PWM_X_PWMUDB_sP16_pwmdp_u0__D0_REG EQU CYREG_B0_UDB10_D0
PWM_X_PWMUDB_sP16_pwmdp_u0__D1_REG EQU CYREG_B0_UDB10_D1
PWM_X_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB10_ACTL
PWM_X_PWMUDB_sP16_pwmdp_u0__F0_F1_REG EQU CYREG_B0_UDB10_F0_F1
PWM_X_PWMUDB_sP16_pwmdp_u0__F0_REG EQU CYREG_B0_UDB10_F0
PWM_X_PWMUDB_sP16_pwmdp_u0__F1_REG EQU CYREG_B0_UDB10_F1
PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG EQU CYREG_B0_UDB11_12_A0
PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG EQU CYREG_B0_UDB11_12_A1
PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG EQU CYREG_B0_UDB11_12_D0
PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG EQU CYREG_B0_UDB11_12_D1
PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB11_12_ACTL
PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG EQU CYREG_B0_UDB11_12_F0
PWM_X_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG EQU CYREG_B0_UDB11_12_F1
PWM_X_PWMUDB_sP16_pwmdp_u1__A0_A1_REG EQU CYREG_B0_UDB11_A0_A1
PWM_X_PWMUDB_sP16_pwmdp_u1__A0_REG EQU CYREG_B0_UDB11_A0
PWM_X_PWMUDB_sP16_pwmdp_u1__A1_REG EQU CYREG_B0_UDB11_A1
PWM_X_PWMUDB_sP16_pwmdp_u1__D0_D1_REG EQU CYREG_B0_UDB11_D0_D1
PWM_X_PWMUDB_sP16_pwmdp_u1__D0_REG EQU CYREG_B0_UDB11_D0
PWM_X_PWMUDB_sP16_pwmdp_u1__D1_REG EQU CYREG_B0_UDB11_D1
PWM_X_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG EQU CYREG_B0_UDB11_ACTL
PWM_X_PWMUDB_sP16_pwmdp_u1__F0_F1_REG EQU CYREG_B0_UDB11_F0_F1
PWM_X_PWMUDB_sP16_pwmdp_u1__F0_REG EQU CYREG_B0_UDB11_F0
PWM_X_PWMUDB_sP16_pwmdp_u1__F1_REG EQU CYREG_B0_UDB11_F1
PWM_X_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB11_MSK_ACTL
PWM_X_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB11_MSK_ACTL

; PWM_Y
PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB13_14_CTL
PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB13_14_CTL
PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB13_14_CTL
PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB13_14_CTL
PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB13_14_MSK
PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB13_14_MSK
PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB13_14_MSK
PWM_Y_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB13_14_MSK
PWM_Y_PWMUDB_genblk1_ctrlreg__7__MASK EQU 0x80
PWM_Y_PWMUDB_genblk1_ctrlreg__7__POS EQU 7
PWM_Y_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
PWM_Y_PWMUDB_genblk1_ctrlreg__CONTROL_REG EQU CYREG_B0_UDB13_CTL
PWM_Y_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG EQU CYREG_B0_UDB13_ST_CTL
PWM_Y_PWMUDB_genblk1_ctrlreg__COUNT_REG EQU CYREG_B0_UDB13_CTL
PWM_Y_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG EQU CYREG_B0_UDB13_ST_CTL
PWM_Y_PWMUDB_genblk1_ctrlreg__MASK EQU 0x80
PWM_Y_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
PWM_Y_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
PWM_Y_PWMUDB_genblk1_ctrlreg__PERIOD_REG EQU CYREG_B0_UDB13_MSK
PWM_Y_PWMUDB_genblk8_stsreg__0__MASK EQU 0x01
PWM_Y_PWMUDB_genblk8_stsreg__0__POS EQU 0
PWM_Y_PWMUDB_genblk8_stsreg__1__MASK EQU 0x02
PWM_Y_PWMUDB_genblk8_stsreg__1__POS EQU 1
PWM_Y_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
PWM_Y_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG EQU CYREG_B0_UDB13_14_ST
PWM_Y_PWMUDB_genblk8_stsreg__2__MASK EQU 0x04
PWM_Y_PWMUDB_genblk8_stsreg__2__POS EQU 2
PWM_Y_PWMUDB_genblk8_stsreg__3__MASK EQU 0x08
PWM_Y_PWMUDB_genblk8_stsreg__3__POS EQU 3
PWM_Y_PWMUDB_genblk8_stsreg__MASK EQU 0x0F
PWM_Y_PWMUDB_genblk8_stsreg__MASK_REG EQU CYREG_B0_UDB13_MSK
PWM_Y_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
PWM_Y_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
PWM_Y_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
PWM_Y_PWMUDB_genblk8_stsreg__STATUS_CNT_REG EQU CYREG_B0_UDB13_ST_CTL
PWM_Y_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG EQU CYREG_B0_UDB13_ST_CTL
PWM_Y_PWMUDB_genblk8_stsreg__STATUS_REG EQU CYREG_B0_UDB13_ST
PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG EQU CYREG_B0_UDB12_13_A0
PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG EQU CYREG_B0_UDB12_13_A1
PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG EQU CYREG_B0_UDB12_13_D0
PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG EQU CYREG_B0_UDB12_13_D1
PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB12_13_ACTL
PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG EQU CYREG_B0_UDB12_13_F0
PWM_Y_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG EQU CYREG_B0_UDB12_13_F1
PWM_Y_PWMUDB_sP16_pwmdp_u0__A0_A1_REG EQU CYREG_B0_UDB12_A0_A1
PWM_Y_PWMUDB_sP16_pwmdp_u0__A0_REG EQU CYREG_B0_UDB12_A0
PWM_Y_PWMUDB_sP16_pwmdp_u0__A1_REG EQU CYREG_B0_UDB12_A1
PWM_Y_PWMUDB_sP16_pwmdp_u0__D0_D1_REG EQU CYREG_B0_UDB12_D0_D1
PWM_Y_PWMUDB_sP16_pwmdp_u0__D0_REG EQU CYREG_B0_UDB12_D0
PWM_Y_PWMUDB_sP16_pwmdp_u0__D1_REG EQU CYREG_B0_UDB12_D1
PWM_Y_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB12_ACTL
PWM_Y_PWMUDB_sP16_pwmdp_u0__F0_F1_REG EQU CYREG_B0_UDB12_F0_F1
PWM_Y_PWMUDB_sP16_pwmdp_u0__F0_REG EQU CYREG_B0_UDB12_F0
PWM_Y_PWMUDB_sP16_pwmdp_u0__F1_REG EQU CYREG_B0_UDB12_F1
PWM_Y_PWMUDB_sP16_pwmdp_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB12_MSK_ACTL
PWM_Y_PWMUDB_sP16_pwmdp_u0__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB12_MSK_ACTL
PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG EQU CYREG_B0_UDB13_14_A0
PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG EQU CYREG_B0_UDB13_14_A1
PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG EQU CYREG_B0_UDB13_14_D0
PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG EQU CYREG_B0_UDB13_14_D1
PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG EQU CYREG_B0_UDB13_14_F0
PWM_Y_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG EQU CYREG_B0_UDB13_14_F1
PWM_Y_PWMUDB_sP16_pwmdp_u1__A0_A1_REG EQU CYREG_B0_UDB13_A0_A1
PWM_Y_PWMUDB_sP16_pwmdp_u1__A0_REG EQU CYREG_B0_UDB13_A0
PWM_Y_PWMUDB_sP16_pwmdp_u1__A1_REG EQU CYREG_B0_UDB13_A1
PWM_Y_PWMUDB_sP16_pwmdp_u1__D0_D1_REG EQU CYREG_B0_UDB13_D0_D1
PWM_Y_PWMUDB_sP16_pwmdp_u1__D0_REG EQU CYREG_B0_UDB13_D0
PWM_Y_PWMUDB_sP16_pwmdp_u1__D1_REG EQU CYREG_B0_UDB13_D1
PWM_Y_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
PWM_Y_PWMUDB_sP16_pwmdp_u1__F0_F1_REG EQU CYREG_B0_UDB13_F0_F1
PWM_Y_PWMUDB_sP16_pwmdp_u1__F0_REG EQU CYREG_B0_UDB13_F0
PWM_Y_PWMUDB_sP16_pwmdp_u1__F1_REG EQU CYREG_B0_UDB13_F1
PWM_Y_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL
PWM_Y_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG EQU CYREG_B0_UDB13_MSK_ACTL

; Touch
Touch_ADC_DEC__COHER EQU CYREG_DEC_COHER
Touch_ADC_DEC__CR EQU CYREG_DEC_CR
Touch_ADC_DEC__DR1 EQU CYREG_DEC_DR1
Touch_ADC_DEC__DR2 EQU CYREG_DEC_DR2
Touch_ADC_DEC__DR2H EQU CYREG_DEC_DR2H
Touch_ADC_DEC__GCOR EQU CYREG_DEC_GCOR
Touch_ADC_DEC__GCORH EQU CYREG_DEC_GCORH
Touch_ADC_DEC__GVAL EQU CYREG_DEC_GVAL
Touch_ADC_DEC__OCOR EQU CYREG_DEC_OCOR
Touch_ADC_DEC__OCORH EQU CYREG_DEC_OCORH
Touch_ADC_DEC__OCORM EQU CYREG_DEC_OCORM
Touch_ADC_DEC__OUTSAMP EQU CYREG_DEC_OUTSAMP
Touch_ADC_DEC__OUTSAMPH EQU CYREG_DEC_OUTSAMPH
Touch_ADC_DEC__OUTSAMPM EQU CYREG_DEC_OUTSAMPM
Touch_ADC_DEC__OUTSAMPS EQU CYREG_DEC_OUTSAMPS
Touch_ADC_DEC__PM_ACT_CFG EQU CYREG_PM_ACT_CFG10
Touch_ADC_DEC__PM_ACT_MSK EQU 0x01
Touch_ADC_DEC__PM_STBY_CFG EQU CYREG_PM_STBY_CFG10
Touch_ADC_DEC__PM_STBY_MSK EQU 0x01
Touch_ADC_DEC__SHIFT1 EQU CYREG_DEC_SHIFT1
Touch_ADC_DEC__SHIFT2 EQU CYREG_DEC_SHIFT2
Touch_ADC_DEC__SR EQU CYREG_DEC_SR
Touch_ADC_DEC__TRIM__M1 EQU CYREG_FLSHID_CUST_TABLES_DEC_M1
Touch_ADC_DEC__TRIM__M2 EQU CYREG_FLSHID_CUST_TABLES_DEC_M2
Touch_ADC_DEC__TRIM__M3 EQU CYREG_FLSHID_CUST_TABLES_DEC_M3
Touch_ADC_DEC__TRIM__M4 EQU CYREG_FLSHID_CUST_TABLES_DEC_M4
Touch_ADC_DEC__TRIM__M5 EQU CYREG_FLSHID_CUST_TABLES_DEC_M5
Touch_ADC_DEC__TRIM__M6 EQU CYREG_FLSHID_CUST_TABLES_DEC_M6
Touch_ADC_DEC__TRIM__M7 EQU CYREG_FLSHID_CUST_TABLES_DEC_M7
Touch_ADC_DEC__TRIM__M8 EQU CYREG_FLSHID_CUST_TABLES_DEC_M8
Touch_ADC_DSM__BUF0 EQU CYREG_DSM0_BUF0
Touch_ADC_DSM__BUF1 EQU CYREG_DSM0_BUF1
Touch_ADC_DSM__BUF2 EQU CYREG_DSM0_BUF2
Touch_ADC_DSM__BUF3 EQU CYREG_DSM0_BUF3
Touch_ADC_DSM__CLK EQU CYREG_DSM0_CLK
Touch_ADC_DSM__CR0 EQU CYREG_DSM0_CR0
Touch_ADC_DSM__CR1 EQU CYREG_DSM0_CR1
Touch_ADC_DSM__CR10 EQU CYREG_DSM0_CR10
Touch_ADC_DSM__CR11 EQU CYREG_DSM0_CR11
Touch_ADC_DSM__CR12 EQU CYREG_DSM0_CR12
Touch_ADC_DSM__CR13 EQU CYREG_DSM0_CR13
Touch_ADC_DSM__CR14 EQU CYREG_DSM0_CR14
Touch_ADC_DSM__CR15 EQU CYREG_DSM0_CR15
Touch_ADC_DSM__CR16 EQU CYREG_DSM0_CR16
Touch_ADC_DSM__CR17 EQU CYREG_DSM0_CR17
Touch_ADC_DSM__CR2 EQU CYREG_DSM0_CR2
Touch_ADC_DSM__CR3 EQU CYREG_DSM0_CR3
Touch_ADC_DSM__CR4 EQU CYREG_DSM0_CR4
Touch_ADC_DSM__CR5 EQU CYREG_DSM0_CR5
Touch_ADC_DSM__CR6 EQU CYREG_DSM0_CR6
Touch_ADC_DSM__CR7 EQU CYREG_DSM0_CR7
Touch_ADC_DSM__CR8 EQU CYREG_DSM0_CR8
Touch_ADC_DSM__CR9 EQU CYREG_DSM0_CR9
Touch_ADC_DSM__DEM0 EQU CYREG_DSM0_DEM0
Touch_ADC_DSM__DEM1 EQU CYREG_DSM0_DEM1
Touch_ADC_DSM__MISC EQU CYREG_DSM0_MISC
Touch_ADC_DSM__OUT0 EQU CYREG_DSM0_OUT0
Touch_ADC_DSM__OUT1 EQU CYREG_DSM0_OUT1
Touch_ADC_DSM__REF0 EQU CYREG_DSM0_REF0
Touch_ADC_DSM__REF1 EQU CYREG_DSM0_REF1
Touch_ADC_DSM__REF2 EQU CYREG_DSM0_REF2
Touch_ADC_DSM__REF3 EQU CYREG_DSM0_REF3
Touch_ADC_DSM__RSVD1 EQU CYREG_DSM0_RSVD1
Touch_ADC_DSM__SW0 EQU CYREG_DSM0_SW0
Touch_ADC_DSM__SW2 EQU CYREG_DSM0_SW2
Touch_ADC_DSM__SW3 EQU CYREG_DSM0_SW3
Touch_ADC_DSM__SW4 EQU CYREG_DSM0_SW4
Touch_ADC_DSM__SW6 EQU CYREG_DSM0_SW6
Touch_ADC_DSM__TR0 EQU CYREG_NPUMP_DSM_TR0
Touch_ADC_DSM__TST0 EQU CYREG_DSM0_TST0
Touch_ADC_DSM__TST1 EQU CYREG_DSM0_TST1
Touch_ADC_Ext_CP_Clk__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
Touch_ADC_Ext_CP_Clk__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
Touch_ADC_Ext_CP_Clk__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
Touch_ADC_Ext_CP_Clk__CFG2_SRC_SEL_MASK EQU 0x07
Touch_ADC_Ext_CP_Clk__INDEX EQU 0x00
Touch_ADC_Ext_CP_Clk__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Touch_ADC_Ext_CP_Clk__PM_ACT_MSK EQU 0x01
Touch_ADC_Ext_CP_Clk__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Touch_ADC_Ext_CP_Clk__PM_STBY_MSK EQU 0x01
Touch_ADC_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
Touch_ADC_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
Touch_ADC_IRQ__INTC_MASK EQU 0x20000000
Touch_ADC_IRQ__INTC_NUMBER EQU 29
Touch_ADC_IRQ__INTC_PRIOR_NUM EQU 7
Touch_ADC_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_29
Touch_ADC_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
Touch_ADC_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0
Touch_ADC_theACLK__CFG0 EQU CYREG_CLKDIST_ACFG0_CFG0
Touch_ADC_theACLK__CFG1 EQU CYREG_CLKDIST_ACFG0_CFG1
Touch_ADC_theACLK__CFG2 EQU CYREG_CLKDIST_ACFG0_CFG2
Touch_ADC_theACLK__CFG2_SRC_SEL_MASK EQU 0x07
Touch_ADC_theACLK__CFG3 EQU CYREG_CLKDIST_ACFG0_CFG3
Touch_ADC_theACLK__CFG3_PHASE_DLY_MASK EQU 0x0F
Touch_ADC_theACLK__INDEX EQU 0x00
Touch_ADC_theACLK__PM_ACT_CFG EQU CYREG_PM_ACT_CFG1
Touch_ADC_theACLK__PM_ACT_MSK EQU 0x01
Touch_ADC_theACLK__PM_STBY_CFG EQU CYREG_PM_STBY_CFG1
Touch_ADC_theACLK__PM_STBY_MSK EQU 0x01
Touch_xm__0__INTTYPE EQU CYREG_PICU4_INTTYPE2
Touch_xm__0__MASK EQU 0x04
Touch_xm__0__PC EQU CYREG_PRT4_PC2
Touch_xm__0__PORT EQU 4
Touch_xm__0__SHIFT EQU 2
Touch_xm__AG EQU CYREG_PRT4_AG
Touch_xm__AMUX EQU CYREG_PRT4_AMUX
Touch_xm__BIE EQU CYREG_PRT4_BIE
Touch_xm__BIT_MASK EQU CYREG_PRT4_BIT_MASK
Touch_xm__BYP EQU CYREG_PRT4_BYP
Touch_xm__CTL EQU CYREG_PRT4_CTL
Touch_xm__DM0 EQU CYREG_PRT4_DM0
Touch_xm__DM1 EQU CYREG_PRT4_DM1
Touch_xm__DM2 EQU CYREG_PRT4_DM2
Touch_xm__DR EQU CYREG_PRT4_DR
Touch_xm__INP_DIS EQU CYREG_PRT4_INP_DIS
Touch_xm__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU4_BASE
Touch_xm__LCD_COM_SEG EQU CYREG_PRT4_LCD_COM_SEG
Touch_xm__LCD_EN EQU CYREG_PRT4_LCD_EN
Touch_xm__MASK EQU 0x04
Touch_xm__PORT EQU 4
Touch_xm__PRT EQU CYREG_PRT4_PRT
Touch_xm__PRTDSI__CAPS_SEL EQU CYREG_PRT4_CAPS_SEL
Touch_xm__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT4_DBL_SYNC_IN
Touch_xm__PRTDSI__OE_SEL0 EQU CYREG_PRT4_OE_SEL0
Touch_xm__PRTDSI__OE_SEL1 EQU CYREG_PRT4_OE_SEL1
Touch_xm__PRTDSI__OUT_SEL0 EQU CYREG_PRT4_OUT_SEL0
Touch_xm__PRTDSI__OUT_SEL1 EQU CYREG_PRT4_OUT_SEL1
Touch_xm__PRTDSI__SYNC_OUT EQU CYREG_PRT4_SYNC_OUT
Touch_xm__PS EQU CYREG_PRT4_PS
Touch_xm__SHIFT EQU 2
Touch_xm__SLW EQU CYREG_PRT4_SLW
Touch_xp__0__INTTYPE EQU CYREG_PICU4_INTTYPE0
Touch_xp__0__MASK EQU 0x01
Touch_xp__0__PC EQU CYREG_PRT4_PC0
Touch_xp__0__PORT EQU 4
Touch_xp__0__SHIFT EQU 0
Touch_xp__AG EQU CYREG_PRT4_AG
Touch_xp__AMUX EQU CYREG_PRT4_AMUX
Touch_xp__BIE EQU CYREG_PRT4_BIE
Touch_xp__BIT_MASK EQU CYREG_PRT4_BIT_MASK
Touch_xp__BYP EQU CYREG_PRT4_BYP
Touch_xp__CTL EQU CYREG_PRT4_CTL
Touch_xp__DM0 EQU CYREG_PRT4_DM0
Touch_xp__DM1 EQU CYREG_PRT4_DM1
Touch_xp__DM2 EQU CYREG_PRT4_DM2
Touch_xp__DR EQU CYREG_PRT4_DR
Touch_xp__INP_DIS EQU CYREG_PRT4_INP_DIS
Touch_xp__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU4_BASE
Touch_xp__LCD_COM_SEG EQU CYREG_PRT4_LCD_COM_SEG
Touch_xp__LCD_EN EQU CYREG_PRT4_LCD_EN
Touch_xp__MASK EQU 0x01
Touch_xp__PORT EQU 4
Touch_xp__PRT EQU CYREG_PRT4_PRT
Touch_xp__PRTDSI__CAPS_SEL EQU CYREG_PRT4_CAPS_SEL
Touch_xp__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT4_DBL_SYNC_IN
Touch_xp__PRTDSI__OE_SEL0 EQU CYREG_PRT4_OE_SEL0
Touch_xp__PRTDSI__OE_SEL1 EQU CYREG_PRT4_OE_SEL1
Touch_xp__PRTDSI__OUT_SEL0 EQU CYREG_PRT4_OUT_SEL0
Touch_xp__PRTDSI__OUT_SEL1 EQU CYREG_PRT4_OUT_SEL1
Touch_xp__PRTDSI__SYNC_OUT EQU CYREG_PRT4_SYNC_OUT
Touch_xp__PS EQU CYREG_PRT4_PS
Touch_xp__SHIFT EQU 0
Touch_xp__SLW EQU CYREG_PRT4_SLW
Touch_ym__0__INTTYPE EQU CYREG_PICU4_INTTYPE1
Touch_ym__0__MASK EQU 0x02
Touch_ym__0__PC EQU CYREG_PRT4_PC1
Touch_ym__0__PORT EQU 4
Touch_ym__0__SHIFT EQU 1
Touch_ym__AG EQU CYREG_PRT4_AG
Touch_ym__AMUX EQU CYREG_PRT4_AMUX
Touch_ym__BIE EQU CYREG_PRT4_BIE
Touch_ym__BIT_MASK EQU CYREG_PRT4_BIT_MASK
Touch_ym__BYP EQU CYREG_PRT4_BYP
Touch_ym__CTL EQU CYREG_PRT4_CTL
Touch_ym__DM0 EQU CYREG_PRT4_DM0
Touch_ym__DM1 EQU CYREG_PRT4_DM1
Touch_ym__DM2 EQU CYREG_PRT4_DM2
Touch_ym__DR EQU CYREG_PRT4_DR
Touch_ym__INP_DIS EQU CYREG_PRT4_INP_DIS
Touch_ym__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU4_BASE
Touch_ym__LCD_COM_SEG EQU CYREG_PRT4_LCD_COM_SEG
Touch_ym__LCD_EN EQU CYREG_PRT4_LCD_EN
Touch_ym__MASK EQU 0x02
Touch_ym__PORT EQU 4
Touch_ym__PRT EQU CYREG_PRT4_PRT
Touch_ym__PRTDSI__CAPS_SEL EQU CYREG_PRT4_CAPS_SEL
Touch_ym__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT4_DBL_SYNC_IN
Touch_ym__PRTDSI__OE_SEL0 EQU CYREG_PRT4_OE_SEL0
Touch_ym__PRTDSI__OE_SEL1 EQU CYREG_PRT4_OE_SEL1
Touch_ym__PRTDSI__OUT_SEL0 EQU CYREG_PRT4_OUT_SEL0
Touch_ym__PRTDSI__OUT_SEL1 EQU CYREG_PRT4_OUT_SEL1
Touch_ym__PRTDSI__SYNC_OUT EQU CYREG_PRT4_SYNC_OUT
Touch_ym__PS EQU CYREG_PRT4_PS
Touch_ym__SHIFT EQU 1
Touch_ym__SLW EQU CYREG_PRT4_SLW
Touch_yp__0__INTTYPE EQU CYREG_PICU4_INTTYPE3
Touch_yp__0__MASK EQU 0x08
Touch_yp__0__PC EQU CYREG_PRT4_PC3
Touch_yp__0__PORT EQU 4
Touch_yp__0__SHIFT EQU 3
Touch_yp__AG EQU CYREG_PRT4_AG
Touch_yp__AMUX EQU CYREG_PRT4_AMUX
Touch_yp__BIE EQU CYREG_PRT4_BIE
Touch_yp__BIT_MASK EQU CYREG_PRT4_BIT_MASK
Touch_yp__BYP EQU CYREG_PRT4_BYP
Touch_yp__CTL EQU CYREG_PRT4_CTL
Touch_yp__DM0 EQU CYREG_PRT4_DM0
Touch_yp__DM1 EQU CYREG_PRT4_DM1
Touch_yp__DM2 EQU CYREG_PRT4_DM2
Touch_yp__DR EQU CYREG_PRT4_DR
Touch_yp__INP_DIS EQU CYREG_PRT4_INP_DIS
Touch_yp__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU4_BASE
Touch_yp__LCD_COM_SEG EQU CYREG_PRT4_LCD_COM_SEG
Touch_yp__LCD_EN EQU CYREG_PRT4_LCD_EN
Touch_yp__MASK EQU 0x08
Touch_yp__PORT EQU 4
Touch_yp__PRT EQU CYREG_PRT4_PRT
Touch_yp__PRTDSI__CAPS_SEL EQU CYREG_PRT4_CAPS_SEL
Touch_yp__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT4_DBL_SYNC_IN
Touch_yp__PRTDSI__OE_SEL0 EQU CYREG_PRT4_OE_SEL0
Touch_yp__PRTDSI__OE_SEL1 EQU CYREG_PRT4_OE_SEL1
Touch_yp__PRTDSI__OUT_SEL0 EQU CYREG_PRT4_OUT_SEL0
Touch_yp__PRTDSI__OUT_SEL1 EQU CYREG_PRT4_OUT_SEL1
Touch_yp__PRTDSI__SYNC_OUT EQU CYREG_PRT4_SYNC_OUT
Touch_yp__PS EQU CYREG_PRT4_PS
Touch_yp__SHIFT EQU 3
Touch_yp__SLW EQU CYREG_PRT4_SLW

; PWM_reset
PWM_reset_Sync_ctrl_reg__0__MASK EQU 0x01
PWM_reset_Sync_ctrl_reg__0__POS EQU 0
PWM_reset_Sync_ctrl_reg__1__MASK EQU 0x02
PWM_reset_Sync_ctrl_reg__1__POS EQU 1
PWM_reset_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB12_13_ACTL
PWM_reset_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB12_13_CTL
PWM_reset_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB12_13_CTL
PWM_reset_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB12_13_CTL
PWM_reset_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB12_13_CTL
PWM_reset_Sync_ctrl_reg__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB12_13_MSK
PWM_reset_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB12_13_MSK
PWM_reset_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB12_13_MSK
PWM_reset_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB12_13_MSK
PWM_reset_Sync_ctrl_reg__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB12_ACTL
PWM_reset_Sync_ctrl_reg__CONTROL_REG EQU CYREG_B0_UDB12_CTL
PWM_reset_Sync_ctrl_reg__CONTROL_ST_REG EQU CYREG_B0_UDB12_ST_CTL
PWM_reset_Sync_ctrl_reg__COUNT_REG EQU CYREG_B0_UDB12_CTL
PWM_reset_Sync_ctrl_reg__COUNT_ST_REG EQU CYREG_B0_UDB12_ST_CTL
PWM_reset_Sync_ctrl_reg__MASK EQU 0x03
PWM_reset_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB12_MSK_ACTL
PWM_reset_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB12_MSK_ACTL
PWM_reset_Sync_ctrl_reg__PERIOD_REG EQU CYREG_B0_UDB12_MSK

; PinServoX
PinServoX__0__INTTYPE EQU CYREG_PICU12_INTTYPE2
PinServoX__0__MASK EQU 0x04
PinServoX__0__PC EQU CYREG_PRT12_PC2
PinServoX__0__PORT EQU 12
PinServoX__0__SHIFT EQU 2
PinServoX__AG EQU CYREG_PRT12_AG
PinServoX__BIE EQU CYREG_PRT12_BIE
PinServoX__BIT_MASK EQU CYREG_PRT12_BIT_MASK
PinServoX__BYP EQU CYREG_PRT12_BYP
PinServoX__DM0 EQU CYREG_PRT12_DM0
PinServoX__DM1 EQU CYREG_PRT12_DM1
PinServoX__DM2 EQU CYREG_PRT12_DM2
PinServoX__DR EQU CYREG_PRT12_DR
PinServoX__INP_DIS EQU CYREG_PRT12_INP_DIS
PinServoX__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
PinServoX__MASK EQU 0x04
PinServoX__PORT EQU 12
PinServoX__PRT EQU CYREG_PRT12_PRT
PinServoX__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
PinServoX__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
PinServoX__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
PinServoX__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
PinServoX__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
PinServoX__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
PinServoX__PS EQU CYREG_PRT12_PS
PinServoX__SHIFT EQU 2
PinServoX__SIO_CFG EQU CYREG_PRT12_SIO_CFG
PinServoX__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
PinServoX__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
PinServoX__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
PinServoX__SLW EQU CYREG_PRT12_SLW

; PinServoY
PinServoY__0__INTTYPE EQU CYREG_PICU12_INTTYPE3
PinServoY__0__MASK EQU 0x08
PinServoY__0__PC EQU CYREG_PRT12_PC3
PinServoY__0__PORT EQU 12
PinServoY__0__SHIFT EQU 3
PinServoY__AG EQU CYREG_PRT12_AG
PinServoY__BIE EQU CYREG_PRT12_BIE
PinServoY__BIT_MASK EQU CYREG_PRT12_BIT_MASK
PinServoY__BYP EQU CYREG_PRT12_BYP
PinServoY__DM0 EQU CYREG_PRT12_DM0
PinServoY__DM1 EQU CYREG_PRT12_DM1
PinServoY__DM2 EQU CYREG_PRT12_DM2
PinServoY__DR EQU CYREG_PRT12_DR
PinServoY__INP_DIS EQU CYREG_PRT12_INP_DIS
PinServoY__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU12_BASE
PinServoY__MASK EQU 0x08
PinServoY__PORT EQU 12
PinServoY__PRT EQU CYREG_PRT12_PRT
PinServoY__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
PinServoY__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
PinServoY__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
PinServoY__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
PinServoY__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
PinServoY__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
PinServoY__PS EQU CYREG_PRT12_PS
PinServoY__SHIFT EQU 3
PinServoY__SIO_CFG EQU CYREG_PRT12_SIO_CFG
PinServoY__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
PinServoY__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
PinServoY__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
PinServoY__SLW EQU CYREG_PRT12_SLW

; X_interrupcion
X_interrupcion__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
X_interrupcion__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
X_interrupcion__INTC_MASK EQU 0x01
X_interrupcion__INTC_NUMBER EQU 0
X_interrupcion__INTC_PRIOR_NUM EQU 7
X_interrupcion__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
X_interrupcion__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
X_interrupcion__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; Y_interrupcion
Y_interrupcion__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
Y_interrupcion__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
Y_interrupcion__INTC_MASK EQU 0x02
Y_interrupcion__INTC_NUMBER EQU 1
Y_interrupcion__INTC_PRIOR_NUM EQU 7
Y_interrupcion__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_1
Y_interrupcion__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
Y_interrupcion__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; ClockServoControl
ClockServoControl__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
ClockServoControl__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
ClockServoControl__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
ClockServoControl__CFG2_SRC_SEL_MASK EQU 0x07
ClockServoControl__INDEX EQU 0x01
ClockServoControl__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
ClockServoControl__PM_ACT_MSK EQU 0x02
ClockServoControl__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
ClockServoControl__PM_STBY_MSK EQU 0x02

; Miscellaneous
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 18
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E123069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 18
CYDEV_CHIP_MEMBER_4D EQU 13
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 19
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 17
CYDEV_CHIP_MEMBER_4I EQU 23
CYDEV_CHIP_MEMBER_4J EQU 14
CYDEV_CHIP_MEMBER_4K EQU 15
CYDEV_CHIP_MEMBER_4L EQU 22
CYDEV_CHIP_MEMBER_4M EQU 21
CYDEV_CHIP_MEMBER_4N EQU 10
CYDEV_CHIP_MEMBER_4O EQU 7
CYDEV_CHIP_MEMBER_4P EQU 20
CYDEV_CHIP_MEMBER_4Q EQU 12
CYDEV_CHIP_MEMBER_4R EQU 8
CYDEV_CHIP_MEMBER_4S EQU 11
CYDEV_CHIP_MEMBER_4T EQU 9
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 16
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 24
CYDEV_CHIP_MEMBER_FM3 EQU 28
CYDEV_CHIP_MEMBER_FM4 EQU 29
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 25
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 26
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 27
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000003
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END
