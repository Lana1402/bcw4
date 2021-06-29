#ifndef WEREWOLF_HPP
#define WEREWOLF_HPP

#include <iostream>

#include "../Basic/Unit.hpp"
#include "../State/WereWolfState.hpp"

class WereWolf : public Unit {
    private:
        WarriorID warrior;
    public:
        WereWolf(const std::string& name, int hp, int dmg);
        ~WereWolf();
        
        WarriorID getWarriorID() const;
        void setWarriorID(WarriorID newID);
};

#endif //WEREWOLF_HPP
