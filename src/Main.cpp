#include "World.hpp"
#include "Entity.hpp"
#include <sstream>
#include <iostream>

int main() {

	Game::init(1280, 720, 16, 9, 10);
	World world;
	Player player(10, sf::Vector2f(0.5, 1.8), sf::Vector2f(1, 0));
  
  //debugging text
  sf::Font font;
  if (!font.loadFromFile("resources/arial.ttf"))
    std::cout << "Error: Font not found" << std::endl;
  sf::Text text;
  text.setFont(font);
  std::stringstream ss;
  
  sf::Event* event = Game::getEvent();
	while(Game::getGameState() > 0) {
		while(Game::getWindow()->pollEvent(*event))
    {
      if (event->type == sf::Event::Closed)
      {
        Game::getWindow()->close();
        Game::setGameState(0);
      }
      if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
      {
        ss.str("");
        sf::Vector2i intPos = sf::Mouse::getPosition(*Game::getWindow());
        sf::Vector2f pos;
        pos.x = intPos.x;
        pos.y = intPos.y;
        pos = Game::convertPixelsToPos(pos);
        ss << pos.x;
        ss << " ";
        ss << pos.y;
        sf::Vertex* vert = new sf::Vertex(pos, pos);
        world.getChunks()[0]->appendVertex(vert);
      }
    }
  
    text.setString(ss.str());
		Game::getWindow()->clear();
		world.draw();
		player.draw();
    Game::getWindow()->draw(text);
		Game::getWindow()->display();
	}
}
