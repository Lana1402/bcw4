#include "WereWolf.hpp"

WereWolf::WereWolf(const std::string& name, int hp, int dmg) 
    : Unit(name, hp, dmg, new WereWolfState(this))
    , warrior(WarriorID::WEREWOLF) {}

WereWolf::~WereWolf() {}

WarriorID WereWolf::getWarriorID() const {
    return this->warrior;
}

void WereWolf::setWarriorID(WarriorID newID) {
    this->warrior = newID;
}
