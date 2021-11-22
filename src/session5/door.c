//
// Created by Marina Ionel on 21/04/2020.
//

#include "door.h"
#include <stdio.h>

static DoorStatus currentStatus = CLOSED;

DoorStatus door_getDoorStatus() {
    return currentStatus;
}

char *door_getDoorStatusText() {
    if (currentStatus == OPEN) return "OPEN";
    else return "CLOSED";
}

static void door_printDoorStatus(){
    printf("door::The door is %s", door_getDoorStatusText());
}

void door_open() {
    currentStatus = OPEN;
    door_printDoorStatus();
}

void door_close() {
    currentStatus = CLOSED;
    door_printDoorStatus();
}



