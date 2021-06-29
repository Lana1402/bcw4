#ifndef SPELL_CASTER_HPP
#define SPELL_CASTER_HPP

#include <iostream>
#include <string>

#include "../ID/MagicianID.hpp"
#include "../ID/SpellID.hpp"
#include "MagicPower.hpp"
#include "Unit.hpp"

class SpellBook;

class SpellCaster : public Unit {
    protected:
        MagicPower* magic;
        SpellBook* book;
    public:
        SpellCaster(const std::string& name, int hp, int mana, int dmg, State* state);
        
        virtual ~SpellCaster();
        
        MagicPower& getMagicPower() const;
        SpellBook& getSpellBook() const;
        
        virtual MagicianID getMagicianID() const = 0;
        
        virtual void magicAttack(Unit* enemy, SpellID spell);
        virtual void healHealth(Unit* other, SpellID spell);
        virtual void healMagic(SpellCaster* other);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster);

#endif // SPELL_CASTER_HPP
