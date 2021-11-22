//
// Created by Marina Ionel on 21/04/2020.
//

#include "refrigerator.h"
#include <stdio.h>

static int internalTemperature;

void refrigerator_setInternalTemperature(int temperature) {
    internalTemperature = temperature;
    printf("\nrefrigerator::The temperature of the refrigerator was changed to: %d°C", internalTemperature);
}

void refrigerator_turnOn() {
    printf("\nrefrigerator::The refrigerator started...");
}
