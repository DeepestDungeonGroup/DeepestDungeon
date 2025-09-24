/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** draw.cpp
*/

#include "systems/draw.hpp"

#include "components/drawable.hpp"
#include "components/position.hpp"
#include "components/sprite.hpp"
#include "components/window.hpp"

void draw_sys(ECS::Registry& reg)
{
    auto& sprites = reg.getComponents<Sprite>();
    auto& drawables = reg.getComponents<Drawable>();
    auto& positions = reg.getComponents<Position2>();
    std::optional<std::reference_wrapper<Window>> win = findActiveWindow(reg.getComponents<Window>());

    if (!win.has_value())
        return;
    for (size_t e = 0; e < sprites.size(); ++e) {
        if (sprites[e].has_value() && drawables[e].has_value() && positions[e].has_value()) {
            auto& sprite = sprites[e].value();
            auto& pos = positions[e].value();

            sprite.setPosition(pos);
            win.value().get().draw(sprite);
        }
    }
}
