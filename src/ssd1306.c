#include "ssd1306.h"

void ssd1306_init(void){
    //Using the I2C_write function to send these commands to the ssd1306
    I2C_write(SLAVE_ADDR, params, sizeof(params));
}
