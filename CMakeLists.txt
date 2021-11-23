cmake_minimum_required(VERSION 3.16)
project(handin LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        list_tests
        src/session9/list_tests/list_tests.cc
)
target_link_libraries(
        list_tests
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(list_tests)

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
