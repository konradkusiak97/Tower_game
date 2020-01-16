/*
 * DiagonalEnemy.h
 *
 *  Created on: Mar 13, 2019
 *      Author: kevinw
 */

#ifndef TODODIAGONALENEMY_H_
#define TODODIAGONALENEMY_H_

#include "Enemy.h"
extern const int ARENA_H;

class TodoDiagonalEnemy : public Enemy {
public:
    TodoDiagonalEnemy(int, int, int);
    virtual ~TodoDiagonalEnemy();
    
    char getSymbol() const override;
    
    std::string getName() const override;
    
    virtual void move() override;
    
};

#endif /* TODODIAGONALENEMY_H_ */

