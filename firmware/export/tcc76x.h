/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 * $Id$
 *
 * Copyright (C) 2007 Dave Chapman
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
#ifndef __TCC77X_H__
#define __TCC77X_H__

#define CACHEALIGN_BITS (5) // FIXME is this right?


/* Generated from datasheet using this plus some manual attention: */
// sed "s/^\([^ ]*\) 0x\([^ ]*\) .* \(0x[0-9A-Fa-f]*\|Unknown\|-\) \(.*\)$/\/* \4 *\/\n#define \1 (*(volatile unsigned long *)0x80000A\2)/" new\ \ 3.txt  > foo

/* Address Allocations for Internal Peripherals (Base = 0x80000000) */

/*
 * 0x000 ~ 0x0FF DAI & CDIF
 */

/* Digital Audio Input Registers, Left and Right */
#define DADI_L0 (*(volatile unsigned long *)0x80000000)
#define DADI_R0 (*(volatile unsigned long *)0x80000004)
#define DADI_L1 (*(volatile unsigned long *)0x80000008)
#define DADI_R1 (*(volatile unsigned long *)0x8000000C)
#define DADI_L2 (*(volatile unsigned long *)0x80000010)
#define DADI_R2 (*(volatile unsigned long *)0x80000014)
#define DADI_L3 (*(volatile unsigned long *)0x80000018)
#define DADI_R3 (*(volatile unsigned long *)0x8000001C)
#define DADI_L(x)  (*(volatile unsigned long *)(0x80000000 + (x) * 8))
#define DADI_R(x)  (*(volatile unsigned long *)(0x80000004 + (x) * 8))

/* Digital Audio Output Registers, Left and Right */
#define DADO_L0 (*(volatile unsigned long *)0x80000020)
#define DADO_R0 (*(volatile unsigned long *)0x80000024)
#define DADO_L1 (*(volatile unsigned long *)0x80000028)
#define DADO_R1 (*(volatile unsigned long *)0x8000002C)
#define DADO_L2 (*(volatile unsigned long *)0x80000030)
#define DADO_R2 (*(volatile unsigned long *)0x80000034)
#define DADO_L3 (*(volatile unsigned long *)0x80000038)
#define DADO_R3 (*(volatile unsigned long *)0x8000003C)
#define DADO_L(x)  (*(volatile unsigned long *)(0x80000020 + (x) * 8))
#define DADO_R(x)  (*(volatile unsigned long *)(0x80000024 + (x) * 8))

/* Digital Audio Mode Register */
#define DAMR (*(volatile unsigned long *)0x80000040)
#define DAMR_EN (1 << 15) /* DAI Master Enable */
#define DAMR_TE (1 << 14) /* DAI Transmitter Enable */
#define DAMR_RE (1 << 13) /* DAI Receiver Enable */
#define DAMR_MD (1 << 12) /* DAI Bus Mode (0 = IIS, 1 = MSB justified) */
#define DAMR_SM (1 << 11) /* DAI System Clock Master Select */
#define DAMR_BM (1 << 10) /* DAI Bit Clock Master Select */
#define DAMR_FM (1 << 9) /* DAI Frame Clock Master Select */
#define DAMR_CC (1 << 8) /* CDIF Clock Select */
#define DAMR_BD_4 (0 << 6) /* DAI Bit Clock Divider select */
#define DAMR_BD_6 (1 << 6)
#define DAMR_BD_8 (2 << 6)
#define DAMR_BD_16 (3 << 6)
#define DAMR_FD_32 (0 << 4) /* DAI Frame Clock Divider select */
#define DAMR_FD_48 (1 << 4)
#define DAMR_FD_64 (2 << 4)
#define DAMR_BP (1 << 3) /* DAI Bit Clock Polarity (0 = positive edge) */
#define DAMR_CM (1 << 2) /* CDIF Monitor Mode */
#define DAMR_MM (1 << 1) /* DAI Monitor Mode */
#define DAMR_LB (1 << 0) /* DAI Loop-back Mode */

/* Digital Audio Volume Control Register */
#define DAVC (*(volatile unsigned long *)0x80000044)

