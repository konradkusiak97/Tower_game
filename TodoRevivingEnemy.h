/*
 * RevivingEnemy.h
 */

#ifndef TODOREVIVINGENEMY_H_
#define TODOREVIVINGENEMY_H_

#include "Enemy.h"

class TodoRevivingEnemy : public Enemy {
public:
    TodoRevivingEnemy(int, int, int);
    virtual ~TodoRevivingEnemy();
    
    char getSymbol() const override;
    
    std::string getName() const override;
    
    virtual void move() override;
private:
    int reviveCount;
};

#endif /* TODOREVIVINGENEMY_H_ */

