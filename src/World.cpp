#include "World.hpp"

World::World() {
	//generate one rectangular chunk for now
	std::vector<sf::Vertex*> vertices;;
	vertices.push_back(new sf::Vertex(sf::Vector2f(1, 1)));
	vertices.push_back(new sf::Vertex(sf::Vector2f(5, 1)));
        vertices.push_back(new sf::Vertex(sf::Vector2f(4, 2)));
	vertices.push_back(new sf::Vertex(sf::Vector2f(3, 4)));
	chunks.push_back(new Chunk(vertices));	
}

std::vector<Chunk*> World::getChunks() {
	return chunks;
}

void World::draw(sf::RenderWindow &window, sf::Vector2f &aspectRatio, float conversion) {
	//Drawing chunks
	for (auto chunk : chunks)
		chunk->draw(window, aspectRatio, conversion);
	
}
