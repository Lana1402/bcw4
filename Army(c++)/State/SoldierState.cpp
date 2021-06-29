#include "SoldierState.hpp"
#include "../Basic/Unit.hpp"

SoldierState::SoldierState(Unit* thisUnit) : thisUnit(thisUnit) {}

void SoldierState::changeUnit(Unit* enemy) {
    std::cout << "No ability!!!"  << std::endl;
}

void SoldierState::transformTo() {
    std::cout << "No ability!!!"  << std::endl;
}
