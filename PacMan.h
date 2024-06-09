#pragma once

#include <SFML/Graphics.hpp>
#include "Direction.h"

class PacMan 
{
private:

    sf::Vector2f position;
    sf::Vector2f velocity;
    Direction currentDirection;
    Direction desiredDirection;

    sf::CircleShape shape;
    sf::Color color;

public:

    PacMan();

    void setDesiredMove(Direction);
    void move();
    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition();
    float getRadius();
    Direction getDesiredMove();
    void setCurrentDirection(Direction);
    Direction getCurrentDirection();

    friend std::ostream& operator<<(std::ostream&, const PacMan&);
};


