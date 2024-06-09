#include "ObjectManager.h"

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
