# I2C Drivers
## About

The following project was made in C to showcase the I2C communication between a stm32 microcontroller and the ssd1306 OLED display. 
The I2C drivers are not specific to the ssd1306 and can be adapted to other uses. The drivers contains three functions for initializing the I2C peripheral, 
writing to a slave device and handling interrupts during writing.
This does not include any capabilities to read data from a slave device.
This project folder also contains a driver function with basic setup for the ssd1306 to display the functionality of the I2C communication.

## Hardware
- stm32f411 based dev board
- ssd1306 OLED

## Dependencies
- stm32f4xx.h
- core_cm4.h
- cmsis_version.h
- cmsis_compiler.h
- HAL library

## Usage
- Set up hardware
- Clone repository
- Include libraries mentioned under Dependencies
- Compile and run the main file

Once cloned and necessary libraries are included, the write function can be called inside the while loop with any data.
