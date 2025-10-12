/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** hitbox_management.cpp
*/

#include "components/position.hpp"
#include "components/velocity.hpp"
#include "components/hitbox.hpp"

#include "hitbox_management.hpp"

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
            if (pos.x < obj_pos.x + obj_hitbox.width && pos.x + hitbox.width > obj_pos.x &&
                pos.y < obj_pos.y + obj_hitbox.height && pos.y + hitbox.height > obj_pos.y) {
                entities_hit.push_back(e);
            }
        }
    }
    return entities_hit;
}
