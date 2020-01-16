/*
 * IceTower.h
 */

#ifndef TODOICETOWER_H_
#define TODOICETOWER_H_

#include "Tower.h"

class TodoIceTower : public Tower {
public:
    TodoIceTower(int, int, int);
    TodoIceTower(int, int);
    virtual ~TodoIceTower();
    
    virtual bool isInRange(int x, int y) const;
    
    virtual void fire(Enemy&);
    
    virtual void upgrade();
    
    virtual char getSymbol() const { return 'I'; }
    virtual string getName() const { return "IceTower"; }
};

#endif /* TODOICETOWER_H_ */

