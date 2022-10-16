//
// Created by michael on 16/10/22.
//

#ifndef MAX6675_MAX6675_H
#define MAX6675_MAX6675_H


#include "max6675.c"

#define SPI_PORT spi0
#define PIN_MISO 16
#define PIN_CS  17
#define PIN_SCK  18
#define PIN_MOSI 19
#define CAL 1.237562189

static inline void cs_select();
static inline void cs_deselect();
float max6675_temperature_decode(uint8_t *temperature_data);
void read_max6675(uint8_t *buf, uint16_t len);


#endif //MAX6675_MAX6675_H