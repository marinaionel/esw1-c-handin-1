//
// Created by Marina Ionel on 30/03/2020.
//

#pragma once

#include "../model/room.h"
#include "../../1/list.h"

typedef struct RoomListAdapter *roomListAdapter_t;

roomListAdapter_t roomListAdapter_create();

list_ReturnCode_t roomListAdapter_addRoom(roomListAdapter_t roomListAdapter, room_t room);

list_ReturnCode_t roomListAdapter_getRoom(roomListAdapter_t roomListAdapter, room_t* room, int index);

list_ReturnCode_t roomListAdapter_removeRoom(roomListAdapter_t roomListAdapter, room_t room);

uint16_t roomListAdapter_noOfRooms(roomListAdapter_t roomListAdapter);

list_ReturnCode_t roomListAdapter_destroy(roomListAdapter_t roomListAdapter);
