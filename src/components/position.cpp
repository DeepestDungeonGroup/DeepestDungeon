/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** position.cpp
*/

#include "components/position.hpp"

Position2::Position2(float value_x, float value_y) :
    sf::Vector2f(value_x, value_y)
{}

Position2::Position2(const sf::Vector2f& vect) :
    sf::Vector2f(vect)
{}

Position3::Position3(float value_x, float value_y, float value_z):
    sf::Vector3f(value_x, value_y, value_z)
{}

Position3::Position3(const sf::Vector3f& vect) :
    sf::Vector3f(vect)
{}