/* CD Digital Audio Input Registers */
#define CDDI_0 (*(volatile unsigned long *)0x80000080)
#define CDDI_1 (*(volatile unsigned long *)0x80000084)
#define CDDI_2 (*(volatile unsigned long *)0x80000088)
#define CDDI_3 (*(volatile unsigned long *)0x8000008C)

/* CD Interface Control Register */
#define CICR (*(volatile unsigned long *)0x80000090)

/*
 * 0x100 ~ 0x1FF Interrupt Controller
 */

/* Interrupt Enable Register */
#define IEN (*(volatile unsigned long *)0x80000100)
/* Set bit to enable interrupt, clear bit to disable */

/* Bit 15 is master enable when RDYIRQEN bit of Miscellaneous
 * Configuration Register is cleared and external bus ready
 * inerrupt when that bit is cleared.
 */
#define MEN_IRQ_MASK (1<<15) /* Master Enable */
#define ALL_IRQ_MASK 0x7FFFF

#define CIF_IRQ_MASK (1<<18) /* Camera Interface interrupt control */
#define I2C_IRQ_MASK (1<<17) /* I2C interrupt control */
#define ADC_IRQ_MASK (1<<16) /* ADC interrupt control */
#define RDY_IRQ_MASK (1<<15) /* External Bus READY interrupt control. This bit is effective only when */
#define TC32_IRQ_MASK (1<<14) /* 32-bit Timer interrupt control */
#define DMA_IRQ_MASK (1<<13) /* DMA interrupt control */
#define LCD_IRQ_MASK (1<<12) /* LCD interrupt control */
#define CDIF_IRQ_MASK (1<<11) /* CDIF interrupt control */
#define UBH_IRQ_MASK (1<<10) /* USB Host interrupt control */
#define GS_IRQ_MASK (1<<9) /* GSIO interrupt control */
#define UB_IRQ_MASK (1<<8) /* USB interrupt control */
#define UT_IRQ_MASK (1<<7) /* UART/IrDA interrupt control */
#define TC_IRQ_MASK (1<<6) /* Timer/Counter interrupt control */
#define I2T_IRQ_MASK (1<<5) /* I2S TX interrupt control */
#define I2R_IRQ_MASK (1<<4) /* I2S RX interrupt control */
#define E3_IRQ_MASK (1<<3) /* External interrupt request 3 control */
#define E2_IRQ_MASK (1<<2) /* External interrupt request 2 control */
#define E1_IRQ_MASK (1<<1) /* External interrupt request 1 control */
#define E0_IRQ_MASK (1<<0) /* External interrupt request 0 control */

#define DAI_RX_IRQ_MASK  I2R_IRQ_MASK
#define DAI_TX_IRQ_MASK  I2T_IRQ_MASK

/* Clear Interrupt Request Register */
#define CREQ (*(volatile unsigned long *)0x80000104)
/* Interrupt Request Flag Register */
#define IREQ (*(volatile unsigned long *)0x80000108)
/* IRQ/FIQ Select Register */
#define IRQSEL (*(volatile unsigned long *)0x8000010C)
/* External interrupt configuration register */
#define ICFG (*(volatile unsigned long *)0x80000110)
/* Masked interrupt request flag register */
#define MREQ (*(volatile unsigned long *)0x80000114)
/* Test Mode Register (must be remained zero) */
#define TSTREQ (*(volatile unsigned long *)0x80000118)
/* IRQ Raw Status (IREQ & IRQSEL) */
#define IRQ (*(volatile unsigned long *)0x80000120)
/* FIQ Raw Status (~IREQ & IRQSEL) */
#define FIQ (*(volatile unsigned long *)0x80000124)
/* Masked IRQ Status (IRQ & IEN) */
#define MIRQ (*(volatile unsigned long *)0x80000128)
/* Masked FIQ Status (FIQ & IEN) */
#define MFIQ (*(volatile unsigned long *)0x8000012C)
/* Trigger Mode (0: edge, 1:level) */
#define TMODE (*(volatile unsigned long *)0x80000130)
/* Synchronizer Control */
#define SYNC (*(volatile unsigned long *)0x80000134)
/* Wakeup Control */
#define WKUP (*(volatile unsigned long *)0x80000138)

