#ifndef GEOMETRIC_RANGE_HPP
#define GEOMETRIC_RANGE_HPP

#include <iostream>

class GeometricRange {
    private:
        int limit;
        int current;
        int denominator;
    public:
        GeometricRange(int current, int denominator, int limit);
        ~GeometricRange();
        
        void next();
        void operator++();
        void operator++(int);
        bool over();
        int value();
        int operator*();    
};

#endif //GEOMETRIC_RANGE_HPP