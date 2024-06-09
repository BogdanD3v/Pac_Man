#pragma once

#include "PacMan.h"
#include "Map.h"
#include "Ghost.h"
#include "ObjectManager.hpp"
#include "Direction.h"

class CollisionManager
{
private:

	int currentRow;
	int currentColumn;
	int previousColumn;
	int previousRow;
	int nextColumn;
	int nextRow;
	int lastDirection;

	bool upSwitched;
	bool downSwitched;
	bool rightSwitched;
	bool leftSwitched;
	bool ghostCollision;

	float collisionArea = 0;

	bool setCollisionArea = false;

public:

	CollisionManager();

	bool isWallCollision(PacMan&, Map&);

	void isGhostCollision(PacMan&, ObjectManager<Character*>&);

	bool ghostCollisionState();
};

