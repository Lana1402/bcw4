#include "VampireState.hpp"
#include "../Basic/Unit.hpp"

VampireState::VampireState(Unit* thisUnit) : thisUnit(thisUnit) {}

void VampireState::changeUnit(Unit* enemy) {
    this->thisUnit->getHealth().ensureIsAlive();
    enemy->getHealth().ensureIsAlive();
    
    if ( enemy->getWarriorID() == VAMPIRE || enemy->getWarriorID() == WEREWOLF || enemy->getWarriorID() == WOLF || enemy->getWarriorID() == DEMON ) {
        return;
    }
    
    enemy->transitionTo(new VampireState(enemy));
    
    enemy->setWarriorID(WarriorID::VAMPIRE);
    enemy->getHealth().setDamage(this->thisUnit->getHealth().getDamage());
    enemy->getHealth().setHitPoints(this->thisUnit->getHealth().getHitPointsLimit());
    enemy->getHealth().setHitPointsLimit(this->thisUnit->getHealth().getHitPointsLimit());
}

void VampireState::transformTo() {
    std::cout << "No ability!!!"  << std::endl;
}
