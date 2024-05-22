#include "PacMan.h"

PacMan::PacMan(): position(368, 400), velocity(2, 2), color(sf::Color::Yellow)
{
    shape.setRadius(15.0f);
    shape.setFillColor(color);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setPosition(position);
}

void PacMan::move(sf::Vector2f direction)
{
    position = { shape.getPosition().x + (velocity.x * direction.x), shape.getPosition().y + (velocity.y * direction.y) };

    if (shape.getPosition().x >= 736 && direction.x == 1)
        position = { 0, 416 };

    else if (shape.getPosition().x <= 0 && direction.x == -1)
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
