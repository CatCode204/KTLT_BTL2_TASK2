#ifndef VEHICLE_H
#define VEHICLE_H

#include "Unit.h"

enum VehicleType
{
    TRUCK,
    MORTAR,
    ANTIAIRCRAFT,
    ARMOREDCAR,
    APC,
    ARTILLERY,
    TANK
};

class Vehicle : public Unit {
private:
    VehicleType _type;
public:
    Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType);
    int getAttackScore() override;
    string str() const override;
};

#endif // VEHICLE_H
