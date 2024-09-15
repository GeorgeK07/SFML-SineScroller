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
    sf::Text* char_obj;
    sf::Font* font;
    char disp_char;
    int x_pos;
    int y_pos;
    double sine_pos;
    uint8_t r_channel;
    uint8_t g_channel;
    uint8_t b_channel;
    uint8_t a_channel;
    bool rg_second_loop;
    bool b_second_loop;
  public:
    // Create char_obj object
    CharObject();
    // Create char_obj object with arg_char
    CharObject(char arg_char);
    // Move char_obj
    void moveObj();
    // Move char_obj in sine wave
    void moveSineObj();
    // Rainbow fade text color
    void rainbowFade();
    // Render char_obj
    void renderCharObject(sf::RenderWindow* win);
    // Set char
    void setChar(char arg_char);
    // Get char
    char getChar();
    // Set x_pos
    void setXPos(int arg_x_pos);
    // Get x_pos
    int getXPos();
    // Set y_pos
    void setYPos(int arg_y_pos);
    // Get y_pos
    int getYPos();
    // Set sine_pos
    void setSinePos(double arg_sine_pos);
    // Get sine_pos
    double getSinePos();
    // Delete all char_obj related objects
    ~CharObject();
};

#endif