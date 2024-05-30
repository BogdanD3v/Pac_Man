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
    , lastDirection(0) {}


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

    if (pacMan.getDesiredMove().y < 0 && !map.getMapData()[previousRow][currentColumn] && upSwitched == false)
    {
        pacMan.setCurrentDirection(pacMan.getDesiredMove());
        upSwitched = true;
        downSwitched = false;
        rightSwitched = false;
        leftSwitched = false;
    }
    else if (pacMan.getDesiredMove().y > 0 && !map.getMapData()[nextRow][currentColumn] && downSwitched == false)
    {
        pacMan.setCurrentDirection(pacMan.getDesiredMove());
        upSwitched = false;
        downSwitched = true;
        rightSwitched = false;
        leftSwitched = false;
    }
    else if (pacMan.getDesiredMove().x < 0 && !map.getMapData()[currentRow][previousColumn] && leftSwitched == false)
    {
        pacMan.setCurrentDirection(pacMan.getDesiredMove());
        upSwitched = false;
        downSwitched = false;
        rightSwitched = false;
        leftSwitched = true;
    }
    else if (pacMan.getDesiredMove().x > 0 && !map.getMapData()[currentRow][nextColumn] && rightSwitched == false)
    {
        pacMan.setCurrentDirection(pacMan.getDesiredMove());
        upSwitched = false;
        downSwitched = false;
        rightSwitched = true;
        leftSwitched = false;
    }


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
