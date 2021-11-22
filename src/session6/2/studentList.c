//
// Created by Marina Ionel on 02/04/2020.
//

#include "studentList.h"
#include <corecrt_malloc.h>
#include "../1/list.h"

typedef struct StudentList {
    list_t list;
} StudentList;

studentList_t studentList_create() {
    studentList_t studentList = calloc(sizeof(StudentList), 1);
    if (NULL == studentList) return NULL;
    studentList->list = list_create();
    if (NULL == studentList->list) studentList = NULL;
    return studentList;
}


list_ReturnCode_t studentList_addStudent(studentList_t studentList, student_t student) {
    if (studentList == NULL) return LIST_NULL;
    if (studentList->list == NULL) return LIST_NULL;

    return list_addItem(studentList->list, (void **) student);
}

list_ReturnCode_t studentList_getStudent(studentList_t studentList, student_t *student, int index) {
    if (studentList == NULL) return LIST_NULL;
    if (studentList->list == NULL) return LIST_NULL;
    void *out = NULL;
    list_ReturnCode_t _result = list_getItem(studentList->list, &out, index);
    if (_result == LIST_NOT_FOUND) {
        student = NULL;
        return LIST_NOT_FOUND;
    }
    if (_result == LIST_OK) *student = (student_t) out;
    return _result;
}

list_ReturnCode_t studentList_removeStudent(studentList_t studentList, student_t student) {
    if (studentList == NULL) return LIST_NULL;
    if (studentList->list == NULL) return LIST_NULL;

    list_ReturnCode_t _result = list_removeItem(studentList->list, &student);
    return _result;
}

uint16_t studentList_noOfStudents(studentList_t studentList) {
    if (studentList == NULL) return LIST_NULL;
    if (studentList->list == NULL) return LIST_NULL;
    return list_noOfItems(studentList->list);
}

list_ReturnCode_t studentList_destroy(studentList_t studentList) {
    if (studentList == NULL) return LIST_NULL;
    student_t _tmp;
    for (int i = 0; i < studentList_noOfStudents(studentList); i++) {
        studentList_getStudent(studentList, &_tmp, i);
        student_destroy(_tmp);
    }
    if (studentList->list != NULL) list_destroy(studentList->list);
    free(studentList);
    studentList = NULL;
    return LIST_OK;
}