#include <iostream>
#include <fstream>
#include <string>

#include "ArithmeticRange.hpp"
#include "GeometricRange.hpp"
#include "IterableFactorial.hpp"
#include "IterableFibonacci.hpp"
#include "IterablePrime.hpp"
#include "IterableArray.hpp"
#include "IterableFile.hpp"

int main() {
	// int array[] = {3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    // char array[] = "Hello, world!";
    // ArithmeticRange seq(-5, 10);
    // GeometricRange seq(-2, -2, 5);
    // ItarableFactorial seq(1, 5);
    // IterableFibonacci seq(-10, 0);
    // IterablePrime seq(-3, 10);
    // IterableArray<int> seq(5, 10, array);
    // IterableArray<char> seq(0, 2, array);
    IterableFile<char> seq(7, 19, "file.txt");

    for ( ; !seq.over(); seq++ ) {
        std::cout << *seq << " ";
    }
    
    std::cout << std::endl;
    
    for ( ; !seq.begin(); seq-- ) {
        std::cout << *seq << " ";
    }
    std::cout << std::endl;

    return 0;
}