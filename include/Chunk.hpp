#ifndef CHUNK_HPP
#define CHUNK_HPP
#include <vector>
#include <SFML/Graphics.hpp>

class Chunk {
	public:
		Chunk(std::vector<sf::Vertex> &vertices);
		std::vector<sf::Vertex> getVertices();
	private:
		std::vector<sf::Vertex> vertices;
};

#endif
