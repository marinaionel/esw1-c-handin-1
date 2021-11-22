#pragma once
/**
\file
\author Ib Havn
\version 1.0.0
	Linked list.
*/
#include <stdint.h>

/** 
Pointer to the list instance.
*/
typedef struct list * list_t;

/**
\brief Linked List return codes.
These are the codes that can be returned the linked lists functions.
*/
typedef enum {
    LIST_OK /**< Everything went well */
    ,LIST_EMPTY /**< The List is empty */
    ,LIST_NOT_FOUND /**< The item was not found in the list */
    ,LIST_NULL /**< The list pointer is NULL */
    ,LIST_ERROR /**< The function could not be completed due to memory limit */
} list_ReturnCode_t;

/* ======================================================================================================================= */
/**
\brief Create a new instance of the linked list
Creates and initialize a new linked list.
\return list_t pointer to the new instance.
\retval NULL Out of memory - the list is not created!
\retval and address to the new instance.
*/
list_t list_create(void);

/* ======================================================================================================================= */
/**
\brief Destroy a linked list
Removes all nodes and cleans up memory for the linked list. 
\note The list must be created before use \ref list_create.
\note The Items are not removed - that is up to the user.
\return list_ReturnCode_t.
\retval LIST_OK The list is detroyed.
\retval LIST_NULL The list pointer must not be NULL.
*/
list_ReturnCode_t list_destroy(list_t self);

/* ======================================================================================================================= */
/**
\brief Add an item to the linked list.
\note The list must be created before use \ref list_create.
\param[in] self pointer to the list to add the item to.
\param[in] *item pointer to the item to add to the list.
\return list_ReturnCode_t.
\retval LIST_OK The item is added to the linked list.
\retval LIST_NULL The list pointer must not be NULL.
\retval LIST_ERROR Out of memory - the item is NOT added to the linked list.
*/
list_ReturnCode_t list_addItem(list_t self, void* item);


/* ======================================================================================================================= */
/**
\brief Get an item from the linked list.
\note The list must be created before use \ref list_create.
\note  The item is not removed from the list - if removal is wanted then use \ref list_removeItem.
\param[in] self pointer to the list to get the item from.
\param[out] **item pointer to the pointer where the items address will be returned.
\param[in] index to the item in the list to get.
\return list_ReturnCode_t.
\retval LIST_OK The item is found and item is pointing to the item found.
\retval LIST_NULL The list pointer must not be NULL.
\retval LIST_NOT_FOUND the item is not found in the list and item will be assigned to NULL.
*/
list_ReturnCode_t list_getItem(list_t self, void** item, uint16_t index);

/* ======================================================================================================================= */
/**
\brief Remove an item from the linked list.
\note The list must be created before use \ref list_create.
\param[in] self pointer to the list to remove the item from.
\param[in] *item pointer to the item that will be removed.
\return list_ReturnCode_t.
\retval LIST_OK The item is found and removed from the list.
\retval LIST_NULL The list pointer must not be NULL.
\retval LIST_NOT_FOUND the item is not found in the list.
*/
list_ReturnCode_t list_removeItem(list_t self, void* item);

/* ======================================================================================================================= */
/**
\brief Get no of items currently in the linked list.
\note The list must be created before use \ref list_create.
\param[in] self pointer to the list to get the item from.
\return No of items in the list.
*/
uint16_t list_noOfItems(list_t self);