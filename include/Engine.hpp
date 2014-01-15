#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <vector>
#include <SFML/Graphics.hpp>

class Engine 
{
  private:
    sf::RenderWindow* window;
    sf::Vector2f aspectRatio;
    float conversion;
  public:
    Engine(sf::RenderWindow* window, sf::Vector2f aspectRatio, float conversion);
    std::vector<sf::Vertex> convertToPixels(std::vector<sf::Vertex*> vertices);
    sf::Vector2f convertSizeToPixels(sf::Vector2f vector);
    sf::Vector2f convertPosToPixels(sf::Vector2f vector);
    sf::Vector2f convertPixelsToPos(sf::Vector2f vector);
    sf::Vertex* getElement(std::vector<sf::Vertex*> vertices, int i);
    void loadTexture(std::string textureName);
};

#endif //ENGINE_HPP
