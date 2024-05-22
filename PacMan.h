#pragma once

#include <SFML/Graphics.hpp>

class PacMan {
private:
    sf::Vector2f position;
    sf::Vector2f velocity;

    sf::CircleShape shape;
    sf::Color color;

public:
    PacMan();

    void move(sf::Vector2f velocity);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition();
    float getRadius();
};


