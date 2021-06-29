#ifndef ITERABLE_FIBONACCI_HPP
#define ITERABLE_FIBONACCI_HPP

#include <iostream>

class IterableFibonacci {
    private:
        int limit;
        int current;
        
        int fibonacci(int n);
    public:
        IterableFibonacci(int current, int limit);
        ~IterableFibonacci();
        
        void next();
        void operator++();
        void operator++(int);
        bool over();
        int value();
        int operator*();
};

#endif //ITERABLE_FIBONACCI_HPP
