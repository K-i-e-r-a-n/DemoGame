#include "World.hpp"
#include "Entity.hpp"

int main() {
	Game::init(1280, 720, 16, 9, 10);
	World world;
	Player player(10, sf::Vector2f(0.5, 1.8), sf::Vector2f(1, 0));
	
	while(Game::getGameState() > 0) {
		Game::handleEvents();

		Game::getWindow()->clear();
		world.draw();
		player.draw();
		Game::getWindow()->display();
	}
}
