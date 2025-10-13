/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** interactive.hpp
*/

#ifndef INTERACTIVE_HPP_
    #define INTERACTIVE_HPP_

    #include <SFML/Graphics/Rect.hpp>
    #include <functional>

    #include "Registry.hpp"

typedef std::function<void(ECS::Registry&)> interactive_func;

struct Interactive {
    Interactive(const sf::FloatRect&, const interactive_func& func = [](ECS::Registry&){});
    Interactive(const sf::Vector2f&, const sf::Vector2f&, const interactive_func& func = [](ECS::Registry&){});
    Interactive(float left, float top, float width, float height, const interactive_func& func = [](ECS::Registry&){});
    sf::FloatRect hitbox;
    interactive_func event;
};

#endif
