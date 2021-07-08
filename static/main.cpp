#include <iostream>

#include "Countable.hpp"
#include "Identifiable.hpp"
#include "Mohican.hpp"

int main() {
	Countable* a = new Countable();
	Identifiable* q = new Identifiable();
	Identifiable* w = new Identifiable();
	Identifiable* e = new Identifiable();
	Mohican* z = new Mohican("lana");
	Mohican* m = new Mohican("Vova"); 

	// std::cout << "Quantity: " << a->getQuantity() << std::endl;
	// Countable* b = new Countable();
	// Countable* c = new Countable();
	// std::cout << "Quantity: " << c->getQuantity() << std::endl;
	// Countable* d = new Countable();
	// // std::cout << "Quantity: " << c->getQuantity() << std::endl;

	// std::cout << "Quantity: " << Countable::getQuantity() << std::endl;


	// std::cout << "Identifiable: " << q->getID() << std::endl;
	// std::cout << "Identifiable: " << w->getID() << std::endl;
	// std::cout << "Identifiable: " << e->getID() << std::endl;

	// std::cout << "Mohican: " << Mohican::getLastMohican() << std::endl;

	Mohican* x = new Mohican("Roma"); 

	// std::cout << "Mohican: " << Mohican::getLastMohican() << std::endl;

	delete x;

	// std::cout << "Mohican: " << Mohican::getLastMohican() << std::endl;

	delete z;

	// std::cout << "Mohican: " << Mohican::getLastMohican() << std::endl;

	delete m;

	std::cout << "Mohican: " << Mohican::getLastMohican() << std::endl;




	return 0;
}