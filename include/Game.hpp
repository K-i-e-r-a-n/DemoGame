#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "World.hpp"
#include "Chunk.hpp"
#include "Engine.hpp"
//#include "Entity.hpp"

class Game {
	private:
		//static Player player; - need to fix drawing
		static sf::RenderWindow window;
		static sf::Vector2f aspectRatio;
		static float conversion;
		static int gameState;
		static std::map<std::string, sf::Texture> textures;
		static sf::Event event;
		static World world;
    static sf::RenderTexture rTexture;
	public:
    static void init(float windowX, float windowY, float aspectX, float aspectY, float conv);
		static void loadTexture(std::string textureName);
		static void handleEvents();
		static void draw();
		
		//getters
		static sf::RenderWindow* getWindow();
		static sf::Vector2f* getAspectRatio();
		static float getConversion();
		static int getGameState();
		static sf::Texture* getTexture(std::string textureName);
    static sf::Event* getEvent();
		//setters
		static void setGameState(int state);
		

};

#endif
