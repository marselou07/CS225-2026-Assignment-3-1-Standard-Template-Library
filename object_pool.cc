#include "object_pool.hh"
/******************************************************************************
filename    object_pool.cc
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  3.1
due date    6/11/2026

Brief Description: This program will create the logic for object_pool class
to work with the PoolItems
******************************************************************************/
/**
 * isTrue
 * @param context: Checks of the PoolItem is active
 * @param p: A pointer to the checked item
 * @return the active bool
 */
bool isTrue(PoolItem* p)
{
    return p->active;
}
/**
 * isFalse
 * @param context: Checks of the PoolItem is not active
 * @param p: A pointer to the checked item
 * @return the active bool
 */
bool isFalse(PoolItem* p)
{
    return p->active== false;
}
/**
 * UpdatePool
 * @param context: Calls update for all objects
 * @param p: A pointer to the checked item
 * @return nothing
 */
void UpdatePool(PoolItem* p)
{
    p->update();
}
/**
 * Drawpool
 * @param context: Calls draw for all objects
 * @param p: A pointer to the checked item
 * @return nothing
 */
void Drawpool(PoolItem* p)
{
    p->draw();
}
/**
 * add
 * @param context: Adds a new item to the
 * container
 * @param item: The adress of the item 
 * @return nothing
 */
void ObjectPool::add(PoolItem& item)
{
    this->Object_container.push_back(&item);
}
/**
 * count
 * @param context: gets the size of the 
 * container
 * @return the size of the container
 */
int ObjectPool::count()
{
    return this->Object_container.size();
}
/**
 * countActive
 * @param context: gets the all active elements on
 * the container
 * @return the number of active elements
 */
int ObjectPool::countActive()
{
    auto number = std::count_if(Object_container.begin(),Object_container.end(),isTrue);
    return number;
}
/**
 * findByName
 * @param context: find the first object with the 
 * provided name
 * @param name: The name of the object
 * @return a pointer to the object or nullptr
 * if that componets does not exist
 */
PoolItem* ObjectPool::findByName(const std::string name)
{
    PoolFinder finder(name);
    auto it = find_if(this->Object_container.begin(),Object_container.end(), finder);
    if(it == Object_container.end())
    {
        return nullptr;
    }
    return (*it);
}
/**
 * findByRef
 * @param context: find the first object that matches the
 * provided component name
 * @param PoolName: a reference to the obeject that is 
 * the test
 * @return a pointer to the object or nullptr
 * if that componet doesn´t match
 */
PoolItem* ObjectPool::findByRef(PoolItem PoolName)
{
    PoolFinder finder(PoolName.name);
    auto it = find_if(this->Object_container.begin(),Object_container.end(), finder);
    if(it == Object_container.end())
    {
        return nullptr;
    }
    return (*it);
}
/**
 * activate
 * @param context:set all objects that matches to active
 * @param name: the name of the object
 * @return nothing
 */
void ObjectPool::activate(const std::string name)
{
    std::for_each(Object_container.begin(),Object_container.end(),[name]( PoolItem* Pool)
{
    if(Pool->name == name)
    {
        Pool->active = true;
    }
});
}
/**
 * deactivate
 * @param context:set all objects that matches  active to false
 * @param name: the name of the object
 * @return nothing
 */
void ObjectPool::deactivate(const std::string name)
{
    std::for_each(Object_container.begin(),Object_container.end(),[name]( PoolItem* Pool)
{
    if(Pool->name == name)
    {
        Pool->active = false;
    }
});
}
/**
 * updateAll
 * @param context: call update for all objects
 * @return nothing
 */
void ObjectPool::updateAll()
{
    std::for_each(Object_container.begin(),Object_container.end(),UpdatePool);
}
/**
 * drawAll
 * @param context: call draw for all objects
 * @return nothing
 */
void ObjectPool::drawAll()
{
    std::for_each(Object_container.begin(),Object_container.end(),Drawpool);
}
/**
 * updateActive
 * @param context: call update for all objects that are active
 * @return nothing
 */
void ObjectPool::updateActive()
{
    std::for_each(Object_container.begin(),Object_container.end(),[]( PoolItem* Pool)
    {
        if(Pool->active == true)
        Pool->update();
    });
}
/**
 * drawActive
 * @param context: call draw for all objects that are active
 * @return nothing
 */
void ObjectPool::drawActive()
{
    std::for_each(Object_container.begin(),Object_container.end(),[]( PoolItem* Pool)
    {
        if(Pool->active == true)
        Pool->draw();
    });
}
/**
 * removeByName
 * @param context:remove the fist object that matches with the
 * name provided and free the memory
 * @param name: the name of the object
 * @return nothing
 */
void ObjectPool::removeByName(std::string name)
{
    PoolFinder finder(name);
    auto it = std::remove_if(Object_container.begin(),Object_container.end(),finder);
    Object_container.erase(it,Object_container.end());
}
/**
 * removeInactive
 * @param context:remove all objects that are not active
 * @param name: the name of the object
 * @return nothing
 */
void ObjectPool::removeInactive()
{
    auto it = std::remove_if(Object_container.begin(),Object_container.end(),isFalse);
    Object_container.erase(it,Object_container.end());
}
