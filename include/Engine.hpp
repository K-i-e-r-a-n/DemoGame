#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <vector>
#include <SFML/Graphics.hpp>

namespace Engine {
	std::vector<sf::Vertex> convertToPixels(std::vector<sf::Vertex*> vertices, sf::Vector2f aspectRatio, float conversion, float height);
	sf::Vertex* getElement(std::vector<sf::Vertex*> vertices, int i);
}



#endif
