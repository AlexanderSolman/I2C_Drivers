/*Definitions and declarations used for setting up I2C communication
  and for writing with a slave device. Handling flags risen from
  ITEVTEN and ITBUFEN is done resetting the communication.*/

#ifndef _I2C_H_
#define _I2C_H_

/*INCLUDES*/

#include "stm32f4xx.h"
#include "core_cm4.h"
#include <stdint.h>
#include <stdbool.h>

/*DEFINE MACROS*/

#define GPIOB_CLOCK_ENABLE      (1U<<1)
#define GPIOB_MODER_MASK        0xF000
#define GPIOB_AF_MODE_SELECT    0xA000
#define GPIOB_AFR_MASK          0x3FC00000
#define GPIOB_AF4_SELECT        0x44000000
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
#define I2C_CR1_ENABLE          0x1
#define I2C_SR1_SB              0x1
#define I2C_SR1_ADDR            (1U<<1)
#define I2C_SR2_BUSY            (1U<<1)
#define I2C_SR2_MSL             0x1
#define I2C_SR1_TXE             (1U<<7)
#define I2C_SR1_BTF             (1U<<2)
#define I2C_ACK_FAIL            (1U<<10)
#define I2C_ARLO                (1U<<9)
#define I2C_BERR                (1U<<8)

/*FUNCTION DECLERATIONS*/

void I2C1_Init(void); // Function to initiate and setup i2c communication
void I2C_write(uint8_t, uint8_t *, uint32_t); // Function to write over i2c bus to slave
bool I2C_flagHandler(); // Function to handle errors during communication

/*VARIABLE DECLERATIONS*/

/*----------------------------------------------------------------------*/

#endif