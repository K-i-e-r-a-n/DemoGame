#ifndef CHUNK_HPP
#define CHUNK_HPP
#include <vector>
#include <SFML/Graphics.hpp>
#include "Engine.hpp"
#include <cmath>

class Chunk {
	public:
		Chunk(std::vector<sf::Vertex*> &vertices);
		std::vector<sf::Vertex*> getVertices();
		void draw(sf::RenderWindow &window, sf::Vector2f &aspectRatio, float conversion);
	private:
		std::vector<sf::Vertex*> vertices;
    sf::Texture texture;
};

#endif
