/*
 * LazyTower.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: kevinw
 */

#include "TodoSimpleTower.h"

const int SIMPLE_TOWER_COST = 1;
const int SIMPLE_TOWER_UPGRADE_COST = 1;
const int SIMPLE_TOWER_POWER = 3;


TodoSimpleTower::TodoSimpleTower(int x, int y) : Tower(SIMPLE_TOWER_COST, SIMPLE_TOWER_UPGRADE_COST, SIMPLE_TOWER_POWER) {
    
    setXY(x, y);
}

TodoSimpleTower::TodoSimpleTower(int cost, int upgrade_cost, int power) : Tower(cost, upgrade_cost, power) {
    
}

bool TodoSimpleTower::isInRange(int x, int y) const {
    int ax, ay;
    getXY(ax, ay);
    if (ax - 1 == x && ay == y)
        return true;
    else if (ax - 2 == x && ay == y)
        return true;
    else
        return false;
}

TodoSimpleTower::~TodoSimpleTower() {
    
}

