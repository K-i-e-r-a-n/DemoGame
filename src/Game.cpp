#include <SFML/Graphics.hpp>
#include "World.hpp"
#include <iostream>

void convertToPixels(sf::Vertex &vertex, sf::Vector2f &aspectRatio,  float conversion, float height) {
	vertex.position.x = vertex.position.x * conversion * aspectRatio.x ;
	vertex.position.y = height - (vertex.position.y * conversion * aspectRatio.y);
}

void drawWorld(World &world, sf::Vector2f &aspectRatio, sf::RenderWindow &window) {
	//drawing terrain
	std::vector<Chunk*> chunks = world.getChunks();
	for (auto chunk : chunks) {
		std::vector<sf::Vertex> vertices = chunk->getVertices();
		for (int a = 0; a < vertices.size(); a++) {
			convertToPixels(vertices[a], aspectRatio, 10, window.getSize().y);
		}
		window.draw(&vertices[0], vertices.size(), sf::LinesStrip);
	}

}
 
int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(1600, 900) , "SFML works!");
		sf::Vector2f aspectRatio(16, 9);
		World world;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();	
				drawWorld(world, aspectRatio, window);
        window.display();
    }

    return 0;
}
