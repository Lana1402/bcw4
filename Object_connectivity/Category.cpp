#include "Category.hpp"
#include "Item.hpp"

int Category::globalID = 1;

std::list<Category*> Category::category = std::list<Category*>();

void Category::getAllCategorys() {
    for( auto& iter : category ) {
        std::cout << (*iter);
    }
}

Category::Category(const std::string& name) {
    this->name = name;
    this->id = Category::globalID;
    this->items = new std::list<Item*>();
    Category::category.push_back(this);
    Category::globalID += 1;
}

Category::~Category() {
    Category::category.remove(this);
    for( auto& iter : *items ) {
        Item::items.remove(&(*iter));
    }
    this->items->clear();
}

const std::string& Category::getName() const {
    return this->name;
}

int Category::getID() const {
    return this->id;
}

void Category::addItem(Item* item) {
    this->items->push_back(item);
}

void Category::removeItem(Item* item) {
    this->items->remove(item);
}

void Category::getItemsInCategory() const {
    if ( this->items->empty() ) {
        throw NoCategory();
    }
    
    for( auto& iter : *items ) {
        std::cout << (*iter);
    }
}

std::ostream& operator<<(std::ostream& out, const Category& category) {
    out << category.getName() << " : " << "ID category - " << category.getID() << std::endl;

    return out;
}
