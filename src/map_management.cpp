/*
** EPITECH PROJECT, 2025
** DeepestDungeon
** File description:
** map_reader.c++
*/

#include <vector>
#include <fstream>
#include <SFML/System/Vector2.hpp>

#include "map_management.hpp"

#include "components/drawable.hpp"
#include "components/position.hpp"
#include "components/sprite.hpp"
#include "components/hitbox.hpp"
#include "components/velocity.hpp"
#include "components/player.hpp"
#include "components/interactive.hpp"

static void load_player(ECS::Registry& reg, const sf::Vector2u& pos)
{
    reg.addComponent(MAP_ENTITY_PLAYER, Drawable());
    reg.addComponent(MAP_ENTITY_PLAYER, Position2(pos.x * SQUARE_WIDTH, pos.y * SQUARE_HEIGHT));
    reg.addComponent(MAP_ENTITY_PLAYER, Sprite(sf::IntRect(0, 0, 30, 30), sf::Color::Blue));
    reg.addComponent(MAP_ENTITY_PLAYER, Velocity2(0.0f, 0.0f));
    reg.addComponent(MAP_ENTITY_PLAYER, Player());
    reg.addComponent(MAP_ENTITY_PLAYER, Hitbox(0.0f, 0.0f, 30.0f, 30.0f));
    reg.addComponent(MAP_ENTITY_PLAYER, Interactive(-15.0f, -15.0f, 60.0f, 60.0f));
}

static void create_square(ECS::Registry& reg, const ECS::Entity& entity_id, char type, const sf::Vector2u& pos)
{
    if (type == MAP_WALL) {
        reg.addComponent(entity_id, Drawable());
        reg.addComponent(entity_id, Position2(pos.x * SQUARE_WIDTH, pos.y * SQUARE_HEIGHT));
        reg.addComponent(entity_id, Sprite(sf::IntRect(0, 0, SQUARE_WIDTH, SQUARE_HEIGHT), sf::Color::Red));
        reg.addComponent(entity_id, Hitbox(0.0f, 0.0f, SQUARE_WIDTH, SQUARE_WIDTH));
    } else if (type == MAP_DOOR) {
        reg.addComponent(entity_id, Drawable());
        reg.addComponent(entity_id, Position2(pos.x * SQUARE_WIDTH, pos.y * SQUARE_HEIGHT));
        reg.addComponent(entity_id, Sprite(sf::IntRect(0, 0, SQUARE_WIDTH, SQUARE_HEIGHT), sf::Color::Yellow));
        reg.addComponent(entity_id, Hitbox(0.0f, 0.0f, SQUARE_WIDTH, SQUARE_WIDTH));
        reg.addComponent(entity_id, Interactive(-15.0f, -15.0f, 60.0f, 60.0f, [](ECS::Registry& reg){
            reg.killEntity(MAP_ENTITY_PLAYER);
            for (ECS::Entity e = MAP_ENTITY_BACKGROUND; e < MAP_MAX_ENTITY_BACKGROUND; ++e) {
                reg.killEntity(e);
            }
            load_map(reg, MAPS_PATHS.at("test2"));
        }));
    } else if (type == MAP_PLAYER) {
        load_player(reg, pos);
    }
}

static void create_line(ECS::Registry& reg, ECS::Entity& entity_id, const std::string& line, size_t y)
{
    for (size_t x = 0; x < line.size() && x < MAP_MAX_WIDTH; ++x) {
        create_square(reg, entity_id, line[x], sf::Vector2u(x, y));
        entity_id += 1;
    }
}

void load_map(ECS::Registry& reg, const std::string& path)
{
    std::ifstream file(path);
    std::string line;
    std::vector<std::string> content;
    ECS::Entity entity_id = MAP_ENTITY_BACKGROUND;

    if (path.compare(path.size() - MAP_EXTENTION.size() - 1, MAP_EXTENTION.size(), MAP_EXTENTION)) {
        for (size_t y = 0; std::getline(file, line) && y < MAP_MAX_HEIGHT; ++y) {
            create_line(reg, entity_id, line, y);
        }
    }
}