#include "Countable.hpp" 

int Countable::globalQuantity = 0;

int Countable::getQuantity() {
    return globalQuantity;
}

Countable::Countable() {
    Countable::globalQuantity += 1;
}

Countable::~Countable() {}
