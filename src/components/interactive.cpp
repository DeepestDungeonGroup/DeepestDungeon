/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** interactive.cpp
*/

#include "components/interactive.hpp"

Interactive::Interactive(const sf::FloatRect& rect, const interactive_func& func)
{
    hitbox.height = rect.height;
    hitbox.width = rect.width;
    hitbox.top = rect.top;
    hitbox.left = rect.left;
    event = func;
}

Interactive::Interactive(const sf::Vector2f& pos, const sf::Vector2f& size, const interactive_func& func)
{
    hitbox.height = size.y;
    hitbox.width = size.x;
    hitbox.top = pos.y;
    hitbox.left = pos.x;
    event = func;
}

Interactive::Interactive(float left, float top, float width, float height, const interactive_func& func)
{
    hitbox.height = height;
    hitbox.width = width;
    hitbox.top = top;
    hitbox.left = left;
    event = func;
}
