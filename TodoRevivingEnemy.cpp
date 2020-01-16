/*
 * RevivingEnemy.cpp
 *
 *  Created on: Mar 15, 2019
 *      Author: kevinw
 */

#include "TodoRevivingEnemy.h"

TodoRevivingEnemy::TodoRevivingEnemy(int hp, int x, int y) : Enemy(hp, x, y), reviveCount(0){
    
}

char TodoRevivingEnemy::getSymbol() const {
    return 'R';
}

std::string TodoRevivingEnemy::getName() const {
    return "RevivingEnemy";
}

void TodoRevivingEnemy::move(){
    
    if (reviveCount == 0)
        if (getState() == ObjectState::DEAD)
        {
            setState(ObjectState::NORMAL);
            reviveCount = 1;
            hp = 1;
        }
    Enemy::move();
    
}

TodoRevivingEnemy::~TodoRevivingEnemy(){
    
}
