#ifndef CATEGORY_HPP
#define CATEGORY_HPP

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

#include "Exceptions.hpp"

class Item;

class Category {
    private:
        std::string name;
        int id;
        std::list<Item*>* items;
        
        static int globalID;
    public:
        Category(const std::string& name);
        ~Category();
        
        static std::list<Category*> category;
        
        const std::string& getName() const;
        int getID() const;
        
        void addItem(Item* item);
        void removeItem(Item* item);
        void getItemsInCategory() const;
        
        static void getAllCategorys();
};

std::ostream& operator<<(std::ostream& out, const Category& category);

#endif //CATEGORY_HPP
