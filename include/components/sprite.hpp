/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** sprite.hpp
*/

#ifndef SPRITE_HPP_
    #define SPRITE_HPP_

    #include <string>
    #include <SFML/Graphics/Texture.hpp>
    #include <SFML/Graphics/Sprite.hpp>

struct Sprite : public sf::Sprite {
    Sprite() = default;
    Sprite(const sf::IntRect&, const sf::Color&);
    Sprite(const std::string&);
    Sprite(const Sprite&);
    Sprite(Sprite&&);

    sf::Texture texture;
};

#endif
