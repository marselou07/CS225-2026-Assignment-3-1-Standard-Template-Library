#include "object_pool.hh"
bool isTrue(PoolItem* p)
{
    return p->active;
}
bool isFalse(PoolItem* p)
{
    return p->active== false;
}
void ObjectPool::add(PoolItem& item)
{
    this->Object_container.push_back(&item);
}

int ObjectPool::count()
{
    return this->Object_container.size();
}

int ObjectPool::countActive()
{
    auto number = std::count_if(Object_container.begin(),Object_container.end(),isTrue);
    return number;
}

PoolItem* ObjectPool::findByName(const std::string name)
{
    auto it = find_if(this->Object_container.begin(),Object_container.end(), [name](const PoolItem* Pool)
    {
        return Pool->name == name;
    });
    if(it == Object_container.end())
    {
        return nullptr;
    }
    return (*it);
}

PoolItem* ObjectPool::findByRef(PoolItem PoolName)
{
    auto it = find_if(this->Object_container.begin(),Object_container.end(), [PoolName](const PoolItem* Pool)
    {
        return Pool->name == PoolName.name;
    });
    if(it == Object_container.end())
    {
        return nullptr;
    }
    return (*it);
}

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

void ObjectPool::updateAll()
{
    std::for_each(Object_container.begin(),Object_container.end(),[]( PoolItem* Pool)
    {
        Pool->update();
    });
}

void ObjectPool::drawAll()
{
    std::for_each(Object_container.begin(),Object_container.end(),[]( PoolItem* Pool)
    {   
        Pool->draw();
    });
}

void ObjectPool::updateActive()
{
    std::for_each(Object_container.begin(),Object_container.end(),[]( PoolItem* Pool)
    {
        if(Pool->active == true)
        Pool->update();
    });
}

void ObjectPool::drawActive()
{
    std::for_each(Object_container.begin(),Object_container.end(),[]( PoolItem* Pool)
    {
        if(Pool->active == true)
        Pool->draw();
    });
}

void ObjectPool::removeByName(std::string name)
{
    auto it = std::remove_if(Object_container.begin(),Object_container.end(),[name]( PoolItem* Pool)
    {
        return name == Pool->name;
    });
    Object_container.erase(it,Object_container.end());
}

void ObjectPool::removeInactive()
{
    auto it = std::remove_if(Object_container.begin(),Object_container.end(),isFalse);
    Object_container.erase(it,Object_container.end());
}
