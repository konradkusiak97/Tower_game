/*
 * IceTower.cpp
 */

#include "TodoIceTower.h"
#include "Enemy.h"

const int TODO_ICE_TOWER_COST = 3;
const int TODO_ICE_TOWER_UPGRADE_COST = 0;
const int TODO_ICE_TOWER_POWER = 0;

TodoIceTower::TodoIceTower(int cost, int upgrade_cost, int power) : Tower(cost, upgrade_cost, power) {
    
}

TodoIceTower::TodoIceTower(int x, int y) : Tower(TODO_ICE_TOWER_COST, TODO_ICE_TOWER_UPGRADE_COST, TODO_ICE_TOWER_POWER) {
    
    setXY(x, y);
}

TodoIceTower::~TodoIceTower() {
    
}

bool TodoIceTower::isInRange(int x, int y) const {
    int ax, ay;
    getXY(ax, ay);
    if (x >= ax)
        return true;
    else
        return false;
}

void TodoIceTower::fire(Enemy& enemy) {
    int x, y;
    enemy.getXY(x, y);
    if (isInRange(x, y) && enemy.getHP() > 0){
        enemy.setState(ObjectState::FROZEN);
    }
}

void TodoIceTower::upgrade() {
    return;
}
