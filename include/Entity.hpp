#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <SFML/Graphics.hpp>
#include "Game.hpp"

class Entity {
	public:
		Entity(double mass, sf::Vector2f size, sf::Vector2f position);
	private:
		double mass;
		sf::Vector2f size;
		sf::Vector2f position;
		sf::Sprite sprite;
};

class Player : public Entity {
	public:
		Player(double mass, sf::Vector2f size, sf::Vector2f position);
	private:
		sf::Vector2f velocity;
		sf::Vector2f accel;
		
		//bodyparts
		sf::CircleShape head;
		sf::RectangleShape torso;
		sf::RectangleShape rightArm;
		sf::RectangleShape leftArm;
		sf::RectangleShape rightLeg;
		sf::RectangleShape leftLeg;
};

#endif
