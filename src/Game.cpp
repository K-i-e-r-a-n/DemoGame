#include "Game.hpp"

extern float Game::conversion;
extern sf::RenderWindow Game::window;
extern sf::Vector2f Game::aspectRatio;
extern int Game::gameState;
extern std::map<std::string, sf::Texture> Game::textures;

void Game::init(float windowX, float windowY, float aspectX, float aspectY, float conv) {
	window.create(sf::VideoMode(windowX, windowY), "Such Game");
	conversion = conv;
	aspectRatio.x = aspectX;
	aspectRatio.y = aspectY;
	gameState = 1;
}

//Main Game Loop
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

std::vector<sf::Vertex> Game::convertToPixels(std::vector<sf::Vertex*> vertices) {
	std::vector<sf::Vertex> copy;
	for (auto vertex : vertices) {
		copy.push_back(*vertex);
	}

	for (int a  = 0; a < vertices.size(); a++) {
		copy[a].position.x = copy[a].position.x * aspectRatio.x * conversion;
		copy[a].position.y = window.getSize().y - (copy[a].position.y * aspectRatio.y * conversion);
		copy[a].texCoords.x = copy[a].position.x * aspectRatio.x * conversion;
		copy[a].texCoords.y = window.getSize().y - (copy[a].position.y * aspectRatio.y * conversion);
	}
	return copy;
}

sf::Vertex* Game::getElement(std::vector<sf::Vertex*> vertices, int i)
{
	if (i >= vertices.size())
		i %= vertices.size();	
	return vertices[i];
}


void Game::loadTexture(std::string textureName) {
	//todo
}


//getters
sf::RenderWindow* Game::getWindow() {
	return &window;
}

sf::Vector2f* Game::getAspectRatio() {
	return &aspectRatio;
}

float Game::getConversion() {
	return conversion;
}

int Game::getGameState() {
	return gameState;
}

sf::Texture* Game::getTexture(std::string textureName) {
	return &textures[textureName];
}
