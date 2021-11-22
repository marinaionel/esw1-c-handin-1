//
// Created by Marina Ionel on 30/03/2020.
//

#include "roomListAdapter.h"
#include <corecrt_malloc.h>

#define ROOM_LIST_ADAPTER_MAX_SIZE 10

typedef struct RoomListAdapter {
    list_t list;
} RoomListAdapter;

roomListAdapter_t roomListAdapter_create() {
    roomListAdapter_t _roomListAdapter = calloc(sizeof(RoomListAdapter), 1);
    if (NULL == _roomListAdapter) return NULL;
    _roomListAdapter->list = list_create();
    if (NULL == _roomListAdapter->list) return NULL;
    return _roomListAdapter;
}


list_ReturnCode_t roomListAdapter_addRoom(roomListAdapter_t roomListAdapter, room_t room) {
    if (roomListAdapter == NULL) return LIST_NULL;
    if (roomListAdapter->list == NULL) return LIST_NULL;

    if (list_noOfItems(roomListAdapter->list) >= ROOM_LIST_ADAPTER_MAX_SIZE) return LIST_ERROR;

    return list_addItem(roomListAdapter->list, (void *) room);
}

list_ReturnCode_t roomListAdapter_getRoom(roomListAdapter_t roomListAdapter, room_t* room, int index) {
    if (roomListAdapter == NULL) return LIST_NULL;
    if (roomListAdapter->list == NULL) return LIST_NULL;
    void *_outRoom_ = NULL;
    list_ReturnCode_t _result = list_getItem(roomListAdapter->list, &_outRoom_, index);
    if (_result == LIST_NOT_FOUND) {
        room = NULL;
        return LIST_NOT_FOUND;
    }
    if (_result == LIST_OK) *room = (room_t) _outRoom_;
    return _result;
}

list_ReturnCode_t roomListAdapter_removeRoom(roomListAdapter_t roomListAdapter, room_t room) {
    if (roomListAdapter == NULL) return LIST_NULL;
    if (roomListAdapter->list == NULL) return LIST_NULL;

    list_ReturnCode_t _result = list_removeItem(roomListAdapter->list, &room);
    return _result;
}

uint16_t roomListAdapter_noOfRooms(roomListAdapter_t roomListAdapter) {
    if (NULL == roomListAdapter) return -1;
    return list_noOfItems(roomListAdapter->list);
}

list_ReturnCode_t roomListAdapter_destroy(roomListAdapter_t roomListAdapter) {
    if (NULL == roomListAdapter)
        return LIST_NULL;

    list_destroy(roomListAdapter->list);
    free(roomListAdapter);
    roomListAdapter = NULL;
    return LIST_OK;
}
