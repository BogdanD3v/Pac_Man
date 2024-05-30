#pragma once

#include "PacMan.h"
#include "Map.h"

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

	float collisionArea = 0;

	bool setCollisionArea = false;

public:

	CollisionManager();

	bool isWallCollision(PacMan&, Map&);
};

