#ifndef VAMPIRE_STATE_HPP
#define VAMPIRE_STATE_HPP

#include "State.hpp"

class VampireState : public State {
    protected:
        Unit* thisUnit;
    public:
        VampireState(Unit* thisUnit);
        virtual ~VampireState() = default;
        
        virtual void changeUnit(Unit* enemy) override;
        virtual void transformTo() override;
};

#endif //VAMPIRE_STATE_HPP
