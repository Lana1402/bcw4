#include "SpellBook.hpp"

SpellBook::SpellBook() {
    spellBook.emplace(FREEZE, new Spell(15, 0, 20));
    spellBook.emplace(HELLFIRE, new Spell(30, 0, 55));
    spellBook.emplace(LIGHTNING, new Spell(25, 0, 40));
    spellBook.emplace(ACIDMIST, new Spell(20, 0, 30));
    spellBook.emplace(HUMAN, new Spell(80, 0, 0));
    spellBook.emplace(HEAL, new Spell(20, 0, 60));
    spellBook.emplace(RETURN_MAGIC, new Spell(40, 70, 0));
    
}

SpellBook::~SpellBook() {}

std::map<SpellID, Spell*> SpellBook::getSpellBook() const {
    return this->spellBook;
}
