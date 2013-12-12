#include "Chunk.hpp"
#include "iostream"
Chunk::Chunk(std::vector<sf::Vertex*> &vertices) {
	this->vertices = vertices;
}

std::vector<sf::Vertex*> Chunk::getVertices() {
	return vertices;
}

void Chunk::draw(sf::RenderWindow &window, sf::Vector2f &aspectRatio, float conversion) {
	std::vector<sf::Vertex> converted = Engine::convertToPixels(vertices, aspectRatio, conversion, window.getSize().y);
	window.draw(&converted[0], converted.size(), sf::LinesStrip);
}
