//
// Created by Marina Ionel on 02/04/2020.
//

#pragma once

#include "student.h"

typedef struct StudentHandler *studentHandler_t;

/**
 * \brief Create a new instance of the student handler
Creates and initialize a new student handler.
 * \return studentHandler_t pointer to the new instance.
 * \retval NULL Out of memory - the student handler is not created!
 * \retval and address to the new instance.
 */
studentHandler_t studentHandler_create();

/**
 * \brief Print the information about one student
*/
void studentHandler_printStudentInfo(student_t student);

/**
 * \brief Print the information about all the stored students
 * \note The studentHandler must be created before use \ref studentHandler_create.
*/
void studentHandler_printAllStudentsInfo(studentHandler_t studentHandler);

/**
 * \note The studentHandler must be created before use \ref studentHandler_create.
 * \retval NULL student was not found
 */
student_t studentHandler_searchStudentById(studentHandler_t studentHandler, int studentId);

/**
 * \brief Search a student by last name (returns the first one found)
 * \retval NULL student was not found
 */
student_t studentHandler_searchStudentByLastName(studentHandler_t studentHandler, char *lastName);

/**
 * \brief Add a student
 * \note The studentHandler must be created before use \ref studentHandler_create.
*/
void studentHandler_addStudent(studentHandler_t studentHandler, student_t student);

/**
 * \brief Destroy a student handler
 * \note The studentHandler must be created before use \ref studentHandler_create.
 * @param studentHandler the reference to the student handler to be destroyed
 */
void studentHandler_destroy(studentHandler_t studentHandler);