/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** hitbox_management.hpp
*/

#ifndef HITBOX_MANAGEMENT_HPP_
    #define HITBOX_MANAGEMENT_HPP_

    #include "Registry.hpp"

std::vector<ECS::Entity> entity_hit(ECS::Registry& reg, const ECS::Entity entity);
void entity_interaction(ECS::Registry& reg, const ECS::Entity entity);

#endif
