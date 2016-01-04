/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 * This file was automatically generated by headergen, DO NOT EDIT it.
 * headergen version: 2.1.8
 * XML versions: stmp3700:3.2.0
 *
 * Copyright (C) 2013 by Amaury Pouly
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/
#ifndef __HEADERGEN__STMP3700__AUDIOOUT__H__
#define __HEADERGEN__STMP3700__AUDIOOUT__H__

#define REGS_AUDIOOUT_BASE (0x80048000)

#define REGS_AUDIOOUT_VERSION "3.2.0"

/**
 * Register: HW_AUDIOOUT_CTRL
 * Address: 0
 * SCT: yes
*/
#define HW_AUDIOOUT_CTRL                        (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x0 + 0x0))
#define HW_AUDIOOUT_CTRL_SET                    (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x0 + 0x4))
#define HW_AUDIOOUT_CTRL_CLR                    (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x0 + 0x8))
#define HW_AUDIOOUT_CTRL_TOG                    (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x0 + 0xc))
#define BP_AUDIOOUT_CTRL_SFTRST                 31
#define BM_AUDIOOUT_CTRL_SFTRST                 0x80000000
#define BF_AUDIOOUT_CTRL_SFTRST(v)              (((v) << 31) & 0x80000000)
#define BP_AUDIOOUT_CTRL_CLKGATE                30
#define BM_AUDIOOUT_CTRL_CLKGATE                0x40000000
#define BF_AUDIOOUT_CTRL_CLKGATE(v)             (((v) << 30) & 0x40000000)
#define BP_AUDIOOUT_CTRL_DMAWAIT_COUNT          16
#define BM_AUDIOOUT_CTRL_DMAWAIT_COUNT          0x1f0000
#define BF_AUDIOOUT_CTRL_DMAWAIT_COUNT(v)       (((v) << 16) & 0x1f0000)
#define BP_AUDIOOUT_CTRL_LR_SWAP                14
#define BM_AUDIOOUT_CTRL_LR_SWAP                0x4000
#define BF_AUDIOOUT_CTRL_LR_SWAP(v)             (((v) << 14) & 0x4000)
#define BP_AUDIOOUT_CTRL_EDGE_SYNC              13
#define BM_AUDIOOUT_CTRL_EDGE_SYNC              0x2000
#define BF_AUDIOOUT_CTRL_EDGE_SYNC(v)           (((v) << 13) & 0x2000)
#define BP_AUDIOOUT_CTRL_INVERT_1BIT            12
#define BM_AUDIOOUT_CTRL_INVERT_1BIT            0x1000
#define BF_AUDIOOUT_CTRL_INVERT_1BIT(v)         (((v) << 12) & 0x1000)
#define BP_AUDIOOUT_CTRL_SS3D_EFFECT            8
#define BM_AUDIOOUT_CTRL_SS3D_EFFECT            0x300
#define BF_AUDIOOUT_CTRL_SS3D_EFFECT(v)         (((v) << 8) & 0x300)
#define BP_AUDIOOUT_CTRL_WORD_LENGTH            6
#define BM_AUDIOOUT_CTRL_WORD_LENGTH            0x40
#define BF_AUDIOOUT_CTRL_WORD_LENGTH(v)         (((v) << 6) & 0x40)
#define BP_AUDIOOUT_CTRL_DAC_ZERO_ENABLE        5
#define BM_AUDIOOUT_CTRL_DAC_ZERO_ENABLE        0x20
#define BF_AUDIOOUT_CTRL_DAC_ZERO_ENABLE(v)     (((v) << 5) & 0x20)
#define BP_AUDIOOUT_CTRL_LOOPBACK               4
#define BM_AUDIOOUT_CTRL_LOOPBACK               0x10
#define BF_AUDIOOUT_CTRL_LOOPBACK(v)            (((v) << 4) & 0x10)
#define BP_AUDIOOUT_CTRL_FIFO_UNDERFLOW_IRQ     3
#define BM_AUDIOOUT_CTRL_FIFO_UNDERFLOW_IRQ     0x8
#define BF_AUDIOOUT_CTRL_FIFO_UNDERFLOW_IRQ(v)  (((v) << 3) & 0x8)
#define BP_AUDIOOUT_CTRL_FIFO_OVERFLOW_IRQ      2
#define BM_AUDIOOUT_CTRL_FIFO_OVERFLOW_IRQ      0x4
#define BF_AUDIOOUT_CTRL_FIFO_OVERFLOW_IRQ(v)   (((v) << 2) & 0x4)
#define BP_AUDIOOUT_CTRL_FIFO_ERROR_IRQ_EN      1
#define BM_AUDIOOUT_CTRL_FIFO_ERROR_IRQ_EN      0x2
#define BF_AUDIOOUT_CTRL_FIFO_ERROR_IRQ_EN(v)   (((v) << 1) & 0x2)
#define BP_AUDIOOUT_CTRL_RUN                    0
#define BM_AUDIOOUT_CTRL_RUN                    0x1
#define BF_AUDIOOUT_CTRL_RUN(v)                 (((v) << 0) & 0x1)