/*
 * 0x200 ~ 0x2FF Timer Counter
 */

/* Timer/Counter 0 Configuration Register */
#define TCFG0 (*(volatile unsigned short *)0x80000200)
/* Timer/Counter 0 Counter Register */
#define TCNT0 (*(volatile unsigned long *)0x80000204)
/* Timer/Counter 0 Reference Register */
#define TREF0 (*(volatile unsigned long *)0x80000208)
/* Timer/Counter 0 Middle Reference Register */
#define TMREF0 (*(volatile unsigned long *)0x8000020C)
/* Timer/Counter 1 Configuration Register */
#define TCFG1 (*(volatile unsigned short *)0x80000210)
/* Timer/Counter 1 Counter Register */
#define TCNT1 (*(volatile unsigned long *)0x80000214)
/* Timer/Counter 1 Reference Register */
#define TREF1 (*(volatile unsigned long *)0x80000218)
/* Timer/Counter 1 Middle Reference Register */
#define TMREF1 (*(volatile unsigned long *)0x8000021C)
/* Timer/Counter 2 Configuration Register */
#define TCFG2 (*(volatile unsigned short *)0x80000220)
/* Timer/Counter 2 Counter Register */
#define TCNT2 (*(volatile unsigned long *)0x80000224)
/* Timer/Counter 2 Reference Register */
#define TREF2 (*(volatile unsigned long *)0x80000228)
/* Timer/Counter 2 Middle Reference Register */
#define TMREF2 (*(volatile unsigned long *)0x8000022C)
/* Timer/Counter 3 Configuration Register */
#define TCFG3 (*(volatile unsigned short *)0x80000230)
/* Timer/Counter 3 Counter Register */
#define TCNT3 (*(volatile unsigned long *)0x80000234)
/* Timer/Counter 3 Reference Register */
#define TREF3 (*(volatile unsigned long *)0x80000238)
/* Timer/Counter 3 Middle Reference Register */
#define TMREF3 (*(volatile unsigned long *)0x8000023C)
/* Timer/Counter 4 Configuration Register */
#define TCFG4 (*(volatile unsigned short *)0x80000240)
/* Timer/Counter 4 Counter Register */
#define TCNT4 (*(volatile unsigned long *)0x80000244)
/* Timer/Counter 4 Reference Register */
#define TREF4 (*(volatile unsigned long *)0x80000248)
/* Timer/Counter 5 Configuration Register */
#define TCFG5 (*(volatile unsigned short *)0x80000250)
/* Timer/Counter 5 Counter Register */
#define TCNT5 (*(volatile unsigned long *)0x80000254)
/* Timer/Counter 5 Reference Register */
#define TREF5 (*(volatile unsigned long *)0x80000258)
/* Timer/Counter n Interrupt Request Register */
#define TIREQ (*(volatile unsigned short *)0x80000260)

/* TIREQ flags */
#define TF0 (1<<8) /* Timer 0 reference value reached */
#define TF1 (1<<9) /* Timer 1 reference value reached */
#define TI0 (1<<0) /* Timer 0 IRQ flag */
#define TI1 (1<<1) /* Timer 1 IRQ flag */

/* Watchdog Timer Configuration Register */
#define TWDCFG (*(volatile unsigned short *)0x80000270)
/* Watchdog Timer Clear Register */
#define TWDCLR (*(volatile unsigned short *)0x80000274)
/* 32-bit Counter Enable / Pre-scale Value */
#define TC32EN (*(volatile unsigned long *)0x80000280)
/* 32-bit Counter Load Value */
#define TC32LDV (*(volatile unsigned long *)0x80000284)
/* 32-bit Counter Match Value 0 */
#define TC32CMP0 (*(volatile unsigned long *)0x80000288)
/* 32-bit Counter Match Value 1 */
#define TC32CMP1 (*(volatile unsigned long *)0x8000028C)
/* 32-bit Counter Current Value (pre-scale counter) */
#define TC32PCNT (*(volatile unsigned long *)0x80000290)
/* 32-bit Counter Current Value (main counter) */
#define TC32MCNT (*(volatile unsigned long *)0x80000294)
/* 32-bit Counter Interrupt Control Register */
#define TC32IRQ (*(volatile unsigned long *)0x80000298)

