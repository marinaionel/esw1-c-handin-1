//
// Created by Marina Ionel on 02/04/2020.
//

#pragma once

#include "student.h"
#include "../1/list.h"

typedef struct StudentList *studentList_t;

studentList_t studentList_create();

list_ReturnCode_t studentList_addStudent(studentList_t studentList, student_t student);

list_ReturnCode_t studentList_getStudent(studentList_t studentList, student_t* student, int index);

list_ReturnCode_t studentList_removeStudent(studentList_t studentList, student_t student);

uint16_t studentList_noOfStudents(studentList_t studentList);

list_ReturnCode_t studentList_destroy(studentList_t studentList);