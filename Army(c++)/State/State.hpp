#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>

class Unit;

class State {
    protected:
        Unit* uContext;
    public:
        virtual ~State() = default;
        
        void setContext(Unit* context);
        
        virtual void changeUnit(Unit* enemy) = 0;
        virtual void transformTo() = 0;
};

#endif //STATE_HPP