#include "Necromancer.hpp"
#include "../State/State.hpp"
#include "../Magic/SpellBook.hpp"

Necromancer::Necromancer(const std::string& name,  int hp, int mana, int dmg) 
    : SpellCaster(name, hp, mana, dmg, new SoldierState(this))
    , warrior(WarriorID::NECROMANCER), magician(MagicianID::SORCERER) {}

Necromancer::~Necromancer() {}

WarriorID Necromancer::getWarriorID() const {
    return this->warrior;
}

void Necromancer::setWarriorID(WarriorID newID) {
    this->warrior = newID;
}

MagicianID Necromancer::getMagicianID() const {
    return this->magician;
}

void Necromancer::update(Unit* enemy) {
    if ( enemy->getHealth().getHitPoints() == 0 ) {
        this->getHealth().addHitPoints(enemy->getHealth().getHitPointsLimit()/5);
        enemy->detach();
    }
}

void Necromancer::attack(Unit* enemy) {
    this->getAttack().attack(enemy);
    enemy->attach(this);
}

void Necromancer::counterAttack(Unit* enemy) {
    this->getAttack().counterAttack(enemy);
    enemy->attach(this);
}

void Necromancer::magicAttack(Unit* enemy, SpellID spell) {
    if ( spell == FREEZE || spell == HELLFIRE || spell == LIGHTNING || spell == ACIDMIST ) { 
        this->book->getSpellBook().find(spell)->second->mAttack(enemy, this);
    }
    enemy->attach(this);
}
