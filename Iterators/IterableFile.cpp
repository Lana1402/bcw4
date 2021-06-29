#include "IterableFile.hpp"

#include <cmath>

template <class Type>
IterableFile<Type>::IterableFile(int current, int limit, const std::string& nameFile) 
    : current(abs(current)), start(abs(current)), index(-1), limit(limit) {
        this->array = (Type*)malloc(limit*sizeof(Type));
        this->file.open(nameFile);
    }

template <class Type>
IterableFile<Type>::~IterableFile(){
    free(this->array);
    this->file.close();
}

template <class Type>
void IterableFile<Type>::next() {
    if ( over() ) {
        return;
    }
    this->file.seekg(this->current);
    this->index += 1;
    this->array[this->index] = this->file.get();
    this->current += 1;
}

template <class Type>
void IterableFile<Type>::operator++() {
    next();
}

template <class Type>
void IterableFile<Type>::operator++(int) {
    operator++();
}

template <class Type>
void IterableFile<Type>::previous() {
    if ( begin() ) {
        return;
    }
    this->current -= 1;
    this->index -= 1;
}

template <class Type>
void IterableFile<Type>::operator--() {
    previous();
}

template <class Type>
void IterableFile<Type>::operator--(int) {
    operator--();
}

template <class Type>
bool IterableFile<Type>::over() {
    return this->current >= this->limit;
}

template <class Type>
bool IterableFile<Type>::begin() {
    return this->index < 0;
}

template <class Type>
Type IterableFile<Type>::value() {
    if ( this->current == this->start ) {
        next();
    }
    if ( this->index == ((this->limit-1) - this->start) ) {
        previous();
    }
    return this->array[this->index];
}

template <class Type>
Type IterableFile<Type>::operator*() {
    return value();
}

template class IterableFile<char>;
