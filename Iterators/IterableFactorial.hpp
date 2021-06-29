#ifndef ITERABLE_FACTORIAL_HPP
#define ITERABLE_FACTORIAL_HPP

#include <iostream>

class IterableFactorial {
    private:
        int limit;
        int current;
        
        int factorial(int n);
    public:
        IterableFactorial(int current, int limit);
        ~IterableFactorial();
        
        void next();
        void operator++();
        void operator++(int);
        bool over();
        int value();
        int operator*();
};

#endif //ITERABLE_FACTORIAL_HPP
