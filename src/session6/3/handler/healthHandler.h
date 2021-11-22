#pragma once

#include "../model/room.h"

typedef struct healthHandler *healthHandler_t;

healthHandler_t healthHandler_create(void);

void healthHandler_showBuildingHealth(healthHandler_t healthHandler);

void healthHandler_addRoom(healthHandler_t self, room_t room);

void healthHandler_destroy(healthHandler_t self);