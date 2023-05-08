#ifndef __SSD1306_H
#define __SSD1306_H

#include <stdint.h>
#include "i2c.h"

#define SLAVE_ADDR 0x3C
#define BUFFER_SIZE (128 * 32 / 8)

/*SETUP PARAMETERS FOR SSD1306 -- THE HEX VALUES CAN BE FOUND IN THE DATASHEET
  These include but are not limited to:
  Display on/off, clock, offset, multiplex ratio, memory addressing mode, 
  horizontal addressing mode, pre-charge, VCOMH deselect*/
uint8_t params[] = {0xAE, 0xD5, 0xD3, 0xA8, 0x40, 0x8D, 0x14, 0x20, 0x00, 
                    0xA1, 0xC8, 0xDA, 0x12, 0x81, 0xD9, 0xDB, 0xAF};

uint8_t cmd[] = {0x21, 0x00, 0x7F, 0x22, 0x00, 0x07};


void ssd1306_init(void);

#endif