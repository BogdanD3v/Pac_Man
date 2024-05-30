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
    std::vector<std::vector<bool>> mapDataPoints;

    sf::Color wallColor;
    sf::Color spaceColor;

    sf::Texture pointTexture;
    sf::Sprite point;

    int currentRow;
    int currentColumn;

    const float tileSize;

    float offsetY;

    bool loadMapFromFile(const std::string&);
    void loadMapPoints();
    int loadTextures();

public:

    Map();

    void load(const std::string&);
    void draw(sf::RenderWindow&);
    bool isPointCollected(PacMan&);

    float getOffSetY();
    const float getTileSize();
    std::vector<std::vector<bool>> getMapData();
};
