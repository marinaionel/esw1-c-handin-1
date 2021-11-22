#include "student.h"
#include <corecrt_malloc.h>
#include <stdio.h>
#include <string.h>

//
// Created by Marina Ionel on 02/04/2020.
//
typedef struct Student {
    char *firstName;
    char *lastName;
    int studentId;
    char *nationality;
} Student;

student_t student_createStudent(char *firstName, char *lastName, int studentId, char *nationality) {
    student_t _student = calloc(sizeof(Student), 1);

    //the allocation wasn't possible
    if (NULL == _student) return NULL;

    //initialize the fields
    _student->firstName = firstName;
    _student->lastName = lastName;
    _student->studentId = studentId;
    _student->nationality = nationality;

    //return the reference to the created list object
    return _student;
}

void student_printInfo(student_t student) {
    printf("\nContents of structure student{");
    printf("\nstudentId: %d", student->studentId);
    printf("\nfirstName: %s", student->firstName);
    printf("\nlastName: %s", student->lastName);
    printf("\nnationality: %s", student->nationality);
    printf("\n}");
}

int student_getStudentId(student_t student) {
    if (NULL == student) return -1;
    return student->studentId;
}

char *student_getLastName(student_t student) {
    if (student == NULL) return NULL;
    return student->lastName;
}

void student_destroy(student_t student) {
    free(student);
    student = NULL;
}