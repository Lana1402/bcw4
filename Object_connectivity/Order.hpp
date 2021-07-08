#ifndef ORDER_HPP
#define ORDER_HPP

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

#include "Item.hpp"
#include "Exceptions.hpp"

class Customer;

class Order {
    private:
        Customer* customer;
        Item* item;
        std::list<Item*>* items;
        int id;
        
        static int globalID;
    public:
        Order(Customer* customer, Item* item);
        ~Order();
        
        static std::list<Order*> order;
        
        int getID() const;
        
        void addItem(Item* item);
        void removeItem(Item* item);
        void getItemsInOrder() const;
        
        static void getAllOrders();
};

std::ostream& operator<<(std::ostream& out, const Order& order);

#endif //ORDER_HPP