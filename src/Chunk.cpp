#include "Chunk.hpp"

Chunk::Chunk(std::vector<sf::Vertex*> &vertices) {
  this->vertices = vertices;
  background.loadFromFile("resources/ground.png");
}

std::vector<sf::Vertex*> Chunk::getVertices() {
	return vertices;
}

void Chunk::draw() {
  std::vector<sf::Vertex*> copy = vertices;
  std::vector<sf::Vertex*> triangles;
  int i = 0;
  float theta = 0.0;
  sf::Vector2f u;
  sf::Vector2f v;
  int previousSize = copy.size();
  while (copy.size() > 2)
  {
    if (i >= copy.size())
    {
      i = 0;
      if (copy.size() == previousSize)
        break;//stop if hanging
      else
	      previousSize = copy.size();
	  }
    u.x = (Game::getElement(copy, i+1)->position.x - Game::getElement(copy, i)->position.x); 
    u.y = (Game::getElement(copy, i+1)->position.y - Game::getElement(copy, i)->position.y);
    v.x = (Game::getElement(copy, i+2)->position.x - Game::getElement(copy, i+1)->position.x);
    v.y = (Game::getElement(copy, i+2)->position.y - Game::getElement(copy, i+1)->position.y);
    //theta = acos((u.x*v.x + u.y*v.y)/(sqrt(pow(u.x, 2) + pow(u.y, 2))*sqrt(pow(v.x, 2) + pow(v.y, 2))));
    //std::cout << theta << std::endl;
    //sf::sleep(sf::seconds(1));
    float normalK = u.x*v.y - v.x*u.y;
    if (normalK < 0)
    {
      triangles.push_back(Game::getElement(copy, i));
      triangles.push_back(Game::getElement(copy, i+1));
      triangles.push_back(Game::getElement(copy, i+2));
      if (i+1 >= copy.size())
        copy.erase(copy.begin() + (i+1)%copy.size());
	    else
	      copy.erase(copy.begin()+i+1);     
	  }
	  i++;
	}
  Game::getWindow()->draw(&(Game::convertToPixels(triangles))[0], triangles.size(), sf::Triangles, Game::getTexture("background"));
	//Game::getWindow()->draw(&(Game::convertToPixels(vertices))[0], vertices.size(), sf::LinesStrip);
}


