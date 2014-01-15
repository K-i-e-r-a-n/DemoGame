#include "DebugMonitor.hpp"

DebugMonitor::DebugMonitor(int size, std::string fontLoc)
{
  font.loadFromFile(fontLoc);
  text.setFont(font);
  text.setCharacterSize(size);
}

void DebugMonitor::draw()
{ 
  ss.str("");
  text.setString(ss.str());
  Game::getWindow()->draw(text);
}
