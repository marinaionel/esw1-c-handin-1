#include <stdio.h>
#include "healthHandler.h"
#include "../adapter/roomListAdapter.h"
#include <corecrt_malloc.h>

typedef struct healthHandler {
    roomListAdapter_t roomListAdapter;
} healthHandler;


static void _printRoomHealth(room_t room) {
    char *location = room_getLocation(room);
    uint16_t area = room_getArea(room);
    room_roomHealth_t roomHealth = room_getRoomHealth(room);
    char *roomHealthText = room_getRoomHealthText(roomHealth);
    printf("%s: area: %d m2 Health: %s\n", location, area, roomHealthText);
}

void healthHandler_addRoom(healthHandler_t self, room_t room) {
    if (NULL == room || NULL == self) return;
    roomListAdapter_addRoom(self->roomListAdapter, room);
}

healthHandler_t healthHandler_create(void) {
    healthHandler_t _healthHandler = calloc(sizeof(healthHandler), 1);
    if (NULL == _healthHandler) return NULL;
    _healthHandler->roomListAdapter = roomListAdapter_create();
    return _healthHandler;
}

void healthHandler_destroy(healthHandler_t self) {
    if (self != NULL) {
        roomListAdapter_destroy(self->roomListAdapter);
        free(self);
        self = NULL;
    }
}

void healthHandler_showBuildingHealth(healthHandler_t healthHandler) {
    room_t _outRoom = NULL;
    for (int i = 0; i < roomListAdapter_noOfRooms(healthHandler->roomListAdapter); i++) {
        roomListAdapter_getRoom(healthHandler->roomListAdapter, &_outRoom, i);
        if (_outRoom != NULL) {
            _printRoomHealth(_outRoom);
        }
    }
}