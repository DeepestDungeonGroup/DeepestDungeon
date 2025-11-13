/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** interactive.cpp
*/

#include "components/interactive.hpp"

Interactive::Interactive(const sf::FloatRect& rect, const interactive_func& func)
{
    hitbox.size.y = rect.size.y;
    hitbox.size.x = rect.size.x;
    hitbox.position.y = rect.position.y;
    hitbox.position.x = rect.position.x;
    event = func;
}

Interactive::Interactive(const sf::Vector2f& pos, const sf::Vector2f& size, const interactive_func& func)
{
    hitbox.size.y = size.y;
    hitbox.size.x = size.x;
    hitbox.position.y = pos.y;
    hitbox.position.x = pos.x;
    event = func;
}

Interactive::Interactive(float left, float top, float width, float height, const interactive_func& func)
{
    hitbox.size.y = height;
    hitbox.size.x = width;
    hitbox.position.y = top;
    hitbox.position.x = left;
    event = func;
}
