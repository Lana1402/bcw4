#include "Order.hpp"
#include "Customer.hpp"

int Order::globalID = 0;

std::list<Order*> Order::order = std::list<Order*>();

void Order::getAllOrders() {
    for( auto& iter : order ) {
        std::cout << (*iter);
    }
}

Order::Order(Customer* customer, Item* item) {
    std::list<Customer*>::iterator it = std::find(Customer::customer.begin(), Customer::customer.end(), customer );
    if ( it == Customer::customer.end() ) {
        throw NoCustomer();
    }
    std::list<Item*>::iterator iter = std::find(Item::items.begin(), Item::items.end(), item );
    if ( iter == Item::items.end() ) {
        throw NoItems();
    }
    this->customer = customer;
    this->customer->addOrder(this);
    this->id = Order::globalID;
    this->item = item;
    this->item->addInOrder();
    this->items = new std::list<Item*>();
    this->items->push_back(item);
    Order::order.push_back(this);
    Order::globalID += 1;
}

Order::~Order() {
    Order::order.remove(this);
    this->customer->removeOrder(this);
    this->items->clear();
    this->item->removeFromOrder();
}

int Order::getID() const {
    return this->id;
}

void Order::addItem(Item* item) {
    this->items->push_back(item);
}

void Order::removeItem(Item* item) {
    this->items->remove(item);
}

void Order::getItemsInOrder() const {
    std::list<Customer*>::iterator it = std::find(Customer::customer.begin(), Customer::customer.end(), customer );
    if ( it == Customer::customer.end() ) {
        delete this;;
    }
    std::list<Item*>::iterator iter = std::find(Item::items.begin(), Item::items.end(), item );
    if ( iter == Item::items.end() ) {
        delete this;
    }
    if ( this->items->empty() ) {
        throw NoOrder();
    }
    
    for( auto& iter : *items ) {
        std::cout << (*iter);
    }
}

std::ostream& operator<<(std::ostream& out, const Order& order) {
    order.getItemsInOrder();
    out << "ID order - " << order.getID() << std::endl;

    return out;
}