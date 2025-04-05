#include "Vehicle.h"

Vehicle::Vehicle(int quantity, int weight, Position pos, VehicleType vehicleType): Unit(quantity, weight, pos), _type(vehicleType) {}

int Vehicle::getAttackScore() {
    return std::ceil((_type * 304 + this->_quantity * this->_weight) / 30.f);
}

std::string VehicleEnumToString(VehicleType type) {
    if (type == VehicleType::ANTIAIRCRAFT)
        return "ANTIAIRCRAFT";
    if (type == VehicleType::APC)
        return "APC";
    if (type == VehicleType::ARMOREDCAR)
        return "AMOREDCAR";
    if (type == VehicleType::ARTILLERY)
        return "ARTILLERY";
    if (type == VehicleType::MORTAR)
        return "MORTAR";
    if (type == VehicleType::TANK)
        return "TANK";
    return "TRUCK";
}

string Vehicle::str() const {
    std::stringstream out;
    out << "Vehicle[" 
        << "vehicleType=" << VehicleEnumToString(_type) << ","
        << "quantity=" << this->_quantity << ","
        << "weight=" << this->_weight << ","
        << "pos=" << this->_pos.str() << "]";
    return out.str();
}

VehicleType Vehicle::GetType() const {
    return this->_type;
}