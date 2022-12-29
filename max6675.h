//
// Created by michael on 16/10/22.
//

#ifndef MAX6675_MAX6675_H
#define MAX6675_MAX6675_H


#include "max6675.c"



static inline void cs_select();
static inline void cs_deselect();
float max6675_temperature_decode(uint8_t *temperature_data);
void read_max6675(uint8_t *buf, uint16_t len);


#endif //MAX6675_MAX6675_H