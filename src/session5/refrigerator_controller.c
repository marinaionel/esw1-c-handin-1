//
// Created by Marina Ionel on 21/04/2020.
//

#include "refrigerator_controller.h"
#include "door.h"
#include <stdio.h>

static int currentLevel;

void refrigeratorController_create() {
    refrigeratorController_setLevel(3);
}

ResultInfo refrigeratorController_setLevel(int level) {
    if (level < 1 || level > 5) {
        printf("\nrefrigerator_controller::INVALID_ARGUMENT::Invalid level");
        return INVALID_ARGUMENT;
    }
    if (door_getDoorStatus() == CLOSED) {
        printf("\nrefrigerator_controller::ERROR::The door is closed");
        return ERROR;
    }
    currentLevel = level;

    printf("\nrefrigerator_controller::The level was set to %d", level);

    switch (currentLevel) {
        case 1:
            refrigerator_setInternalTemperature(1);
            break;
        case 2:
            refrigerator_setInternalTemperature(2);
            break;
        case 3:
            refrigerator_setInternalTemperature(3);
            break;
        case 4:
            refrigerator_setInternalTemperature(4);
            break;
        case 5:
            refrigerator_setInternalTemperature(5);
            break;
        default:
            break;
    }
    return OK;
}