#include "Unit.h"

template<typename T>
T clamp(const T& value, const T& min_value, const T& max_value) {
    T = max(T,min_value);
    T = min(T,max_value);
    return T;
}

Unit::Unit(int quantity, int weight, Position pos)
    : quantity(quantity), weight(weight), pos(pos) {

}

Unit::~Unit() {
}

Position Unit::getCurrentPosition() const {
}