#include "World.hpp"

World::World() {
	std::vector<sf::Vertex*> vertices;
  /* test coords
  vertices.push_back(new sf::Vertex(sf::Vector2f(0,0), sf::Vector2f(0,0)));
  vertices.push_back(new sf::Vertex(sf::Vector2f(0,9), sf::Vector2f(0,9)));
  vertices.push_back(new sf::Vertex(sf::Vector2f(9,10), sf::Vector2f(9,10)));
  vertices.push_back(new sf::Vertex(sf::Vector2f(10,0), sf::Vector2f(10,0)));
  */
  
  vertices.push_back(new sf::Vertex(sf::Vector2f(1, 1), sf::Vector2f(1, 1)));
  vertices.push_back(new sf::Vertex(sf::Vector2f(1, 5), sf::Vector2f(1, 5)));
  vertices.push_back(new sf::Vertex(sf::Vector2f(3, 1), sf::Vector2f(3, 1)));
  vertices.push_back(new sf::Vertex(sf::Vector2f(3, 5), sf::Vector2f(3, 5)));
  vertices.push_back(new sf::Vertex(sf::Vector2f(4, 6), sf::Vector2f(4, 6)));
  vertices.push_back(new sf::Vertex(sf::Vector2f(3, 5), sf::Vector2f(3, 5)));
  vertices.push_back(new sf::Vertex(sf::Vector2f(5, 2), sf::Vector2f(5, 2)));
  vertices.push_back(new sf::Vertex(sf::Vector2f(4, 3), sf::Vector2f(4, 3)));
  vertices.push_back(new sf::Vertex(sf::Vector2f(6, 1), sf::Vector2f(6, 1)));
  chunks.push_back(new Chunk(vertices));	
}

std::vector<Chunk*> World::getChunks() {
	return chunks;
}

void World::draw() {
	//Drawing chunks
	for (auto chunk : chunks)
		chunk->draw();	
}
