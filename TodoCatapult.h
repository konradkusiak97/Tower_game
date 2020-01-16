/*
 * Catapult.h
 */

#ifndef TODOCATAPULT_H_
#define TODOCATAPULT_H_

#include "Tower.h"

class TodoCatapult : public Tower {
public:
    TodoCatapult(int, int, int);
    TodoCatapult(int, int);
    virtual ~TodoCatapult();
    
    virtual bool isInRange(int x, int y) const;
    virtual char getSymbol() const { return 'C'; }
    virtual string getName() const { return "CatapultTower"; }
    
};

#endif /* TODOCATAPULT_H_ */

