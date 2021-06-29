#ifndef UNIT_HPP
#define UNIT_HPP

#include <iostream>
#include <typeinfo>
#include <string>

#include "../ID/WarriorID.hpp"
#include "../State/State.hpp"
#include "Health.hpp"
#include "Attack.hpp"

class IObserver;

class Unit {
    protected:
        std::string name;
        Health* uHealth;
        Attack* uAttack;
        State* uState;
        IObserver* observer;
    public:
        Unit(const std::string& name, int hp, int dmg, State* state);
        virtual ~Unit();
        
        const std::string& getName() const;
        Health& getHealth() const;
        State& getState() const;
        Attack& getAttack() const;
        virtual WarriorID getWarriorID() const = 0;
        virtual void setWarriorID(WarriorID newID) = 0;
        
        virtual void transitionTo(State* state);
        
        virtual void attach(IObserver* observer);
        virtual void detach();
        virtual void notify();
        
        virtual void transform(Unit* enemy);
        virtual void swichTo();
        
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_HPP
