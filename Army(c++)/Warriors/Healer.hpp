#ifndef HEALER_HPP
#define HEALER_HPP

#include <iostream>

#include "../Basic/SpellCaster.hpp"
#include "../State/SoldierState.hpp"

class Healer : public SpellCaster {
    private:
        WarriorID warrior;
        MagicianID magician;
    public:
        Healer(const std::string& name,  int hp, int mana, int dmg);
        ~Healer();
        
        WarriorID getWarriorID() const;
        void setWarriorID(WarriorID newID);
        MagicianID getMagicianID() const;
};

#endif //HEALER_HPP
