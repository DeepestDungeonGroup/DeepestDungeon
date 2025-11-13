/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** sprite.hpp
*/

#ifndef SPRITE_HPP_
    #define SPRITE_HPP_

    #include <SFML/Graphics/Sprite.hpp>
    #include <SFML/Graphics/Texture.hpp>

struct Sprite : public sf::Sprite {
    Sprite(const sf::Texture& texture) : sf::Sprite(texture) {};
};

#endif
