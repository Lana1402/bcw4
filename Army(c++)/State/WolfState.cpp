#include "WolfState.hpp"
#include "WereWolfState.hpp"
#include "../Basic/Unit.hpp"

WolfState::WolfState(Unit* thisUnit) : thisUnit(thisUnit) {}

void WolfState::changeUnit(Unit* enemy) {
    std::cout << "No ability!!!"  << std::endl;
}

void WolfState::transformTo() {
    this->thisUnit->getHealth().ensureIsAlive();
    
    this->thisUnit->transitionTo(new WereWolfState(this->thisUnit));
    
    this->thisUnit->setWarriorID(WarriorID::WEREWOLF);
    this->thisUnit->getHealth().setDamage(this->thisUnit->getHealth().getDamage()/1.5);
    this->thisUnit->getHealth().setHitPoints(this->thisUnit->getHealth().getHitPoints()/2);
    this->thisUnit->getHealth().setHitPointsLimit(this->thisUnit->getHealth().getHitPointsLimit()/2);
}
