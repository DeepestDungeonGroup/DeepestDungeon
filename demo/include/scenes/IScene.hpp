/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** IScene.hpp
*/

#ifndef ISCENE_HPP_
    #define ISCENE_HPP_

    #include <SFML/Graphics/RenderWindow.hpp>
    #include <SFML/Graphics/View.hpp>
    #include <SFML/Graphics/Rect.hpp>

class IScene {
    public:
        virtual void run(void) = 0;
        
};

#endif