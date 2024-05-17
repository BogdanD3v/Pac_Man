#include "PacMan.h"

PacMan::PacMan(): position(368, 400), velocity(2, 2), color(sf::Color::Yellow)
{
    shape.setRadius(15.0f);
    shape.setFillColor(color);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setPosition(position);
}

void PacMan::move(sf::Vector2f _velocity)
{
    position = { shape.getPosition().x + (velocity.x * _velocity.x), shape.getPosition().y + (velocity.y * _velocity.y) };
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
