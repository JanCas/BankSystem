# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.17)

project(BankSystem C)

set(CMAKE_C_STANDARD 11)

add_executable(
        bankSystem.c user.c user.h file_utils.c file_utils.h main.c bankSystem.h)

file(GLOB MY_FILES "*.dat")
file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
