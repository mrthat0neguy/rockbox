/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 * $Id$
 *
 * Copyright (C) 2002 by Alan Korr
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

#include "config.h"

#include "hwcompat.h"
#include "kernel.h"
#include "lcd.h"
#include "system.h"

/*** definitions ***/

#define LCD_SET_LOWER_COLUMN_ADDRESS              ((char)0x00)
#define LCD_SET_HIGHER_COLUMN_ADDRESS             ((char)0x10)
#define LCD_SET_INTERNAL_REGULATOR_RESISTOR_RATIO ((char)0x20)
#define LCD_SET_POWER_CONTROL_REGISTER            ((char)0x28)
#define LCD_SET_DISPLAY_START_LINE                ((char)0x40)
#define LCD_SET_CONTRAST_CONTROL_REGISTER         ((char)0x81)
#define LCD_SET_SEGMENT_REMAP                     ((char)0xA0)
#define LCD_SET_LCD_BIAS                          ((char)0xA2)
#define LCD_SET_ENTIRE_DISPLAY_OFF                ((char)0xA4)
#define LCD_SET_ENTIRE_DISPLAY_ON                 ((char)0xA5)
#define LCD_SET_NORMAL_DISPLAY                    ((char)0xA6)
#define LCD_SET_REVERSE_DISPLAY                   ((char)0xA7)
#define LCD_SET_MULTIPLEX_RATIO                   ((char)0xA8)
#define LCD_SET_BIAS_TC_OSC                       ((char)0xA9)
#define LCD_SET_1OVER4_BIAS_RATIO                 ((char)0xAA)
#define LCD_SET_INDICATOR_OFF                     ((char)0xAC)
#define LCD_SET_INDICATOR_ON                      ((char)0xAD)
#define LCD_SET_DISPLAY_OFF                       ((char)0xAE)
#define LCD_SET_DISPLAY_ON                        ((char)0xAF)
#define LCD_SET_PAGE_ADDRESS                      ((char)0xB0)
#define LCD_SET_COM_OUTPUT_SCAN_DIRECTION         ((char)0xC0)
#define LCD_SET_TOTAL_FRAME_PHASES                ((char)0xD2)
#define LCD_SET_DISPLAY_OFFSET                    ((char)0xD3)
#define LCD_SET_READ_MODIFY_WRITE_MODE            ((char)0xE0)
#define LCD_SOFTWARE_RESET                        ((char)0xE2)
#define LCD_NOP                                   ((char)0xE3)
#define LCD_SET_END_OF_READ_MODIFY_WRITE_MODE     ((char)0xEE)

/* LCD command codes */
#define LCD_CNTL_RESET          0xe2    /* Software reset */
#define LCD_CNTL_POWER          0x2f    /* Power control */
#define LCD_CNTL_CONTRAST       0x81    /* Contrast */
#define LCD_CNTL_OUTSCAN        0xc8    /* Output scan direction */
#define LCD_CNTL_SEGREMAP       0xa1    /* Segment remap */
#define LCD_CNTL_DISPON         0xaf    /* Display on */

#define LCD_CNTL_PAGE           0xb0    /* Page address */
#define LCD_CNTL_HIGHCOL        0x10    /* Upper column address */
#define LCD_CNTL_LOWCOL         0x00    /* Lower column address */

/** globals **/

static int xoffset; /* needed for flip */

/*** hardware configuration ***/

//FIXME
#include "tcc76x.h"

#define LCD_COMMAND_PORT (*(volatile unsigned char *)0x50080000)
#define LCD_DATA_PORT (*(volatile unsigned char *)0x50080001)

void lcd_write_command(int c) {
    LCD_COMMAND_PORT=c;
    asm volatile ("nop; nop; nop;");
}

void lcd_write_data(const unsigned char *c, int n) {
    int i;
    for (i = 0; i < n; i++) {
        LCD_DATA_PORT = c[i];
        asm volatile ("nop; nop; nop;");
    }
}

int lcd_default_contrast(void)
{
    return 44; //return (HW_MASK & LCD_CONTRAST_BIAS) ? 31 : 49;
}

void lcd_set_contrast(int val)
{
    lcd_write_command(LCD_CNTL_CONTRAST);
    lcd_write_command(val);
}

void lcd_set_invert_display(bool yesno)
{
    if (yesno)
        lcd_write_command(LCD_SET_REVERSE_DISPLAY);
    else
        lcd_write_command(LCD_SET_NORMAL_DISPLAY);
}

/* turn the display upside down (call lcd_update() afterwards) */
void lcd_set_flip(bool yesno)
{
#ifdef HAVE_DISPLAY_FLIPPED
    if (!yesno)
#else
    if (yesno)
#endif
    {
        lcd_write_command(LCD_SET_SEGMENT_REMAP);
        lcd_write_command(LCD_SET_COM_OUTPUT_SCAN_DIRECTION);
        xoffset = 132 - LCD_WIDTH; /* 132 colums minus the 112 we have */
    }
    else
    {
        lcd_write_command(LCD_SET_SEGMENT_REMAP | 0x01);
        lcd_write_command(LCD_SET_COM_OUTPUT_SCAN_DIRECTION | 0x08);
        xoffset = 0;
    }
}

