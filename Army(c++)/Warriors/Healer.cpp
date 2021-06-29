#include "Healer.hpp"
#include "../State/State.hpp"

Healer::Healer(const std::string& name,  int hp, int mana, int dmg) 
    : SpellCaster(name, hp, mana, dmg, new SoldierState(this))
    , warrior(WarriorID::HEALER), magician(MagicianID::HEALING) {}

Healer::~Healer() {}

WarriorID Healer::getWarriorID() const {
    return this->warrior;
}

void Healer::setWarriorID(WarriorID newID) {
    this->warrior = newID;
}

MagicianID Healer::getMagicianID() const {
	return this->magician;
}
