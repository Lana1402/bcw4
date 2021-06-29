#ifndef SPELL_BOOK_HPP
#define SPELL_BOOK_HPP

#include <map>
#include "Spell.hpp"

class SpellBook {
    protected:
        std::map<SpellID, Spell*>spellBook;
    public:
        SpellBook();
        ~SpellBook();
        
        std::map<SpellID, Spell*> getSpellBook() const;
};

#endif //SPELL_BOOK_HPP
