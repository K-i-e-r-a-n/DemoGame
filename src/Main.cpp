#include "World.hpp"
#include "Entity.hpp"
#include <sstream>
#include <iostream>

int main() {

	Game::init(1280, 720, 16, 9, 10);
 
  //debugging text
  sf::Font font;
  if (!font.loadFromFile("resources/arial.ttf"))
    std::cout << "Error: Font not found" << std::endl;
  sf::Text text;
  text.setFont(font);
  text.setCharacterSize(10);
  std::stringstream ss;
  
  
	while(Game::getGameState() > 0) {
		Game::handleEvents();	
	}
  
  text.setString(ss.str());
	Game::getWindow()->clear();
	Game::getWindow()->draw(text);
	Game::getWindow()->display();
}
