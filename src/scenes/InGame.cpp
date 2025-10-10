/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** InGame.cpp
*/

#include "scenes/in_game/InGame.hpp"

#include "scenes/in_game/in_game.cpmt.hpp"
#include "scenes/in_game/in_game.sys.hpp"

InGame::InGame()
{
    setECS();
    setEntities();
}

void InGame::setECS(void)
{
    _reg.registerComponent<Drawable>();
    _reg.registerComponent<Position2>();
    _reg.registerComponent<Velocity2>();
    _reg.registerComponent<Sprite>();
    _reg.registerComponent<Window>();
    _reg.registerComponent<Player>();
    _reg.registerComponent<Hitbox>();

    _reg.addSystem(&movement2_sys);
    _reg.addSystem(&manageEvent);
    _reg.addSystem(&follow_player_sys);
    _reg.addSystem(&draw_sys);
    _reg.addSystem(&display_sys);
}

void InGame::setEntities(void)
{
    _reg.addComponent(MAIN_WINDOW, Window());
    _reg.addComponent(PLAYER, Drawable());
    _reg.addComponent(PLAYER, Position2(100.0f, 100.0f));
    _reg.addComponent(PLAYER, Sprite(sf::IntRect(0, 0, 30, 30), sf::Color::Blue));
    _reg.addComponent(PLAYER, Velocity2(0.0f, 0.0f));
    _reg.addComponent(PLAYER, Player());
    _reg.addComponent(PLAYER, Hitbox(0.0f, 0.0f, 30.0f, 30.0f));
    _reg.addComponent(BACKGROUND_1, Drawable());
    _reg.addComponent(BACKGROUND_1, Position2(0.0f, 0.0f));
    _reg.addComponent(BACKGROUND_1, Sprite(sf::IntRect(0, 0, 20, 20), sf::Color::Red));
    _reg.addComponent(BACKGROUND_1, Hitbox(0.0f, 0.0f, 20.0f, 20.0f));
    _reg.addComponent(BACKGROUND_2, Drawable());
    _reg.addComponent(BACKGROUND_2, Position2(20.0f, 10.0f));
    _reg.addComponent(BACKGROUND_2, Sprite(sf::IntRect(0, 0, 20, 20), sf::Color::Red));
    _reg.addComponent(BACKGROUND_2, Hitbox(0.0f, 0.0f, 20.0f, 20.0f));
    _reg.addComponent(BACKGROUND_3, Drawable());
    _reg.addComponent(BACKGROUND_3, Position2(-5.0f, 15.0f));
    _reg.addComponent(BACKGROUND_3, Sprite(sf::IntRect(0, 0, 20, 20), sf::Color::Red));
    _reg.addComponent(BACKGROUND_3, Hitbox(0.0f, 0.0f, 20.0f, 20.0f));
}

void InGame::run(void)
{
    while (MAIN_WIN_EXIST && MAIN_WIN_ISOPEN) {
        _reg.runSystems();
    }
}
