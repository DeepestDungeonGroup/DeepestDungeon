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

static void load_player(ECS::Registry& reg, const sf::Vector2u& pos)
{
    reg.addComponent(MAP_ENTITY_PLAYER, Drawable());
    reg.addComponent(MAP_ENTITY_PLAYER, Position2(pos.x * SQUARE_WIDTH, pos.y * SQUARE_HEIGHT));
    reg.addComponent(MAP_ENTITY_PLAYER, Sprite(sf::IntRect(0, 0, 30, 30), sf::Color::Blue));
    reg.addComponent(MAP_ENTITY_PLAYER, Velocity2(0.0f, 0.0f));
    reg.addComponent(MAP_ENTITY_PLAYER, Player());
    reg.addComponent(MAP_ENTITY_PLAYER, Hitbox(0.0f, 0.0f, 30.0f, 30.0f));
}

static void create_square(ECS::Registry& reg, char type, const sf::Vector2u& pos)
{
    static size_t entity_id = MAP_ENTITY_BACKGROUND;

    if (type == MAP_WALL) {
        reg.addComponent(entity_id, Drawable());
        reg.addComponent(entity_id, Position2(pos.x * SQUARE_WIDTH, pos.y * SQUARE_HEIGHT));
        reg.addComponent(entity_id, Sprite(sf::IntRect(0, 0, SQUARE_WIDTH, SQUARE_HEIGHT), sf::Color::Red));
        reg.addComponent(entity_id, Hitbox(0.0f, 0.0f, SQUARE_WIDTH, SQUARE_WIDTH));
    } else if (type == MAP_PLAYER) {
        load_player(reg, pos);
    }
    entity_id += 1;
}

static void create_line(ECS::Registry& reg, const std::string& line, size_t y)
{
    for (size_t x = 0; x < line.size() && x < MAP_MAX_WIDTH; ++x) {
        create_square(reg, line[x], sf::Vector2u(x, y));
    }
}

void load_map(ECS::Registry& reg, const std::string& path)
{
    std::ifstream file(path);
    std::string line;
    std::vector<std::string> content;

    if (path.compare(path.size() - MAP_EXTENTION.size() - 1, MAP_EXTENTION.size(), MAP_EXTENTION)) {
        for (size_t y = 0; std::getline(file, line) && y < MAP_MAX_HEIGHT; ++y) {
            create_line(reg, line, y);
        }
    }
}