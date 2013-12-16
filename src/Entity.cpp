#include "Entity.hpp"

Entity::Entity(double mass, sf::Vector2f size, sf::Vector2f position) {
	this->mass = mass;
	this->size = size;
	this->position = position;
}

Player::Player(double mass, sf::Vector2f size, sf::Vector2f position) : Entity(mass, size, position){
	velocity.x = 0;
	velocity.y = 0;
	accel.x = 0;
	accel.y = 0;
}
