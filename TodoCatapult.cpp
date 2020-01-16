/*
 * Catapult.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: kevinw
 */

#include "TodoCatapult.h"

const int TODO_CATAPULT_COST = 2;
const int TODO_CATAPULT_UPGRADE_COST = 2;
const int TODO_CATAPULT_POWER = 5;
const int TODO_CATAPULT_RANGE = 5;

TodoCatapult::TodoCatapult(int cost, int upgrade_cost, int power) : Tower(cost, upgrade_cost, power) {
    
}

TodoCatapult::TodoCatapult(int x, int y) : Tower(TODO_CATAPULT_COST, TODO_CATAPULT_UPGRADE_COST, TODO_CATAPULT_POWER) {
    
    setXY(x, y);
}

bool TodoCatapult::isInRange(int x, int y) const {
    
    int ax, ay;
    getXY(ax, ay);
    
    int range_x = x - ax;
    if (range_x < 0)
        range_x = range_x * (-1);
    int range_y = y - ay;
    if (range_y < 0)
        range_y = range_y * (-1);
    if(range_y + range_x == TODO_CATAPULT_RANGE)
        return true;
    else
        return false;
}

TodoCatapult::~TodoCatapult() {
    
}
