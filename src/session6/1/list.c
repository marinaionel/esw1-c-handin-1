//
// Created by Marina Ionel on 23/03/2020.
//

#include "list.h"
#include <stdint.h>
#include <corecrt_malloc.h>

typedef struct node {
	void* item;
	struct node* next;
} node;

typedef struct node* node_t;

typedef struct list {
	uint16_t size;
	node_t* root;
} list;

list_t list_create() {
	list_t _list = calloc(sizeof(list), 1);

	//the allocation wasn't possible
	if (NULL == _list) return NULL;

	//initialize the fields
	_list->root = NULL;
	_list->size = 0;

	//return the reference to the created list object
	return _list;
}

list_ReturnCode_t list_destroy(list_t self) {
	if (NULL == self) return LIST_NULL;

	node_t _root = (node_t)self->root;

	//a temporary variable which will store the next node after root in order to free the root at every iteration
	node_t _tmp;

	//free every node in the list
	while (NULL != _root) {
		_tmp = _root->next;
		free(_root);
		_root = _tmp;
	}

	//free the list itself
	free(self);
	return LIST_OK;
}

uint16_t list_noOfItems(list_t list) {
	if (NULL == list) return -1;
	return list->size;
}

static node_t* linkedList_nodeCreate(void* data) {
	node_t _node = calloc(sizeof(struct node), 1);

	//the allocation wasn't possible
	if (!_node) return NULL;

	//initialize the fields
	_node->item = data;
	_node->next = NULL;

	//return the reference to the created node object
	return (node_t*)_node;
}

list_ReturnCode_t list_addItem(list_t self, void* item) {
	if (self == NULL) return LIST_NULL;
	node_t _tmp = NULL;
	if (NULL == self->root) {
		node_t _node = (node_t)linkedList_nodeCreate(item);
		if (NULL == _node)
			//          Out of memory - the item is NOT added to the linked self.
			return LIST_ERROR;
		self->root = (node_t*)_node;
	}
	else {
		_tmp = (node_t)self->root;

		//a loop to find the last node
		while (_tmp->next != NULL) {
			_tmp = _tmp->next;
		}
		node_t _node = (node_t)linkedList_nodeCreate(item);
		if (NULL == _node)
			//          Out of memory - the item is NOT added to the linked self.
			return LIST_ERROR;
		_tmp->next = _node;
	}
	self->size++;
	return LIST_OK;
}

list_ReturnCode_t list_getItem(list_t self, void** item, uint16_t index) {
	if (NULL == self) return LIST_NULL;
	if (NULL == self->root || index >= list_noOfItems(self) || index < 0) {
		*item = NULL;
		return LIST_NOT_FOUND;
	}

	node_t _tmp = (node_t)self->root;
	uint16_t counter = 0;

	while (NULL != _tmp) {
		if (counter == index) {
			*item = _tmp->item;
			return LIST_OK;
		}
		//go to the next node
		_tmp = _tmp->next;
		counter++;
	}
	*item = NULL;
	return LIST_NOT_FOUND;
}

list_ReturnCode_t list_removeItem(list_t self, void* item) {
	if (NULL == self) return LIST_NULL;
	if (NULL == self->root) return LIST_NOT_FOUND;

	node_t _tmp = (node_t)self->root;
	node_t pre = NULL;

	while (_tmp != NULL) {
		if (_tmp->item == item) {
			if (NULL == pre) {
				self->root = (node_t*)_tmp->next;
			}
			else {
				pre->next = _tmp->next;
			}
			free(_tmp);
			self->size--;
			return LIST_OK;
		}
		pre = _tmp;
		_tmp = _tmp->next;
	}
	return LIST_NOT_FOUND;
}