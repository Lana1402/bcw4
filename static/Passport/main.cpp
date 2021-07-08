#include <iostream>

#include "Passport.hpp"

int main() {
	Passport* p = new Passport("Lana", "Patuk", 29, 6, 1992);

	Passport::setSeries('Z', 'A', 999999);
	std::cout << *p << std::endl;

	// try {
	// 	Passport* z = new Passport("Roma", "Grach", 15, 7, 1995);
	// } catch (IsDone) {
	// 	std::cout << "Is Done" << std::endl;
	// }

	Passport* z = new Passport("Roma", "Grach", 15, 7, 1995);
	std::cout << *z << std::endl;
	Passport* r = new Passport("Vova", "Zasuha", 13, 2, 1990);
	std::cout << *r << std::endl;
	Passport* t = new Passport("Andrey", "Kuznecov", 25, 10, 1989);

	Passport::setSeries('D', 'Z');

	std::cout << *t << std::endl;


	return 0;
}