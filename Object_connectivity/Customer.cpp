#include "Customer.hpp"
#include "Order.hpp"

int Customer::globalID = 1;

std::list<Customer*> Customer::customer = std::list<Customer*>();

void Customer::getAllCustomers() {
    for( auto& iter : customer ) {
        std::cout << (*iter);
    }
}

Customer::Customer(const std::string& name) {
    this->name = name;
    this->id = Customer::globalID;
    this->orders = new std::list<Order*>();
    Customer::customer.push_back(this);
    Customer::globalID += 1;
}

Customer::~Customer() {
    Customer::customer.remove(this);
    this->orders->clear();
}

const std::string& Customer::getName() const {
    return this->name;
}

int Customer::getID() const {
    return this->id;
}

void Customer::addOrder(Order* order) {
    this->orders->push_back(order);
}

void Customer::removeOrder(Order* order) {
    this->orders->remove(order);
}

void Customer::getOrder() const {
    if ( this->orders->empty() ) {
        throw NoOrder();
    }
    
    std::cout << this->name << "\t" << "Everything in the order :" << std::endl;
    
    for( auto& iter : *orders ) {
        std::cout << (*iter);
    }
}

std::ostream& operator<<(std::ostream& out, const Customer& customer) {
    out << customer.getName() << " : " << "ID customer - " << customer.getID() << std::endl;

    return out;
}