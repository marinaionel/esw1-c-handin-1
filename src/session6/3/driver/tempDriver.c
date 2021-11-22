#include <time.h>
#include <stddef.h>
#include <stdlib.h>

#include "tempDriver.h"

void temperatureDriver_initDriver(uint8_t port) {
    srand(time(NULL));
}

float temperatureDriver_getVoltage() {
    int r = (rand() % (50 - 0 + 1));
    return ((double) r + 0.5) / 10.0;
}