/*
 * 0x300 ~ 0x3FF GPIO
 */

/* GPIO_A Data Register */
#define GPIOA (*(volatile unsigned long *)0x80000300)
/* GPIO_A Direction Control Register */
#define GPIOA_DIR (*(volatile unsigned long *)0x80000304)
/* GPIO_A Function Select Register 1 */
#define GSEL_A (*(volatile unsigned long *)0x80000308)
/* GPIO_A Function Select Register 2 */
#define GTSEL_A (*(volatile unsigned long *)0x8000030C)
/* GPIO_B Data Register */
#define GPIOB (*(volatile unsigned long *)0x80000310)
/* GPIO_B Direction Control Register */
#define GPIOB_DIR (*(volatile unsigned long *)0x80000314)
/* GPIO_B Function Select Register 1 */
#define GSEL_B (*(volatile unsigned long *)0x80000318)
/* GPIO_B Function Select Register 2 */
#define GTSEL_B (*(volatile unsigned long *)0x8000031C)
/* GPIO_C Data Register */
#define GPIOC (*(volatile unsigned long *)0x80000320)
/* GPIO_C Direction Control Register */
#define GPIOC_DIR (*(volatile unsigned long *)0x80000324)
/* GPIO_D Data Register */
#define GPIOD (*(volatile unsigned long *)0x80000330)
/* GPIO_D Direction Control Register */
#define GPIOD_DIR (*(volatile unsigned long *)0x80000334)

/*
 * 0x400 ~ 0x4FF Clock Generator & Power Management
 */

/* Clock Control Register:  set bits to disable clocks */
#define CKCTRL (*(volatile unsigned long *)0x80000400)
#define CKCTRL_PDN (1 << 25) /* All blocks */
#define CKCTRL_IDLE (1 << 24) /* CPU */
#define CKCTRL_CIF (1 << 14)
#define CKCTRL_ADC (1 << 13)
#define CKCTRL_XTIN (1 << 12)
#define CKCTRL_PLL (1 << 11)
#define CKCTRL_UBH (1 << 10) /* USB Host */
#define CKCTRL_GCK (1 << 9) /* GSIO */
#define CKCTRL_TCK (1 << 8) /* Timer */
#define CKCTRL_LCK (1 << 7) /* LCD */
#define CKCTRL_USB (1 << 6) /* USB */
#define CKCTRL_UART (1 << 5)
#define CKCTRL_EX1 (1 << 4) /* EXT1 */
#define CKCTRL_EX2 (1 << 3) /* EXT2 (I2C) */
#define CKCTRL_DAI (1 << 1)

/* PLL Control Register */
#define PLLMODE (*(volatile unsigned long *)0x80000404)
#define PLLMODE_LOCK (1 << 20)
#define PLLMODE_XTE (1 << 19) /* XTIN Enable in Power Down Mode */
#define PLLMODE_DIV1 (1 << 18) /* Set to use PLL to clock CPU */
/* Values defining PLL speed: fPLL = fXin * 8 * (M + 2) / ((P + 2) * 2**S ) */
#define PLLMODE_VAL(p,m,s) ((p)|((m)<<8)|((s)<<16))

