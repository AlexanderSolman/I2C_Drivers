#include "i2c.h"
#include "ssd1306.h"

int main(){

    //Data to be transmitted i.e '2023'
    uint8_t buffer[BUFFER_SIZE] = {0x7E, 0x11, 0x11, 0x7E, 
                                   0x10, 0x3E, 0x00, 0x00, 
                                   0x10, 0x11, 0x11, 0x1E,
                                   0x10, 0x21, 0x21, 0x1E};

    //Initiate I2C communication
    I2C_Init();
    //Initiate ssd1306
    ssd1306_init();

    while(tx_fail){

        I2C_write(SLAVE_ADDR, cmd, sizeof(cmd));

        //Call the write function to write '2023' to the ssd1306
        I2C_write(SLAVE_ADDR, buffer, sizeof(buffer));

        /*Call function to check for errors
          Handle errors if raised and reset
          protocol and re-call init. Then
          call write function again.*/
        tx_fail = flag_check();
    }


    return 0;
}