void lcd_init_device(void)
{
#ifdef ARCHOS
    /* Initialize PB0-3 as output pins */
    PBCR2 &= 0xff00; /* MD = 00 */
    PBIOR |= 0x000f; /* IOR = 1 */

    /* inits like the original firmware */
    lcd_write_command(LCD_SOFTWARE_RESET);
    lcd_write_command(LCD_SET_INTERNAL_REGULATOR_RESISTOR_RATIO + 4);
    lcd_write_command(LCD_SET_1OVER4_BIAS_RATIO + 0); /* force 1/4 bias: 0 */
    lcd_write_command(LCD_SET_POWER_CONTROL_REGISTER + 7);
               /* power control register: op-amp=1, regulator=1, booster=1 */
    lcd_write_command(LCD_SET_DISPLAY_ON);
    lcd_write_command(LCD_SET_NORMAL_DISPLAY);
    lcd_set_flip(false);
    lcd_write_command(LCD_SET_DISPLAY_START_LINE + 0);
    lcd_set_contrast(lcd_default_contrast());
    lcd_write_command(LCD_SET_PAGE_ADDRESS);
    lcd_write_command(LCD_SET_LOWER_COLUMN_ADDRESS + 0);
    lcd_write_command(LCD_SET_HIGHER_COLUMN_ADDRESS + 0);

    lcd_clear_display();
    lcd_update();
#endif
    GPIOD |= 0x200000; /* This seems to enable LCD and backlight power */

    CSCFG1 = 0x0f540059; /* Configure LCD chip select */

    lcd_write_command(LCD_SET_DISPLAY_OFF);
    lcd_write_command(LCD_SET_LCD_BIAS);
    lcd_write_command(LCD_SET_SEGMENT_REMAP);
    asm volatile ("nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop; nop;");
    lcd_write_command(LCD_SET_COM_OUTPUT_SCAN_DIRECTION|8);
    asm volatile ("nop; nop; nop; nop; nop; nop;");
    lcd_write_command(LCD_SET_INTERNAL_REGULATOR_RESISTOR_RATIO + 5);
    lcd_set_contrast(lcd_default_contrast());
    lcd_write_command(LCD_CNTL_POWER);

    lcd_clear_display();
    lcd_update();

    lcd_write_command(LCD_SET_DISPLAY_ON);
    lcd_write_command(LCD_SET_ENTIRE_DISPLAY_OFF);
}

/*** Update functions ***/

/* Performance function that works with an external buffer
   note that by and bheight are in 8-pixel units! */
void lcd_blit_mono(const unsigned char *data, int x, int by, int width,
                   int bheight, int stride)
{
    /* Copy display bitmap to hardware */
    while (bheight--)
    {
        lcd_write_command (LCD_CNTL_PAGE | (by++ & 0xf));
        lcd_write_command (LCD_CNTL_HIGHCOL | (((x+xoffset)>>4) & 0xf));
        lcd_write_command (LCD_CNTL_LOWCOL | ((x+xoffset) & 0xf));

        lcd_write_data(data, width);
        data += stride;
    }
}

#if 0
/* Helper function for lcd_grey_phase_blit(). */
void lcd_grey_data(unsigned char *values, unsigned char *phases, int count);

/* Performance function that works with an external buffer
   note that by and bheight are in 8-pixel units! */
void lcd_blit_grey_phase(unsigned char *values, unsigned char *phases,
                         int x, int by, int width, int bheight, int stride)
{
    stride <<= 3; /* 8 pixels per block */
    while (bheight--)
    {
        lcd_write_command (LCD_CNTL_PAGE | (by++ & 0xf));
        lcd_write_command (LCD_CNTL_HIGHCOL | (((x+xoffset)>>4) & 0xf));
        lcd_write_command (LCD_CNTL_LOWCOL | ((x+xoffset) & 0xf));

        lcd_grey_data(values, phases, width);
        values += stride;
        phases += stride;
    }
}
#endif
void lcd_blit_grey_phase(unsigned char *values, unsigned char *phases,
                         int x, int by, int width, int bheight, int stride)
{ // FIXME
}


/* Update the display.
   This must be called after all other LCD functions that change the display. */
void lcd_update(void)
{
    int y;

    /* Copy display bitmap to hardware */
    for (y = 0; y < LCD_FBHEIGHT; y++)
    {
        lcd_write_command (LCD_CNTL_PAGE | (y & 0xf));
        lcd_write_command (LCD_CNTL_HIGHCOL | ((xoffset >> 4) & 0xf));
        lcd_write_command (LCD_CNTL_LOWCOL | (xoffset & 0xf));

        lcd_write_data (FBADDR(0, y), LCD_WIDTH);
    }
}

/* Update a fraction of the display. */
void lcd_update_rect(int x, int y, int width, int height)
{
    int ymax;

    /* The Y coordinates have to work on even 8 pixel rows */
    ymax = (y + height-1) >> 3;
    y >>= 3;

    if(x + width > LCD_WIDTH)
        width = LCD_WIDTH - x;
    if (width <= 0)
        return; /* nothing left to do, 0 is harmful to lcd_write_data() */
    if(ymax >= LCD_FBHEIGHT)
        ymax = LCD_FBHEIGHT-1;

    /* Copy specified rectange bitmap to hardware */
    for (; y <= ymax; y++)
    {
        lcd_write_command (LCD_CNTL_PAGE | (y & 0xf));
        lcd_write_command (LCD_CNTL_HIGHCOL | (((x+xoffset) >> 4) & 0xf));
        lcd_write_command (LCD_CNTL_LOWCOL | ((x+xoffset) & 0xf));

        lcd_write_data (FBADDR(x,y), width);
    }
}
