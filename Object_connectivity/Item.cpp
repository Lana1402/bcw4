#include "Item.hpp"
#include "Order.hpp"

int Item::globalID = 1;

std::list<Item*> Item::items = std::list<Item*>();

void Item::getAllItems() {
    for( auto& iter : items ) {
        std::cout << (*iter);
    }
}

Item::Item(const std::string& name, Category* category) {
    std::list<Category*>::iterator it = std::find(Category::category.begin(), Category::category.end(), category );
    if ( it == Category::category.end() ) {
        throw NoCategory();
    }
    this->name = name;
    this->id = Item::globalID;
    this->category = category;
    this->order = new std::list<Item*>();
    this->category->addItem(this);
    Item::items.push_back(this);
    Item::globalID += 1;
}

Item::~Item() {
    Item::items.remove(this);
    this->category->removeItem(this);
    this->order->remove(this);
}

const std::string& Item::getName() const {
    return this->name;
}

int Item::getID() const {
    return this->id;
}

void Item::addInOrder() {
    this->order->push_back(this);
}

void Item::removeFromOrder() {
    this->order->pop_back();
}

void Item::getOrder() const {
    std::list<Category*>::iterator it = std::find(Category::category.begin(), Category::category.end(), this->category );
    if ( it == Category::category.end() ) {
        delete this;
    }
    if ( this->order->empty() ) {
        throw NoItems();
    }
    
    std::cout << this->name << " - " << this->order->size() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item.getName() << " : " << "\t" << "ID item - " << item.getID() << std::endl;
    
    return out;
}
