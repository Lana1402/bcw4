#include "Rogue.hpp"

Rogue::Rogue(const std::string& name, int hp, int dmg) 
    : Unit(name, hp, dmg, new SoldierState(this))
    , warrior(WarriorID::ROGUE) {}

Rogue::~Rogue() {}

WarriorID Rogue::getWarriorID() const {
    return this->warrior;
}

void Rogue::setWarriorID(WarriorID newID) {
    this->warrior = newID;
}
