#include "Chunk.hpp"

Chunk::Chunk(std::vector<sf::Vertex> &vertices) {
	this->vertices = vertices;
}

std::vector<sf::Vertex> Chunk::getVertices() {
	return vertices;

void Chunk::draw(sf::RenderWindow *window)
{
    drawPolygon(this->vertices, window);
}

static void Chunk::drawPolygon(std::vector<sf::Vertex> &vertices, sf::RenderWindow *window)
{
    if (vertices.size() > 4)
    {
        //todo: make this not break if the first one is the lowest.
        int low1Index;
        int low2Index;
        int low1 = vertices[1].position.y;
        int low2 = 0;
        for (int i = 1; i < vertices.size()-1; i++)
        {
            if (vertices[i].position.y < low1)
            {
                low2Index = low1Index;
                low1Index = i;
                low2 = low1; 
                low1 = vertices[i].position.y;
            }
        }
        std::vector<sf::Vertex base = {vertices[0], vertices[low1Index], vertices[low2Index], vertices[vertices.size() - 1]};
        std::vector<sf::Vertex> one;
        std::vector<sf::Vertex> two;
        std::vector<sf::Vertex> three;
        for (int i = 0; i <= low1Index, i++)
            one.push_back(vertices[i]);
        for (int i = low1Index; i <= low2Index; i++)
            two.push_back(vertices[i]);
        for (int i = low2Index; i < vertices.size(); i++)
            three.push_back(vertices[i]);
        window->draw(base; base.size(); sf::Quads); //add window reference to parameters
        drawPolygon(one, window);
        drawPolygon(two, window);
        drawPolygon(three, window);
    }    
    else if (vertices.size() == 4)
    {
        window->draw(vertices, vertices.size(); sf::Quads);
    }
    else if (vertices.size() == 3)
    {
        window->draw(vertices, vertices.size(); sf::Triangles);   
    }
}
