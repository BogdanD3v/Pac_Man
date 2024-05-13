#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

class Map
{
private:

    std::vector<std::vector<bool>> mapData;
    sf::Color wallColor;
    sf::Color spaceColor;

    bool loadMapFromFile(const std::string& filename);

public:

    Map();
 
    bool load(const std::string& filename);
    void draw(sf::RenderWindow& window);
};
