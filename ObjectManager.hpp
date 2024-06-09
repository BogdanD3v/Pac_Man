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
    std::vector<T> getObjects();
};

template <typename T>
void ObjectManager<T>::addObject(const T& obj)
{
    objects.push_back(obj);
}

template <typename T>
void ObjectManager<T>::removeObject(const T& obj)
{
    objects.erase(std::remove(objects.begin(), objects.end(), obj), objects.end());
}

template <typename T>
void ObjectManager<T>::updateAll()
{
    for (auto& obj : objects)
    {
        obj->update();
    }
}

template <typename T>
void ObjectManager<T>::drawAll(sf::RenderWindow& window)
{
    for (auto& obj : objects)
    {
        obj->draw(window);
    }
}

template<typename T>
void ObjectManager<T>::move(Map& map)
{
    for (auto& obj : objects)
    {
        obj->move(map);
    }
}

template<typename T>
std::vector<T> ObjectManager<T>::getObjects()
{
    return objects;
}