/**
 * Register: HW_AUDIOOUT_STAT
 * Address: 0x10
 * SCT: no
*/
#define HW_AUDIOOUT_STAT                (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x10))
#define BP_AUDIOOUT_STAT_DAC_PRESENT    31
#define BM_AUDIOOUT_STAT_DAC_PRESENT    0x80000000
#define BF_AUDIOOUT_STAT_DAC_PRESENT(v) (((v) << 31) & 0x80000000)

/**
 * Register: HW_AUDIOOUT_DACSRR
 * Address: 0x20
 * SCT: yes
*/
#define HW_AUDIOOUT_DACSRR                          (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x20 + 0x0))
#define HW_AUDIOOUT_DACSRR_SET                      (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x20 + 0x4))
#define HW_AUDIOOUT_DACSRR_CLR                      (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x20 + 0x8))
#define HW_AUDIOOUT_DACSRR_TOG                      (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x20 + 0xc))
#define BP_AUDIOOUT_DACSRR_OSR                      31
#define BM_AUDIOOUT_DACSRR_OSR                      0x80000000
#define BV_AUDIOOUT_DACSRR_OSR__OSR6                0x0
#define BV_AUDIOOUT_DACSRR_OSR__OSR12               0x1
#define BF_AUDIOOUT_DACSRR_OSR(v)                   (((v) << 31) & 0x80000000)
#define BF_AUDIOOUT_DACSRR_OSR_V(v)                 ((BV_AUDIOOUT_DACSRR_OSR__##v << 31) & 0x80000000)
#define BP_AUDIOOUT_DACSRR_BASEMULT                 28
#define BM_AUDIOOUT_DACSRR_BASEMULT                 0x70000000
#define BV_AUDIOOUT_DACSRR_BASEMULT__SINGLE_RATE    0x1
#define BV_AUDIOOUT_DACSRR_BASEMULT__DOUBLE_RATE    0x2
#define BV_AUDIOOUT_DACSRR_BASEMULT__QUAD_RATE      0x4
#define BF_AUDIOOUT_DACSRR_BASEMULT(v)              (((v) << 28) & 0x70000000)
#define BF_AUDIOOUT_DACSRR_BASEMULT_V(v)            ((BV_AUDIOOUT_DACSRR_BASEMULT__##v << 28) & 0x70000000)
#define BP_AUDIOOUT_DACSRR_SRC_HOLD                 24
#define BM_AUDIOOUT_DACSRR_SRC_HOLD                 0x7000000
#define BF_AUDIOOUT_DACSRR_SRC_HOLD(v)              (((v) << 24) & 0x7000000)
#define BP_AUDIOOUT_DACSRR_SRC_INT                  16
#define BM_AUDIOOUT_DACSRR_SRC_INT                  0x1f0000
#define BF_AUDIOOUT_DACSRR_SRC_INT(v)               (((v) << 16) & 0x1f0000)
#define BP_AUDIOOUT_DACSRR_SRC_FRAC                 0
#define BM_AUDIOOUT_DACSRR_SRC_FRAC                 0x1fff
#define BF_AUDIOOUT_DACSRR_SRC_FRAC(v)              (((v) << 0) & 0x1fff)

/**
 * Register: HW_AUDIOOUT_DACVOLUME
 * Address: 0x30
 * SCT: yes
*/
#define HW_AUDIOOUT_DACVOLUME                           (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x30 + 0x0))
#define HW_AUDIOOUT_DACVOLUME_SET                       (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x30 + 0x4))
#define HW_AUDIOOUT_DACVOLUME_CLR                       (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x30 + 0x8))
#define HW_AUDIOOUT_DACVOLUME_TOG                       (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x30 + 0xc))
#define BP_AUDIOOUT_DACVOLUME_VOLUME_UPDATE_LEFT        28
#define BM_AUDIOOUT_DACVOLUME_VOLUME_UPDATE_LEFT        0x10000000
#define BF_AUDIOOUT_DACVOLUME_VOLUME_UPDATE_LEFT(v)     (((v) << 28) & 0x10000000)
#define BP_AUDIOOUT_DACVOLUME_EN_ZCD                    25
#define BM_AUDIOOUT_DACVOLUME_EN_ZCD                    0x2000000
#define BF_AUDIOOUT_DACVOLUME_EN_ZCD(v)                 (((v) << 25) & 0x2000000)
#define BP_AUDIOOUT_DACVOLUME_MUTE_LEFT                 24
#define BM_AUDIOOUT_DACVOLUME_MUTE_LEFT                 0x1000000
#define BF_AUDIOOUT_DACVOLUME_MUTE_LEFT(v)              (((v) << 24) & 0x1000000)
#define BP_AUDIOOUT_DACVOLUME_VOLUME_LEFT               16
#define BM_AUDIOOUT_DACVOLUME_VOLUME_LEFT               0xff0000
#define BF_AUDIOOUT_DACVOLUME_VOLUME_LEFT(v)            (((v) << 16) & 0xff0000)
#define BP_AUDIOOUT_DACVOLUME_VOLUME_UPDATE_RIGHT       12
#define BM_AUDIOOUT_DACVOLUME_VOLUME_UPDATE_RIGHT       0x1000
#define BF_AUDIOOUT_DACVOLUME_VOLUME_UPDATE_RIGHT(v)    (((v) << 12) & 0x1000)
#define BP_AUDIOOUT_DACVOLUME_MUTE_RIGHT                8
#define BM_AUDIOOUT_DACVOLUME_MUTE_RIGHT                0x100
#define BF_AUDIOOUT_DACVOLUME_MUTE_RIGHT(v)             (((v) << 8) & 0x100)
#define BP_AUDIOOUT_DACVOLUME_VOLUME_RIGHT              0
#define BM_AUDIOOUT_DACVOLUME_VOLUME_RIGHT              0xff
#define BF_AUDIOOUT_DACVOLUME_VOLUME_RIGHT(v)           (((v) << 0) & 0xff)

