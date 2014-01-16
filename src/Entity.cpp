#include "Entity.hpp"
#include <iostream>

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
	direction = 1;
	
	//calculating bodypart's Sizes
	float headSize = Engine::convertSizeToPixels(size).y * 0.1;
	sf::Vector2f torsoSize, armSize, legSize;
	torsoSize = armSize = legSize = Engine::convertSizeToPixels(size);

	torsoSize.x *= 0.4;
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


	//setting body part origin to center top
	head.setOrigin(head.getRadius(), 0);
	torso.setOrigin(torsoSize.x/2, 0);
	leftArm.setOrigin(armSize.x/2, 0);
	rightArm.setOrigin(armSize.x/2, 0);
	leftLeg.setOrigin(legSize.x/2, 0);
	rightLeg.setOrigin(legSize.x/2, 0);


	//setting colors for testing
	rightArm.setFillColor(sf::Color::Red);
	leftArm.setFillColor(sf::Color::Blue);
	rightLeg.setFillColor(sf::Color::Red);
	leftLeg.setFillColor(sf::Color::Blue);

	//setting screen position based to center
	//screenPos.x = Game::getWindow()->getSize().x/2;
	//screenPos.y = Game::getWindow()->getSize().y/2;

}

void Player::draw() {
	//calculating bodypart's positions
	sf::Vector2f headPos, torsoPos, armPos, legPos;
	headPos = torsoPos = armPos = legPos = screenPos;	

	headPos.y -= Engine::convertSizeToPixels(size).y;
	torsoPos.y = headPos.y + head.getRadius() * 2;
	armPos.y = torsoPos.y + torso.getSize().y/10;
	legPos.y = torsoPos.y + torso.getSize().y;

	//setting body part positions
	head.setPosition(headPos);
	torso.setPosition(torsoPos);
	rightArm.setPosition(armPos);
	leftArm.setPosition(armPos);
	rightLeg.setPosition(legPos);
	leftLeg.setPosition(legPos);

	//drawing body parts
	if (direction == 1) {
		//Game::getWindow()->draw(leftArm);
		//Game::getWindow()->draw(leftLeg);
	}
	else {
		//Game::getWindow()->draw(rightArm);
		//Game::getWindow()->draw(rightLeg);
	}
	//Game::getWindow()->draw(head);
	//Game::getWindow()->draw(torso);
	if (direction == 0) {
		//Game::getWindow()->draw(leftArm);
		//Game::getWindow()->draw(leftLeg);
	}
	else {
		//Game::getWindow()->draw(rightArm);
		//Game::getWindow()->draw(rightLeg);
	}

}
