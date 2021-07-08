#ifndef PASSPORT_HPP
#define PASSPORT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>

#include "Exception.hpp"

class Passport {
    private:
        std::string name;
        std::string lastName;
        int day;
        int month;
        int year;
        
        static char firtsLetter;
        static char secondLetter;
        static int number;
        
        void validateDate(int day, int month, int year);
        void correctSeries();
        
        static void validateSeries(char firtsLetter, char secondLetter);
        static void validateNumber(int number);
    public:
        Passport(const std::string& name, const std::string& lastName, int day, int month, int year);
        ~Passport();
        
        const std::string& getName() const;
        const std::string& getLastName() const;
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        
        static char getFirtsLetter();
        static char getSecondLetter();
        static int getNumber();
        
        static void setSeries(char firtsLetter, char secondLetter, int number = 0);
        
        static void printNumber();
};

std::ostream& operator<<(std::ostream& out, const Passport& passport);

#endif //PASSPORT_HPP
