#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <SFML/Graphics.hpp>
#include "Game.hpp"

class Entity {
	public:
		Entity(double mass, sf::Vector2f size, sf::Vector2f position);
	protected:
		double mass;
		sf::Vector2f size;
		sf::Vector2f position;
		sf::Sprite sprite;
};

class Player : public Entity {
	public:
		Player(double mass, sf::Vector2f size, sf::Vector2f position);
		void draw();
	private:
		sf::Vector2f screenPos;
		sf::Vector2f velocity;
		sf::Vector2f accel;
		bool direction; // 0=left 1=right
		
		//bodyparts
		sf::CircleShape head;
		sf::RectangleShape torso;
		sf::RectangleShape rightArm;
		sf::RectangleShape leftArm;
		sf::RectangleShape rightLeg;
		sf::RectangleShape leftLeg;
};

#endif
