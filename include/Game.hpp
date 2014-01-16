#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include <vector>
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
	public:
		static void init(float windowX, float windowY, float aspectX, float aspectY, float conv);
		static std::vector<sf::Vertex> convertToPixels(std::vector<sf::Vertex*> vertices);
		static sf::Vector2f convertSizeToPixels(sf::Vector2f vector);
		static sf::Vector2f convertPosToPixels(sf::Vector2f vector);
    static sf::Vector2f convertPixelsToPos(sf::Vector2f vector);
		static sf::Vertex* getElement(std::vector<sf::Vertex*> vertices, int i);
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
