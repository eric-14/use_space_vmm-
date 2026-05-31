cmake_minimum_required(VERSION 3.28)
project(spartan)

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/spartan")

find_program(CLANG_FORMAT_EXE clang-format REQUIRED)
if(CLANG_FORMAT_EXE)

    file(GLOB_RECURSE ALL_C_SOURCE_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.c" 
    )
    if(NOT ALL_C_SOURCE_FILES)
        message(FATAL_ERROR "ALL_C_SOURCE_FILES is empty. Check your GLOB pattern.")
    endif()
    add_custom_target(
        format 
        COMMAND ${CLANG_FORMAT_EXE} -i -style=file ${ALL_C_SOURCE_FILES}
        COMMENT "Running Clang format....."
    )
endif()