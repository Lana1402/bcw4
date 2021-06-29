#include "WereWolfState.hpp"
#include "WolfState.hpp"
#include "../Basic/Unit.hpp"

WereWolfState::WereWolfState(Unit* thisUnit) : thisUnit(thisUnit) {}

void WereWolfState::changeUnit(Unit* enemy) {
    this->thisUnit->getHealth().ensureIsAlive();
    enemy->getHealth().ensureIsAlive();
    
    if ( enemy->getWarriorID() == VAMPIRE || enemy->getWarriorID() == WEREWOLF || enemy->getWarriorID() == WOLF || enemy->getWarriorID() == DEMON ) {
        return;
    }
    
    enemy->transitionTo(new WereWolfState(enemy));
    
    enemy->setWarriorID(WarriorID::WEREWOLF);
    enemy->getHealth().setDamage(this->thisUnit->getHealth().getDamage());
    enemy->getHealth().setHitPoints(this->thisUnit->getHealth().getHitPointsLimit());
    enemy->getHealth().setHitPointsLimit(this->thisUnit->getHealth().getHitPointsLimit());
}

void WereWolfState::transformTo() {
    this->thisUnit->getHealth().ensureIsAlive();
    
    this->thisUnit->transitionTo(new WolfState(this->thisUnit));
    
    this->thisUnit->setWarriorID(WarriorID::WOLF);
    this->thisUnit->getHealth().setDamage(this->thisUnit->getHealth().getDamage()*1.5);
    this->thisUnit->getHealth().setHitPoints(this->thisUnit->getHealth().getHitPoints()*2);
    this->thisUnit->getHealth().setHitPointsLimit(this->thisUnit->getHealth().getHitPointsLimit()*2);
}
