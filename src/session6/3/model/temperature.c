#include <stdbool.h>
#include "../driver/tempDriver.h"
#include "temperature.h"
#include <corecrt_malloc.h>

extern bool temperature_metricUnits; // Declaration

typedef struct temperature {
    float latestTemp;
    uint8_t driverPort;
} temperature;

static float _calculateTemp(float voltage) {
    return 15.0f + (voltage * 5.0f); // dummy calc
}

temperature_t temperature_create(uint8_t portNo) {
    temperature_t _temperature = calloc(sizeof(temperature), 1);
    if (NULL == _temperature)
        return NULL;
    _temperature->latestTemp = 0.0f;
    _temperature->driverPort = portNo;
    temperatureDriver_initDriver(portNo);
    return _temperature;
}

void temperature_measure(temperature_t temperature1) {
    temperature1->latestTemp = _calculateTemp(temperatureDriver_getVoltage());
}

float temperature_getTemperature(temperature_t self) {
    float _tmp_ = self->latestTemp;
    if (temperature_metricUnits) {
        _tmp_ *= 0.2f; // dummy conversion
    }

    return _tmp_;
}
