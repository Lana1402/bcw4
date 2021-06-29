#ifndef SPELL_HPP
#define SPELL_HPP

#include <iostream>

#include "../Basic/SpellCaster.hpp"
#include "../State/State.hpp"
#include "../State/SoldierState.hpp"

class Spell {
    protected:
        int manaCost;
        int mana;
        int hitPoints;
    public:
        Spell(int cost, int mana, int hp);
        ~Spell();
        
        virtual void mAttack(Unit* enemy, SpellCaster* magician);
        virtual void healHealth(Unit* other, SpellCaster* magician);
        virtual void healMagic(SpellCaster* other, SpellCaster* magician);
        virtual void backToHuman(Unit* other, SpellCaster* magician);
};

#endif //SPELL_HPP