/**
 * Register: HW_AUDIOOUT_DACDEBUG
 * Address: 0x40
 * SCT: yes
*/
#define HW_AUDIOOUT_DACDEBUG                                (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x40 + 0x0))
#define HW_AUDIOOUT_DACDEBUG_SET                            (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x40 + 0x4))
#define HW_AUDIOOUT_DACDEBUG_CLR                            (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x40 + 0x8))
#define HW_AUDIOOUT_DACDEBUG_TOG                            (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x40 + 0xc))
#define BP_AUDIOOUT_DACDEBUG_ENABLE_DACDMA                  31
#define BM_AUDIOOUT_DACDEBUG_ENABLE_DACDMA                  0x80000000
#define BF_AUDIOOUT_DACDEBUG_ENABLE_DACDMA(v)               (((v) << 31) & 0x80000000)
#define BP_AUDIOOUT_DACDEBUG_RAM_SS                         8
#define BM_AUDIOOUT_DACDEBUG_RAM_SS                         0xf00
#define BF_AUDIOOUT_DACDEBUG_RAM_SS(v)                      (((v) << 8) & 0xf00)
#define BP_AUDIOOUT_DACDEBUG_SET_INTERRUPT1_CLK_CROSS       5
#define BM_AUDIOOUT_DACDEBUG_SET_INTERRUPT1_CLK_CROSS       0x20
#define BF_AUDIOOUT_DACDEBUG_SET_INTERRUPT1_CLK_CROSS(v)    (((v) << 5) & 0x20)
#define BP_AUDIOOUT_DACDEBUG_SET_INTERRUPT0_CLK_CROSS       4
#define BM_AUDIOOUT_DACDEBUG_SET_INTERRUPT0_CLK_CROSS       0x10
#define BF_AUDIOOUT_DACDEBUG_SET_INTERRUPT0_CLK_CROSS(v)    (((v) << 4) & 0x10)
#define BP_AUDIOOUT_DACDEBUG_SET_INTERRUPT1_HAND_SHAKE      3
#define BM_AUDIOOUT_DACDEBUG_SET_INTERRUPT1_HAND_SHAKE      0x8
#define BF_AUDIOOUT_DACDEBUG_SET_INTERRUPT1_HAND_SHAKE(v)   (((v) << 3) & 0x8)
#define BP_AUDIOOUT_DACDEBUG_SET_INTERRUPT0_HAND_SHAKE      2
#define BM_AUDIOOUT_DACDEBUG_SET_INTERRUPT0_HAND_SHAKE      0x4
#define BF_AUDIOOUT_DACDEBUG_SET_INTERRUPT0_HAND_SHAKE(v)   (((v) << 2) & 0x4)
#define BP_AUDIOOUT_DACDEBUG_DMA_PREQ                       1
#define BM_AUDIOOUT_DACDEBUG_DMA_PREQ                       0x2
#define BF_AUDIOOUT_DACDEBUG_DMA_PREQ(v)                    (((v) << 1) & 0x2)
#define BP_AUDIOOUT_DACDEBUG_FIFO_STATUS                    0
#define BM_AUDIOOUT_DACDEBUG_FIFO_STATUS                    0x1
#define BF_AUDIOOUT_DACDEBUG_FIFO_STATUS(v)                 (((v) << 0) & 0x1)

