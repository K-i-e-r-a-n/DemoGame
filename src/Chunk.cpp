#include "Chunk.hpp"
#include <iostream>

Chunk::Chunk(std::vector<sf::Vertex*> &vertices) {
	this->vertices = vertices;
}

std::vector<sf::Vertex*> Chunk::getVertices() {
	return vertices;
}

void Chunk::draw(sf::RenderWindow &window, sf::Vector2f &aspectRatio, float conversion) {
	double PI = 3.14159265358;
	std::vector<sf::Vertex*> copy = vertices;
	std::vector<sf::Vertex*> triangles;
	int i = 0;
	float theta = 0.0;
	std::vector<float> u = {0.0, 0.0};
	std::vector<float> v = {0.0, 0.0};
	while (copy.size() > 2)
	{
		if (i == copy.size())
			i = 0;
		u[0] = (Engine::getElement(copy, i+1)->position.x - Engine::getElement(copy, i)->position.x); 
		u[1] = (Engine::getElement(copy, i+1)->position.y - Engine::getElement(copy, i)->position.y);
		v[0] = (Engine::getElement(copy, i+2)->position.x - Engine::getElement(copy, i+1)->position.x);
		v[1] = (Engine::getElement(copy, i+2)->position.y - Engine::getElement(copy, i+1)->position.y);
		theta = acos((u[0]*v[0] + u[1]*v[1])/(sqrt(pow(u[0], 2) + pow(u[1], 2))*sqrt(pow(v[0], 2) + pow(v[1], 2))));
		//std::cout << theta << std::endl;
		//sf::sleep(sf::seconds(1));

		if (theta > PI)
			i++;
		else
		{
			triangles.push_back(Engine::getElement(copy, i));
			triangles.push_back(Engine::getElement(copy, i+1));
			triangles.push_back(Engine::getElement(copy, i+2));
			if (i == copy.size())
				copy.erase(copy.begin());
			else
				copy.erase(copy.begin() + i);
			i++;
		}
	}
	window.draw(&(Engine::convertToPixels(triangles, aspectRatio, conversion, window.getSize().y))[0], 9, sf::Triangles);
	
	window.draw(&(Engine::convertToPixels(vertices, aspectRatio, conversion, window.getSize().y))[0], vertices.size(), sf::LinesStrip);
}

