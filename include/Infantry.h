#ifndef INFANTRY_H
#define INFANTRY_H

#include "Unit.h"

enum InfantryType
{
    SNIPER,
    ANTIAIRCRAFTSQUAD,
    MORTARSQUAD,
    ENGINEER,
    SPECIALFORCES,
    REGULARINFANTRY
};

class Infantry : public Unit {
private:
    InfantryType _type;  // * Thể loại bộ binh

public:
    Infantry(int quantity, int weight, Position pos, InfantryType infantryType);
    int getAttackScore() override;
    string str() const override;

    InfantryType GetType() const;

private:
    int _CalculateBaseScore() const;
};

#endif // INFANTRY_H