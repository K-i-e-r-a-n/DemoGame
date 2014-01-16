#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <vector>
#include <SFML/Graphics.hpp>

class Engine 
{
  private:
    static sf::RenderWindow* window;
    static sf::Vector2f aspectRatio;
    static float conversion;
		static std::map<std::string, sf::Texture> textures;
  public:
		static void init(sf::RenderWindow* window, sf::Vector2f aspectRatio, float conversion);
    static std::vector<sf::Vertex> convertToPixels(std::vector<sf::Vertex*> vertices);
    static sf::Vector2f convertSizeToPixels(sf::Vector2f vector);
    static sf::Vector2f convertPosToPixels(sf::Vector2f vector);
    static sf::Vector2f convertPixelsToPos(sf::Vector2f vector);
    static sf::Vertex* getElement(std::vector<sf::Vertex*> vertices, int i);
    static void loadTexture(std::string textureName);
};

#endif //ENGINE_HPP
