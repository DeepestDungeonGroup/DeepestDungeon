/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** event.cpp
*/

#include <SFML/Window/Event.hpp>

#include "systems/event.hpp"
#include "components/window.hpp"
#include "components/player.hpp"
#include "components/position.hpp"
#include "components/velocity.hpp"

void playerMovementEvent(ECS::Registry& reg)
{
    auto& players = reg.getComponents<Player>();

    for (ECS::Entity e = 0; e < players.size(); ++e) {
        if (players[e].has_value()) {
            auto& velocities = reg.getComponents<Velocity2>();
            if (e < velocities.size() && velocities[e].has_value()) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
                    velocities[e].value().x = P_MOVEMENT.at(P_LEFT_MOV);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                    velocities[e].value().x = P_MOVEMENT.at(P_RIGHT_MOV);
                else
                    velocities[e].value().x = 0.0f;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
                    velocities[e].value().y = P_MOVEMENT.at(P_TOP_MOV);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                    velocities[e].value().y = P_MOVEMENT.at(P_BOT_MOV);
                else
                    velocities[e].value().y = 0.0f;
            }
        }
    }
}

void manageEvent(ECS::Registry& reg)
{
    std::optional<std::reference_wrapper<Window>> opt_win = findActiveWindow(reg.getComponents<Window>());
    if (!opt_win.has_value())
        return;
    std::reference_wrapper<Window> win = opt_win.value();
    
    while(std::optional event = win.get().pollEvent()) {
        if (event->is<sf::Event::Closed>())
            win.get().close();
    }
    playerMovementEvent(reg);
}
