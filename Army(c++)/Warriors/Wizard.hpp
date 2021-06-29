#ifndef WIZARD_HPP
#define WIZARD_HPP

#include <iostream>

#include "../Basic/SpellCaster.hpp"
#include "../State/SoldierState.hpp"

class Wizard : public SpellCaster {
    private:
        WarriorID warrior;
        MagicianID magician;
    public:
        Wizard(const std::string& name,  int hp, int mana, int dmg);
        ~Wizard();
        
        WarriorID getWarriorID() const;
        void setWarriorID(WarriorID newID);
        MagicianID getMagicianID() const;
};

#endif //WIZARD_HPP
