//
// Created by michael on 16/10/22.

/* Example code to talk to a MAX6675 Thremocouple interface.


NOTE: Ensure the device is capable of being driven at 3.3v NOT 5v. The Pico
GPIO (and therefor SPI) cannot be used at 5v.

You will need to use a level shifter on the I2C lines if you want to run the
board at 5v.

Connections on Raspberry Pi Pico board and a generic MPU9250 board, other
boards may vary.

GPIO 16 (pin 21) Master in Slave out MISO/spi0_RX-> SO on Max6675 board
GPIO 17 (pin 22) Chip select spi0_CSn-> CS on Max6675 board
GPIO 18 (pin 24) Clock SCK/spi0_SCK -> SCk on Max6675 board


3.3v (pin 36) -> VCC on Max6675 board
GND (pin 38)  -> GND on Max6675 board

Note: SPI devices can have a number of different naming schemes for pins. See
the Wikipedia page at https://en.wikipedia.org/wiki/Serial_Peripheral_Interface
for variations.
The particular device used here uses the same pins for I2C and SPI, hence the
using of I2C names
 */

// SPI Defines
// We are going to use SPI 0, and allocate it to the following GPIO pins
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments

//

#include "hardware/spi.h"
#include "pico/stdlib.h"
#include "pico/binary_info.h"


#define SPI_PORT spi0
#define PIN_MISO 4 // data read
#define PIN_CS  5  // chip select
#define PIN_SCK  6 // clk
#define PIN_MOSI 19 //not required
#define CAL 1.0     //calibrate the sensor offset

static inline void cs_select() {
//    picoasm volatile("nop \n nop \n nop"); //machine code delay?
    gpio_put(PIN_CS, 0);                // Actively selected when low
//    picoasm volatile("nop \n nop \n nop");
}

static inline void cs_deselect() {
//    picoasm volatile("nop \n nop \n nop"); //machine code delay?
    gpio_put(PIN_CS, 1);                // Actively selected when low
//    picoasm volatile("nop \n nop \n nop");
}

float max6675_temperature_decode(uint8_t *temperature_data) {
//
    uint32_t raw_temperature;
    float adjusted_temperature;

    raw_temperature = (temperature_data[0]<<8)|temperature_data[1];
    raw_temperature <<=1; //Not sure why I have to do this
    //scope indicates that I am out by one bit
    //this is the easiest fix

    adjusted_temperature = (double) (raw_temperature>>3)*CAL;
    return adjusted_temperature/10;



}

void read_max6675(uint8_t *buf, uint16_t len) {
    // For  this particular device, we send select the chip and read the data

    cs_select();
    sleep_ms(1);
    spi_read_blocking(SPI_PORT, 0, buf, len);
    sleep_ms(10);
    cs_deselect();
    //sleep_ms(10);
}
