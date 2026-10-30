#pragma once

#include <Algorithm>
#include <vector>
#include "pool_item.hh"
class ObjectPool
{
    std::vector<PoolItem*> Object_container;
    public:
    void add(PoolItem& item);
    int count();
    int countActive();
    PoolItem* findByName(const std::string name);
    PoolItem* findByRef(PoolItem  PoolName);
    void activate(const std::string name);
    void deactivate(const std::string name);
    void updateAll();
    void drawAll();
    void updateActive();
    void drawActive();
    void removeByName(std::string name);
    void removeInactive();
};