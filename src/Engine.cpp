#include "Engine.hpp"

Engine::Engine(sf::RenderWindow* window, sf::Vector2f aspectRatio, float conversion)
{
  this->window = window;
  this->aspectRatio = aspectRatio;
  this->conversion = conversion;
}

std::vector<sf::Vertex> Engine::convertToPixels(std::vector<sf::Vertex*> vertices) {
	std::vector<sf::Vertex> copy;
	for (auto vertex : vertices) {
		copy.push_back(*vertex);
	}

	for (int a  = 0; a < vertices.size(); a++) {
		copy[a].position.x = copy[a].position.x * aspectRatio.x * conversion;
		copy[a].position.y = window->getSize().y - (copy[a].position.y * aspectRatio.y * conversion);
		copy[a].texCoords.x = copy[a].texCoords.x * aspectRatio.x * conversion;
		copy[a].texCoords.y = window->getSize().y - (copy[a].texCoords.y * aspectRatio.y * conversion);
	}
	return copy;
}

sf::Vector2f Engine::convertPosToPixels(sf::Vector2f vector) {
	vector.x = vector.x * aspectRatio.x * conversion;
	vector.y = window->getSize().y - (vector.y * aspectRatio.y * conversion);
	return vector;
}

sf::Vector2f Engine::convertSizeToPixels(sf::Vector2f vector) {
	vector.x = vector.x * aspectRatio.x * conversion;
	vector.y = vector.y * aspectRatio.y * conversion;
	return vector;
}

sf::Vector2f Engine::convertPixelsToPos(sf::Vector2f vector)
{
  vector.x = (vector.x/aspectRatio.x)/conversion;
  vector.y = ((window->getSize().y - vector.y)/aspectRatio.y)/conversion;
  return vector;
}

sf::Vertex* Engine::getElement(std::vector<sf::Vertex*> vertices, int i)
{
	if (i >= vertices.size())
		i %= vertices.size();	
	return vertices[i];
}
