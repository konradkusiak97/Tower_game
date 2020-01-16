/*
 * Laser.h
 */

#ifndef TODOLASERTOWER_H_
#define TODOLASERTOWER_H_

#include "Tower.h"

class TodoLaserTower : public Tower {
public:
    TodoLaserTower(int, int, int);
    TodoLaserTower(int, int);
    virtual ~TodoLaserTower();
    
    virtual bool isInRange(int x, int y) const;
    virtual char getSymbol() const { return 'L'; }
    virtual string getName() const { return "LaserTower"; }
};

#endif /* TODOLASERTOWER_H_ */

