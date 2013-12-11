#include <SFML/Graphics.hpp>
#include "World.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600) , "SFML works!");
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
		
		//drawing terrain
		std::vector<Chunk*> chunks = world.getChunks();
		for (int a = 0; a < chunks.size(); a++) {
			std::vector<sf::Vertex> vertices = chunks[a]->getVertices();
			for (int b = 0; b < vertices.size() - 1; b++) {

				vertices[b].position.x = vertices[b].position.x*10 + 10;
				vertices[b].position.y = vertices[b].position.y*10 + 10;
				vertices[b+1].position.x = vertices[b+1].position.x*10 + 10;
				vertices[b+1].position.y = vertices[b+1].position.y*10 + 10;
				sf::Vertex line [] = { vertices[b], vertices[b+1] };
				window.draw(line, 2, sf::Lines);
				vertices[b].position.x = (vertices[b].position.x - 10)/10;
				vertices[b].position.y = (vertices[b].position.y - 10)/10;
				vertices[b+1].position.x = (vertices[b+1].position.x - 10)/10;
				vertices[b+1].position.y = (vertices[b+1].position.y - 10)/10;
			}
		}

        window.display();
    }

    return 0;
}
