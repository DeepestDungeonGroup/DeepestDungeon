/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** view_player.cpp
*/

#include "systems/view_player.hpp"

#include "components/player.hpp"
#include "components/window.hpp"
#include "components/position.hpp"

void follow_player_sys(ECS::Registry& reg)
{
    auto& players = reg.getComponents<Player>();
    auto& positions = reg.getComponents<Position2>();
    std::optional<std::reference_wrapper<Window>> win = findActiveWindow(reg.getComponents<Window>());

    if (!win.has_value())
        return;
    for (ECS::Entity e = 0; e < players.size() && e < positions.size(); ++e) {
        if (players[e].has_value() && positions[e].has_value()) {
            auto& pos = positions[e].value();
            win.value().get().setView(sf::View(pos, static_cast<sf::Vector2f>(win.value().get().getSize())));
        }
    }
}