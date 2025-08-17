/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** InGame.cpp
*/

#include "scenes/InGame.hpp"

#include "components/ig_cmpts.hpp"
#include "systems/ig_sys.hpp"

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
    _reg.registerComponent<Drawable>();
    _reg.registerComponent<Window>();
    _reg.registerComponent<Player>();

    _reg.addSystem(&movement2_sys);
    _reg.addSystem(&manageEvent);
    _reg.addSystem(&draw_sys);
    _reg.addSystem(&display_sys);
}

void InGame::setEntities(void)
{
    _reg.addComponent(MAIN_WINDOW, Window());
    _reg.addComponent(PLAYER, Drawable());
    _reg.addComponent(PLAYER, Position2(100.0f, 100.0f));
    _reg.addComponent(PLAYER, Sprite(PLAYER_SPRITE_PATH));
    _reg.addComponent(PLAYER, Velocity2(0.0f, 0.0f));
    _reg.addComponent(PLAYER, Player());
}

void InGame::run(void)
{
    while (MAIN_WIN_EXIST && MAIN_WIN_ISOPEN) {
        _reg.runSystems();
    }
}
