/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** map_management.hpp
*/

#ifndef MAP_MANAGEMENT_HPP_
    #define MAP_MANAGEMENT_HPP_

    #include <string>
    #include <map>

    #include "Registry.hpp"

    #define MAP_MAX_WIDTH 100 /* Maximim width readed from file */
    #define MAP_MAX_HEIGHT 100 /* Maximum heigth readed from file */
    
    #define MAP_ENTITY_PLAYER 999 /* Player entity pose in sparse array */
    #define MAP_ENTITY_BACKGROUND 1000 /* First wall entity pose in sparse array */
    #define MAP_MAX_ENTITY_BACKGROUND MAP_ENTITY_BACKGROUND + MAP_MAX_WIDTH * MAP_MAX_HEIGHT


    #define SQUARE_WIDTH 50
    #define SQUARE_HEIGHT 50

static const std::string MAP_EXTENTION(".ddmap"); /* Extention for map initialisation */

void load_map(ECS::Registry& reg, const std::string& path);

enum MAP_TYPES : char {
    MAP_WALL = 'X',
    MAP_PLAYER = 'P',
    MAP_DOOR = 'D',
};

static const std::map<std::string, std::string> MAPS_PATHS = {
    {"test1", "./assets/maps/test1.ddmap"},
    {"test2", "./assets/maps/test2.ddmap"},
};

#endif
