#include "World.hpp"

World::World() {
	//generate one funky chunky. Don't forget to texture.
    std::vector<sf::Vertex*> vertices;;
    vertices.push_back(new sf::Vertex(sf::Vector2f(1, 1), sf::Vector2f(1, 1)));
    vertices.push_back(new sf::Vertex(sf::Vector2f(1, 5), sf::Vector2f(1, 5)));
    vertices.push_back(new sf::Vertex(sf::Vector2f(3, 1), sf::Vector2f(3, 1)));
    vertices.push_back(new sf::Vertex(sf::Vector2f(3, 5), sf::Vector2f(3, 5)));
    vertices.push_back(new sf::Vertex(sf::Vector2f(4, 6), sf::Vector2f(4, 6)));
    vertices.push_back(new sf::Vertex(sf::Vector2f(3, 5), sf::Vector2f(3, 5)));
    vertices.push_back(new sf::Vertex(sf::Vector2f(5, 2), sf::Vector2f(5, 2)));
    vertices.push_back(new sf::Vertex(sf::Vector2f(4, 7), sf::Vector2f(4, 7)));
    vertices.push_back(new sf::Vertex(sf::Vector2f(6, 1), sf::Vector2f(6, 1)));
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
