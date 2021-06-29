#ifndef ATTACK_HPP
#define ATTACK_HPP

#include <iostream>

class Unit;

class Attack {
    protected: 
        Unit* thisUnit;
    public:
        Attack(Unit* thisUnit);
        virtual ~Attack() = default;
        
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif //ATTACK_HPP