/* System Clock Control Register */
#define SCLKmode (*(volatile unsigned long *)0x80000408)
/* DCLK (DAI/CODEC) Control Register */
#define DCLKmode (*(volatile unsigned long *)0x8000040C)
/* ADCLK and EX2CLK Control Register */
#define EACLKmode (*(volatile unsigned long *)0x80000410)
/* EX1CLK Control Register */
#define EX1CLKmode (*(volatile unsigned long *)0x80000414)
/* UTCLK (UART) Control Register */
#define UTCLKmode (*(volatile unsigned long *)0x80000418)
/* UBCLK (USB) Control Register */
#define UBCLKmode (*(volatile unsigned long *)0x8000041C)
/* LCLK (LCD) Control Register */
#define LCLKmode (*(volatile unsigned long *)0x80000420)
/* TCLK (Timer) Control Register */
#define TCLKmode (*(volatile unsigned long *)0x80000424)
/* GCLK (GSIO) Control Register */
#define GCLKmode (*(volatile unsigned long *)0x80000428)
/* CIFCLK Control Register */
#define CIFCLKmode (*(volatile unsigned long *)0x8000042C)
/* Software Reset for each peripherals */
#define SW_nRST (*(volatile unsigned long *)0x8000043C)
/* Power Down Control */
#define PWDCTL (*(volatile unsigned long *)0x80000440)
/* Divider Mode Enable (DCO Disable) */
#define DIVMODE (*(volatile unsigned long *)0x80000444)
#define DIVMODE_DVMCIF (1 << 12) /* Divider Mode Enable for CIF Clock (CIFCLK) */
#define DIVMODE_DVMGSIO (1 << 11) /* Divider Mode Enable for GSIO Clock (GCLK) */
#define DIVMODE_DVMTC (1 << 10) /* Divider Mode Enable for Timer/Counter Clock (TCLK) */
#define DIVMODE_DVMLCD (1 << 9) /* Divider Mode Enable for LCD Clock (LCLK) */
#define DIVMODE_DVMUSB (1 << 8) /* Divider Mode Enable for USB Clock (UHCLK, UDCLK) */
#define DIVMODE_DVMUART (1 << 7) /* Divider Mode Enable for UART/IrDA Clock (UTCLK) */
#define DIVMODE_DVMEXT (1 << 6) /* Divider Mode Enable for External Clock (EX1CLK) */
#define DIVMODE_DVMADC (1 << 5) /* Divider Mode Enable for ADC Clock (ADCLK) */
#define DIVMODE_DVMI2C (1 << 4) /* Divider Mode Enable for I2C Clock (EX2CLK) */
#define DIVMODE_DVMDAI (1 << 3) /* Divider Mode Enable for DAI Clock (DCLK) */
#define DIVMODE_DVMAHB (1 << 1) /* Divider Mode Enable for AHB Clock (HCLK) */
#define DIVMODE_DVMCPU (1 << 0) /* Divider Mode Enable for CPU Clock (FCLK) */
/* HCLK Stop Control */
#define HCLKSTOP (*(volatile unsigned long *)0x80000448)

/*
 * 0x500 ~ 0x5FF USB1.1 Device
 */

/* Non Indexed Registers */

/* Function Address Register */
#define UBFADR (*(volatile unsigned short *)0x80000500)
/* Power Management Register */
#define UBPWR (*(volatile unsigned short *)0x80000504)
/* Endpoint Interrupt Flag Register */
#define UBEIR (*(volatile unsigned short *)0x80000508)
/* USB Interrupt Flag Register */
#define UBIR (*(volatile unsigned short *)0x80000518)
/* Endpoint Interrupt Enable Register */
#define UBEIEN (*(volatile unsigned short *)0x8000051C)
/* Interrupt Enable Register */
#define UBIEN (*(volatile unsigned short *)0x8000052C)
/* Frame Number 1 Register */
#define UBFRM1 (*(volatile unsigned short *)0x80000530)
/* Frame Number 2 Register */
#define UBFRM2 (*(volatile unsigned short *)0x80000534)
/* Index Register */
#define UBIDX (*(volatile unsigned short *)0x80000538)

/* Common Indexed Register */

/* IN Max Packet Register */
#define MAXP (*(volatile unsigned short *)0x80000540)

/* In Indexed Registers */

/* IN CSR1 Register (EP0 CSR Register) */
#define INCSR1 (*(volatile unsigned short *)0x80000544)
/* IN CSR2 Register */
#define INCSR2 (*(volatile unsigned short *)0x80000548)

/* Out Indexed Registers */

/* OUT CSR1 Register */
#define OCSR1 (*(volatile unsigned short *)0x80000550)
/* OUT CSR2 Register */
#define OCSR2 (*(volatile unsigned short *)0x80000554)
/* OUT FIFO Write Count 1 Register */
#define OFIFO1 (*(volatile unsigned short *)0x80000558)
/* OUT FIFO Write Count 2 Register */
#define OFIFO2 (*(volatile unsigned short *)0x8000055C)

/* FIFO Registers */

