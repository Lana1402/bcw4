#ifndef NECROMANCER_HPP
#define NECROMANCER_HPP

#include <iostream>

#include "../Basic/IObserver.hpp"
#include "../Basic/SpellCaster.hpp"
#include "../State/SoldierState.hpp"

class Necromancer : public SpellCaster, IObserver {
    private:
        WarriorID warrior;
        MagicianID magician;
    public:
        Necromancer(const std::string& name,  int hp, int mana, int dmg);
        ~Necromancer();
        
        WarriorID getWarriorID() const;
        void setWarriorID(WarriorID newID);
        MagicianID getMagicianID() const;
        
        void update(Unit* enemy);

        void attack(Unit* enemy);
        void counterAttack(Unit* enemy);
        
        void magicAttack(Unit* enemy, SpellID spell);
};

#endif //NECROMANCER_HPP