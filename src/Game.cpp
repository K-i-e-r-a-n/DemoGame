#include <SFML/Graphics.hpp>
#include "World.hpp"
#include <iostream>

void drawWorld(World &world, sf::Vector2f &aspectRatio, sf::RenderWindow &window) {
	//drawing terrain
	std::vector<Chunk*> chunks = world.getChunks();
	for (auto chunk : chunks) {
		std::vector<sf::Vertex> vertices = chunk->getVertices();
		for (int a = 0; a < vertices.size(); a++) {
			sf::Vertex line[2];	
			if (a != vertices.size()-1) {
				line[0] = vertices[a];
				line[1] = vertices[a+1];
			}
			else {
				line[0] = vertices[a];
				line[1] = vertices[0];
			}	
			
			line[0].position.x = line[0].position.x * aspectRatio.x * 10;
			line[0].position.y = window.getSize().y - (line[0].position.y * aspectRatio.y * 10);
			line[1].position.x = line[1].position.x * aspectRatio.x * 10;
			line[1].position.y = window.getSize().y - (line[1].position.y * aspectRatio.y * 10);
			window.draw(line, 2, sf::Lines);
			line[0].position.x = line[0].position.x / aspectRatio.x / 10;
			line[0].position.y = window.getSize().y - (line[0].position.y / aspectRatio.y / 10);
			line[1].position.x = line[1].position.x / aspectRatio.x / 10;
			line[1].position.y = window.getSize().y - (line[1].position.y / aspectRatio.y / 10);
		}
	} //end terrain


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
