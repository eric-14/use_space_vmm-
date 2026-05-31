cmake_minimum_required(VERSION 3.28)
project(spartan)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_CLANG_TIDY "clang-tidy;-checks=-*,readability-*")
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


find_program(CLANG_TIDY_EXE clang-tidy REQUIRED)

if(CLANG_TIDY_EXE)
  
    add_custom_target(tidy
    COMMAND ${CLANG_TIDY_EXE}
            -checks=-*,readability-*
            ${ALL_C_SOURCE_FILES}
            --
            -I${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Running clang tidy on spartan"
)   
endif()


add_executable(spartan main.c)
# add_dependencies(spartan format)
# add_dependencies(spartan tidy)