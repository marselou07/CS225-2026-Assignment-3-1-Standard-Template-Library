#include "object_pool.hh"
bool isTrue(PoolItem* p)
{
    return p->Active;
}

void ObjectPool::add(PoolItem item)
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
