#include "GeometricRange.hpp"

#include <cmath>

GeometricRange::GeometricRange(int current, int denominator, int limit) 
    : current(abs(current)), denominator(denominator), limit(limit) {}

GeometricRange::~GeometricRange(){}

void GeometricRange::next() {
    if ( over() ) {
        return;
    }
    this->current *= this->denominator;
}

void GeometricRange::operator++() {
    next(); 
}

void GeometricRange::operator++(int) {
    operator++(); 
}

bool GeometricRange::over() {
    return this->current > this->limit;
}

int GeometricRange::value() {
    return this->current; 
}

int GeometricRange::operator*() {
    return value(); 
}
