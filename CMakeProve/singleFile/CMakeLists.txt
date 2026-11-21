#define 

cmake_minimum_required(VERSION 4.4.5)

project(Project1)

add_executable(Project1)

target_sources(Project1 
     PRIVATE 
          main.c
     )

set_target_properties(Project1 PROPERTIES
     RUNTIME_OUTPUT_NAME ${CMAKE_SOURCE_DIR}/bin/Project1
)

