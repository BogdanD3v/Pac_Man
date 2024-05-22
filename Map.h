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
    std::vector<std::vector<bool>> mapPoints;

    sf::Color wallColor;
    sf::Color spaceColor;

    sf::Texture pointTexture;
    sf::Sprite point;

    const float tileSize = 32.0f;
    float offsetY;
    bool setCollisionArea = false;

    bool loadMapFromFile(const std::string& filename);
    void loadMapPoints();
    int loadTextures();

public:

    Map();

    bool isWallCollision(PacMan&, sf::Vector2f);
    void load(const std::string&);
    void draw(sf::RenderWindow&);
    bool isPointCollected(PacMan&);

    // Maintance ----------
    void showVectorSize();
    int currentRow = 0;
    int currentColumn = 0;
    float collisionArea = 0;
    // Maintance -----------
};
