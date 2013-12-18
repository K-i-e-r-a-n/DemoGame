#include "Game.hpp"

extern float Game::conversion;
extern sf::RenderWindow Game::window;
extern sf::Vector2f Game::aspectRatio;
extern int Game::gameState;

void Game::init(float windowX, float windowY, float aspectX, float aspectY, float conv) {
	window.create(sf::VideoMode(windowX, windowY), "Such Game");
	conversion = conv;
	aspectRatio.x = aspectX;
	aspectRatio.y = aspectY;
	gameState = 1;
}

int Game::run() {
	
	while (gameState == 1) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		window.display();
	}

	return 0;
}
