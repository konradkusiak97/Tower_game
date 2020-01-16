/*
 * Arena.cpp
 *
 *  Created on: Feb 25, 2016
 *      Author: kevinw
 */

#include "Arena.h"

#include "Enemy.h"
#include "TodoCatapult.h"
#include "TodoDiagonalEnemy.h"
#include "TodoIceTower.h"
#include "TodoLaserTower.h"
#include "TodoRevivingEnemy.h"
#include "TodoSimpleTower.h"
#include <cmath>

const int ARENA_W = 45;
const int ARENA_H = 5;
const int TOWER_X = 35;
const int ENEMY_X = 0;





Arena::~Arena() {
    //TODO
    for (int i = 0; i < num_objects; i++)
        delete objects[i];
    delete[] objects;
}

//Perform shallow copying and add this object to the array objects.
//The ownership of this object is transfered to Arena.
void Arena::addObject(Object* newobj) {
    //TODO
    Object** newobjects = new Object* [num_objects+1];
    for (int i = 0; i < num_objects; i++)
        newobjects[i] = objects[i];
    
    newobjects[num_objects++] = newobj;
    if (num_objects != 1)
        delete [] objects;
    objects = newobjects;
    newobjects = nullptr;
}

//To return a dynamic const Object array. You might treat the memory
//pointed by obj is garbage.
void Arena::getConstObjects(const Object**& obj, int& count) const {
    //TODO
    count = num_objects;
    if (num_objects == 0) {
        obj = nullptr;
        return;
    }
    
    obj = new const Object* [num_objects];
    for (int i = 0; i < num_objects; i++) {
        obj[i] = objects[i];
    }
}

//Return the object in the array objects with the coordinate aX and aY.
//If there are more than one object is in this coordinate, return any
//one of them. If there are no object is in this coordinate, return nullptr
Object* Arena::getObjectAt(int aX, int aY) const {
    //TODO
    int x, y;
    for (int i = 0; i < num_objects; i++) {
        objects[i]->getXY(x,y);
        if (x == aX && y == aY)
            return objects[i];
    }
    return nullptr;
    
}

//Return true if the game is over, false otherwise.
//The game is over when any not DEAD enemy reaches the end-zone - i.e., its
//x-coordinate >= the constant TOWER_X.
bool Arena::isGameOver() const {
    //TODO
    Object* obj;
    int x, y;
    string type;
    
    for (int i = 0; i < num_objects; i++) {
        obj = objects[i];
        type  = obj->getName();
        if (type == "DiagonalEnemy" || type == "RevivingEnemy")
            if (obj->getState() != ObjectState::DEAD) {
                obj->getXY(x, y);
                if (x >= TOWER_X)
                    return true;
            }
    }
    return false;
}


//Remove the object pointed by the pointer r from the array objects if it is
//in the list. Do nothing if r is a nullptr or r is not in the array.
void Arena::removeObject(Object* r) {
    //TODO
    if (num_objects <= 0)
        return;
    if (num_objects == 1 && r == objects[0]) {
        delete objects[0];
        num_objects = 0;
        delete [] objects;
        objects = nullptr;
        return;
    }
    
    if (r != nullptr) {
        int i;
        for (i = 0; i < num_objects; i++)
            if (objects[i] == r)
                break;
        delete objects[i];
        for (int j = i; j < num_objects - 1; j++) {
            objects[j] = objects[j+1];
        }
        objects[num_objects - 1] = nullptr;
        num_objects--;
        return;
        
        
    }
}


//Depends on the value of the variable building, construct a tower at the coordinate x, y when money is larger than the building cost.
// if building is SIMPLE_TOWER - construct a TodoSimpleTower
// if building is CATAPUL_TOWER - construct a TodoCatapult
// if building is LASER_TOWER - construct a TodoLaserTower
// if building is ICE_TOWER - construct a TodoIceTower
// otherwise - do nothing.
// After building the tower, deduct the money by the building cost of the tower
void Arena::addBuilding(int building, int x, int y) {
    //TODO
    if (getObjectAt(x, y) != nullptr)
        return;
    
    Tower* newTower = nullptr;
    switch (building) {
        case SIMPLE_TOWER:
            newTower = new TodoSimpleTower(x, y);
            break;
        case CATAPULT_TOWER:
            newTower = new TodoCatapult(x, y);
            break;
        case LASER_TOWER:
            newTower = new TodoLaserTower(x, y);
            break;
        case ICE_TOWER:
            newTower = new TodoIceTower(x, y);
            break;
    }
    if (newTower->getCost() > money)
        delete newTower;
    else {
        addObject(newTower);
        money -= newTower->getCost();
    }
}


