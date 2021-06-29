#include "SpellCaster.hpp"
#include "../Magic/SpellBook.hpp"

SpellCaster::SpellCaster(const std::string& name,  int hp, int mana, int dmg, State* state) 
    : Unit(name, hp, dmg, state), magic(new MagicPower(mana))
    , book(new SpellBook()) {}

SpellCaster::~SpellCaster(){
    delete this->magic;
    delete this->book;
}

MagicPower& SpellCaster::getMagicPower() const {
    return *(this->magic);
}

SpellBook& SpellCaster::getSpellBook() const {
    return *(this->book);
}

void SpellCaster::magicAttack(Unit* enemy, SpellID spell) {
    if ( spell == FREEZE || spell == HELLFIRE || spell == LIGHTNING || spell == ACIDMIST ) { 
        this->book->getSpellBook().find(spell)->second->mAttack(enemy, this);
    }
}

void SpellCaster::healHealth(Unit* other, SpellID spell) {
    if ( spell == HEAL ) {
        this->book->getSpellBook().find(spell)->second->healHealth(other, this);
    } else if ( spell == HUMAN ) {
        this->book->getSpellBook().find(spell)->second->backToHuman(other, this);
    } else {
        return;
    }
}

void SpellCaster::healMagic(SpellCaster* other) {
    this->book->getSpellBook().find(RETURN_MAGIC)->second->healMagic(other, this);
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster) {
    out << spellCaster.getName() << " - " << typeid(spellCaster.getState()).name() << std::endl;
    out << spellCaster.getMagicPower() << std::endl;
    out << spellCaster.getHealth() << std::endl;
    
    return out;
}
