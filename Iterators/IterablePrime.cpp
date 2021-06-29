#include "IterablePrime.hpp"

#include <cmath>

int IterablePrime::isPrime(int n) {
    if ( n == 2 ) {
        return 1;
    }
    
    if ( n % 2 == 0 || n < 2 ) {
        return 0;
    }
    
    for ( int i = 3; i <= sqrt(n); i += 2 ) {
        if ( n % i == 0 ) {
            return 0;
        }
    }
    return 1;
}

IterablePrime::IterablePrime(int current, int limit) 
    : current(abs(current)), start(abs(current))
    , limit(limit), index(-1), element(abs(current)) {
        this->array = (int*)malloc(limit*sizeof(int));
    }

IterablePrime::~IterablePrime(){
    free(this->array);
}

void IterablePrime::next() {
    if ( over() ) {
        return;
    }
    
    if ( isPrime(this->element) ) {
        this->index += 1;
        this->array[this->index] = this->element;
        this->current += 1;
        this->element += 1;
    } else {
        this->element += 1;
        next();
    }
}

void IterablePrime::operator++() {
    next();
}

void IterablePrime::operator++(int) {
    operator++();
}

void IterablePrime::previous() {
    if ( begin() ) {
        return;
    }
    this->current -= 1;
    this->index -= 1;
}

void IterablePrime::operator--() {
    previous();
}

void IterablePrime::operator--(int) {
    operator--();
}

bool IterablePrime::over() {
    return this->current > this->limit;
}

bool IterablePrime::begin() {
    return this->index < 0;
}

int IterablePrime::value() {
    if ( this->current == this->start ) {
        next();
    }
    if ( this->index == (this->limit - this->start) ) {
        previous();
    }
    return this->array[this->index];
}

int IterablePrime::operator*() {
    return value();
}
