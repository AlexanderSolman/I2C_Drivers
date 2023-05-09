/* This file contains commands which sets up the ssd1306-(128x32).
   For a full list of commands refer to the datasheet*/

#ifndef __SSD1306_H
#define __SSD1306_H

/*INCLUDES*/

#include <stdint.h>
#include "i2c.h"

/*DEFINE MACROS*/

#define SLAVE_ADDR (uint8_t)0x3C //SA0 LOW, if HIGH -> 0x3D
#define WIDTH 128
#define HEIGHT 32
#define BUFFER_SIZE (WIDTH * HEIGHT / 8) // Size of RAM is W * H / (8-pages) [512]

/*FUNCTION DECLERATIONS*/

/*-------------------------------------------------------------------------*/

/*VARIABLE DECLERATIONS*/

/*SETUP PARAMETERS FOR SSD1306 -- THE HEX VALUES CAN BE FOUND IN THE DATASHEET
  These include but are not limited to:
  Display on/off, clock, offset, multiplex ratio, memory addressing mode, 
  horizontal addressing mode, pre-charge, VCOMH deselect*/
uint8_t init_params[] = {0xAE, 0xD5, 0xD3, 0xA8, 0x40, 0x8D, 0x14, 0x20, 0x00, 
                         0xA1, 0xC8, 0xDA, 0x12, 0x81, 0xD9, 0xDB, 0xAF};

//Page address and column address in RAM
uint8_t cmd[] = {0x21, 0x00, 0x7F, 0x22, 0x00, 0x07};


#endif