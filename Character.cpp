#include "Character.h"

Character::Character(sf::Vector2f startPosition) 
	: currentDirection(0,0)
	, velocity(0)
	, position(startPosition) {}

Character::~Character() {}


