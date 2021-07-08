#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <iostream>
#include <string>
#include <list>
#include <map>

#include "Exceptions.hpp"

class Order;

class Customer {
    private:
        std::string name;
        int id;
        Order* order;
        std::list<Order*>* orders;
        
        static int globalID;
    public:
        Customer(const std::string& name);
        ~Customer();
        
        static std::list<Customer*> customer;
        
        const std::string& getName() const;
        int getID() const;
        
        void addOrder(Order* order);
        void removeOrder(Order* order);
        void getOrder() const;
        
        static void getAllCustomers();
};

std::ostream& operator<<(std::ostream& out, const Customer& customer);

#endif //CUSTOMER_HPP
