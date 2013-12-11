#include "Chunk.hpp"

Chunk::Chunk(std::vector<sf::Vertex> &vertices) {
	this->vertices = vertices;
}

std::vector<sf::Vertex> Chunk::getVertices() {
	return vertices;
}
