#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>

class Game {
	private:
		static sf::RenderWindow window;
		static sf::Vector2f aspectRatio;
		static float conversion;
		static int gameState;
	public:
		static void init(float windowX, float windowY, float aspectX, float aspectY, float conv);
		static int run();
};

#endif
