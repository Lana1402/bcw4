#include "Spell.hpp"

Spell::Spell(int cost, int mana, int hp) : manaCost(cost), mana(mana), hitPoints(hp)  {}

Spell::~Spell() {}

void Spell::mAttack(Unit* enemy, SpellCaster* magician) {
    magician->getHealth().ensureIsAlive();
    magician->getMagicPower().ensureHaveIsMana();
    
    if ( magician->getMagicPower().getMana() < this->manaCost) {
        std::cout << "Not enough mana!" << std::endl;
        return;
    }
    
    if ( enemy->getWarriorID() == BERSERKER ) {
        std::cout << "Magic is powerless!" << std::endl;
        return;
    }
    
    if ( magician->getMagicianID() == SORCERER ) {
        enemy->getHealth().takeDamage(this->hitPoints);
    }
    
    if ( magician->getMagicianID() == HEALING ) {
        enemy->getHealth().takeDamage(this->hitPoints/2);
    }
    
    if ( magician->getMagicianID() == CHURCH_WORKER ) {
        if ( enemy->getWarriorID() == VAMPIRE || enemy->getWarriorID() == NECROMANCER ) {
            enemy->getHealth().takeDamage(this->hitPoints);
        } else {
            enemy->getHealth().takeDamage(this->hitPoints/2);
        }
    }
    
    magician->getMagicPower().takeMana(this->manaCost);
    
    enemy->notify();
}

void Spell::healHealth(Unit* other, SpellCaster* magician) {
    magician->getHealth().ensureIsAlive();
    
    if ( magician->getMagicPower().getMana() < this->manaCost) {
        std::cout << "Not enough mana!" << std::endl;
        return;
    }
    
    if ( other->getWarriorID() == BERSERKER || other->getWarriorID() == DEMON  ) {
        std::cout << "Magic is powerless!" << std::endl;
        return;
    }
    
    if ( magician->getMagicianID() == HEALING || magician->getMagicianID() == CHURCH_WORKER ) {
        other->getHealth().addHitPoints(this->hitPoints);
    } else {
        other->getHealth().addHitPoints(this->hitPoints/2);
    }
    
    magician->getMagicPower().takeMana(this->manaCost);
}

void Spell::healMagic(SpellCaster* other, SpellCaster* magician) {
    magician->getHealth().ensureIsAlive();
    other->getHealth().ensureIsAlive();
    
    if ( magician->getMagicPower().getMana() < this->manaCost) {
        std::cout << "Not enough mana!" << std::endl;
        return;
    }
    
    if ( magician->getMagicianID() == HEALING || magician->getMagicianID() == CHURCH_WORKER ) {
        other->getMagicPower().addMana(this->mana);
    } else {
        other->getMagicPower().addMana(this->mana/2);
    }
    
    magician->getMagicPower().takeMana(this->manaCost);
}

void Spell::backToHuman(Unit* enemy, SpellCaster* magician) {
    magician->getHealth().ensureIsAlive();
    magician->getMagicPower().ensureHaveIsMana();
    enemy->getHealth().ensureIsAlive();
    
    if ( magician->getMagicPower().getMana() < this->manaCost) {
        std::cout << "Not enough mana!" << std::endl;
        return;
    }
    
    if ( enemy->getWarriorID() == VAMPIRE || enemy->getWarriorID() == WEREWOLF || enemy->getWarriorID() == WOLF ) {
        enemy->transitionTo(new SoldierState(enemy));
    }
    
    magician->getMagicPower().takeMana(this->manaCost);
}
