#include "IterableFactorial.hpp"

#include <cmath>

int IterableFactorial::IterableFactorial(int n) {
    if ( n < 2 ) {
        return 1;
    }
    return n * factorial(n-1);
}

IterableFactorial::IterableFactorial(int current, int limit) 
    : current(abs(current)), limit(limit) {}

ItarableFactorial::~ItarableFactorial(){}

void IterableFactorial::next() {
    if ( over() ) {
        return;
    }
    this->current += 1;
}

void IterableFactorial::operator++() {
    next();
}

void IterableFactorial::operator++(int) {
    operator++(); 
}

bool IearableFactorial::over() {
    return this->current > this->limit;
}

int IterableFactorial::value() {
    return factorial(this->current);
}

int IterableFactorial::operator*() {
    return value(); 
}
