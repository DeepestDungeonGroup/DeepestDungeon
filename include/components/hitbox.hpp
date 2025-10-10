/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** hitbox.hpp
*/

#ifndef HITBOX_HPP_
    #define HITBOX_HPP_

    #include <SFML/Graphics/Rect.hpp>

struct Hitbox : public sf::FloatRect {
    Hitbox(const sf::FloatRect&);
    Hitbox(const sf::Vector2f&, const sf::Vector2f&);
    Hitbox(float left, float top, float width, float height);
};

#endif