#include "Infantry.h"

constexpr int FIGHTING_YEAR = 1975;

bool isPerfectSquare(int n) {
    int sqrtN = sqrt(n);
    return sqrtN * sqrtN == n;
}

int sumDigits(int n) {
    return n ? sumDigits(n / 10) + n % 10 : 0;
}

int computeSingleDigit(int score, int year) {
    int sum = sumDigits(score) + sumDigits(year);
    while (sum / 10 != 0) sum = sumDigits(sum);
    return sum;
}

//!----------------------------------------------
//! Lớp Infantry
//!----------------------------------------------
Infantry::Infantry(int quantity, int weight, Position pos, InfantryType infantryType): Unit(quantity, weight, pos), _type(infantryType) {}

int Infantry::_CalculateBaseScore() const {
    int score = this->_type * 56 + this->_quantity * this->_weight;
    if (this->_type == InfantryType::SPECIALFORCES && isPerfectSquare(this->_weight))
        score += 75;
}

int Infantry::getAttackScore() {
    int score = this->_CalculateBaseScore();
    if (computeSingleDigit(score,FIGHTING_YEAR) > 7)
        this->_quantity = ceil(this->_quantity * 1.2f);
    else if (computeSingleDigit(score,FIGHTING_YEAR) < 3)
        this->_quantity = ceil(this->_quantity * 0.9f);
    return this->_CalculateBaseScore();
}

std::string InfantryEnumToStr(InfantryType type) {
    if (type == InfantryType::ANTIAIRCRAFTSQUAD)
        return "ANTIAIRCRAFTSQUAD";
    if (type == InfantryType::ENGINEER)
        return "ENGINEER";
    if (type == InfantryType::MORTARSQUAD)
        return "MOTARSQUAD";
    if (type == InfantryType::REGULARINFANTRY)
        return "REGULARINFANTRY";
    if (type == InfantryType::SNIPER)
        return "SNIPER";
    if (type == InfantryType::SPECIALFORCES)
        return "SPECIALFORCES";
}

string Infantry::str() const {
    std::stringstream out;
    out << "Infantry["
        << "infantryType=" << InfantryEnumToStr(this->_type) << ","
        << "quantity=" << this->_quantity << ","
        << "weight=" << this->_weight << ","
        << "pos=" << this->_pos.str() << "]";
    return out.str();
}