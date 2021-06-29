#ifndef BERSERKER_HPP
#define BERSERKER_HPP

#include <iostream>

#include "../Basic/Unit.hpp"
#include "../State/SoldierState.hpp"

class Berserker : public Unit {
    private:
        WarriorID warrior;
    public:
        Berserker(const std::string& name, int hp, int dmg);
        ~Berserker();

        WarriorID getWarriorID() const;
        void setWarriorID(WarriorID newID);
};

#endif //BERSERKER_HPP
