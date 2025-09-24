/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** position.hpp
*/

#ifndef POSITION_HPP_
    #define POSITION_HPP_

    #include <iostream>
    #include <SFML/System/Vector2.hpp>
    #include <SFML/System/Vector3.hpp>

struct Position2 : public sf::Vector2f {
    Position2() = default;
    Position2(float value_x, float value_y);
    Position2(const sf::Vector2f&);
};

struct Position3 : public sf::Vector3f {
    Position3() = default;
    Position3(float value_x, float value_y, float value_z);
    Position3(const sf::Vector3f&);
};

#endif 
