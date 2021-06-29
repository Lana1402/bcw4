#include "MagicPower.hpp"

MagicPower::MagicPower(int mana) : mana(mana), manaLimit(mana) {}

MagicPower::~MagicPower() {}

void MagicPower::ensureHaveIsMana() {
    if ( this->mana == 0 ) {
       throw MagicManaOff();
   }
}

int MagicPower::getMana() const {
    return this->mana;
}

int MagicPower::getManaLimit() const {
    return this->manaLimit;
}

void MagicPower::addMana(int mana) {
    this->ensureHaveIsMana();
    
    if ( mana <= (this->manaLimit - this->mana) ) {
        this->mana += mana;
    } else {
        this->mana = this->manaLimit;
    }
}

void MagicPower::takeMana(int cost) {
    this->ensureHaveIsMana();
    
    this->mana -= cost;
    
    if ( this->mana < 0 ) {
        this->mana = 0;
    }
}

std::ostream& operator<<(std::ostream& out, const MagicPower& magic) {
    out << "Mana " << magic.getMana() << std::endl;
    out << "Mana Limit " << magic.getManaLimit() << std::endl;
    
    return out;
}
