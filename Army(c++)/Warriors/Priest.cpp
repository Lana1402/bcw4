#include "Priest.hpp"
#include "../State/State.hpp"

Priest::Priest(const std::string& name,  int hp, int mana, int dmg) 
    : SpellCaster(name, hp, mana, dmg, new SoldierState(this))
    , warrior(WarriorID::PRIEST), magician(MagicianID::CHURCH_WORKER) {}

Priest::~Priest() {}

WarriorID Priest::getWarriorID() const {
    return this->warrior;
}

void Priest::setWarriorID(WarriorID newID) {
    this->warrior = newID;
}

MagicianID Priest::getMagicianID() const {
    return this->magician;
}
