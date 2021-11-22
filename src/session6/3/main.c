#include <time.h>
#include <stdbool.h>
#include "model/temperature.h"
#include "model/humidity.h"
#include "model/room.h"
#include "handler/healthHandler.h"

bool temperature_metricUnits = true; // Definition

static void _delayMs(int milliseconds) {
    long _pause;
    clock_t _now, _then;

    _pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    _now = _then = clock();
    while ((_now - _then) < _pause)
        _now = clock();
}

static healthHandler_t _setupApplication(void) {
    healthHandler_t healthHandler = healthHandler_create();

    room_t livingRoom = room_create("Living Room", 75);

    temperature_t t0 = temperature_create(0);
    room_addTemperature(livingRoom, t0);

    temperature_t t1 = temperature_create(1);
    room_addTemperature(livingRoom, t1);

    humidity_t h1 = humidity_create(1);
    room_addHumidity(livingRoom, h1);

    healthHandler_addRoom(healthHandler, livingRoom);

    room_t kitchen = room_create("Kitchen", 40);

    temperature_t t2 = temperature_create(2);
    room_addTemperature(kitchen, t2);

    humidity_t h2 = humidity_create(2);
    room_addHumidity(kitchen, h2);

    healthHandler_addRoom(healthHandler, kitchen);

    return healthHandler;
}

static void _runApplication(healthHandler_t healthHandler) {
    while (1) {
        healthHandler_showBuildingHealth(healthHandler);
        _delayMs(1000);
    }
}

int main(void) {
    _runApplication(_setupApplication());

    return 0;
}