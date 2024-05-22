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

void Map::loadMapPoints()
{
    mapPoints.resize(mapData.size());

    for (size_t i = 0; i < mapData.size(); i++)
    {
        mapPoints[i].resize(mapData[i].size());
        for (size_t j = 0; j < mapData[i].size(); j++)
        {
            mapPoints[i][j] = !mapData[i][j];
        }
    }
}

bool Map::isPointCollected(PacMan& pacMan)
{
    currentRow = static_cast<int>((pacMan.getPosition().y - offsetY) / tileSize);
    currentColumn = static_cast<int>(pacMan.getPosition().x / tileSize);

    if (currentColumn > mapData[0].size() - 1)
        currentColumn = mapData[0].size() - 1;

    if (currentRow > mapData.size() - 1)
        currentRow = mapData.size() - 1;

    if (mapPoints[currentRow][currentColumn])
    {
        mapPoints[currentRow][currentColumn] = false;
        return true;
    }
    else
        return false;
    
}

int Map::loadTextures()
{
    if (!pointTexture.loadFromFile("textures/pill.png"))
        return 1;

    point.setTexture(pointTexture);
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

    if (nextRow > mapData.size())
        nextRow = mapData.size();

    if (nextColumn >= 22)
        nextColumn = 22;
    

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
            collisionArea = -1;
            return true;
        }
    }

    return false;

}

void Map::load(const std::string& filename)
{
    loadMapFromFile(filename); 
    loadTextures();
    loadMapPoints();
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

            if (mapPoints[y][x])
            {
                float pointX = x * tileSize + (tileSize / 2) - (point.getTextureRect().width / 2);
                float pointY = y * tileSize + offsetY + (tileSize / 2) - (point.getTextureRect().height / 2);
                point.setPosition(pointX, pointY);
                window.draw(point);
            }
        }
    }
}

void Map::showVectorSize()
{
    std::cout << "Wektor rozmiar wiersze: " << mapData.size(); std::cout << " " << "Wektor rozmiar kolumny: "; std::cout << mapData[11].size();
}
