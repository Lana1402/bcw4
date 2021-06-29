#ifndef ITERABLE_FILE_HPP
#define ITERABLE_FILE_HPP

#include <iostream>
#include <fstream>

template <class Type>
class IterableFile {
    private:
        int limit;
        int start;
        int current;
        int index;
        Type *array;
        std::ifstream file;
    public:
        IterableFile(int current, int limit, const std::string& nameFile);
        ~IterableFile();
        
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

#endif //ITERABLE_FILE_HPP