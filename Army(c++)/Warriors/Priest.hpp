#ifndef PRIEST_HPP
#define PRIEST_HPP

#include <iostream>
#include "../Basic/SpellCaster.hpp"
#include "../State/SoldierState.hpp"

class  Priest : public virtual SpellCaster {
    private:
        WarriorID warrior;
        MagicianID magician;
    public:
         Priest(const std::string& name,  int hp, int mana, int dmg);
        ~Priest();
        
        WarriorID getWarriorID() const;
        void setWarriorID(WarriorID newID);
        MagicianID getMagicianID() const;
};

#endif //PRIEST_HPP
