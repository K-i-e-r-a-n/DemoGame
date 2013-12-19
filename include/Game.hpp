#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include "World.hpp"

class Game {
	private:
		static sf::RenderWindow window;
		static sf::Vector2f aspectRatio;
		static float conversion;
		static int gameState;
		static std::map<std::string, sf::Texture> textures;
		static std::vector<World*> worlds;
	
	public:
		static void init(float windowX, float windowY, float aspectX, float aspectY, float conv);
		static std::vector<sf::Vertex> convertToPixels(std::vector<sf::Vertex*> vertices);
		static sf::Vertex* getElement(std::vector<sf::Vertex*> vertices, int i);
		static int run();
		static void loadTexture(std::string textureName);
		
		//getters
		static sf::RenderWindow* getWindow();
		static sf::Vector2f* getAspectRatio();
		static float getConversion();
		static int getGameState();
		static sf::Texture* getTexture(std::string textureName);
		

};

#endif