/**
 * Register: HW_AUDIOOUT_HPVOL
 * Address: 0x50
 * SCT: yes
*/
#define HW_AUDIOOUT_HPVOL                           (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x50 + 0x0))
#define HW_AUDIOOUT_HPVOL_SET                       (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x50 + 0x4))
#define HW_AUDIOOUT_HPVOL_CLR                       (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x50 + 0x8))
#define HW_AUDIOOUT_HPVOL_TOG                       (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x50 + 0xc))
#define BP_AUDIOOUT_HPVOL_VOLUME_UPDATE_PENDING     28
#define BM_AUDIOOUT_HPVOL_VOLUME_UPDATE_PENDING     0x10000000
#define BF_AUDIOOUT_HPVOL_VOLUME_UPDATE_PENDING(v)  (((v) << 28) & 0x10000000)
#define BP_AUDIOOUT_HPVOL_EN_MSTR_ZCD               25
#define BM_AUDIOOUT_HPVOL_EN_MSTR_ZCD               0x2000000
#define BF_AUDIOOUT_HPVOL_EN_MSTR_ZCD(v)            (((v) << 25) & 0x2000000)
#define BP_AUDIOOUT_HPVOL_MUTE                      24
#define BM_AUDIOOUT_HPVOL_MUTE                      0x1000000
#define BF_AUDIOOUT_HPVOL_MUTE(v)                   (((v) << 24) & 0x1000000)
#define BP_AUDIOOUT_HPVOL_SELECT                    16
#define BM_AUDIOOUT_HPVOL_SELECT                    0x10000
#define BF_AUDIOOUT_HPVOL_SELECT(v)                 (((v) << 16) & 0x10000)
#define BP_AUDIOOUT_HPVOL_VOL_LEFT                  8
#define BM_AUDIOOUT_HPVOL_VOL_LEFT                  0x7f00
#define BF_AUDIOOUT_HPVOL_VOL_LEFT(v)               (((v) << 8) & 0x7f00)
#define BP_AUDIOOUT_HPVOL_VOL_RIGHT                 0
#define BM_AUDIOOUT_HPVOL_VOL_RIGHT                 0x7f
#define BF_AUDIOOUT_HPVOL_VOL_RIGHT(v)              (((v) << 0) & 0x7f)

/**
 * Register: HW_AUDIOOUT_RESERVED
 * Address: 0x60
 * SCT: no
*/
#define HW_AUDIOOUT_RESERVED    (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x60))

/**
 * Register: HW_AUDIOOUT_PWRDN
 * Address: 0x70
 * SCT: yes
*/
#define HW_AUDIOOUT_PWRDN               (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x70 + 0x0))
#define HW_AUDIOOUT_PWRDN_SET           (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x70 + 0x4))
#define HW_AUDIOOUT_PWRDN_CLR           (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x70 + 0x8))
#define HW_AUDIOOUT_PWRDN_TOG           (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x70 + 0xc))
#define BP_AUDIOOUT_PWRDN_LINEOUT       24
#define BM_AUDIOOUT_PWRDN_LINEOUT       0x1000000
#define BF_AUDIOOUT_PWRDN_LINEOUT(v)    (((v) << 24) & 0x1000000)
#define BP_AUDIOOUT_PWRDN_SELFBIAS      20
#define BM_AUDIOOUT_PWRDN_SELFBIAS      0x100000
#define BF_AUDIOOUT_PWRDN_SELFBIAS(v)   (((v) << 20) & 0x100000)
#define BP_AUDIOOUT_PWRDN_RIGHT_ADC     16
#define BM_AUDIOOUT_PWRDN_RIGHT_ADC     0x10000
#define BF_AUDIOOUT_PWRDN_RIGHT_ADC(v)  (((v) << 16) & 0x10000)
#define BP_AUDIOOUT_PWRDN_DAC           12
#define BM_AUDIOOUT_PWRDN_DAC           0x1000
#define BF_AUDIOOUT_PWRDN_DAC(v)        (((v) << 12) & 0x1000)
#define BP_AUDIOOUT_PWRDN_ADC           8
#define BM_AUDIOOUT_PWRDN_ADC           0x100
#define BF_AUDIOOUT_PWRDN_ADC(v)        (((v) << 8) & 0x100)
#define BP_AUDIOOUT_PWRDN_CAPLESS       4
#define BM_AUDIOOUT_PWRDN_CAPLESS       0x10
#define BF_AUDIOOUT_PWRDN_CAPLESS(v)    (((v) << 4) & 0x10)
#define BP_AUDIOOUT_PWRDN_HEADPHONE     0
#define BM_AUDIOOUT_PWRDN_HEADPHONE     0x1
#define BF_AUDIOOUT_PWRDN_HEADPHONE(v)  (((v) << 0) & 0x1)

