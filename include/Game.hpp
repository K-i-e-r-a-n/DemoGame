#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <vector>

class Game {
	private:
		static sf::RenderWindow window;
		static sf::Vector2f aspectRatio;
		static float conversion;
		static int gameState;
	public:
		static void init(float windowX, float windowY, float aspectX, float aspectY, float conv);
		static std::vector<sf::Vertex> convertToPixels(std::vector<sf::Vertex*> vertices, sf::Vector2f aspectRatio, float conversion, float height);
		sf::Vertex* getElement(std::vector<sf::Vertex*> vertices, int i);
		static int run();
};

#endif
