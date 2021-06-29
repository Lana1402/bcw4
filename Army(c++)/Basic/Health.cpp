#include "Health.hpp"

Health::Health(int hp, int dmg) : hitPoints(hp), hitPointsLimit(hp), damage(dmg) {}

Health::~Health() {}

void Health::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
       throw UnitIsDead();
   }
}

int Health::getDamage() const {
    return this->damage;
}

void Health::setDamage(int dmg) {
    this->damage = dmg;
}

int Health::getHitPoints() const {
    return this->hitPoints;
}

void Health::setHitPoints(int hp) {
    this->hitPoints = hp;
}

int Health::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

void Health::setHitPointsLimit(int hp) {
    this->hitPointsLimit = hp;
}

void Health::addHitPoints(int hp) {
    this->ensureIsAlive();
    
    if ( hp <= (this->hitPointsLimit - this->hitPoints) ) {
        this->hitPoints += hp;
    } else {
        this->hitPoints = this->hitPointsLimit;
    }
}

void Health::takeDamage(int dmg) {
    this->ensureIsAlive();
    
    this->hitPoints -= dmg;
    
    if ( this->hitPoints < 0 ) {
        this->hitPoints = 0;
    }
}

std::ostream& operator<<(std::ostream& out, const Health& health) {
    out << "Damage " << health.getDamage() << std::endl;
    out << "Hit points " << health.getHitPoints() << std::endl;
    out << "Hit points limit " << health.getHitPointsLimit() << std::endl;
    
    return out;
}
