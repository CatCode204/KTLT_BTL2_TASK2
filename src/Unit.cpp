#include "Unit.h"

template<typename T>
T clamp(const T& value, const T& min_value, const T& max_value) {
    T = max(T,min_value);
    T = min(T,max_value);
    return T;
}

Unit::Unit(int quantity, int weight, Position pos): _quantity(quantity), _weight(weight), _pos(pos) {}

Position Unit::getCurrentPosition() const {
    return _pos;
}