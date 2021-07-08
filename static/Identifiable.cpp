#include "Identifiable.hpp"  

int Identifiable::globalId = 1;

Identifiable::Identifiable() {
    this->id = Identifiable::globalId;
    Identifiable::globalId += 1;
}

Identifiable::~Identifiable() {}

int Identifiable::getID() const {
    return this->id;
}
