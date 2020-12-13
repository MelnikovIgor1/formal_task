cmake_minimum_required(VERSION 3.16)
project(FormalPractice1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror --coverage")

add_compile_options(
    --coverage
    )

add_executable(out main.cpp machine.cpp)

find_package( Threads )
find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Test Tests.cpp test_main.cpp machine.cpp)

find_program(GCOVR_EXECUTABLE gcovr)
if(MYLIB_COVERAGE AND GCOVR_EXECUTABLE)
    message(STATUS "Измерение покрытия кода тестами включено")

    target_compile_options(Test PRIVATE --coverage)
    target_link_libraries(Test PRIVATE gcov ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

    add_custom_target(coverage
        COMMAND
            ${GCOVR_EXECUTABLE}
                --root=${PROJECT_SOURCE_DIR}/include/
                --object-directory=${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS
            check
    )
elseif(MYLIB_COVERAGE AND NOT GCOVR_EXECUTABLE)
    set(MYLIB_COVERAGE OFF)
    message(WARNING "Для замеров покрытия кода тестами требуется программа gcovr")
endif()



