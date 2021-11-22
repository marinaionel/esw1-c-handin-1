cmake_minimum_required(VERSION 3.16)
project(handin C)

set(CMAKE_C_STANDARD 11)

##start GoogleTests
#configure_file(CMakeLists.txt.in freertos_exercises/CMakeLists.txt)
#execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
#        RESULT_VARIABLE result
#        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
#if (result)
#    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
#endif ()
#execute_process(COMMAND ${CMAKE_COMMAND} --build .
#        RESULT_VARIABLE result
#        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
#if (result)
#    message(FATAL_ERROR "Build step for googletest failed: ${result}")
#endif ()
#
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#
#add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
#        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
#        EXCLUDE_FROM_ALL)
#
#if (CMAKE_VERSION VERSION_LESS 2.8.11)
#    include_directories("${gtest_SOURCE_DIR}/include")
#endif ()
##end GoogleTests

add_executable(handin src/session1/ex2.c)
add_executable(ex1 src/session1/ex1.c)
add_executable(fahrenheit src/session1/fahrenheit.c)
add_executable(celsius src/session1/celsius.c)
add_executable(main src/session2/main.c src/session2/subtraction.c src/session2/subtraction.h src/session2/addition.c src/session2/addition.h src/session2/multiplication.c src/session2/multiplication.h)
add_executable(divide_7_with_3 src/session3/divide_7_with_3.c)
add_executable(exercise_3_2_how_does_string_character_arrays_work_in_c src/session3/exercise_3_2_how_does_string_character_arrays_work_in_c.c)
add_executable(calling_functions src/session3/calling_functions.c)
add_executable(my_string_func src/session3/my_string_func.c src/session3/main.c src/session3/my_string_func.h)
add_executable(myStr src/session4/myStr.c src/session4/myStr.h src/session4/main.c)
add_executable(list src/session6/1/list.c src/session6/1/list.h src/session6/1/main.c)
add_executable(refrigerator src/session5/refrigerator.h src/session5/refrigerator.c src/session5/light.c src/session5/light.h src/session5/door.c src/session5/door.h src/session5/refrigerator_controller.c src/session5/refrigerator_controller.h src/session5/main.c)
add_executable(student src/session6/1/list.c
        src/session6/1/list.h
        src/session6/2/student.c
        src/session6/2/student.h
        src/session6/2/studentHandler.c
        src/session6/2/studentHandler.h
        src/session6/2/studentList.h
        src/session6/2/studentList.c
        src/session6/2/main.c)
add_executable(room_health
        src/session6/1/list.c
        src/session6/1/list.h
        src/session6/3/adapter/humidityListAdapter.c
        src/session6/3/adapter/humidityListAdapter.h
        src/session6/3/adapter/roomListAdapter.c
        src/session6/3/adapter/roomListAdapter.h
        src/session6/3/adapter/temperatureListAdapter.c
        src/session6/3/adapter/temperatureListAdapter.h
        src/session6/3/driver/humidityDriver.c
        src/session6/3/driver/humidityDriver.h
        src/session6/3/driver/humidityDriver.h
        src/session6/3/driver/tempDriver.c
        src/session6/3/handler/healthHandler.c
        src/session6/3/handler/healthHandler.h
        src/session6/3/model/humidity.c
        src/session6/3/model/humidity.h
        src/session6/3/model/room.c
        src/session6/3/model/room.h
        src/session6/3/model/temperature.c
        src/session6/3/model/temperature.h
        src/session6/3/main.c)