#ifndef MAGIC_POWER_HPP
#define MAGIC_POWER_HPP

#include <iostream>
#include "Exception.hpp"

class MagicPower {
    protected:
        int mana;
        int manaLimit;
    public:
        MagicPower(int mana);
        virtual ~MagicPower();
        
        void ensureHaveIsMana();
        int getMana() const;
        int getManaLimit() const;
        
        virtual void addMana(int mana);
        virtual void takeMana(int cost);
};

std::ostream& operator<<(std::ostream& out, const MagicPower& healthSC);

#endif //MAGIC_POWER_HPP
