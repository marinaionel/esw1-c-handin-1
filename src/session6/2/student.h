//
// Created by Marina Ionel on 02/04/2020.
//

#pragma once
typedef struct Student *student_t;

student_t student_createStudent(char *firstName, char *lastName, int studentId, char *nationality);

void student_printInfo(student_t student);

char *student_getLastName(student_t student);

int student_getStudentId(student_t student);

void student_destroy(student_t student);