/* EP0 FIFO Register */
#define EP0FIFO (*(volatile unsigned short *)0x80000580)
/* EP1 FIFO Register */
#define EP1FIFO (*(volatile unsigned short *)0x80000584)
/* EP2 FIFO Register */
#define EP2FIFO (*(volatile unsigned short *)0x80000588)

/* DMA Registers */

/* DMA Control Register */
#define DMACON (*(volatile unsigned short *)0x800005C0)
/* EP1 FIFO Access Register for DMA */
#define DMAEP1 (*(volatile unsigned short *)0x800005C4)
/* EP2 FIFO Access Register for DMA */
#define DMAEP2 (*(volatile unsigned short *)0x800005C8)

/* 0x600 ~ 0x6FF UART/IrDA */

/* 0x700 ~ 0x7FF GSIO (General Purpose Serial Input/Output) */

/* GSIO1 Output Data Register */
#define GSDO0 (*(volatile unsigned long *)0x80000700)
/* GSIO0 Input Data Register */
#define GSDI0 (*(volatile unsigned long *)0x80000704)
/* GSIO0 Control Register */
#define GSCR0 (*(volatile unsigned long *)0x80000708)
#define GSCR_EN (1 << 31) /* GSIO Enable */
#define GSCR_MS (1 << 30) /* 0: LSB first, 1: MSB first */
#define GSCR_WORD(x) (((x)&0xF) << 26) /* GSIO word size minus 1 */
#define GSCR_WS (1 << 25) /* Word size determined by 0: GSCRn, 1: GSDO */
#define GSCR_DIV(x) (((x)&0x7F) << 18) /* Use 1/(2n+2) of GCLK frequency */
#define GSCR_CP (1 << 17) /* GSIO clock polarity 0: falling, 1: rising */
#define GSCR_CM (1 << 16) /* 1: GSIO clock is masked at the last SDO period */
#define GSCR_DELAY(x) (((x)&3) << 13) /* Initial delay, must not be 0 */
#define GSCR_FP (1 << 12) /* 0: FRM active low, 1: FRM active high */
#define GSCR_FRM1(x) (((x)&0x3F) << 6) /* Frame pulse start position */
#define GSCR_FRM2(x) (((x)&0x3F) << 0) /* Frame pulse end position */
/* GSIO Global Control Register */
#define GSGCR (*(volatile unsigned long *)0x8000070C)
#define GSGCR_G3 (1 << 15) /* Use GPIO_B[23:21] for GSIO */
#define GSGCR_G2 (1 << 14)
#define GSGCR_G1 (1 << 13)
#define GSGCR_G0 (1 << 12)
#define GSGCR_IEN3 (1 << 11) /* Interrupt enable */
#define GSGCR_IEN2 (1 << 10)
#define GSGCR_IEN1 (1 << 9)
#define GSGCR_IEN0 (1 << 8)
#define GSGCR_FLG3 (1 << 7) /* Set when operation complete */
#define GSGCR_FLG2 (1 << 6)
#define GSGCR_FLG1 (1 << 5)
#define GSGCR_FLG0 (1 << 4)
#define GSGCR_Busy3 (1 << 3)
#define GSGCR_Busy2 (1 << 2)
#define GSGCR_Busy1 (1 << 1)
#define GSGCR_Busy0 (1 << 0)

#define GSDO1 (*(volatile unsigned long *)0x80000710)
#define GSDI1 (*(volatile unsigned long *)0x80000714)
#define GSCR1 (*(volatile unsigned long *)0x80000718)

#define GSDO2 (*(volatile unsigned long *)0x80000720)
#define GSDI2 (*(volatile unsigned long *)0x80000724)
#define GSCR2 (*(volatile unsigned long *)0x80000728)

#define GSDO3 (*(volatile unsigned long *)0x80000730)
#define GSDI3 (*(volatile unsigned long *)0x80000734)
#define GSCR3 (*(volatile unsigned long *)0x80000738)

/* 0x800 ~ 0x8FF I2C */

/* 0x900 ~ 0x9FF ECC */

/*
 * 0xA00 ~ 0xAFF ADC Control & Etc.
 */

