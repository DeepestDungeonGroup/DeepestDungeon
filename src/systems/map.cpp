/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** map.cpp
*/

#include <SFML/Window/Event.hpp>

#include "hitbox_management.hpp"
#include "components/window.hpp"
#include "components/player.hpp"
#include "components/interactive.hpp"

#include "systems/map.hpp"

static void interaction_hitbox(ECS::Registry& reg)
{
    auto& players = reg.getComponents<Player>();
    auto& interactives = reg.getComponents<Interactive>();

    for (ECS::Entity e = 0; e < players.size() && e < interactives.size(); ++e) {
        if (players[e].has_value() && interactives[e].has_value()) {
            entity_interaction(reg, e);
        }
    }
}

void player_interaction_sys(ECS::Registry& reg)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
        interaction_hitbox(reg);
    }
}
