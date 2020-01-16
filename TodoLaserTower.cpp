/*
 * Laser.cpp
 */

#include "TodoLaserTower.h"


const int LASER_COST = 3;
const int LASER_UPGRADE_COST = 2;
const int LASER_POWER = 10;


TodoLaserTower::TodoLaserTower(int x, int y) : Tower(LASER_COST, LASER_UPGRADE_COST, LASER_POWER) {
    
    setXY(x,y);
}
TodoLaserTower::TodoLaserTower(int cost, int upgrade_cost, int power) : Tower(cost, upgrade_cost, power) {
    
}

TodoLaserTower::~TodoLaserTower(){
    
}

bool TodoLaserTower::isInRange(int x, int y) const {
    int ax, ay;
    getXY(ax, ay);
    if (x == ax || y == ay)
        return true;
    else
        return false;
}

