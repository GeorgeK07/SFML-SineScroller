/*
Game class function definitions
*/

// Include libraries
#include <SFML/Graphics.hpp>
// Include local header files
#include "CharObject.h"
#include "Game.h"

// Create Game object with certain screen settings
Game::Game() {
  win = new sf::RenderWindow(sf::VideoMode(320, 240), "SFML-SineScroller");
  win->setFramerateLimit(60);
  rect_obj = new CharObject();
}

// Game loop
void Game::gameLoop() {
  // While the window is open, check if window has been closed, then render game
  while (win->isOpen()) {
    // Create Event object event
    sf::Event event;
    //  While events are polled, check if window close event has occured, and
    // close window if so
    while (win->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        win->close();
      }
    }
    // Move rectangle
    rect_obj->moveSineObj();
    // Render Game
    renderGame();
  }
}

// Render Game
void Game::renderGame() {
  // Clear screen
  win->clear();
  // Draw rectangle
  rect_obj->renderCharObject(win);
  // Display all objects drawn to screen
  win->display();
}

// Delete all Game related objects
Game::~Game() {}