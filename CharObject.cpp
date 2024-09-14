/*
CharObject class function definitions
*/

// Include libraries
#include <SFML/Graphics.hpp>
#include <cmath>
// Include local header files
#include "CharObject.h"

// Create char_obj object (placeholder for letters)
CharObject::CharObject() {
  // Set vars
  x_pos = 240;
  y_pos = 120;
  sine_pos = 0;
  // Create new object and set properties
  char_obj = new sf::RectangleShape(sf::Vector2f(10, 10));
  char_obj->setFillColor(sf::Color::Red);
  char_obj->setPosition(x_pos, y_pos);
  char_obj->setOrigin(5, 5);
}

// Move char_obj
void CharObject::moveObj() {
  char_obj->move(1, 1);
}

// Move char_obj in sine wave
void CharObject::moveSineObj() {
  char_obj->move(-1, 0);
  char_obj->setPosition(char_obj->getPosition().x, y_pos + 32 * sin(sine_pos));
  sine_pos = sine_pos + 0.1;
}

// Render char_obj
void CharObject::renderCharObject(sf::RenderWindow* win) {
  win->draw(*char_obj);
}

// Delete all char_obj related objects
CharObject::~CharObject() {}