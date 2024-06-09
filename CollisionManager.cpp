#include "CollisionManager.h"

CollisionManager::CollisionManager() 
    : currentRow(0)
    , currentColumn(0)
    , previousColumn(0)
    , previousRow(0)
    , nextColumn(0)
    , nextRow(0)
    , collisionArea(0)
    , setCollisionArea(false)
    , upSwitched(false)
    , downSwitched(false)
    , rightSwitched(false)
    , leftSwitched(false)
    , lastDirection(0)
    , ghostCollision(false) {}

bool CollisionManager::isWallCollision(PacMan& pacMan, Map& map)
{
    currentRow = static_cast<int>((pacMan.getPosition().y - map.getOffSetY()) / map.getTileSize());
    currentColumn = static_cast<int>(pacMan.getPosition().x / map.getTileSize());
    previousColumn = currentColumn - 1;
    previousRow = currentRow - 1;
    nextColumn = currentColumn + 1;
    nextRow = currentRow + 1;

    if (previousRow < 0)
        previousRow = 0;
    if (previousColumn < 0)
        previousColumn = 0;
    if (nextRow > map.getMapData().size())
        nextRow = map.getMapData().size();
    if (nextColumn >= 22)
        nextColumn = 22;

    auto updateDirection = [&](float x, float y, bool& switchFlag, int row, int column, float nextPosition, bool& other1, bool& other2, bool& other3) {
        if (pacMan.getDesiredMove().x == x && pacMan.getDesiredMove().y == y && !map.getMapData()[row][column] && !switchFlag) 
        {
            pacMan.setCurrentDirection(pacMan.getDesiredMove());
            switchFlag = true;
            other1 = other2 = other3 = false;
        }
    };

    updateDirection(0, -1, upSwitched, previousRow, currentColumn, pacMan.getPosition().y, downSwitched, rightSwitched, leftSwitched);
    updateDirection(0, 1, downSwitched, nextRow, currentColumn, pacMan.getPosition().y, upSwitched, rightSwitched, leftSwitched);
    updateDirection(-1, 0, leftSwitched, currentRow, previousColumn, pacMan.getPosition().x, upSwitched, downSwitched, rightSwitched);
    updateDirection(1, 0, rightSwitched, currentRow, nextColumn, pacMan.getPosition().x, upSwitched, downSwitched, leftSwitched);

    if (pacMan.getDesiredMove().y < 0)
    {
        if (map.getMapData()[previousRow][currentColumn] && !setCollisionArea)
        {
            collisionArea = (previousRow * map.getTileSize()) + map.getOffSetY() + pacMan.getRadius();
            setCollisionArea = true;
        }
        if (pacMan.getPosition().y <= collisionArea + map.getTileSize())
        {
            setCollisionArea = false;
            collisionArea = 0;
            return true;
        }
    }

    if (pacMan.getDesiredMove().y > 0)
    {
        if (map.getMapData()[nextRow][currentColumn] && !setCollisionArea)
        {
            collisionArea = (currentRow * map.getTileSize()) + map.getOffSetY() + pacMan.getRadius();
            setCollisionArea = true;
        }
        if (pacMan.getPosition().y >= collisionArea && collisionArea != 0)
        {
            setCollisionArea = false;
            collisionArea = 0;
            return true;
        }
    }

    if (pacMan.getDesiredMove().x > 0)
    {
        if (map.getMapData()[currentRow][nextColumn] && !setCollisionArea)
        {
            collisionArea = (currentColumn * map.getTileSize()) + pacMan.getRadius();
            setCollisionArea = true;
        }
        if (pacMan.getPosition().x >= collisionArea && collisionArea != 0)
        {
            setCollisionArea = false;
            collisionArea = 0;
            return true;
        }
    }

    if (pacMan.getDesiredMove().x < 0)
    {
        if (map.getMapData()[currentRow][previousColumn] && !setCollisionArea)
        {
            collisionArea = (currentColumn * map.getTileSize()) + pacMan.getRadius();
            setCollisionArea = true;
        }
        if (pacMan.getPosition().x <= collisionArea)
        {
            setCollisionArea = false;
            collisionArea = -1;
            return true;
        }
    }

    return false;
}

void CollisionManager::isGhostCollision(PacMan& pacMan, ObjectManager<Character*>& ghosts)
{
    for (auto ghost : ghosts.getObjects())
    {
        if (
            (ghost->getPosition().x <= pacMan.getPosition().x
                &&
                ghost->getPosition().x + 30 >= pacMan.getPosition().x)
            &&
            (ghost->getPosition().y <= pacMan.getPosition().y
                &&
                ghost->getPosition().y + 30 >= pacMan.getPosition().y)
            )
        {
            ghostCollision = true;
        }
    }
}

bool CollisionManager::ghostCollisionState()
{
    return ghostCollision;
}
