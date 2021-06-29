#include "Wizard.hpp"
#include "../State/State.hpp"

Wizard::Wizard(const std::string& name,  int hp, int mana, int dmg) 
    : SpellCaster(name, hp, mana, dmg, new SoldierState(this))
    , warrior(WarriorID::WIZARD), magician(MagicianID::SORCERER) {}

Wizard::~Wizard() {}

WarriorID Wizard::getWarriorID() const {
    return this->warrior;
}

void Wizard::setWarriorID(WarriorID newID) {
    this->warrior = newID;
}

MagicianID Wizard::getMagicianID() const {
    return this->magician;
}
