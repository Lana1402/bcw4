#include "Mohican.hpp"

Mohican* Mohican::mohican = nullptr;

std::list<Mohican*> Mohican::list = std::list<Mohican*>();

Mohican& Mohican::getLastMohican() {
    return *(mohican);
}

Mohican::Mohican(const std::string& name) {
    this->name = name;
    Mohican::list.push_back(this);
    Mohican::mohican = list.back();
}

Mohican::~Mohican() {
    Mohican::list.remove(this);
    Mohican::mohican = list.back();
}

const std::string& Mohican::getName() const {
    return this->name;
}

std::ostream& operator<<(std::ostream& out, const Mohican& mohican) {
    out << mohican.getName() << std::endl;
    
    return out;
}
