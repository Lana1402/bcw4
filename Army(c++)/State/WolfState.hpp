#ifndef WOLF_STATE_HPP
#define WOLF_STATE_HPP

#include "State.hpp"

class WolfState : public State {
    protected:
        Unit* thisUnit;
    public:
        WolfState(Unit* thisUnit);
        virtual ~WolfState() = default;
        
        virtual void changeUnit(Unit* enemy) override;
        virtual void transformTo() override;
};

#endif //WOLF_STATE_HPP
