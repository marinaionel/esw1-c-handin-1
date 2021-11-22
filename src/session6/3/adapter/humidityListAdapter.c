//
// Created by Marina Ionel on 14/04/2020.
//

#include <corecrt_malloc.h>
#include "humidityListAdapter.h"

#define HUMIDITY_LIST_MAX_SIZE 2

typedef struct humidityListAdapter {
    list_t list;
} humidityListAdapter;

list_ReturnCode_t humidityListAdapter_destroy(humidityListAdapter_t pHumidityListAdapter) {
    if (NULL == pHumidityListAdapter)
        return LIST_NULL;

    list_destroy(pHumidityListAdapter->list);
    free(pHumidityListAdapter);
    pHumidityListAdapter = NULL;
    return LIST_OK;
}

list_ReturnCode_t humidityListAdapter_addHumidity(humidityListAdapter_t pHumidityListAdapter, humidity_t humidity) {
    if (pHumidityListAdapter == NULL) return LIST_NULL;
    if (pHumidityListAdapter->list == NULL) return LIST_NULL;

    if (list_noOfItems(pHumidityListAdapter->list) >= HUMIDITY_LIST_MAX_SIZE) return LIST_ERROR;

    return list_addItem(pHumidityListAdapter->list, (void *) humidity);
}

list_ReturnCode_t
humidityListAdapter_getHumidity(humidityListAdapter_t pHumidityListAdapter, humidity_t *humidity, int index) {
    if (pHumidityListAdapter == NULL) return LIST_NULL;
    if (pHumidityListAdapter->list == NULL) return LIST_NULL;
    void *out = NULL;
    list_ReturnCode_t _result = list_getItem(pHumidityListAdapter->list, &out, index);
    if (_result == LIST_NOT_FOUND) {
        humidity = NULL;
        return LIST_NOT_FOUND;
    }
    if (_result == LIST_OK) *humidity = (humidity_t) out;
    return _result;
}

list_ReturnCode_t
humidityListAdapter_removeHumidity(humidityListAdapter_t pHumidityListAdapter, humidity_t pHumidity) {
    if (pHumidityListAdapter == NULL) return LIST_NULL;
    if (pHumidityListAdapter->list == NULL) return LIST_NULL;

    list_ReturnCode_t _result = list_removeItem(pHumidityListAdapter->list, &pHumidity);
    return _result;
}

uint16_t humidityListAdapter_noOfHumidityIndicators(humidityListAdapter_t pHumidityListAdapter) {
    if (NULL == pHumidityListAdapter) return -1;
    return list_noOfItems(pHumidityListAdapter->list);
}

humidityListAdapter_t humidityListAdapter_create() {
    humidityListAdapter_t _HumidityListAdapter = calloc(sizeof(humidityListAdapter), 1);
    if (NULL == _HumidityListAdapter) return NULL;
    _HumidityListAdapter->list = list_create();
    return _HumidityListAdapter;
}