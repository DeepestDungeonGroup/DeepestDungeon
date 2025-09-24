cmake_minimum_required(VERSION 3.10)
project(ECS)

########## SETUP ##########
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(ECS_SRC_DIR "${PROJECT_SOURCE_DIR}/src/")
set(ECS_HDR_DIR "${PROJECT_SOURCE_DIR}/include/")

########## ECS ##########
add_library( ${PROJECT_NAME} STATIC
    ${ECS_SRC_DIR}Registry.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${ECS_HDR_DIR}
)

