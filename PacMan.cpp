#include "PacMan.h"

PacMan::PacMan()
    : position(176, 704)
    , velocity(2, 2)
    , color(sf::Color::Yellow)
    , desiredDirection(Direction::None)
    , currentDirection(Direction::None)
{
    shape.setRadius(15.0f);
    shape.setFillColor(color);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setPosition(position);
}

void PacMan::setDesiredMove(Direction _desiredDirection)
{
    desiredDirection = _desiredDirection;
}

void PacMan::move()
{
    switch (currentDirection)
    {
    case Direction::Up:
        position.y -= velocity.y;
        break;
    case Direction::Down:
        position.y += velocity.y;
        break;
    case Direction::Left:
        position.x -= velocity.x;
        break;
    case Direction::Right:
        position.x += velocity.x;
        break;
    default:
        break;
    }

    if (shape.getPosition().x >= 736 && currentDirection == Direction::Right)
        position = { 0, 416 };

    else if (shape.getPosition().x <= 0 && currentDirection == Direction::Left)
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

Direction PacMan::getDesiredMove()
{
    return desiredDirection;
}

void PacMan::setCurrentDirection(Direction _currentDirection)
{
    currentDirection = _currentDirection;
}

Direction PacMan::getCurrentDirection()
{
    return currentDirection;
}

std::ostream& operator<<(std::ostream& os, const PacMan& pacman)
{
    os << "Position: (" << pacman.position.x << ", " << pacman.position.y << "), "
        << "Velocity: (" << pacman.velocity.x << ", " << pacman.velocity.y << "), "
        << "Current Direction: " << toString(pacman.currentDirection) << ", "
        << "Desired Direction: " << toString(pacman.desiredDirection);
    return os;
}
