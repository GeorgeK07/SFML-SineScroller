/*
Game class function signatures
*/

#ifndef GAME_H
#define GAME_H

// Include libraries
#include <SFML/Graphics.hpp>
// Include local header files
#include "CharObject.h"

// Game class
class Game {
  private:
    sf::RenderWindow* win;
    CharObject* rect_obj;
  public:
    // Create Game object with certain screen settings
    Game();
    // Game loop
    void gameLoop();
    // Render Game
    void renderGame();
    // Delete all Game related objects
    ~Game();
};

#endif