/**
 * Register: HW_AUDIOOUT_REFCTRL
 * Address: 0x80
 * SCT: yes
*/
#define HW_AUDIOOUT_REFCTRL                     (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x80 + 0x0))
#define HW_AUDIOOUT_REFCTRL_SET                 (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x80 + 0x4))
#define HW_AUDIOOUT_REFCTRL_CLR                 (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x80 + 0x8))
#define HW_AUDIOOUT_REFCTRL_TOG                 (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x80 + 0xc))
#define BP_AUDIOOUT_REFCTRL_FASTSETTLING        26
#define BM_AUDIOOUT_REFCTRL_FASTSETTLING        0x4000000
#define BF_AUDIOOUT_REFCTRL_FASTSETTLING(v)     (((v) << 26) & 0x4000000)
#define BP_AUDIOOUT_REFCTRL_RAISE_REF           25
#define BM_AUDIOOUT_REFCTRL_RAISE_REF           0x2000000
#define BF_AUDIOOUT_REFCTRL_RAISE_REF(v)        (((v) << 25) & 0x2000000)
#define BP_AUDIOOUT_REFCTRL_XTAL_BGR_BIAS       24
#define BM_AUDIOOUT_REFCTRL_XTAL_BGR_BIAS       0x1000000
#define BF_AUDIOOUT_REFCTRL_XTAL_BGR_BIAS(v)    (((v) << 24) & 0x1000000)
#define BP_AUDIOOUT_REFCTRL_VBG_ADJ             20
#define BM_AUDIOOUT_REFCTRL_VBG_ADJ             0x700000
#define BF_AUDIOOUT_REFCTRL_VBG_ADJ(v)          (((v) << 20) & 0x700000)
#define BP_AUDIOOUT_REFCTRL_LOW_PWR             19
#define BM_AUDIOOUT_REFCTRL_LOW_PWR             0x80000
#define BF_AUDIOOUT_REFCTRL_LOW_PWR(v)          (((v) << 19) & 0x80000)
#define BP_AUDIOOUT_REFCTRL_LW_REF              18
#define BM_AUDIOOUT_REFCTRL_LW_REF              0x40000
#define BF_AUDIOOUT_REFCTRL_LW_REF(v)           (((v) << 18) & 0x40000)
#define BP_AUDIOOUT_REFCTRL_BIAS_CTRL           16
#define BM_AUDIOOUT_REFCTRL_BIAS_CTRL           0x30000
#define BF_AUDIOOUT_REFCTRL_BIAS_CTRL(v)        (((v) << 16) & 0x30000)
#define BP_AUDIOOUT_REFCTRL_VDDXTAL_TO_VDDD     14
#define BM_AUDIOOUT_REFCTRL_VDDXTAL_TO_VDDD     0x4000
#define BF_AUDIOOUT_REFCTRL_VDDXTAL_TO_VDDD(v)  (((v) << 14) & 0x4000)
#define BP_AUDIOOUT_REFCTRL_ADJ_ADC             13
#define BM_AUDIOOUT_REFCTRL_ADJ_ADC             0x2000
#define BF_AUDIOOUT_REFCTRL_ADJ_ADC(v)          (((v) << 13) & 0x2000)
#define BP_AUDIOOUT_REFCTRL_ADJ_VAG             12
#define BM_AUDIOOUT_REFCTRL_ADJ_VAG             0x1000
#define BF_AUDIOOUT_REFCTRL_ADJ_VAG(v)          (((v) << 12) & 0x1000)
#define BP_AUDIOOUT_REFCTRL_ADC_REFVAL          8
#define BM_AUDIOOUT_REFCTRL_ADC_REFVAL          0xf00
#define BF_AUDIOOUT_REFCTRL_ADC_REFVAL(v)       (((v) << 8) & 0xf00)
#define BP_AUDIOOUT_REFCTRL_VAG_VAL             4
#define BM_AUDIOOUT_REFCTRL_VAG_VAL             0xf0
#define BF_AUDIOOUT_REFCTRL_VAG_VAL(v)          (((v) << 4) & 0xf0)
#define BP_AUDIOOUT_REFCTRL_DAC_ADJ             0
#define BM_AUDIOOUT_REFCTRL_DAC_ADJ             0x7
#define BF_AUDIOOUT_REFCTRL_DAC_ADJ(v)          (((v) << 0) & 0x7)

