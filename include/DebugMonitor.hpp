#ifndef DEBUGMONITOR_HPP
#define DEBUGMONITOR_HPP
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <sstream>

class DebugMonitor 
{
  public:
    DebugMonitor(int size, std::string fontLoc);
    void draw();
  private:
    std::stringstream ss;
    sf::Font font;
    sf::Text text;
    int size;
};

#endif //DEBUGMONITOR_HPP

