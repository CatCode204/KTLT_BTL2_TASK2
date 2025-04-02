#ifndef UNIT_H
#define UNIT_H

#include "Position.h"

class Unit {
protected:
    int _quantity, _weight;
    Position _pos;

public:
    Unit(int quantity, int weight, Position pos);
    virtual ~Unit() = default;
    virtual int getAttackScore() = 0;
    Position getCurrentPosition() const;
    virtual string str() const = 0;
};

#endif // UNIT_H
