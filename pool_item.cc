#include "pool_item.hh"
/******************************************************************************
filename    pool_item.cc
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  3.1
due date    6/11/2026

Brief Description: will handle the basic information of the entity PoolItem class
******************************************************************************/
/**
 * update
 * @param context: calls the update
 * @return nothing
 */
void PoolItem::update() {
    //Do not change or delete this line
    Entity::updateBase();            
}
/**
 * draw
 * @param context: calls the draw
 * @return nothing
 */
void PoolItem::draw() {
    //Do not change or delete this line
    Entity::drawBase();
}
/**
 * Constructor
 * @param context: Creates a new PoolItem
 * @param n: name of the item
 * @param A: the type of bool
 * @return nothing
 */
PoolItem::PoolItem(std::string n, bool A): name(n),active(A)
{}