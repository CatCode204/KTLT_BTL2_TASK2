#include "Army.h"

constexpr int MIN_LF = 0;
constexpr int MAX_LF = 1000;
constexpr int MIN_EXP = 0;
constexpr int MAX_EXP = 500;

Army::Army(Unit **unitArray, int size, string name) : _name(name) {
    for (int i=0;i < size;++i)
        if (dynamic_cast<Vehicle*>(unitArray[i]) != nullptr)
            this->_LF += unitArray[i]->getAttackScore();
        else
            this->_EXP += unitArray[i]->getAttackScore();

    this->_name = name;

    this->_LF = clamp(this->_LF,MIN_LF,MAX_LF);
    this->_EXP = clamp(this->_EXP,MIN_EXP,MAX_EXP);
}