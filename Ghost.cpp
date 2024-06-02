#include "Ghost.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Ghost::Ghost()
    : direction(1.0f, 0.0f)
    , velocity(2.0f) 
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

Ghost::~Ghost()
{
    texture.~Texture();
}

bool Ghost::loadTexture(const std::string& filename)
{
    if (!texture.loadFromFile(filename))
    {
        std::cerr << "Fail to load ghost texture!" << "\n";
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
    int mapX;
    int mapY;

    if (direction.x == 1 && direction.y == 0 || direction.x == 0 && direction.y == 1)
    {
        mapX = static_cast<int>((sprite.getPosition().x + 30.f) / map.getTileSize());
        mapY = static_cast<int>(((sprite.getPosition().y - map.getOffSetY()) + 30.f) / map.getTileSize());
    }
    else
    {
        mapX = static_cast<int>(sprite.getPosition().x / map.getTileSize());
        mapY = static_cast<int>((sprite.getPosition().y - map.getOffSetY()) / map.getTileSize());
    }

    sf::Vector2f nextPosition = getNextPosition();

    if (isValidMove(nextPosition, map))
    {
        sprite.setPosition(nextPosition);
    }
    else
    {
        changeDirection();
    }
}

void Ghost::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::Vector2f Ghost::getPosition()
{
    return sprite.getPosition();
}

sf::Vector2f Ghost::getNextPosition()
{
    return sprite.getPosition() + direction * velocity;
}

bool Ghost::isValidMove(const sf::Vector2f& position, Map& map)
{
    int mapX;
    int mapY;

    if (direction.x == 1 && direction.y == 0 || direction.x == 0 && direction.y == 1)
    {
        mapX = static_cast<int>((position.x + 30.f) / map.getTileSize());
        mapY = static_cast<int>(((position.y - map.getOffSetY()) + 30.f) / map.getTileSize());
    }
    else
    {
        mapX = static_cast<int>(position.x / map.getTileSize());
        mapY = static_cast<int>((position.y - map.getOffSetY()) / map.getTileSize());
    }

    if (mapX < 0 || mapX >= map.getMapData()[0].size() || mapY < 0 || mapY >= map.getMapData().size())
    {
        return false;
    }

    return map.getMapData()[mapY][mapX] == 0;
}

void Ghost::changeDirection()
{
    int changeDirection = rand() % 4 + 1;

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
