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

std::vector<sf::Vertex> Game::convertToPixels(std::vector<sf::Vertex*> vertices, sf::Vector2f aspectRatio, float conversion, float height) {
	std::vector<sf::Vertex> copy;
	for (auto vertex : vertices) {
		copy.push_back(*vertex);
	}

	for (int a  = 0; a < vertices.size(); a++) {
		copy[a].position.x = copy[a].position.x * aspectRatio.x * conversion;
		copy[a].position.y = height - (copy[a].position.y * aspectRatio.y * conversion);
		copy[a].texCoords.x = copy[a].position.x * aspectRatio.x * conversion;
		copy[a].texCoords.y = height - (copy[a].position.y * aspectRatio.y * conversion);
	}
	return copy;
}

sf::Vertex* Game::getElement(std::vector<sf::Vertex*> vertices, int i)
{
	if (i >= vertices.size())
		i %= vertices.size();	
	return vertices[i];
}

