#ifndef COUNTABLE_HPP
#define COUNTABLE_HPP

#include <iostream>

class Countable {
    private:
        static int globalQuantity;
        
    public:
    	Countable();
        ~Countable();
        
        static int getQuantity();
};

#endif //COUNTABLE_HPP
