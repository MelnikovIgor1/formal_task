cmake_minimum_required(VERSION 3.16)
project(FormalPractice1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(out main.cpp machine.cpp
)

find_package( Threads )
find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Test Tests.cpp Tests.h test_main.cpp machine.cpp)
target_link_libraries(Test ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

