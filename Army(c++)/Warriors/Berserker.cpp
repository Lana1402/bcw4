#include "Berserker.hpp"

Berserker::Berserker(const std::string& name, int hp, int dmg) 
    : Unit(name, hp, dmg, new SoldierState(this))
    , warrior(WarriorID::BERSERKER) {}

Berserker::~Berserker() {}

WarriorID Berserker::getWarriorID() const {
    return this->warrior;
}

void Berserker::setWarriorID(WarriorID newID) {
    this->warrior = newID;
}
