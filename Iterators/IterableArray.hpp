#ifndef ITERABLE_ARRAY_HPP
#define ITERABLE_ARRAY_HPP

#include <iostream>

template <class Type>
class IterableArray {
    private:
        int limit;
        int start;
        int current;
        Type *array;
    public:
        IterableArray(int current, int limit, Type *array);
        ~IterableArray();
        
        void next();
        void operator++();
        void operator++(int);
        void previous();
        void operator--();
        void operator--(int);
        bool over();
        bool begin();
        Type value();
        Type operator*();
};

#endif //ITERABLE_ARRAY_HPP
