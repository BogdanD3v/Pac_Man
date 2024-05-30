#include "PacMan.h"

PacMan::PacMan()
    : position(176, 704)
    , velocity(2, 2)
    , color(sf::Color::Yellow)
    , desiredDirection({0,0})
    , currentDirection({0,0})
{
    shape.setRadius(15.0f);
    shape.setFillColor(color);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setPosition(position);
}

void PacMan::setDesiredMove(sf::Vector2f _desiredDirection)
{
    desiredDirection = _desiredDirection;
}

void PacMan::move()
{
    position = { shape.getPosition().x + (velocity.x * currentDirection.x), shape.getPosition().y + (velocity.y * currentDirection.y) };

    if (shape.getPosition().x >= 736 && currentDirection.x == 1)
        position = { 0, 416 };

    else if (shape.getPosition().x <= 0 && currentDirection.x == -1)
        position = { 736, 416 };

    shape.setPosition(position);
}

void PacMan::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::Vector2f PacMan::getPosition()
{
    return position;
}

float PacMan::getRadius()
{
    return shape.getRadius();
}

sf::Vector2f PacMan::getDesiredMove()
{
    return desiredDirection;
}

void PacMan::setCurrentDirection(sf::Vector2f _currentDirection)
{
    currentDirection = _currentDirection;
}
