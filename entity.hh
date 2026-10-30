#pragma once
#include <vector>
#include <iostream>
#include "component.hh"

// global bars for testing purposes
inline int updateCounter = 0, drawCounter = 0;

/// <summary>
/// Abstract class for all Entities
/// </summary>
class Entity
{
protected:
    // Components attached to the class
    std::vector<Component*> components;
    
public:
    //Default constructor
    Entity();

    // Get a component by their name
    Component* getComponent(const char* name);
    
    // Attach a component to the Entity
    void attach(Component* component);
    
    // Update method for the entity, can be overriden and called from the game state Update method
    virtual void update() = 0;

    // Draw method for the entity, can be overriden and called from the game state Draw method
    virtual void draw() = 0;

    // Default destroyer for the class
    virtual ~Entity();

    //Methods for testing purposes
    void updateBase(){
        updateCounter++;    
        std::cout << "Entity " << updateCounter << " updated " << std::endl;
    }

    void drawBase(){
        drawCounter++;    
        std::cout << "Entity " << drawCounter << " drawed " << std::endl;
    }
};
