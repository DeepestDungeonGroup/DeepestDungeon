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
    return (rect1.position.x < rect2.position.x + rect2.size.x && rect1.position.x + rect1.size.x > rect2.position.x &&
        rect1.position.y < rect2.position.y + rect2.size.y && rect1.position.y + rect1.size.y > rect2.position.y);

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
                sf::FloatRect{sf::Vector2f(pos.x + hitbox.position.x, pos.y + hitbox.position.y), sf::Vector2f(hitbox.size.x, hitbox.size.y)},
                sf::FloatRect{sf::Vector2f(obj_pos.x + obj_hitbox.position.x, obj_pos.y + obj_hitbox.position.y), sf::Vector2f(obj_hitbox.size.x, obj_hitbox.size.y)})) {
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
                sf::FloatRect{sf::Vector2f(pos.x + inter.hitbox.position.x, pos.y + inter.hitbox.position.y), sf::Vector2f(inter.hitbox.size.x, inter.hitbox.size.y)},
                sf::FloatRect{sf::Vector2f(obj_pos.x + obj_inter.hitbox.position.x, obj_pos.y + obj_inter.hitbox.position.y), sf::Vector2f(obj_inter.hitbox.size.x, obj_inter.hitbox.size.y)})) {
                obj_inter.event(reg);
            }
        }
    }
}
