#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include "Map.h"

template <typename T>
class ObjectManager 
{
private:

    std::vector<T> objects;

public:

    void addObject(const T&);
    void removeObject(const T&);
    void updateAll();
    void drawAll(sf::RenderWindow&);
    void move(Map&);
};
