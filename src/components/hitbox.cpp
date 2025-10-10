/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** hitbox.cpp
*/

#include "components/hitbox.hpp"

Hitbox::Hitbox(const sf::FloatRect& rect)
{
    this->height = rect.height;
    this->width = rect.width;
    this->top = rect.top;
    this->left = rect.left;
}

Hitbox::Hitbox(const sf::Vector2f& pos, const sf::Vector2f& size)
{
    this->height = size.y;
    this->width = size.x;
    this->top = pos.y;
    this->left = pos.x;
}

Hitbox::Hitbox(float left, float top, float width, float height)
{
    this->height = height;
    this->width = width;
    this->top = top;
    this->left = left;
}
