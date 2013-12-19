#include "World.hpp"

int main() {
	Game::init(1600, 900, 16, 9, 10);
	World world;
	
	while(Game::getGameState() > 0) {
		sf::Event event;
		while (Game::getWindow()->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				Game::getWindow()->close();
				Game::setGameState(0);
			}
		}

		Game::getWindow()->clear();
		world.draw();
		Game::getWindow()->display();
	}
}
