#include "IterableArray.hpp"

template <class Type>
IterableArray<Type>::IterableArray(int current, int limit, Type *array) 
    : current(current), start(current), limit(limit), array(array) {}

template <class Type>
IterableArray<Type>::~IterableArray(){}

template <class Type>
void IterableArray<Type>::next() {
    if ( over() ) {
        return;
    }
    this->current += 1;
}

template <class Type>
void IterableArray<Type>::operator++() {
    next();
}

template <class Type>
void IterableArray<Type>::operator++(int) {
    operator++();
}

template <class Type>
void IterableArray<Type>::previous() {
    if ( begin() ) {
        return;
    }
    this->current -= 1;
}

template <class Type>
void IterableArray<Type>::operator--() {
    previous();
}

template <class Type>
void IterableArray<Type>::operator--(int) {
    operator--();
}

template <class Type>
bool IterableArray<Type>::over() {
    return this->current >= this->limit;
}

template <class Type>
bool IterableArray<Type>::begin() {
    return this->current < this->start;
}

template <class Type>
Type IterableArray<Type>::value() {
    if ( this->current == this->limit ) {
       previous(); 
    }
    return this->array[this->current];
}

template <class Type>
Type IterableArray<Type>::operator*() {
    return value();
}

template class IterableArray<int>;
template class IterableArray<float>;
template class IterableArray<double>;
template class IterableArray<char>;
