#include <SFML/Graphics.hpp>
#include "World.hpp"
#include <iostream>
#include <sstream>
/*void convertToPixels(sf::Vertex &vertex, sf::Vector2f &aspectRatio,  float conversion, float height) {
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

}*/
 
int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(1280, 720) , "RPG");
	sf::Vector2f aspectRatio(16, 9);
	float conversion = 10;
	World world;
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		std::cout<<"Error: \"arial.tff\" could not be found." << std::endl;
	text.setFont(font);
	std::stringstream ss;
	sf::Clock clock;

	int frameTime;
	float fps;

    while (window.isOpen())
    {
		ss.str("");
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		window.clear();

	    frameTime = (clock.restart()).asMicroseconds();
        if (frameTime == 0)
            std::cout << "Error: frame time is zero" << std::endl;
        else
        {
            fps = 1000000/frameTime;
            ss << fps;
            text.setString(ss.str());
            window.draw(text);
        }
	world.draw(window, aspectRatio, conversion);
        window.display();
    }

    return 0;
}
