#include "ArithmeticRange.hpp"

ArithmeticRange::ArithmeticRange(int current, int limit) 
    : current(current), limit(limit) {}

ArithmeticRange::~ArithmeticRange(){}

void ArithmeticRange::next() {
    if ( over() ) {
        return;
    }
    this->current += 1;
}

void ArithmeticRange::operator++() {
    next(); 
}

void ArithmeticRange::operator++(int) {
    operator++(); 
}

bool ArithmeticRange::over() {
    return this->current > this->limit;
}

int ArithmeticRange::value() {
    return this->current; 
}

int ArithmeticRange::operator*() {
    return value(); 
}
