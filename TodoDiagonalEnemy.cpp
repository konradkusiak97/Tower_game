/*
 * DiagonalEnemy.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: kevinw
 */

#include "TodoDiagonalEnemy.h"

TodoDiagonalEnemy::TodoDiagonalEnemy(int hp, int x, int y) : Enemy(hp, x, y) {
    
}
char TodoDiagonalEnemy::getSymbol() const {
    
    return 'D';
}

std::string TodoDiagonalEnemy::getName() const {
    
    return "DiagonalEnemy";
}

void TodoDiagonalEnemy::move() {
    
    Enemy::move();
    int x, y, mark = 0;
    getXY(x,y);
    
    if (y == 0)
        mark = 1;
    if (y == ARENA_H - 1)
        mark = 0;
    
    if (mark == 0)
        setXY(x, y - 1);
    if (mark == 1)
        setXY(x, y + 1);
}

TodoDiagonalEnemy::~TodoDiagonalEnemy(){
    
}















