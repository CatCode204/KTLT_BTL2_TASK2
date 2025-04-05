#ifndef _H_UNITLIST_H_
#define _H_UNITLIST_H_

#include "Infantry.h"
#include "Vehicle.h"

class UnitList {
private:
    struct UnitNode {
        Unit* unit = nullptr;
        UnitNode* next = nullptr;
    };
    UnitNode* _head = nullptr;
    int _capacity = 0,_countVehicle = 0,_countInfantry = 0;

public:
    UnitList(int capacity);
    bool insert(Unit *unit);
    bool isContain(VehicleType vehicleType);
    bool isContain(InfantryType infantryType);
    string str() const;

    void Remove(Unit* unit);
};

#endif
