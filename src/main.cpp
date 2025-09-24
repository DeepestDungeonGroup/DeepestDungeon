/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** main.cpp
*/

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#include "scenes/in_game/InGame.hpp"

int main(int, const char **)
{
    std::unique_ptr<IScene> scene = std::make_unique<InGame>();

    scene->run();
    return EXIT_SUCCESS;
}
