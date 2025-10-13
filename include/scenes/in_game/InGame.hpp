/*
** EPITECH PROJECT, 2025
** ECS
** File description:
** InGame.hpp
*/

#ifndef IN_GAME_HPP_
    #define IN_GAME_HPP_

    #include <map>
    #include <vector>

    #include "scenes/AScene.hpp"
    #include "map_management.hpp"

    #define PLAYER_SPRITE_PATH "assets/test.png"
    #define CLOCK_RATE 1000 / DEFAULT_FRAME_LIMIT

enum IG_entities_e : ECS::Entity {
    MAIN_WINDOW = 0,
    PLAYER = MAP_ENTITY_PLAYER,
    MIN_BG = MAP_ENTITY_BACKGROUND,
    MAX_BG = MAP_MAX_ENTITY_BACKGROUND,
};
    
    /**
     * @brief Check if the MAIN_WINDOW entity exist
     * 
     * Search in the local registry if the SparceArray of Window component has the
     * MAIN_WINDOW entity inside
     * @param MAIN_WINDOW is Entity index for the main window
     * @param Window is SFML like type RenderWindow component
     * @param _reg The local registry of the class
     * @return TRUE if the window exist, FALSE if not 
     */
    #define MAIN_WIN_EXIST (this->_reg.getComponents<Window>().size() > MAIN_WINDOW && this->_reg.getComponents<Window>()[MAIN_WINDOW].has_value())

    /**
     * @brief Check if the MAIN_WINDOW entity is open
     *
     * Search in the local registry inside the Window component SparseArray at the
     * MAIN_WINDOW index if the window is open using SFML RenderWindow.isOpen()
     * method
     * @param MAIN_WINDOW is Entity index for the main window
     * @param Window is SFML like type RenderWindow component
     * @param _reg The local registry of the class
     * @return TRUE if the window is open, FALSE if not 
     */
    #define MAIN_WIN_ISOPEN (this->_reg.getComponents<Window>()[MAIN_WINDOW].value().isOpen())
  
class InGame : public AScene {
    public:
        InGame();
        ~InGame() = default;

        void run(void) override;

    private:
        void setECS(void);
        void setEntities(void);
};

#endif