//This function would first make all tower fires (if there is
//at least one enemy in its range). By default, the tower will select
//the nearest enemy to shoot. If there are more than one nearest enemies,
//pick anyone of them (we would not test this case during grading).
//
//Next all enemies are going to move. Remember that an enemy in the state
//FROZEN or DEAD cannot move.
//
//Next you need to generate one new Enemy by calling the function genereateEnemy(). The function generateEnemy has been written for you already.
//
//Finally you need to clean up all DEAD enemy and tower that was destroyed by enemy in this turn.
//
//The amount of money will be increased by the enemies killed in this turn.
//(*noted: if a RevivingEnemy revive, money will not be added)

// Helper function : theClosest();

Object* theClosest(Tower* tower, Object** objects, int num_objects) {
    int ex, ey, tx, ty, Ex = 0, Ey = 0, closestObj = 0, check = 0;
    tower->getXY(tx, ty);
    
    for (int j = 0; j < num_objects; j++) {
        if (objects[j]->getObjectType() == ObjectType::ENEMY)
            if (objects[j]->getState() != ObjectState::DEAD){
                objects[j]->getXY(ex, ey);
                if(tower->isInRange(ex, ey))
                    if ((pow(ex-tx, 2) + pow(ey-ty, 2)) < (pow(Ex-tx, 2) + pow(Ey-ty, 2))) {
                        Ex = ex;
                        Ey = ey;
                        closestObj = j;
                        check = 1;
                    }
            }
    }
    if (check == 1)
        return objects[closestObj];
    else
        return nullptr;
}

void Arena::nextRound() {
    //TODO
    ObjectType typeT, typeE;
    
    for (int i = 0; i < num_objects; i++) {
        typeT = objects[i]->getObjectType();
        if(typeT == ObjectType::TOWER) {
            Tower* tower = static_cast<Tower*>(objects[i]);
            Object* E = theClosest(tower, objects, num_objects);
            if (E != nullptr){
                Enemy& enemy = *static_cast<Enemy*>(E);
                tower->fire(enemy);
                money += tower->collectMoney();
            }
        }
    }
    for (int i = 0; i < num_objects; i++) {
        typeE = objects[i]->getObjectType();
        if(typeE == ObjectType::ENEMY){
            Enemy* enemy = static_cast<Enemy*>(objects[i]);
            enemy->move();
        }
    }
    int xt, yt, xe, ye;
    for (int i = 0; i < num_objects; i++){
        typeT = objects[i]->getObjectType();
        if (typeT == ObjectType::TOWER){
            objects[i]->getXY(xt, yt);
            for (int j = 0; j < num_objects; j++) {
                typeE = objects[j]->getObjectType();
                if (typeT != typeE){
                    objects[j]->getXY(xe, ye);
                    if ( xe == xt && ye == yt)
                        objects[i]->setState(ObjectState::DEAD);
                }
            }
        }
    }
    generateEnemy();
    for (int i = 0; i < num_objects; i++)
        if(objects[i]->getState() == ObjectState::DEAD) {
            if (objects[i]->getObjectType() == ObjectType::ENEMY)
                enemy_kill++;
            removeObject(objects[i]);
        }
}


//Completed
bool Arena::upgrade(Tower* t) {
    if (t == nullptr || money < t->getUpgradeCost())
        return false;
    money -= t->getUpgradeCost();
    t->upgrade();
    return true;
}

//Completed
void Arena::generateEnemy() {
    int i = rand() % ARENA_H;
    Enemy* e;
    switch (rand() % 3) {
        case 0: e = new Enemy(5, ENEMY_X, i); break;
        case 1: e = new TodoDiagonalEnemy(6, ENEMY_X, i); break;
        case 2: e = new TodoRevivingEnemy(10, ENEMY_X, i); break;
    }
    addObject(e);
    
}

//Completed
Arena::Arena() : objects(nullptr), num_objects(0), money(10), enemy_kill(0) {
    nextRound();
}