/**
 * Register: HW_AUDIOOUT_ANACTRL
 * Address: 0x90
 * SCT: yes
*/
#define HW_AUDIOOUT_ANACTRL                     (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x90 + 0x0))
#define HW_AUDIOOUT_ANACTRL_SET                 (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x90 + 0x4))
#define HW_AUDIOOUT_ANACTRL_CLR                 (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x90 + 0x8))
#define HW_AUDIOOUT_ANACTRL_TOG                 (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x90 + 0xc))
#define BP_AUDIOOUT_ANACTRL_SHORT_CM_STS        28
#define BM_AUDIOOUT_ANACTRL_SHORT_CM_STS        0x10000000
#define BF_AUDIOOUT_ANACTRL_SHORT_CM_STS(v)     (((v) << 28) & 0x10000000)
#define BP_AUDIOOUT_ANACTRL_SHORT_LR_STS        24
#define BM_AUDIOOUT_ANACTRL_SHORT_LR_STS        0x1000000
#define BF_AUDIOOUT_ANACTRL_SHORT_LR_STS(v)     (((v) << 24) & 0x1000000)
#define BP_AUDIOOUT_ANACTRL_SHORTMODE_CM        20
#define BM_AUDIOOUT_ANACTRL_SHORTMODE_CM        0x300000
#define BF_AUDIOOUT_ANACTRL_SHORTMODE_CM(v)     (((v) << 20) & 0x300000)
#define BP_AUDIOOUT_ANACTRL_SHORTMODE_LR        17
#define BM_AUDIOOUT_ANACTRL_SHORTMODE_LR        0x60000
#define BF_AUDIOOUT_ANACTRL_SHORTMODE_LR(v)     (((v) << 17) & 0x60000)
#define BP_AUDIOOUT_ANACTRL_SHORT_LVLADJL       12
#define BM_AUDIOOUT_ANACTRL_SHORT_LVLADJL       0x7000
#define BF_AUDIOOUT_ANACTRL_SHORT_LVLADJL(v)    (((v) << 12) & 0x7000)
#define BP_AUDIOOUT_ANACTRL_SHORT_LVLADJR       8
#define BM_AUDIOOUT_ANACTRL_SHORT_LVLADJR       0x700
#define BF_AUDIOOUT_ANACTRL_SHORT_LVLADJR(v)    (((v) << 8) & 0x700)
#define BP_AUDIOOUT_ANACTRL_HP_HOLD_GND         5
#define BM_AUDIOOUT_ANACTRL_HP_HOLD_GND         0x20
#define BF_AUDIOOUT_ANACTRL_HP_HOLD_GND(v)      (((v) << 5) & 0x20)
#define BP_AUDIOOUT_ANACTRL_HP_CLASSAB          4
#define BM_AUDIOOUT_ANACTRL_HP_CLASSAB          0x10
#define BF_AUDIOOUT_ANACTRL_HP_CLASSAB(v)       (((v) << 4) & 0x10)

/**
 * Register: HW_AUDIOOUT_TEST
 * Address: 0xa0
 * SCT: yes
*/
#define HW_AUDIOOUT_TEST                    (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xa0 + 0x0))
#define HW_AUDIOOUT_TEST_SET                (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xa0 + 0x4))
#define HW_AUDIOOUT_TEST_CLR                (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xa0 + 0x8))
#define HW_AUDIOOUT_TEST_TOG                (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xa0 + 0xc))
#define BP_AUDIOOUT_TEST_HP_ANTIPOP         28
#define BM_AUDIOOUT_TEST_HP_ANTIPOP         0x70000000
#define BF_AUDIOOUT_TEST_HP_ANTIPOP(v)      (((v) << 28) & 0x70000000)
#define BP_AUDIOOUT_TEST_TM_ADCIN_TOHP      26
#define BM_AUDIOOUT_TEST_TM_ADCIN_TOHP      0x4000000
#define BF_AUDIOOUT_TEST_TM_ADCIN_TOHP(v)   (((v) << 26) & 0x4000000)
#define BP_AUDIOOUT_TEST_TM_LINEOUT         25
#define BM_AUDIOOUT_TEST_TM_LINEOUT         0x2000000
#define BF_AUDIOOUT_TEST_TM_LINEOUT(v)      (((v) << 25) & 0x2000000)
#define BP_AUDIOOUT_TEST_TM_HPCOMMON        24
#define BM_AUDIOOUT_TEST_TM_HPCOMMON        0x1000000
#define BF_AUDIOOUT_TEST_TM_HPCOMMON(v)     (((v) << 24) & 0x1000000)
#define BP_AUDIOOUT_TEST_HP_I1_ADJ          22
#define BM_AUDIOOUT_TEST_HP_I1_ADJ          0xc00000
#define BF_AUDIOOUT_TEST_HP_I1_ADJ(v)       (((v) << 22) & 0xc00000)
#define BP_AUDIOOUT_TEST_HP_IALL_ADJ        20
#define BM_AUDIOOUT_TEST_HP_IALL_ADJ        0x300000
#define BF_AUDIOOUT_TEST_HP_IALL_ADJ(v)     (((v) << 20) & 0x300000)
#define BP_AUDIOOUT_TEST_VAG_CLASSA         13
#define BM_AUDIOOUT_TEST_VAG_CLASSA         0x2000
#define BF_AUDIOOUT_TEST_VAG_CLASSA(v)      (((v) << 13) & 0x2000)
#define BP_AUDIOOUT_TEST_VAG_DOUBLE_I       12
#define BM_AUDIOOUT_TEST_VAG_DOUBLE_I       0x1000
#define BF_AUDIOOUT_TEST_VAG_DOUBLE_I(v)    (((v) << 12) & 0x1000)
#define BP_AUDIOOUT_TEST_DAC_CLASSA         2
#define BM_AUDIOOUT_TEST_DAC_CLASSA         0x4
#define BF_AUDIOOUT_TEST_DAC_CLASSA(v)      (((v) << 2) & 0x4)
#define BP_AUDIOOUT_TEST_DAC_DOUBLE_I       1
#define BM_AUDIOOUT_TEST_DAC_DOUBLE_I       0x2
#define BF_AUDIOOUT_TEST_DAC_DOUBLE_I(v)    (((v) << 1) & 0x2)
#define BP_AUDIOOUT_TEST_DAC_DIS_RTZ        0
#define BM_AUDIOOUT_TEST_DAC_DIS_RTZ        0x1
#define BF_AUDIOOUT_TEST_DAC_DIS_RTZ(v)     (((v) << 0) & 0x1)

