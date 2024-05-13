#include "Map.h"

Map::Map()
{
    wallColor = sf::Color::Blue;
    spaceColor = sf::Color::Black;
}

bool Map::loadMapFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<bool> row;
        for (char c : line) {
            if (c == '#') {
                row.push_back(true);
            }
            else if (c == ' ') {
                row.push_back(false);
            }
        }
        mapData.push_back(row);
    }

    file.close();
    return true;
}

bool Map::load(const std::string& filename)
{
    return loadMapFromFile(filename);
}

void Map::draw(sf::RenderWindow& window)
{
    const float tileSize = 32.0f;

    sf::Vector2u windowSize = window.getSize();
    float windowHeight = static_cast<float>(windowSize.y);

    float mapHeight = mapData.size() * tileSize;

    float offsetY = (windowHeight - mapHeight) / 2.0f;

    for (size_t y = 0; y < mapData.size(); ++y) {
        for (size_t x = 0; x < mapData[y].size(); ++x) {
            sf::RectangleShape square(sf::Vector2f(tileSize, tileSize));
            square.setPosition(x * tileSize, y * tileSize + offsetY);
            square.setFillColor(mapData[y][x] ? wallColor : spaceColor);
            window.draw(square);
        }
    }
}
