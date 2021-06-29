#ifndef SOLDIER_STATE_HPP
#define SOLDIER_STATE_HPP

#include "State.hpp"

class SoldierState : public State {
    protected:
        Unit* thisUnit;
    public:
        SoldierState(Unit* thisUnit);
        virtual ~SoldierState() = default;
        
        virtual void changeUnit(Unit* enemy) override;
        virtual void transformTo() override;
};

#endif //SOLDIER_STATE_HPP
