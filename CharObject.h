/*
CharObject class function signatures
*/

#ifndef CHAROBJECT_H
#define CHAROBJECT_H

// Include libraries
#include <SFML/Graphics.hpp>

// CharObject class
class CharObject {
  private:
    sf::RectangleShape* char_obj;
    int x_pos;
    int y_pos;
    double sine_pos;
  public:
    // Create char_obj object (placeholder for letters)
    CharObject();
    // Move char_obj
    void moveObj();
    // Move char_obj in sine wave
    void moveSineObj();
    // Render char_obj
    void renderCharObject(sf::RenderWindow* win);
    // Delete all char_obj related objects
    ~CharObject();
};

#endif