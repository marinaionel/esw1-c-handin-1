//
// Created by Marina Ionel on 21/04/2020.
//

#ifndef HANDIN_DOOR_H
#define HANDIN_DOOR_H

typedef enum DoorStatus {
    OPEN, CLOSED
} DoorStatus;

DoorStatus door_getDoorStatus();

char *door_getDoorStatusText();

void door_open();

void door_close();

#endif //HANDIN_DOOR_H
