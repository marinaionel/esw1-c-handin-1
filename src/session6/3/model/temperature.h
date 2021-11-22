#pragma once

#include <stdint.h>

typedef struct temperature *temperature_t;

temperature_t temperature_create(uint8_t portNo);

void temperature_measure(temperature_t temperature1);

float temperature_getTemperature(temperature_t self);