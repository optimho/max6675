#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "max6675.h"

#define SPI_PORT spi0
#define PIN_MISO 16
#define PIN_CS  17
#define PIN_SCK  18
#define PIN_MOSI 19
#define CAL 1.237562189

int main()
{
    stdio_init_all();
    const int BYTES = 2;
    uint8_t buffer[BYTES];
    float the_temperature;


    // SPI initialisation. This example will use SPI at 500Hz. can go faster to about 4MHZ
    spi_init(SPI_PORT, 5*100);
    gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
    gpio_set_function(PIN_CS,   GPIO_FUNC_SIO);
    gpio_set_function(PIN_SCK,  GPIO_FUNC_SPI);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);

    // Make the SPI pins available to picotool

    bi_decl(bi_3pins_with_func(PIN_MISO, PIN_MOSI, PIN_SCK, GPIO_FUNC_SPI));
    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_init(PIN_CS);
    gpio_set_dir(PIN_CS, GPIO_OUT);

    // Make the CS pin available to picotool
    bi_decl(bi_1pin_with_name(PIN_CS, "SPI CS"));

    while(1) {
        sleep_ms(2000);
        read_max6675(buffer, 2);
        the_temperature=max6675_temperature_decode(buffer);
        //view on a terminal
        printf("this is the temperature returned %.2f\n", the_temperature);
        //printf(data);
    }
    return 0;
}
