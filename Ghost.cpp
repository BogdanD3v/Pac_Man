#include "Ghost.h"
#include <cstdlib>
#include <iostream>

Ghost::Ghost()
    : direction(1.0f, 0.0f)
    , velocity(2.0f) {}

bool Ghost::loadTexture(const std::string& filename)
{
    if (!texture.loadFromFile(filename))
    {
        return false;
    }
    sprite.setTexture(texture);
    sprite.setScale(1, 1);
    return true;
}

void Ghost::setPosition(const sf::Vector2f& position)
{
    sprite.setPosition(position);
}

void Ghost::move(Map& map)
{
    sf::Vector2f nextPosition = getNextPosition();

    int changeDirection;

    if (isValidMove(nextPosition, map))
    {
        sprite.setPosition(nextPosition);
    }
    else
    {
        changeDirection = rand() % 4 + 1;
        switch (changeDirection)
        {
        case 1:
            direction = { 1,0 };
            break;
        case 2:
            direction = { -1,0 };
            break;
        case 3:
            direction = { 0,1 };
            break;
        case 4:
            direction = { 0,-1 };
            break;
        default:
            break;
        }
    }
}

void Ghost::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::Vector2f Ghost::getNextPosition()
{
    return sprite.getPosition() + direction * velocity;
}

bool Ghost::isValidMove(const sf::Vector2f& position, Map& map)
{
    int mapX = static_cast<int>(position.x / map.getTileSize());
    int mapY = static_cast<int>((position.y - map.getOffSetY()) / map.getTileSize());

    return !map.getMapData()[mapY][mapX];
}
