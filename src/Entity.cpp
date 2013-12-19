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
	
	//calculating bodypart's Sizes
	float headSize = Game::convertToPixels(size).y * 0.1;
	sf::Vector2f torsoSize, armSize, legSize = Game::convertToPixels(size);
	torsoSize.x *= 0.8;
	torsoSize.y *= 0.4;
	armSize.x *= 0.2;
	armSize.y *= 0.4;
	legSize.x *= 0.3;
	legSize.y *= 0.4;

	//setting body part Sizes
	head.setRadius(headSize);
	torso.setSize(torsoSize);
	rightArm.setSize(armSize);
	leftArm.setSize(armSize);
	rightLeg.setSize(legSize);
	leftLeg.setSize(legSize);

	//calculating bodypart's positions
	sf::Vector2f headPos, torsoPos, armPos, legPos = Game::convertToPixels(position);
	headPos.y += Game::convertToPixels(size).y;
	headPos.x += Game::convertToPixels(size).x / 2;
	torsoPos.y = headPos.y - headSize * 2;
	torsoPos.x += Game::convertToPixels(size).x / 2 - torsoSize.x / 2;
}
