#include "Game.hpp"


//extern Player player;
extern World Game::world = *(new World(&window));
extern float Game::conversion;
extern sf::RenderWindow Game::window;
extern sf::Vector2f Game::aspectRatio;
extern int Game::gameState;
extern std::map<std::string, sf::Texture> Game::textures;
extern sf::Event Game::event;

//general game functions
void Game::init(float windowX, float windowY, float aspectX, float aspectY, float conv) {
	window.create(sf::VideoMode(windowX, windowY), "Such Game");
	conversion = conv;
	aspectRatio.x = aspectX;
	aspectRatio.y = aspectY;
	gameState = 1;
  //Player player(10, sf::Vector2f(0.5, 1.8), sf::Vector2f(1, 0));
	Engine::init(&window, aspectRatio, conversion);
}


void Game::handleEvents() 
{	
	while(window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      window.close();
      Game::setGameState(0);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
      //ss.str("");
      sf::Vector2i intPos = sf::Mouse::getPosition(window);
      sf::Vector2f pos;
      pos.x = intPos.x;
      pos.y = intPos.y;
      pos = Engine::convertPixelsToPos(pos);
      //ss << pos.x;
      //ss << " ";
      //ss << pos.y;
      sf::Vertex* vert = new sf::Vertex(pos, pos);
      world.getChunks()[0]->appendVertex(vert);
    }
	}
}

void Game::draw()
{ 
  world.draw();
}

//getters
sf::Event* Game::getEvent()
{
  return &event;
}

sf::RenderWindow* Game::getWindow() {
	return &window;
}

sf::Vector2f* Game::getAspectRatio() {
	return &aspectRatio;
}

float Game::getConversion() {
	return conversion;
}

int Game::getGameState() {
	return gameState;
}

sf::Texture* Game::getTexture(std::string textureName) {
	return &textures[textureName];
}

//setters
void Game::setGameState(int state) {
	gameState = state;
}
