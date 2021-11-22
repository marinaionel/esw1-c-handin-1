//
// Created by Marina Ionel on 21/04/2020.
//

#include "student.h"
#include "studentHandler.h"

main() {
    student_t student1 = student_createStudent("John", "Smith", 2000, "British");
    student_t student2 = student_createStudent("Billy", "Wick", 2001, "British");
    student_t student3 = student_createStudent("Ann", "Rock", 2002, "British");

    studentHandler_t studentHandler = studentHandler_create();

    studentHandler_addStudent(studentHandler, student1);
    studentHandler_addStudent(studentHandler, student2);
    studentHandler_addStudent(studentHandler, student3);

    student_t s1 = studentHandler_searchStudentById(studentHandler, 1);
    student_t s2 = studentHandler_searchStudentById(studentHandler, 2001);
    student_t s3 = studentHandler_searchStudentByLastName(studentHandler, "Bee");

    studentHandler_printStudentInfo(s1);
    studentHandler_printStudentInfo(s2);
    studentHandler_printStudentInfo(s3);

    studentHandler_destroy(studentHandler);
}