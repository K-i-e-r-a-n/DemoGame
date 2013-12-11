#include "World.hpp"

World::World() {
	//generate one rectangular chunk for now
	sf::Vertex vert1(sf::Vector2f(0, 0));
	sf::Vertex vert2(sf::Vector2f(0, 10));
	sf::Vertex vert3(sf::Vector2f(50, 10));
	sf::Vertex vert4(sf::Vector2f(50, 0));
	std::vector<sf::Vertex> vertices {vert1, vert2, vert3, vert4};
	chunks.push_back(new Chunk(vertices));	
}

std::vector<Chunk*> World::getChunks() {
	return chunks;
}
