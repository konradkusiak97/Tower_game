#include <iostream>
#include "Arena.h"
#include "TodoSimpleTower.h"
#include "TodoLaserTower.h"
#include "TodoIceTower.h"
#include "TodoCatapult.h"
#include "TodoDiagonalEnemy.h"
#include "TodoRevivingEnemy.h"
#include "definition.h"
using namespace std;

void test1() {
    Arena a;
    a.addBuilding(SIMPLE_TOWER, 1, 1);
    a.addBuilding(ICE_TOWER, 1, 2);
    a.addBuilding(CATAPULT_TOWER, 1, 3);
    a.addBuilding(LASER_TOWER, 1, 4);
    int tmp; const Object** o;
    a.getConstObjects(o, tmp);
    a.getObjectAt(1,1);
    delete []o;
}

void test2() {
    TodoSimpleTower t1(4, 3);
    TodoIceTower t2(2,3);
    TodoCatapult t3(0,1);
    TodoLaserTower t4(6,3);

    t1.isInRange(3,3);
    t2.isInRange(3,3);
    t3.isInRange(3,3);
    t4.isInRange(3,3);

    Enemy e(100, 3, 3);

    t1.fire(e);
    t2.fire(e);
    t3.fire(e);
    t4.fire(e);
}

void test3() {
    Enemy e1(100, 1, 1);
    TodoDiagonalEnemy e2(100, 2, 2);
    TodoRevivingEnemy e3(100, 3, 3);

    e1.move();
    e2.move();
    e3.move();

}

void test4() {
    Arena a;

    for (int i = 0; i < 10; i++)
    a.nextRound();
}

int main() {
    test1();
    test2();
    test3();
    test4();
}
