#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

#include "Category.hpp"
#include "Exceptions.hpp"

class Order;

class Item {
    private:
        std::string name;
        Category* category;
        int id;
        std::list<Item*>* order;
        
        static int globalID;
    public:
        Item(const std::string& name, Category* category);
        ~Item();
        
        static std::list<Item*> items;
        
        const std::string& getName() const;
        int getID() const;
        
        void addInOrder();
        void removeFromOrder();
        void getOrder() const;
        
        static void getAllItems();
};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif //ITEM_HPP