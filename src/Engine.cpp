#include "Engine.hpp"

std::vector<sf::Vertex> Engine::convertToPixels(std::vector<sf::Vertex*> vertices, sf::Vector2f aspectRatio, float conversion, float height) {
	std::vector<sf::Vertex> copy;
	for (auto vertex : vertices) {
		copy.push_back(*vertex);
	}

	for (int a  = 0; a < vertices.size(); a++) {
		copy[a].position.x = copy[a].position.x * aspectRatio.x * conversion;
		copy[a].position.y = height - (copy[a].position.y * aspectRatio.y * conversion);
		copy[a].texCoords.x = copy[a].position.x * aspectRatio.x * conversion;
		copy[a].texCoords.y = height - (copy[a].position.y * aspectRatio.y * conversion);
	}
	return copy;
}

sf::Vertex* Engine::getElement(std::vector<sf::Vertex*> vertices, int i)
{
	if (i >= vertices.size())
		i %= vertices.size();	
	return vertices[i];
}
