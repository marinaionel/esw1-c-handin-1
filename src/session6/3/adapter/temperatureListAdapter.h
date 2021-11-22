//
// Created by Marina Ionel on 14/04/2020.
//

#pragma once

#include "../../1/list.h"
#include "../model/temperature.h"

typedef struct temperatureListAdapter *temperatureListAdapter_t;

list_ReturnCode_t temperatureListAdapter_destroy(temperatureListAdapter_t temperatureListAdapter1);

list_ReturnCode_t
temperatureListAdapter_addTemperature(temperatureListAdapter_t temperatureListAdapter, temperature_t temperature);

list_ReturnCode_t
temperatureListAdapter_getTemperature(temperatureListAdapter_t temperatureListAdapter, temperature_t *temperature,
                                      int index);

list_ReturnCode_t
temperatureListAdapter_removeTemperature(temperatureListAdapter_t roomListAdapter, temperature_t temperature);

int temperatureListAdapter_noOfTemperatureIndicators(temperatureListAdapter_t temperatureListAdapter);

temperatureListAdapter_t temperatureListAdapter_create();
