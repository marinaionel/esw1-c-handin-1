//
// Created by Marina Ionel on 14/04/2020.
//

#pragma once

#include <stdint.h>
#include "../model/humidity.h"
#include "../../1/list.h"

typedef struct humidityListAdapter *humidityListAdapter_t;

humidityListAdapter_t humidityListAdapter_create();

uint16_t humidityListAdapter_noOfHumidityIndicators(humidityListAdapter_t pHumidityListAdapter);

list_ReturnCode_t humidityListAdapter_removeHumidity(humidityListAdapter_t pHumidityListAdapter, humidity_t pHumidity);

list_ReturnCode_t humidityListAdapter_destroy(humidityListAdapter_t pHumidityListAdapter);

list_ReturnCode_t
humidityListAdapter_addHumidity(humidityListAdapter_t pHumidityListAdapter, humidity_t humidity);

list_ReturnCode_t
humidityListAdapter_getHumidity(humidityListAdapter_t pHumidityListAdapter, humidity_t *humidity,
                                int index);