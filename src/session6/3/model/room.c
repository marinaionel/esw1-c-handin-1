#include <string.h>
#include "room.h"
#include "temperature.h"
#include "humidity.h"
#include "../adapter/temperatureListAdapter.h"
#include "../adapter/humidityListAdapter.h"
#include <corecrt_malloc.h>

#define TEMPERATURE_LIST_MAX_SIZE 4
#define HUMIDITY_LIST_MAX_SIZE 2

typedef struct room {
    char location[30];
    uint16_t squareMeters;
    temperatureListAdapter_t temperatureListAdapter;
    humidityListAdapter_t humidityListAdapter;
} room;

static room_roomHealth_t _calculateHealth(float average_temperature, uint8_t average_humidity) {
    return (uint16_t) (average_temperature * average_humidity) % 5;// dummy calculation;
}

void room_addTemperature(room_t room, temperature_t temperature) {
    if (room != NULL && temperature != NULL) {
        temperatureListAdapter_addTemperature(room->temperatureListAdapter, temperature);
    }
}

void room_addHumidity(room_t room, humidity_t humidity) {
    if (room != NULL && humidity != NULL) {
        humidityListAdapter_addHumidity(room->humidityListAdapter, humidity);
    }
}

room_t room_create(char *location, uint16_t sqMeter) {
    room_t _room = calloc(sizeof(room), 1);

    if (NULL == _room) return NULL;
//  because you cannot assign a pointer to a string to a character array
    strncpy_s(_room->location, 30, location, 30);
    _room->squareMeters = sqMeter;
    _room->temperatureListAdapter = temperatureListAdapter_create();
    _room->humidityListAdapter = humidityListAdapter_create();
    return _room;
}

void room_destroy(room_t self) {
    if (NULL != self) {
        temperatureListAdapter_destroy(self->temperatureListAdapter);
        humidityListAdapter_destroy(self->humidityListAdapter);
        free(self);
        self = NULL;
    }
}

static float room_calculateAverageHumidity(float humidityArray[]) {
    float _sum = 0;
    int _count = HUMIDITY_LIST_MAX_SIZE;
    for (int i = 0; i < HUMIDITY_LIST_MAX_SIZE; ++i) {
        if (humidityArray[i] == -1.0f) {
            _count--;
            continue;
        }
        _sum += humidityArray[i];
    }
    return _sum / _count;
}

static float room_calculateAverageTemperature(float temperatureArray[]) {
    float _sum = 0;
    int _count = TEMPERATURE_LIST_MAX_SIZE;
    for (int i = 0; i < TEMPERATURE_LIST_MAX_SIZE; ++i) {
        if (temperatureArray[i] == -1.0f) {
            _count--;
            continue;
        }
        _sum += temperatureArray[i];
    }
    return _sum / _count;
}

room_roomHealth_t room_getRoomHealth(room_t room) {
    float temperature_values[TEMPERATURE_LIST_MAX_SIZE] = {-1.0f, -1.0f, -1.0f, -1.0f};
    float humidity_values[HUMIDITY_LIST_MAX_SIZE] = {-1.0f, -1.0f};

    temperature_t _outTemp = NULL;
    humidity_t _outHumid = NULL;

    int _size = temperatureListAdapter_noOfTemperatureIndicators(room->temperatureListAdapter);

    for (int i = 0; i < _size; i++) {
        temperatureListAdapter_getTemperature(room->temperatureListAdapter, &_outTemp, i);
        if (_outTemp != NULL) {
            temperature_measure(_outTemp);
            float temperature = temperature_getTemperature(_outTemp);
            temperature_values[i] = temperature;
        }
    }

    for (int i = 0; i < humidityListAdapter_noOfHumidityIndicators(room->humidityListAdapter); i++) {
        humidityListAdapter_getHumidity(room->humidityListAdapter, &_outHumid, i);
        if (_outHumid != NULL) {
            humidity_measure(_outHumid);
            float humidity = humidity_getHumidity(_outHumid);
            humidity_values[i] = humidity;
        }
    }

    float _avgTemp = room_calculateAverageTemperature(temperature_values);
    float _avgHumid = room_calculateAverageHumidity(humidity_values);

    return _calculateHealth(_avgTemp, _avgHumid);
}

char *room_getRoomHealthText(room_roomHealth_t health) {
    static const char *_health_text[] = {"PERFECT", "GOOD", "AVERAGE", "BAD", "DISASTER"};
    return _health_text[health];
}

char *room_getLocation(room_t self) {
    return self->location;
}

uint16_t room_getArea(room_t self) {
    return self->squareMeters;
}