/*
 * LazyTower.h
 *
 *  Created on: Mar 11, 2019
 *      Author: kevinw
 */

#ifndef TODOSIMPLETOWER_H_
#define TODOSIMPLETOWER_H_

#include "Tower.h"

class TodoSimpleTower : public Tower {
public:
    TodoSimpleTower(int, int);
    TodoSimpleTower(int, int, int);
    virtual ~TodoSimpleTower();
    
    virtual bool isInRange(int x, int y) const override;
    virtual char getSymbol() const override{ return 'S'; }
    virtual string getName() const override{ return "SimpleTower"; }
    
};
#endif /* TODOSIMPLETOWER_H_ */

