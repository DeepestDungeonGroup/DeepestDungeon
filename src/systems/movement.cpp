/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** movement.cpp
*/

#include "systems/movement.hpp"

#include "components/position.hpp"
#include "components/velocity.hpp"
#include "components/hitbox.hpp"

static bool hitbox_manager(ECS::Registry& reg, const ECS::Entity entity, const sf::Vector2f vel)
{    
    auto& positions = reg.getComponents<Position2>();
    auto& hitboxs = reg.getComponents<Hitbox>();

    auto& pos = positions[entity].value();
    auto hitbox = hitboxs[entity].value();

    pos += vel;
    for (ECS::Entity e = 0; e < positions.size() && e < hitboxs.size(); ++e) {
        if (e != entity && positions[e].has_value() && hitboxs[e].has_value()) {
            auto& obj_pos = positions[e].value();
            auto& obj_hitbox = hitboxs[e].value();
            if (pos.x < obj_pos.x + obj_hitbox.width && pos.x + hitbox.width > obj_pos.x &&
                pos.y < obj_pos.y + obj_hitbox.height && pos.y + hitbox.height > obj_pos.y) {
                pos -= vel;
                return true;
            }
        }
    }
    return false;
}

void movement2_sys(ECS::Registry& reg)
{
    auto& positions = reg.getComponents<Position2>();
    auto& velocities = reg.getComponents<Velocity2>();
    auto& hitboxs = reg.getComponents<Hitbox>();

    for (ECS::Entity entity = 0; entity < positions.size() && entity < velocities.size(); ++entity) {
        if (positions[entity].has_value() && velocities[entity].has_value()) {
            auto& pos = positions[entity].value();
            auto& vel = velocities[entity].value();
            if (entity < hitboxs.size() && hitboxs[entity].has_value()) {
                if (hitbox_manager(reg, entity, vel)) {
                    if (hitbox_manager(reg, entity, vel - sf::Vector2f(vel.x, 0.0f))) {
                        hitbox_manager(reg, entity, vel - sf::Vector2f(0.0f, vel.y));
                    }
                }
            } else {
                pos += vel;
            }
        }
    }
}

void movement3_sys(ECS::Registry& reg)
{
    auto& positions = reg.getComponents<Position3>();
    auto& velocities = reg.getComponents<Velocity3>();

    for (size_t entity = 0; entity < positions.size() && entity < velocities.size(); ++entity) {
        if (positions[entity].has_value() && velocities[entity].has_value()) {
            auto& pos = positions[entity].value();
            auto& vel = velocities[entity].value();
            pos += vel;
        }
    }
}
