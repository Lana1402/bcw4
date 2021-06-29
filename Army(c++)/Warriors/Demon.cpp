#include "Demon.hpp"

Demon::Demon(std::string name, int hp, int dmg) 
    : Soldier(name, hp, dmg), warrior(WarriorID::DEMON) {}

Demon::~Demon(){}

WarriorID Demon::getWarriorID() const {
    return this->warrior;
}