/* ADC Control Register */
#define ADCCON (*(volatile unsigned long *)0x80000A00)
/* ADC Data Register */
#define ADCDATA (*(volatile unsigned long *)0x80000A04)
/* ADC Control Register A */
#define ADCCONA (*(volatile unsigned long *)0x80000A80)
/* ADC Status Register */
#define ADCSTATUS (*(volatile unsigned long *)0x80000A84)
/* ADC Configuration Register */
#define ADCCFG (*(volatile unsigned long *)0x80000A88)

/* USB Port Control Register */
#define USBCTR (*(volatile unsigned long *)0x80000A14)
/* Test Mode Control Register */
#define TSTSEL (*(volatile unsigned long *)0x80000A18)
/* Miscellaneous Configuration Register */
#define MISCCFG (*(volatile unsigned long *)0x80000A1C)
/* Pull-up Enable for GPIO_A */
#define CFGPUA (*(volatile unsigned long *)0x80000A20)
/* Pull-up Enable for GPIO_B */
#define CFGPUB (*(volatile unsigned long *)0x80000A24)
/* Pull-up Enable for GPIO_C */
#define CFGPUC (*(volatile unsigned long *)0x80000A28)
/* Pull-up Enable for GPIO_D */
#define CFGPUD (*(volatile unsigned long *)0x80000A2C)
/* Buffer Drive Strength Select AL */
#define CFGDRVAL (*(volatile unsigned long *)0x80000A30)
/* Buffer Drive Strength Select AH */
#define CFGDRVAH (*(volatile unsigned long *)0x80000A34)
/* Buffer Drive Strength Select BL */
#define CFGDRVBL (*(volatile unsigned long *)0x80000A38)
/* Buffer Drive Strength Select BH */
#define CFGDRVBH (*(volatile unsigned long *)0x80000A3C)
/* Buffer Drive Strength Select CL */
#define CFGDRVCL (*(volatile unsigned long *)0x80000A40)
/* Buffer Drive Strength Select CH */
#define CFGDRVCH (*(volatile unsigned long *)0x80000A44)
/* Buffer Drive Strength Select DL */
#define CFGDRVDL (*(volatile unsigned long *)0x80000A48)
/* Buffer Drive Strength Select DH */
#define CFGDRVDH (*(volatile unsigned long *)0x80000A4C)
/* Buffer Drive Strength Select XL */
#define CFGDRVXL (*(volatile unsigned long *)0x80000A50)
/* Buffer Drive Strength Select XH */
#define CFGDRVXH (*(volatile unsigned long *)0x80000A54)
/* System Configuration */
#define CFGSYS (*(volatile unsigned long *)0x80000A60)

/* 0xB00 ~ 0xBFF Camera Interface */

/* 0xC00 ~ 0xCFF Reserved */

/* 0xD00 ~ 0xDFF USB1.1 Host */

/* 0xE00 ~ 0xEFF DMA Controller */

/* 0xF00 ~ 0xFFF LCD controller (TCC761 only) */

/*
 * Memory controller registers at 0xF0000000
 */

/* SDRAM Configuration Register */
#define SDCFG (*(volatile unsigned long *)0xF0000000)
/* SDRAM FSM Status Register */
#define SDFSM (*(volatile unsigned long *)0xF0000004)
/* Miscellaneous Configuration Register */
#define MCFG (*(volatile unsigned long *)0xF0000008)
/* Test mode register (must be remained zero) */
#define TST (*(volatile unsigned long *)0xF000000C)
/* External Chip Select 0 Configuration Register */
#define CSCFG0 (*(volatile unsigned long *)0xF0000010)
/* External Chip Select 1 Configuration Register */
#define CSCFG1 (*(volatile unsigned long *)0xF0000014)
/* External Chip Select 2 Configuration Register */
#define CSCFG2 (*(volatile unsigned long *)0xF0000018)
/* External Chip Select 3 Configuration Register */
#define CSCFG3 (*(volatile unsigned long *)0xF000001C)
/* Memory Controller Clock Count Register */
#define CLKCFG (*(volatile unsigned long *)0xF0000020)
/* SDRAM Command Register */
#define SDCMD (*(volatile unsigned long *)0xF0000024)

#endif