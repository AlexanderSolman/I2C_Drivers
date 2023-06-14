The following project was made in C to showcase the I2C communication between a stm32 microcontroller and the ssd1306 OLED display. The I2C drivers are not specific to the ssd1306 and can be adapted to other uses. The drivers contains three functions for initializing the I2C peripheral, writing to a slave device and handling interrupts during writing.
This does not included any capabilities to read data from a slave device.
This project folder also contains a driver function with basic setup for the ssd1306 to display the functionality of the I2C communication.

You will need the following to use these files:
-stm32f411 based dev board
-Necessary complementary libraries, i.e HAL library for the stm32f411 board
-Knowledge of how to connect the two devices

Once cloned and necessary libraries are included, the write function can be called inside the while loop with any data.
