#pragma once
#include "entity.hh"
#include <string>
class PoolItem : public Entity
{        
    public:
        // Other methods or properties must be here

        void update() override; // Provided method, do not change
    
        void draw() override; // Provided method, do not change
        std::string name;
        bool Active = false;
        PoolItem(std::string n, bool A): name(n),Active(A)
        {}
        



};
