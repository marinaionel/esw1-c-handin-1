//
// Created by Marina Ionel on 14/04/2020.
//

#include "temperatureListAdapter.h"
#include <corecrt_malloc.h>

#define TEMPERATURE_LIST_MAX_SIZE 4

typedef struct temperatureListAdapter {
    list_t list;
} temperatureListAdapter;

temperatureListAdapter_t temperatureListAdapter_create() {
    temperatureListAdapter_t _temperatureListAdapter = calloc(sizeof(temperatureListAdapter), 1);
    if (NULL == _temperatureListAdapter) return NULL;
    _temperatureListAdapter->list = list_create();
    if (_temperatureListAdapter->list == NULL) { _temperatureListAdapter = NULL; }
    return _temperatureListAdapter;
}

list_ReturnCode_t temperatureListAdapter_destroy(temperatureListAdapter_t temperatureListAdapter1) {
    if (NULL == temperatureListAdapter1)
        return LIST_NULL;

    list_destroy(temperatureListAdapter1->list);
    free(temperatureListAdapter1);
    temperatureListAdapter1 = NULL;
    return LIST_OK;
}

list_ReturnCode_t
temperatureListAdapter_addTemperature(temperatureListAdapter_t temperatureListAdapter, temperature_t temperature) {
    if (temperatureListAdapter == NULL) return LIST_NULL;
    if (temperatureListAdapter->list == NULL) return LIST_NULL;

    if (list_noOfItems(temperatureListAdapter->list) >= TEMPERATURE_LIST_MAX_SIZE) return LIST_ERROR;

    return list_addItem(temperatureListAdapter->list, (void *) temperature);
}

list_ReturnCode_t
temperatureListAdapter_getTemperature(temperatureListAdapter_t temperatureListAdapter, temperature_t *temperature,
                                      int index) {
    if (temperatureListAdapter == NULL) return LIST_NULL;
    if (temperatureListAdapter->list == NULL) return LIST_NULL;
    void *out = NULL;
    list_ReturnCode_t _result = list_getItem(temperatureListAdapter->list, &out, index);
    if (_result == LIST_NOT_FOUND) {
        temperature = NULL;
        return LIST_NOT_FOUND;
    }
    if (_result == LIST_OK) *temperature = (temperature_t) out;
    return _result;
}

list_ReturnCode_t
temperatureListAdapter_removeTemperature(temperatureListAdapter_t roomListAdapter, temperature_t temperature) {
    if (roomListAdapter == NULL) return LIST_NULL;
    if (roomListAdapter->list == NULL) return LIST_NULL;

    list_ReturnCode_t _result = list_removeItem(roomListAdapter->list, &temperature);
    return _result;
}

int temperatureListAdapter_noOfTemperatureIndicators(temperatureListAdapter_t temperatureListAdapter) {
    if (NULL == temperatureListAdapter) return -1;
    if (temperatureListAdapter->list == NULL) return -1;
    return list_noOfItems(temperatureListAdapter->list);
}