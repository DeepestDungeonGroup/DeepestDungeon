/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** display.cpp
*/

#include "systems/display.hpp"

#include "components/window.hpp"

void display_sys(ECS::Registry& reg)
{
    auto& windows = reg.getComponents<Window>();

    for (ECS::Entity e = 0; e < windows.size(); ++e) {
        if (windows[e].has_value()) {
            windows[e].value().display();
            windows[e].value().clear();
        }
    }
}
