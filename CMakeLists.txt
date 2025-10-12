cmake_minimum_required(VERSION 3.10)
project(deepest_dungeon)

########## SETUP ##########
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src/")
set(HDR_DIR "${PROJECT_SOURCE_DIR}/include/")

########## SFML ##########
find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

########## ECS ##########
add_subdirectory(ECS)

########## BINARY ##########
add_executable( ${PROJECT_NAME}
    ${SRC_DIR}main.cpp
    ${SRC_DIR}map_reader.cpp
    ${SRC_DIR}hitbox_management.cpp

    # components
    ${SRC_DIR}components/position.cpp
    ${SRC_DIR}components/velocity.cpp
    ${SRC_DIR}components/sprite.cpp
    ${SRC_DIR}components/window.cpp
    ${SRC_DIR}components/hitbox.cpp
    ${SRC_DIR}components/clock.cpp

    # systems
    ${SRC_DIR}systems/display.cpp
    ${SRC_DIR}systems/event.cpp
    ${SRC_DIR}systems/movement.cpp
    ${SRC_DIR}systems/draw.cpp
    ${SRC_DIR}systems/view_player.cpp

    # scenes
    ${SRC_DIR}scenes/InGame.cpp
)

########## LINKAGE ##########
target_include_directories( ${PROJECT_NAME}
    PRIVATE
        ${HDR_DIR}
)

target_link_libraries( ${PROJECT_NAME}
    sfml-graphics
    sfml-audio
    sfml-window
    sfml-system
    ECS
)
