#include "World.hpp"

World::World() {
	//generate one rectangular chunk for now
	sf::Vertex vert1(sf::Vector2f(1, 1));
	sf::Vertex vert2(sf::Vector2f(1, 2));
	sf::Vertex vert3(sf::Vector2f(4, 2));
	sf::Vertex vert4(sf::Vector2f(4, 4));
	sf::Vertex vert5(sf::Vector2f(6, 4));
	sf::Vertex vert6(sf::Vector2f(6, 2));
	sf::Vertex vert7(sf::Vector2f(10, 2));
	sf::Vertex vert8(sf::Vector2f(10, 1));
	std::vector<sf::Vertex> vertices {vert1, vert2, vert3, vert4, vert5, vert6, vert7, vert8};
	chunks.push_back(new Chunk(vertices));	
}

std::vector<Chunk*> World::getChunks() {
	return chunks;
}
