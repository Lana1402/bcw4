#include "Soldier.hpp"

Soldier::Soldier(const std::string& name, int hp, int dmg) 
    : Unit(name, hp, dmg, new SoldierState(this))
    , warrior(WarriorID::SOLDIER) {}

Soldier::~Soldier() {}

WarriorID Soldier::getWarriorID() const {
    return this->warrior;
}

void Soldier::setWarriorID(WarriorID newID) {
    this->warrior = newID;
}
