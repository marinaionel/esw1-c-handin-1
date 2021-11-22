#include "refrigerator.h"
#include "refrigerator_controller.h"
#include "door.h"

//
// Created by Marina Ionel on 21/04/2020.
//
#include <locale.h>

void main() {
    setlocale(LC_ALL, "");

    refrigerator_turnOn();
    refrigeratorController_create();

    refrigeratorController_setLevel(4);

    door_open();
    refrigeratorController_setLevel(5);

    door_close();
}
