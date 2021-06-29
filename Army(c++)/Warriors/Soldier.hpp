#ifndef SOLDIER_HPP
#define SOLDIER_HPP

#include <iostream>
#include "../Basic/Unit.hpp"
#include "../State/SoldierState.hpp"

class Soldier : public Unit {
    private:
        WarriorID warrior;
    public:
        Soldier(const std::string& name, int hp, int dmg);
        ~Soldier();
        
        WarriorID getWarriorID() const;
        void setWarriorID(WarriorID newID);
};

#endif //SOLDIER_HPP
