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

    const int& GetQuantity(); //Read only
    const int& GetWeight(); //Read only
    const Position& GetPosition(); //Read only

    void SetQuantity(const int& quantity);
    void SetWeight(const int& weight);
    void SetPos(const Position& pos);
};

#endif // UNIT_H
