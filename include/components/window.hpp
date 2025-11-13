/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** window.hpp
*/

#ifndef WINDOW_CMPT_HPP_
    #define WINDOW_CMPT_HPP_

    #include <SFML/Graphics/RenderWindow.hpp>
    #include "SparseArray.hpp"

    #define DEFAULT_FRAME_LIMIT 60
    #define DEFAULT_WIN_NAME "Deepest Dungeon"
    #define DEFAULT_VIDEO_MODE sf::VideoMode({1280, 720})

struct Window : public sf::RenderWindow {
    Window();
    Window(const Window&);
    Window(Window&&);
    std::string name;
};

std::optional<std::reference_wrapper<Window>> findActiveWindow(ECS::SparseArray<Window>&);

#endif