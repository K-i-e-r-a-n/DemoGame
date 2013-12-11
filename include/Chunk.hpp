#ifndef CHUNK_HPP
#define CHUNK_HPP
#include <vector>
#include <SFML/Graphics.hpp>

class Chunk {
	public:
		Chunk();
	private:
		std::vector<sf::Vertex> vertices;
};

#endif
