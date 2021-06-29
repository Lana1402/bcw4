#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <iostream>
#include "../Basic/Unit.hpp"
#include "../State/VampireState.hpp"

class Vampire : public Unit {
    private:
        WarriorID warrior;
    public:
        Vampire(const std::string& name, int hp, int dmg);
        ~Vampire();
        
        WarriorID getWarriorID() const;
        void setWarriorID(WarriorID newID);
};

#endif //VAMPIRE_HPP
