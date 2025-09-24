/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** velocity.hpp
*/

#ifndef VELOCITY_HPP_
    #define VELOCITY_HPP_

    #include <SFML/System/Vector2.hpp>
    #include <SFML/System/Vector3.hpp>

struct Velocity2 : public sf::Vector2f {
    Velocity2() = default;
    Velocity2(float value_x, float value_y);
    Velocity2(const sf::Vector2f&);
};

struct Velocity3 : public sf::Vector3f {
    Velocity3() = default;
    Velocity3(float value_x, float value_y, float value_z);
    Velocity3(const sf::Vector3f&);
};

#endif 
