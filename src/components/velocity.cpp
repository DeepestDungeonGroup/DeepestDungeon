/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** velocity.cpp
*/

#include "components/velocity.hpp"

Velocity2::Velocity2(float value_x, float value_y) :
    sf::Vector2f(value_x, value_y)
{}

Velocity2::Velocity2(const sf::Vector2f& vect) :
    sf::Vector2f(vect)
{}

Velocity3::Velocity3(float value_x, float value_y, float value_z) :
    sf::Vector3f(value_x, value_y, value_z)
{}

Velocity3::Velocity3(const sf::Vector3f& vect) :
    sf::Vector3f(vect)
{}

