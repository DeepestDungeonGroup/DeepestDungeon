/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** InGame.cpp
*/

#include "scenes/in_game/InGame.hpp"

#include "scenes/in_game/in_game.cpmt.hpp"
#include "scenes/in_game/in_game.sys.hpp"
#include "components/clock.hpp"

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
    _reg.registerComponent<Interactive>();

    _reg.addSystem(&movement2_sys);
    _reg.addSystem(&player_interaction_sys);
    _reg.addSystem(&manageEvent);
    _reg.addSystem(&follow_player_sys);
    _reg.addSystem(&draw_sys);
    _reg.addSystem(&display_sys);
}

void InGame::setEntities(void)
{
    _reg.addComponent(MAIN_WINDOW, Window());
    load_map(_reg, MAPS_PATHS.at("test1"));
}

void InGame::run(void)
{
    struct Clock clock(CLOCK_RATE);

    while (MAIN_WIN_EXIST && MAIN_WIN_ISOPEN) {
        if (clock.checkCooldown()) {
            _reg.runSystems();
        }
    }
}
