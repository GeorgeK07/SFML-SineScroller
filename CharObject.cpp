/*
CharObject class function definitions
*/

// Include libraries
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
// Include local header files
#include "CharObject.h"

// Create char_obj object
CharObject::CharObject() {
  // Set vars
  x_pos = 240;
  y_pos = 120;
  sine_pos = 0;
  r_channel = 255;
  g_channel = 0;
  b_channel = 0;
  a_channel = 255;
  rg_second_loop = 0;
  b_second_loop = 0;
}

// Create char_obj object
CharObject::CharObject(char arg_char, std::string arg_font, int arg_char_size, sf::Color arg_color) : CharObject() {
  // Load font
  font = new sf::Font;
  bool isExisting = font->openFromFile(arg_font);
  if (!isExisting) {
    std::cout << "Font failed to load.\n";
    exit(1);
  }
  font->setSmooth(false);
  // Create new object and set properties
  char_obj = new sf::Text(*font);
  char_obj->setCharacterSize(arg_char_size);
  char_obj->setFillColor(arg_color);
  char_obj->setString(arg_char);
  char_obj->setPosition({x_pos, y_pos});
  char_obj->setOrigin({(float)(arg_char_size / 2), (float)(arg_char_size / 2)}); // For monospace
}

// Move char_obj
void CharObject::moveObj() { char_obj->move({1, 1}); }

// Move char_obj in sine wave
void CharObject::moveSineObj() {
  char_obj->setPosition({x_pos, y_pos});
  char_obj->move({-1, 0});
  char_obj->setPosition({char_obj->getPosition().x, (float)(y_pos + 40 * sin(sine_pos))});
  sine_pos = sine_pos + 0.1;
  x_pos = char_obj->getPosition().x;
}

// Rainbow fade text color
void CharObject::rainbowFade() {
  // Change text color
  char_obj->setFillColor(sf::Color(r_channel, g_channel, b_channel, a_channel));
  //  Decrement r and increment g if r hasn't reached 0, then increment r and
  // decrement g if r reaches 0 and rg 2nd loop is set
  if (rg_second_loop == 0 && r_channel > 0 && b_channel == 0) {
    r_channel--;
    g_channel++;
  } else if (rg_second_loop == 1 && r_channel < 255) {
    r_channel++;
    g_channel--;
  } else if (r_channel == 255) {
    rg_second_loop = 0;
  }
  //  Increment b if r has reached 0, then set 2nd loop and decrement b, then set
  // 2nd loop for rg when b reaches 0
  if (b_second_loop == 0 && rg_second_loop == 0 && r_channel == 0 &&
      b_channel < 255) {
    b_channel++;
  } else if (b_second_loop == 0 && b_channel == 255) {
    b_second_loop = 1;
  } else if (b_second_loop == 1 && b_channel > 0) {
    b_channel--;
  } else if (b_second_loop == 1 && b_channel == 0) {
    b_second_loop = 0;
    rg_second_loop = 1;
  }
}

// Render char_obj
void CharObject::renderCharObject(sf::RenderWindow* win) {
  win->draw(*char_obj);
}

// Set char
void CharObject::setChar(char arg_char) { disp_char = arg_char; }

// Get char
char CharObject::getChar() { return disp_char; }

// Set x_pos
void CharObject::setXPos(int arg_x_pos) { x_pos = arg_x_pos; }

// Get x_pos
int CharObject::getXPos() { return x_pos; }

// Set y_pos
void CharObject::setYPos(int arg_y_pos) { y_pos = arg_y_pos; }

// Get y_pos
int CharObject::getYPos() { return y_pos; }

// Set sine_pos
void CharObject::setSinePos(float arg_sine_pos) { sine_pos = arg_sine_pos; }

// Get sine_pos
float CharObject::getSinePos() { return sine_pos; }

// Delete all char_obj related objects
CharObject::~CharObject() {
  // Delete font and char object
  delete font;
  delete char_obj;
}