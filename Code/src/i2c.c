/* This file contains the function definitions for initiating I2C peripheral, writing and
   handing errors during write.
   For further information see the datasheet/reference manual*/

#include "i2c.h"

void I2C1_Init(void){

    //Enable GPIOB clock
    RCC->AHB1ENR |= GPIOB_CLOCK_ENABLE;
    //Clearing bits 12 13 14 15 i.e PB6 and PB7
    GPIOB->MODER &= ~GPIOB_MODER_MASK;
    //Setting bits 13 and 15 to 1 for alternate function
    GPIOB->MODER |= GPIOB_AF_MODE_SELECT;
    //Clearing bits 24-31 then setting pins 6,7 to AF4(I2C1)
    GPIOB->AFR[0] &= ~GPIOB_AFR_MASK;
    GPIOB->AFR[0] |= GPIOB_AF4_SELECT;


    //Enable I2C1 clock
    RCC->APB1ENR |= I2C1_CLOCK_ENABLE;
    //Setting bit 15 in CR1 to reset
    I2C->CR1 |= I2C_RESET;
    I2C->CR1 &= ~I2C_RESET;
    //Setting the ccr to Fm mode and calculating the I2C speed/timings
    I2C->CCR |= I2C_FM_MODE_SELECTION;
    I2C->CCR |= (I2C_CLOCK_SPEED / (I2C_BUS_SPEED * 2));
    I2C->TRISE = 1;
    //Setting bit 15 to 7-bit addressing mode
    I2C->OAR1 |= I2C_OAR1_ADDR_MODE;
    /*Enabling ITEVTEN and ITBUFEN
      Interrupt event and interrupt buffer*/
    I2C->CR2 |= I2C_CR2_ITBUFEN;
    I2C->CR2 |= I2C_CR2_ITEVTEN;
    NVIC->ISER[0] |= I2C_EV_ENABLE;
    NVIC->ISER[1] |= I2C_ER_ENABLE;
    //Enabling the I2C peripheral
    I2C->CR1 |= I2C_CR1_ENABLE;
}

void I2C_write(uint8_t s_addr, uint8_t *data, uint32_t data_length){
    //Checking if the bus is busy or ready
    while(!(I2C->SR2 & I2C_SR2_BUSY));
    
    //Setting Start bit in cr1
    I2C->CR1 |= I2C_CR1_START;
    
    //Waiting before start bit is set i.e bit 0 in SR1
    while(!(I2C->SR1 & I2C_SR1_SB));

    /*Sending address and shifting to clear bit-0 for write.
      Waiting for addr ack from slave and
      waiting for master bit to be set*/
    I2C->DR = (s_addr << 1) | 0x00;
    while(!(I2C->SR1 & I2C_SR1_ADDR) && !(I2C->SR2 & I2C_SR2_MSL));

    /*Looping to send the data and waiting for 
      Byte tranfer to finish and data register 
      to be empty*/
    for(uint32_t i = 0; i < data_length; i++){
        while(!(I2C->SR1 & I2C_SR1_TXE));
        I2C->DR = data[i];
        while(!(I2C->SR1 & I2C_SR1_BTF));
    }

    //Setting stop bit at end of tranfer
    I2C->CR1 |= I2C_CR1_STOP;
}

bool I2C_flagHandler(void){
    //Checking if acknowledgement failed, arbitration lost or bus error occured
    if(!(I2C->SR1 & I2C_ACK_FAIL) || !(I2C->SR1 & I2C_ARLO) || !(I2C->SR1 & I2C_BERR)){

        //Resetting I2C through CR1
        I2C->CR1 |= I2C_RESET;
        I2C->CR1 &= ~I2C_RESET;

        //Re-initializing the I2C communication
        I2C1_Init();

        /*Returns true when a flag has been raised
          to re-send the data*/
        return true;
    }
    //Returns false when no flag was raised
    return false;
}