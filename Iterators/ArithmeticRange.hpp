#ifndef ARITHMETIC_RANGE_HPP
#define ARITHMETIC_RANGE_HPP

#include <iostream>

class ArithmeticRange {
    private:
        int limit;
        int current;
    public:
        ArithmeticRange(int current, int limit);
        ~ArithmeticRange();
        
        void next();
        void operator++();
        void operator++(int);
        bool over();
        int value();
        int operator*();
        
};

#endif //ARITHMETIC_RANGE_HPP
