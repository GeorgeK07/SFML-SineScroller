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
  // Create 640x480 screen and scale 320x240 to it
  win = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML-SineScroller");
  sf::View view(sf::Vector2f(160, 120), sf::Vector2f(320, 240));
  win->setView(view);
  win->setPosition(
    sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - 320,
    sf::VideoMode::getDesktopMode().height / 2 - 240));
  // Set framelimit to 60fps (Cannot be on at same time as vsync)
  win->setFramerateLimit(60);
  // win->setVerticalSyncEnabled(true); // Uncomment for vsync
  //  Create message and get its length, then use it to create a CharObject
  // pointer array
  msg = "Hello this is a test for my sine wave scroller made in SFML. This is "
    "my first program made with this library! ABCDEFGHIJKLMNOPQRSTUVWXYZ "
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  msg_size = msg.length();
  rect_obj = new CharObject*[msg_size]();
  // For loop that sets char of each object in CharObject array then offsets
  // x_pos Create var for new x position and offset
  int new_x_pos = 0;
  int offset_x_pos = 0;
  double new_sine_pos = 0;
  double offset_sine_pos = 0;
  for (int i = 0; i < msg_size; i++) {
    // Create dynamic charObjects in indexed element of character array
    rect_obj[i] = new CharObject(msg[i], "darius-darius-ii-large.ttf", 16, sf::Color::White);
    // Offset the x_pos of the charObject by an ever increasing amount
    new_x_pos = rect_obj[i]->getXPos() + offset_x_pos;
    rect_obj[i]->setXPos(new_x_pos);
    offset_x_pos = offset_x_pos + 18;
    // Offset the sine_pos of the charObject by an ever increasing amount
    new_sine_pos = rect_obj[i]->getSinePos() + offset_sine_pos;
    rect_obj[i]->setSinePos(new_sine_pos);
    offset_sine_pos = offset_sine_pos + 0.05;
  }
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
    // Move objects and rainbow fade their color
    for (int i = 0; i < msg_size; i++) {
      rect_obj[i]->moveSineObj();
      rect_obj[i]->rainbowFade();
    }
    // Render Game
    renderGame();
  }
}

// Render Game
void Game::renderGame() {
  // Clear screen
  win->clear();
  // Draw rectangle
  for (int i = 0; i < msg_size; i++) {
    rect_obj[i]->renderCharObject(win);
  }
  // Display all objects drawn to screen
  win->display();
}

// Delete all Game related objects
Game::~Game() {
  // Delete char objects, char object array and window
  for (int i = 0; i < msg_size; i++) {
    delete rect_obj[i];
  }
  delete[] rect_obj;
  delete win;
}