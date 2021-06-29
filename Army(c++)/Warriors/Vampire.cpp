#include "Vampire.hpp"

Vampire::Vampire(const std::string& name, int hp, int dmg) 
    : Unit(name, hp, dmg, new VampireState(this))
    , warrior(WarriorID::VAMPIRE) {}

Vampire::~Vampire() {}

WarriorID Vampire::getWarriorID() const {
    return this->warrior;
}

void Vampire::setWarriorID(WarriorID newID) {
    this->warrior = newID;
}
