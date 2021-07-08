#include "Attack.hpp"
#include "Unit.hpp"

Attack::Attack(Unit* thisUnit) : thisUnit(thisUnit) {}

void Attack::attack(Unit* enemy) {
    thisUnit->getHealth().ensureIsAlive();

    if ( this->thisUnit->getWarriorID() == VAMPIRE ) {
        enemy->getHealth().takeDamage(this->thisUnit->getHealth().getDamage());
        enemy->counterAttack(this->thisUnit);
        
        this->thisUnit->getHealth().addHitPoints(enemy->getHealth().getHitPoints()/5);
        std::cout << "Vampire Attack!!!" << std::endl;
    } else if ( this->thisUnit->getWarriorID() == ROGUE ) {
        enemy->getHealth().takeDamage(this->thisUnit->getHealth().getDamage());
        std::cout << "Rouge Attack!!!" << std::endl;
    } else {
        enemy->getHealth().takeDamage(this->thisUnit->getHealth().getDamage());
        enemy->counterAttack(this->thisUnit);
        std::cout << "Soldier Attack!!!" << std::endl;
    }
    
    enemy->notify();
}

void Attack::counterAttack(Unit* enemy) {
    if ( thisUnit->getHealth().getHitPoints() == 0 ) {
        return;
    }

    if ( this->thisUnit->getWarriorID() == VAMPIRE ) {
        enemy->getHealth().takeDamage(this->thisUnit->getHealth().getDamage()/2);
        
        this->thisUnit->getHealth().addHitPoints(enemy->getHealth().getHitPoints()/5);
    } else {
        enemy->getHealth().takeDamage(this->thisUnit->getHealth().getDamage()/2);
    }
    enemy->notify();
}
