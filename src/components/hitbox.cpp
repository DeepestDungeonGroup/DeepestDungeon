/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** hitbox.cpp
*/

#include "components/hitbox.hpp"

Hitbox::Hitbox(const sf::FloatRect& rect)
{
    this->size.y = rect.size.y;
    this->size.x = rect.size.x;
    this->position.y = rect.position.y;
    this->position.x = rect.position.x;
}

Hitbox::Hitbox(const sf::Vector2f& pos, const sf::Vector2f& size)
{
    this->size.y = size.y;
    this->size.x = size.x;
    this->position.y = pos.y;
    this->position.x = pos.x;
}

Hitbox::Hitbox(float left, float top, float width, float height)
{
    this->size.y = height;
    this->size.x = width;
    this->position.y = top;
    this->position.x = left;
}
