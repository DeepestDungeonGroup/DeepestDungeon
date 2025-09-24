/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** main.cpp
*/

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

#include "scenes/InGame.hpp"

int main(int, const char **)
{
    std::unique_ptr<IScene> scene = std::make_unique<InGame>();

    scene->run();
    return EXIT_SUCCESS;
}
