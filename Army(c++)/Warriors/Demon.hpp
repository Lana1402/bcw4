#ifndef DEMON_HPP
#define DEMON_HPP

#include <iostream>

#include "Soldier.hpp"

class Demon : public Soldier {
    private:
        WarriorID warrior;
    public:
        Demon(std::string name = "Demon", int hp = 150, int dmg = 50);
        ~Demon();
        
        WarriorID getWarriorID() const;
};

#endif //DEMON_HPP
