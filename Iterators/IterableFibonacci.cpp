#include "IterableFibonacci.hpp"

int IterableFibonacci::IterableFibonacci(int n) {
    if ( n == 0 ) {
        return 0;
    }
    if ( n == 1 || n == -1 ) {
        return 1;
    }
    if ( n < 0 ) {
        return fibonacci(n+2) - fibonacci(n+1);
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

IterableFibonacci::IterableFibonacci(int current, int limit) 
    : current(current), limit(limit) {}

IterableFibonacci::~IterableFibonacci(){}

void IterableFibonacci::next() {
    if ( over() ) {
        return;
    }
    this->current += 1;
}

void IterableFibonacci::operator++() { 
    next();
}

void IterableFibonacci::operator++(int) {
    operator++(); 
}

bool IterableFibonacci::over() {
    return this->current > this->limit;
}

int IterableFibonacci::value() {
    return fibonacci(this->current);
}

int IterableFibonacci::operator*() {
    return value(); 
}
