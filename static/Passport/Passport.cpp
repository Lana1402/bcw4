#include "Passport.hpp"

char Passport::firtsLetter = 'A';
char Passport::secondLetter = 'A';
int Passport::number = -1;

char Passport::getFirtLetter()  {
    return firtsLetter;
}

char Passport::getSecondLetter()  {
    return secondLetter;
}

int Passport::getNumber()  {
    return number;
}

void Passport::validateDate(int day, int month, int year) {
    if ( day <= 0 || month <= 0 || year <= 0 || month > 12 ) {
        throw InvalidDate();
    }
    if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
        if ( day > 30 ) {
            throw InvalidDate();
        } else if ( day > 31 ) {
            throw InvalidDate();
        }
    }
    if ( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ) {
        if ( month == 2 && day > 29 ) {
            throw InvalidDate();
        }
    } else if ( month == 2 ) {
        if ( day > 28 ) {
            throw InvalidDate();
        }
    }
}

void Passport::validateSeries(char firtLetter, char secondLetter) {
    if ( firtsLetter < 'A' || firtsLetter > 'Z' ) {
        throw InvalidSeries();
    }
    if ( secondLetter < 'A' || secondLetter > 'Z' ) {
        throw InvalidSeries();
    }
}

void Passport::validateNumber(int number) {
    if ( number < 0 || number > 999999 ) {
        throw InvalidNumber();
    }
}

void Passport::correctSeries() {
    if ( firtsLetter == 'Z' && secondLetter == 'Z' && number >= 999999  ) {
        throw IsDone();
    }
    if ( number >= 999999 ) {
        Passport::secondLetter += 1;
        Passport::number = -1;
    }
    if ( Passport::secondLetter > 'Z' ) {
        Passport::firtsLetter += 1;
        Passport::secondLetter = 'A';
        Passport::number = -1;
    }
}

void Passport::setSeries(char firtsLetter, char secondLetter, int number) {
    Passport::validateSeries(firtsLetter, secondLetter);
    Passport::validateNumber(number);
    
    Passport::firtsLetter = firtLetter;
    Passport::secondLetter = secondLetter;
    Passport::number = number;
}

void Passport::printNumber() {
    printf("%.6d\n", getNumber());
}

Passport::Passport(const std::string& name, const std::string& lastName, int day, int month, int year) {
    validateDate(day, month, year);
    correctSeries();
    
    this->name = name;
    this->lastName = lastName;  
    this->day = day;
    this->month = month;
    this->year = year;
    Passport::number += 1;
}

Passport::~Passport() {}

const std::string& Passport::getName() const {
    return this->name;
}

const std::string& Passport::getLastName() const {
    return this->lastName;
}

int Passport::getDay() const {
    return this->day;
}

int Passport::getMonth() const {
    return this->month;
}

int Passport::getYear() const {
    return this->year;
}

std::ostream& operator<<(std::ostream& out, const Passport& passport) {
    out << passport.getFirtsLetter() << passport.getSecondLetter() << " ";
    
    Passport::printNumber();
    
    out << "Name: " << passport.getName() << " " << passport.getLastName() << std::endl;
    out << "Date of birth: " << passport.getDay() << "." << passport.getMonth() 
        << "." << passport.getYear() << std::endl;
    
    return out; 
}
