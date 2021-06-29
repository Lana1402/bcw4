#ifndef ITERABLE_PRIME_HPP
#define ITERABLE_PRIME_HPP

#include <iostream>

class IterablePrime {
    private:
        int limit;
        int start;
        int current;
        int *array;
        int index;
        int element;
        
        int isPrime(int n);
    public:
        IterablePrime(int current, int limit);
        ~IterablePrime();
        
        void next();
        void operator++();
        void operator++(int);
        void previous();
        void operator--();
        void operator--(int);
        bool over();
        bool begin();
        int value();
        int operator*();
};

#endif //ITERABLE_PRIME_HPP
