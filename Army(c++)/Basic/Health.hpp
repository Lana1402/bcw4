#ifndef HEALTH_HPP
#define HEALTH_HPP

#include <iostream>
#include "Exception.hpp"

class Health {
    protected:
        int damage;
        int hitPoints;
        int hitPointsLimit;
    public:
        Health(int hp, int dmg);
        virtual ~Health();
        
        void ensureIsAlive();
        int getDamage() const;
        void setDamage(int dmg);
        int getHitPoints() const;
        void setHitPoints(int hp);
        int getHitPointsLimit() const;
        void setHitPointsLimit(int hp);
        
        virtual void addHitPoints(int hp);
        virtual void takeDamage(int dmg);
};

std::ostream& operator<<(std::ostream& out, const Health& health);

#endif //HEALTH_HPP
