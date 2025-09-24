/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** sprite.cpp
*/

#include "components/sprite.hpp"

Sprite::Sprite(const std::string& path)
{
    texture.loadFromFile(path);
    setTexture(texture);
}

Sprite::Sprite(Sprite&& sprite)
{
    texture = sprite.texture;
    setTexture(texture);
}

Sprite::Sprite(const Sprite& sprite)
{
    texture = sprite.texture;
    setTexture(texture);
}
