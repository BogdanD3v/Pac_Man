#include "Map.h"

Map::Map() 
    : wallColor(sf::Color::Blue)
    , spaceColor(sf::Color::Black)
    , currentRow(0)
    , currentColumn(0)
    , tileSize(32.f)
    , offsetY(0) {}

bool Map::loadMapFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open()) 
    {
        std::cerr << "Failed to load map data file!" << "\n";
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
    mapDataPoints.resize(mapData.size());

    for (size_t i = 0; i < mapData.size(); i++)
    {
        mapDataPoints[i].resize(mapData[i].size());
        for (size_t j = 0; j < mapData[i].size(); j++)
        {
            mapDataPoints[i][j] = !mapData[i][j];
        }
    }
}

int Map::loadTextures()
{
    if (!pointTexture.loadFromFile("textures/pill.png"))
    {
        std::cerr << "Failed to load map textures!" << "\n";
        return 1;
    }

    point.setTexture(pointTexture);
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

            if (mapDataPoints[y][x])
            {
                float pointX = x * tileSize + (tileSize / 2) - (point.getTextureRect().width / 2);
                float pointY = y * tileSize + offsetY + (tileSize / 2) - (point.getTextureRect().height / 2);
                point.setPosition(pointX, pointY);
                window.draw(point);
            }
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

    if (mapDataPoints[currentRow][currentColumn])
    {
        mapDataPoints[currentRow][currentColumn] = false;
        return true;
    }
    else
        return false;
    
}

float Map::getOffSetY()
{
    return offsetY;
}

const float Map::getTileSize()
{
    return tileSize;
}

std::vector<std::vector<bool>> Map::getMapData()
{
    return mapData;
}







