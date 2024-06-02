#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Character.h"
#include "Map.h"

class Ghost : public Character
{
private:

    sf::Vector2f currentDirection;
    sf::Vector2f position;
    sf::Sprite sprite;
    sf::Texture texture;
    float velocity;

    sf::Vector2f getNextPosition();
    bool isValidMove(const sf::Vector2f&, Map&);
    void changeDirection();

public:
    Ghost(sf::Vector2f);
    ~Ghost();

    bool loadTexture(const std::string&) override;

    void setPosition(const sf::Vector2f&) override;

    void move(Map&) override;

    void draw(sf::RenderWindow&) override;

    sf::Vector2f getPosition() override;
};
