#include "Map.h"

Map::Map()
{
    wallColor = sf::Color::Blue;
    spaceColor = sf::Color::Black;
}

bool Map::loadMapFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open()) 
    {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) 
    {
        std::vector<bool> row;

        for (char c : line) 
        {
            if (c == '#') 
            {
                row.push_back(true);
            }
            else if (c == ' ') 
            {
                row.push_back(false);
            }
        }
        mapData.push_back(row);
    }

    file.close();
    return true;
}

bool Map::isWallCollision(PacMan& pacMan, sf::Vector2f desiredMove)
{
    currentRow = static_cast<int>((pacMan.getPosition().y - offsetY) / tileSize);
    currentColumn = static_cast<int>(pacMan.getPosition().x / tileSize);
    int previousColumn = currentColumn - 1;
    int previousRow = currentRow - 1;
    int nextColumn = currentColumn + 1;
    int nextRow = currentRow + 1;

    if (previousRow < 0)
        previousRow = 0;

    if (previousColumn < 0)
        previousColumn = 0;
    

    if (desiredMove.y < 0)
    {
        if (mapData[previousRow][currentColumn] && !setCollisionArea)
        {
            collisionArea = (previousRow * tileSize) + offsetY + pacMan.getRadius();
            setCollisionArea = true;
        }
        if (pacMan.getPosition().y <= collisionArea + tileSize)
        {
            setCollisionArea = false;
            collisionArea = 0;
            return true;
        }
    }

    if (desiredMove.y > 0)
    {
        if (mapData[nextRow][currentColumn] && !setCollisionArea)
        {
            collisionArea = (currentRow * tileSize) + offsetY + pacMan.getRadius();
            setCollisionArea = true;
        }
        if (pacMan.getPosition().y >= collisionArea && collisionArea != 0)
        {
            setCollisionArea = false;
            collisionArea = 0;
            return true;
        }
    }

    if (desiredMove.x > 0)
    {
        if (mapData[currentRow][nextColumn] && !setCollisionArea)
        {
            collisionArea = (currentColumn * tileSize) + pacMan.getRadius();
            setCollisionArea = true;
        }
        if (pacMan.getPosition().x >= collisionArea && collisionArea != 0)
        {
            setCollisionArea = false;
            collisionArea = 0;
            return true;
        }
    }

    if (desiredMove.x < 0)
    {
        if (mapData[currentRow][previousColumn] && !setCollisionArea)
        {
            collisionArea = (currentColumn * tileSize) + pacMan.getRadius();
            setCollisionArea = true;
        }
        if (pacMan.getPosition().x <= collisionArea)
        {
            setCollisionArea = false;
            collisionArea = 0;
            return true;
        }
    }

    return false;

}

bool Map::load(const std::string& filename)
{
    return loadMapFromFile(filename);
}

void Map::draw(sf::RenderWindow& window)
{
    sf::Vector2u windowSize = window.getSize();
    float windowHeight = static_cast<float>(windowSize.y);

    float mapHeight = mapData.size() * tileSize;

    offsetY = (windowHeight - mapHeight) / 2.0f;

    for (size_t y = 0; y < mapData.size(); ++y) 
    {
        for (size_t x = 0; x < mapData[y].size(); ++x) 
        {
            sf::RectangleShape square(sf::Vector2f(tileSize, tileSize));
            square.setPosition(x * tileSize, y * tileSize + offsetY);
            square.setFillColor(mapData[y][x] ? wallColor : spaceColor);
            window.draw(square);
        }
    }
}

void Map::showVectorSize()
{
    std::cout << "Wektor rozmiar wiersze: " << mapData.size(); std::cout << " " << "Wektor rozmiar kolumny: "; std::cout << mapData[9].size();
}
