#pragma once
#include <SFML/Graphics.hpp>
#include "PacMan.h"
#include <vector>
#include <fstream>
#include <iostream>

class Map
{
private:

    std::vector<std::vector<bool>> mapData;
    sf::Color wallColor;
    sf::Color spaceColor;

    const float tileSize = 32.0f;
    float offsetY;
    bool setCollisionArea = false;

    bool loadMapFromFile(const std::string& filename);

public:

    Map();
    
    bool isWallCollision(PacMan& pacMan, sf::Vector2f desiredMove);
    bool load(const std::string& filename);
    void draw(sf::RenderWindow& window);

    // Maintance ----------
    void showVectorSize();
    int currentRow = 0;
    int currentColumn = 0;
    float collisionArea = 0;
    // Maintance -----------
};
