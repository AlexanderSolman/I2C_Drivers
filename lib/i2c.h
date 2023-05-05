#ifndef I2C_H
#define I2C_H

#include "stm32f4xx.h"
#include "core_cm4.h"
#include <stdint.h>

#define GPIOB_CLOCK_ENABLE      (1U<<1)
#define GPIOB_MODER_MASK        0xF000
#define GPIOB_AFR_MASK          0x3FC00000
#define I2C1_CLOCK_ENABLE       (1U<<21)
#define I2C_RESET               (1U<<15)
#define I2C_FM_MODE_SELECTION   (1U<<15)
#define I2C_BUS_SPEED           ((uint32_t)400000)
#define I2C_CLOCK_SPEED         ((uint32_t)100000000)
#define I2C_OAR1_ADDR_MODE      (1U<<15)
#define I2C_CR2_ITBUFEN         (1U<<10)
#define I2C_CR2_ITEVTEN         (1U<<9)
#define I2C_EV_ENABLE           (1U<<31)
#define I2C_ER_ENABLE           0x1
#define I2C_CR1_START           (1U<<8)
#define I2C_CR1_STOP            (1U<<9)
#define I2C_SR1_SB              (1U<<0)
#define I2C_SR1_ADDR            (1U<<1)
#define I2C_SR2_MSL             (1U<<0)
#define I2C_SR1_TXE             (1U<<7)
#define I2C_SR1_BTF             (1U<<2)

void I2C1_Init(void);
void I2C_write(uint8_t, uint8_t *, uint32_t);

#endif