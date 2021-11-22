#include <stdint.h>
#include "../driver/humidityDriver.h"
#include "humidity.h"
#include <corecrt_malloc.h>

typedef struct humidity {
    int8_t latestHumidity;
    uint8_t portNo;
} humidity;

humidity_t humidity_create(uint8_t portNo) {
    humidity_t humidity1 = calloc(sizeof(humidity), 1);
    if (NULL == humidity1) return NULL;
    humidity1->latestHumidity = 0;
    humidity1->portNo = portNo;
    humidityDriver_initDriver(portNo);
    return humidity1;
}

void humidity_measure(humidity_t humidity) {
    humidity->latestHumidity = humidityDriver_getHumidity();
}

uint8_t humidity_getHumidity(humidity_t humidity) {
    if (humidity == NULL) return -1;
    return humidity->latestHumidity;
}

void humidity_destroy(humidity_t self) {
    if (self == NULL) return;
    free(self);
    self = NULL;
}