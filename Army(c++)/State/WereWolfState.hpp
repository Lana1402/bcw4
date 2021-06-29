#ifndef WEREWOLF_STATE_HPP
#define WEREWOLF_STATE_HPP

#include "State.hpp"

class WereWolfState : public State {
    protected:
        Unit* thisUnit;
    public:
        WereWolfState(Unit* thisUnit);
        virtual ~WereWolfState() = default;
        
        virtual void changeUnit(Unit* enemy) override;
        virtual void transformTo() override;
};

#endif //WEREWOLF_STATE_HPP
