#ifndef ROGUE_HPP
#define ROGUE_HPP

#include <iostream>
#include "../Basic/Unit.hpp"
#include "../State/SoldierState.hpp"

class Rogue : public virtual Unit {
    private:
        WarriorID warrior;
    public:
        Rogue(const std::string& name, int hp, int dmg);
        ~Rogue();
        
        WarriorID getWarriorID() const;
        void setWarriorID(WarriorID newID);
};

#endif //ROGUE_HPP
