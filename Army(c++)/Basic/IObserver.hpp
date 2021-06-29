#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include <iostream>

#include "Unit.hpp"

class IObserver {
    public:
        virtual ~IObserver() = default;
        
        virtual void update(Unit* enemy) = 0;
};

#endif //IOBSERVER_HPP
