#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

#include "../Basic/SpellCaster.hpp"
#include "../State/SoldierState.hpp"
#include "Demon.hpp"

class Warlock : public SpellCaster {
    private:
        int demonCost;
        WarriorID warrior;
        MagicianID magician;
    public:
        Warlock(const std::string& name,  int hp, int mana, int dmg);
        ~Warlock();
        
        Demon* demon;

        WarriorID getWarriorID() const;
        void setWarriorID(WarriorID newID);
        MagicianID getMagicianID() const;
        
        void summonDemon();
        void returnDemon();
};

#endif //WARLOCK_HPP
