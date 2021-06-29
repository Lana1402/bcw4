#include "Warlock.hpp"
#include "../State/State.hpp"

Warlock::Warlock(const std::string& name,  int hp, int mana, int dmg) 
    : SpellCaster(name, hp, mana, dmg, new SoldierState(this)), demonCost(40)
    , warrior(WarriorID::WARLOCK), magician(MagicianID::SORCERER) {}

Warlock::~Warlock() {}

WarriorID Warlock::getWarriorID() const {
    return this->warrior;
}

void Warlock::setWarriorID(WarriorID newID) {
    this->warrior = newID;
}

MagicianID Warlock::getMagicianID() const {
    return this->magician;
}

void Warlock::summonDemon() {
    this->getMagicPower().ensureHaveIsMana();
    this->returnDemon();
    
    if ( this->getMagicPower().getMana() < this->demonCost ) {
        std::cout << "Not enough mana!" << std::endl;
        return;
    }
    this->demon = new Demon();
        
    this->getMagicPower().takeMana(this->demonCost);
}

void Warlock::returnDemon() {
    if ( this->demon != nullptr ) {
        delete this->demon;
    }
}
