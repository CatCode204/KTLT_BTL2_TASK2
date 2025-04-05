#include "Unit.h"

Unit::Unit(int quantity, int weight, Position pos): _quantity(quantity), _weight(weight), _pos(pos) {}

Position Unit::getCurrentPosition() const {
    return _pos;
}

const int& Unit::GetWeight() {
    return this->_weight;
}

const int& Unit::GetQuantity() {
    return this->_quantity;
}

const Position& Unit::GetPosition() {
    return this->_pos;
}

void Unit::SetPos(const Position& pos) {
    this->_pos = pos;
}

void Unit::SetQuantity(const int& quantity) {
    this->_quantity = quantity;
}

void Unit::SetWeight(const int& weight) {
    this->_weight = weight;
}