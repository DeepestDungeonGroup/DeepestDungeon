/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** gravity.cpp
*/

#include "systems/gravity.hpp"

#include "components/position.hpp"
#include "components/velocity.hpp"
#include "components/gravity.hpp"

void gravity_sys(ECS::Registry& reg)
{
    auto& positions = reg.getComponents<Position2>();
    auto& velocities = reg.getComponents<Velocity2>();
    auto& gravities = reg.getComponents<Gravity>();

    for (ECS::Entity e = 0; e < positions.size() && e < velocities.size(); ++e) {
        if (positions[e].has_value() && velocities[e].has_value() && gravities[e].has_value()) {
            auto& pos = positions[e].value();
            auto& vel = velocities[e].value();

            if (pos.y <= 700) {
                vel.y += 0.5f;
                if (vel.x < 0)
                    vel.x += 0.1;
                else if (vel.x > 0)
                    vel.x -= 0.1;
            } else {
                vel.y = 0.0f;
                vel.x = 0.0f;
            }
        }
    }
}
