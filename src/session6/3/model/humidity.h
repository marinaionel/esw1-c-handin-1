#pragma once

#include <stdint.h>

typedef struct humidity *humidity_t;

humidity_t humidity_create(uint8_t portNo);

void humidity_measure(humidity_t humidity);

uint8_t humidity_getHumidity(humidity_t humidity);

void humidity_destroy(humidity_t self);