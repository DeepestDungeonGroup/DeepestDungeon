/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** hitbox_management.cpp
*/

#include "components/position.hpp"
#include "components/velocity.hpp"
#include "components/hitbox.hpp"
#include "components/interactive.hpp"

#include "hitbox_management.hpp"

static bool square_hitbox(sf::FloatRect rect1, sf::FloatRect rect2)
{
    return (rect1.left < rect2.left + rect2.width && rect1.left + rect1.width > rect2.left &&
        rect1.top < rect2.top + rect2.height && rect1.top + rect1.height > rect2.top);

}

std::vector<ECS::Entity> entity_hit(ECS::Registry& reg, const ECS::Entity entity)
{
    std::vector<ECS::Entity> entities_hit;

    auto& positions = reg.getComponents<Position2>();
    auto& hitboxs = reg.getComponents<Hitbox>();

    auto& pos = positions[entity].value();
    auto hitbox = hitboxs[entity].value();

    for (ECS::Entity e = 0; e < positions.size() && e < hitboxs.size(); ++e) {
        if (e != entity && positions[e].has_value() && hitboxs[e].has_value()) {
            auto& obj_pos = positions[e].value();
            auto& obj_hitbox = hitboxs[e].value();
            if (square_hitbox(
                sf::FloatRect{pos.x + hitbox.left, pos.y + hitbox.top, hitbox.width, hitbox.height},
                sf::FloatRect{obj_pos.x + obj_hitbox.left, obj_pos.y + obj_hitbox.top, obj_hitbox.width, obj_hitbox.height})) {
                entities_hit.push_back(e);
            }
        }
    }
    return entities_hit;
}

void entity_interaction(ECS::Registry& reg, const ECS::Entity entity)
{
    auto& positions = reg.getComponents<Position2>();
    auto& interactives = reg.getComponents<Interactive>();

    auto& pos = positions[entity].value();
    auto inter = interactives[entity].value();

    for (ECS::Entity e = 0; e < positions.size() && e < interactives.size(); ++e) {
        if (e != entity && positions[e].has_value() && interactives[e].has_value()) {
            auto& obj_pos = positions[e].value();
            auto& obj_inter = interactives[e].value();
            if (square_hitbox(
                sf::FloatRect{pos.x + inter.hitbox.left, pos.y + inter.hitbox.top, inter.hitbox.width, inter.hitbox.height},
                sf::FloatRect{obj_pos.x + obj_inter.hitbox.left, obj_pos.y + obj_inter.hitbox.top, obj_inter.hitbox.width, obj_inter.hitbox.height})) {
                obj_inter.event(reg);
            }
        }
    }
}
