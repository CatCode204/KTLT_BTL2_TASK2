#include "UnitList.h"

UnitList::UnitList(int capacity): _capacity(capacity) {}

UnitList::~UnitList() {
    UnitNode* node = this->_head;
    while (node) {
        UnitNode* tmp = node;
        node = node->next;
        delete tmp;
    }
}

bool UnitList::insert(Unit *unit) {
    if (unit == nullptr) return false;

    for (UnitNode* node = this->_head; node != nullptr; node = node->next)
        if (node->unit == unit) {
            node->unit->SetQuantity(node->unit->GetQuantity() + unit->GetQuantity());
            return true;
        }
    
    //If not in list
    if (this->_countInfantry + this->_countVehicle + 1 > this->_capacity) return false;

    if (dynamic_cast<Vehicle*>(unit)) {// If unit belong to Vehicle children class
        ++this->_countVehicle;
        if (this->_head == nullptr) {
            this->_head = new UnitNode();
            this->_head->unit = unit;
        } else {
            UnitNode* node = this->_head;
            for (;node->next;node = node->next);
            node->next = new UnitNode();
            node->next->unit = unit;
        }
    } else { //Else unit belong to Infantry children class
        ++this->_countInfantry;
        UnitNode* node = new UnitNode();
        node->unit = unit;
        node->next = this->_head;
        this->_head = node;
    }

    return true;
}

bool UnitList::isContain(VehicleType vehicleType) {
    for (UnitNode* node = this->_head;node != nullptr;node = node->next) {
        Vehicle* vehicle = dynamic_cast<Vehicle*>(node->unit);
        if (vehicle && vehicle->GetType() == vehicleType) return true;
    }

    return false;
}

bool UnitList::isContain(InfantryType infantryType) {
    for (UnitNode* node = this->_head; node != nullptr; node = node->next) {
        Infantry* infantry = dynamic_cast<Infantry*>(node->unit);
        if (infantry && infantry->GetType() == infantryType) return true;
    }
    return false;
}

string UnitList::str() const {
    std::stringstream out;
    out << "UnitList["
        << "count_vehicle=" << this->_countVehicle << ";"
        << "count_infantry=" << this->_countInfantry << ";";
    
    for (UnitNode* node = this->_head;node != nullptr; node = node->next) {
        out << node->unit->str();
        if (node->next) out << ",";
    }

    out << "]";
    return out.str();
}

void UnitList::Remove(Unit* unit) {
    if (this->_head->unit == unit) {
        if (dynamic_cast<Vehicle*>(unit)) 
            --this->_countVehicle;
        else 
            --this->_countInfantry;

        UnitNode* tmp = this->_head;
        this->_head = this->_head->next;
        delete tmp;

    } else {
        for (UnitNode* node = this->_head; node != nullptr; node = node->next)
            if (node->next->unit == unit) {
                if (dynamic_cast<Vehicle *>(unit))
                    --this->_countVehicle;
                else
                    --this->_countInfantry;

                UnitNode* tmp = node->next;
                node->next = tmp->next;
                delete tmp;
            }
    }
}