/**
 * Register: HW_AUDIOOUT_BISTCTRL
 * Address: 0xb0
 * SCT: yes
*/
#define HW_AUDIOOUT_BISTCTRL            (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xb0 + 0x0))
#define HW_AUDIOOUT_BISTCTRL_SET        (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xb0 + 0x4))
#define HW_AUDIOOUT_BISTCTRL_CLR        (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xb0 + 0x8))
#define HW_AUDIOOUT_BISTCTRL_TOG        (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xb0 + 0xc))
#define BP_AUDIOOUT_BISTCTRL_FAIL       3
#define BM_AUDIOOUT_BISTCTRL_FAIL       0x8
#define BF_AUDIOOUT_BISTCTRL_FAIL(v)    (((v) << 3) & 0x8)
#define BP_AUDIOOUT_BISTCTRL_PASS       2
#define BM_AUDIOOUT_BISTCTRL_PASS       0x4
#define BF_AUDIOOUT_BISTCTRL_PASS(v)    (((v) << 2) & 0x4)
#define BP_AUDIOOUT_BISTCTRL_DONE       1
#define BM_AUDIOOUT_BISTCTRL_DONE       0x2
#define BF_AUDIOOUT_BISTCTRL_DONE(v)    (((v) << 1) & 0x2)
#define BP_AUDIOOUT_BISTCTRL_START      0
#define BM_AUDIOOUT_BISTCTRL_START      0x1
#define BF_AUDIOOUT_BISTCTRL_START(v)   (((v) << 0) & 0x1)

/**
 * Register: HW_AUDIOOUT_BISTSTAT0
 * Address: 0xc0
 * SCT: no
*/
#define HW_AUDIOOUT_BISTSTAT0           (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xc0))
#define BP_AUDIOOUT_BISTSTAT0_DATA      0
#define BM_AUDIOOUT_BISTSTAT0_DATA      0xffffff
#define BF_AUDIOOUT_BISTSTAT0_DATA(v)   (((v) << 0) & 0xffffff)

/**
 * Register: HW_AUDIOOUT_BISTSTAT1
 * Address: 0xd0
 * SCT: no
*/
#define HW_AUDIOOUT_BISTSTAT1           (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xd0))
#define BP_AUDIOOUT_BISTSTAT1_STATE     24
#define BM_AUDIOOUT_BISTSTAT1_STATE     0x1f000000
#define BF_AUDIOOUT_BISTSTAT1_STATE(v)  (((v) << 24) & 0x1f000000)
#define BP_AUDIOOUT_BISTSTAT1_ADDR      0
#define BM_AUDIOOUT_BISTSTAT1_ADDR      0xff
#define BF_AUDIOOUT_BISTSTAT1_ADDR(v)   (((v) << 0) & 0xff)

/**
 * Register: HW_AUDIOOUT_ANACLKCTRL
 * Address: 0xe0
 * SCT: yes
*/
#define HW_AUDIOOUT_ANACLKCTRL                  (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xe0 + 0x0))
#define HW_AUDIOOUT_ANACLKCTRL_SET              (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xe0 + 0x4))
#define HW_AUDIOOUT_ANACLKCTRL_CLR              (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xe0 + 0x8))
#define HW_AUDIOOUT_ANACLKCTRL_TOG              (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xe0 + 0xc))
#define BP_AUDIOOUT_ANACLKCTRL_CLKGATE          31
#define BM_AUDIOOUT_ANACLKCTRL_CLKGATE          0x80000000
#define BF_AUDIOOUT_ANACLKCTRL_CLKGATE(v)       (((v) << 31) & 0x80000000)
#define BP_AUDIOOUT_ANACLKCTRL_INVERT_DACCLK    4
#define BM_AUDIOOUT_ANACLKCTRL_INVERT_DACCLK    0x10
#define BF_AUDIOOUT_ANACLKCTRL_INVERT_DACCLK(v) (((v) << 4) & 0x10)
#define BP_AUDIOOUT_ANACLKCTRL_DACDIV           0
#define BM_AUDIOOUT_ANACLKCTRL_DACDIV           0x7
#define BF_AUDIOOUT_ANACLKCTRL_DACDIV(v)        (((v) << 0) & 0x7)

