//
// Created by Marina Ionel on 02/04/2020.
//

#include "studentHandler.h"
#include "studentList.h"
#include <corecrt_malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct StudentHandler {
    studentList_t studentList;
} StudentHandler;

studentHandler_t studentHandler_create() {
    studentHandler_t _studentHandler = calloc(sizeof(StudentHandler), 1);
    if (NULL == _studentHandler) return NULL;
    _studentHandler->studentList = studentList_create();
    if (_studentHandler->studentList == NULL) return NULL;
    return _studentHandler;
}

void studentHandler_printStudentInfo(student_t student) {
    if (student == NULL) {
        printf("\nNULL Student");
        return;
    }
    student_printInfo(student);
}

void studentHandler_printAllStudentsInfo(studentHandler_t studentHandler) {
    if (studentHandler == NULL) {
        printf("NULL StudentHandler");
        return;
    }
    uint16_t size = studentList_noOfStudents(studentHandler->studentList);
    student_t _tmp = NULL;
    for (uint16_t i = 0; i < size; i++) {
        studentList_getStudent(studentHandler->studentList, &_tmp, i);
        if (_tmp != NULL) student_printInfo(_tmp);
    }
}

student_t studentHandler_searchStudentById(studentHandler_t studentHandler, int studentId) {
    if (studentHandler == NULL) return NULL;
    student_t _student = NULL;
    int increment = 0;
    while (increment < studentList_noOfStudents(studentHandler->studentList)) {
        studentList_getStudent(studentHandler->studentList, &_student, increment);
        if (student_getStudentId(_student) == studentId) return _student;
        increment++;
    }
    _student = NULL;
    return _student;
}

student_t studentHandler_searchStudentByLastName(studentHandler_t studentHandler, char *lastName) {
    if (studentHandler == NULL) return NULL;
    student_t _student = NULL;
    int increment = 0;
    while (increment < studentList_noOfStudents(studentHandler->studentList)) {
        studentList_getStudent(studentHandler->studentList, &_student, increment);
        if (strcmp(student_getLastName(_student), lastName) == 0) return _student;
        increment++;
    }
    _student = NULL;
    return _student;
}

void studentHandler_addStudent(studentHandler_t studentHandler, student_t student) {
    if (studentHandler == NULL) {
        printf("NULL StudentHandler");
        return;
    }
    if (studentHandler->studentList == NULL) {
        printf("NULL StudentList");
        return;
    }

    studentList_addStudent(studentHandler->studentList, student);
}

void studentHandler_destroy(studentHandler_t studentHandler) {
    if (studentHandler == NULL) return;
    if (studentHandler->studentList != NULL) studentList_destroy(studentHandler->studentList);
    free(studentHandler);
    studentHandler = NULL;
}