/**
 * Register: HW_AUDIOOUT_DATA
 * Address: 0xf0
 * SCT: yes
*/
#define HW_AUDIOOUT_DATA            (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xf0 + 0x0))
#define HW_AUDIOOUT_DATA_SET        (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xf0 + 0x4))
#define HW_AUDIOOUT_DATA_CLR        (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xf0 + 0x8))
#define HW_AUDIOOUT_DATA_TOG        (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0xf0 + 0xc))
#define BP_AUDIOOUT_DATA_HIGH       16
#define BM_AUDIOOUT_DATA_HIGH       0xffff0000
#define BF_AUDIOOUT_DATA_HIGH(v)    (((v) << 16) & 0xffff0000)
#define BP_AUDIOOUT_DATA_LOW        0
#define BM_AUDIOOUT_DATA_LOW        0xffff
#define BF_AUDIOOUT_DATA_LOW(v)     (((v) << 0) & 0xffff)

/**
 * Register: HW_AUDIOOUT_LINEOUTCTRL
 * Address: 0x100
 * SCT: yes
*/
#define HW_AUDIOOUT_LINEOUTCTRL                             (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x100 + 0x0))
#define HW_AUDIOOUT_LINEOUTCTRL_SET                         (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x100 + 0x4))
#define HW_AUDIOOUT_LINEOUTCTRL_CLR                         (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x100 + 0x8))
#define HW_AUDIOOUT_LINEOUTCTRL_TOG                         (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x100 + 0xc))
#define BP_AUDIOOUT_LINEOUTCTRL_VOLUME_UPDATE_PENDING       28
#define BM_AUDIOOUT_LINEOUTCTRL_VOLUME_UPDATE_PENDING       0x10000000
#define BF_AUDIOOUT_LINEOUTCTRL_VOLUME_UPDATE_PENDING(v)    (((v) << 28) & 0x10000000)
#define BP_AUDIOOUT_LINEOUTCTRL_EN_LINEOUT_ZCD              25
#define BM_AUDIOOUT_LINEOUTCTRL_EN_LINEOUT_ZCD              0x2000000
#define BF_AUDIOOUT_LINEOUTCTRL_EN_LINEOUT_ZCD(v)           (((v) << 25) & 0x2000000)
#define BP_AUDIOOUT_LINEOUTCTRL_MUTE                        24
#define BM_AUDIOOUT_LINEOUTCTRL_MUTE                        0x1000000
#define BF_AUDIOOUT_LINEOUTCTRL_MUTE(v)                     (((v) << 24) & 0x1000000)
#define BP_AUDIOOUT_LINEOUTCTRL_VAG_CTRL                    20
#define BM_AUDIOOUT_LINEOUTCTRL_VAG_CTRL                    0xf00000
#define BF_AUDIOOUT_LINEOUTCTRL_VAG_CTRL(v)                 (((v) << 20) & 0xf00000)
#define BP_AUDIOOUT_LINEOUTCTRL_OUT_CURRENT                 16
#define BM_AUDIOOUT_LINEOUTCTRL_OUT_CURRENT                 0xf0000
#define BF_AUDIOOUT_LINEOUTCTRL_OUT_CURRENT(v)              (((v) << 16) & 0xf0000)
#define BP_AUDIOOUT_LINEOUTCTRL_CHARGE_CAP                  13
#define BM_AUDIOOUT_LINEOUTCTRL_CHARGE_CAP                  0xe000
#define BF_AUDIOOUT_LINEOUTCTRL_CHARGE_CAP(v)               (((v) << 13) & 0xe000)
#define BP_AUDIOOUT_LINEOUTCTRL_VOLUME_LEFT                 8
#define BM_AUDIOOUT_LINEOUTCTRL_VOLUME_LEFT                 0x1f00
#define BF_AUDIOOUT_LINEOUTCTRL_VOLUME_LEFT(v)              (((v) << 8) & 0x1f00)
#define BP_AUDIOOUT_LINEOUTCTRL_VOLUME_RIGHT                0
#define BM_AUDIOOUT_LINEOUTCTRL_VOLUME_RIGHT                0x1f
#define BF_AUDIOOUT_LINEOUTCTRL_VOLUME_RIGHT(v)             (((v) << 0) & 0x1f)

/**
 * Register: HW_AUDIOOUT_VERSION
 * Address: 0x200
 * SCT: no
*/
#define HW_AUDIOOUT_VERSION             (*(volatile unsigned long *)(REGS_AUDIOOUT_BASE + 0x200))
#define BP_AUDIOOUT_VERSION_MAJOR       24
#define BM_AUDIOOUT_VERSION_MAJOR       0xff000000
#define BF_AUDIOOUT_VERSION_MAJOR(v)    (((v) << 24) & 0xff000000)
#define BP_AUDIOOUT_VERSION_MINOR       16
#define BM_AUDIOOUT_VERSION_MINOR       0xff0000
#define BF_AUDIOOUT_VERSION_MINOR(v)    (((v) << 16) & 0xff0000)
#define BP_AUDIOOUT_VERSION_STEP        0
#define BM_AUDIOOUT_VERSION_STEP        0xffff
#define BF_AUDIOOUT_VERSION_STEP(v)     (((v) << 0) & 0xffff)

#endif /* __HEADERGEN__STMP3700__AUDIOOUT__H__ */
