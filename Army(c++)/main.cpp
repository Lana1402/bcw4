#include <iostream>
#include <typeinfo>
#include <string>
#include "Warriors/Soldier.hpp"
#include "Warriors/Rogue.hpp"
#include "Warriors/Berserker.hpp"
#include "Warriors/Vampire.hpp"
#include "Warriors/WereWolf.hpp"
#include "Warriors/Wizard.hpp"
#include "Warriors/Healer.hpp"
#include "Warriors/Priest.hpp"
#include "Warriors/Warlock.hpp"
#include "Warriors/Necromancer.hpp"


int main() {
	// Soldier* john = new Soldier("John", 100, 10);
	Rogue* dale = new Rogue("Dale", 60, 10);
	// Berserker* alex = new Berserker("Alex", 190, 20);
	// Vampire* barbarian = new Vampire("Barbarian", 300, 20);
	// WereWolf* knight = new WereWolf("Knight", 250, 30);
	// Wizard* lana = new Wizard("Lana", 200, 100, 10);
	// Healer* hope = new Healer("Hope", 100, 200, 20);
	// Priest* faith = new Priest("Faith", 100, 200, 10);
	Warlock* warl = new Warlock("Warl", 70, 200, 30);
	Necromancer* nec = new Necromancer("Nec", 300, 150, 5);

	std::cout << std::endl;

	// std::cout << *john << std::endl;
	// std::cout << *dale << std::endl;
	// std::cout << *alex << std::endl;
	// std::cout << *barbarian << std::endl;
	// std::cout << *knight << std::endl;
	// std::cout << *lana << std::endl;
	// std::cout << *hope << std::endl;
	// std::cout << *faith << std::endl;
	std::cout << *warl << std::endl;
	std::cout << *nec << std::endl;

	// barbarian->swichTo();

	// nec->magicAttack(dale, HELLFIRE);
	// nec->attack(dale);

	// std::cout << std::endl;
	// warl->magicAttack(nec, HELLFIRE);
	nec->magicAttack(warl, HELLFIRE);
	nec->attack(warl);
	dale->attack(warl);
	// nec->attack(warl);
	// nec->attack(dale);
	// std::cout << std::endl;
	// std::cout << *warl << std::endl;
	// warl->healHealth(faith, HEAL);
	// // std::cout << std::endl;

	// // lana->healHealth(knight, HUMAN);
	// // std::cout << std::endl;

	// // knight->swichTo();

	// warl->summonDemon();
	// warl->summonDemon();
	// // warl->demon->attack(faith);

	// std::cout << std::endl;

	// faith->attack(warl->demon);

	// barbarian->transform(warl->demon);
	// barbarian->attack(knight);


	// nec->magicAttack(barbarian, HELLFIRE);
	// dale->attack(john);
	std::cout << std::endl;

	// std::cout << *john << std::endl;
	// std::cout << *dale << std::endl;
	// std::cout << *alex << std::endl;
	// std::cout << *barbarian << std::endl;
	// std::cout << *knight << std::endl;
	// std::cout << *lana << std::endl;
	// std::cout << *hope << std::endl;
	// std::cout << *faith << std::endl;
	std::cout << *warl << std::endl;
	// std::cout << *warl->demon << std::endl;
	std::cout << *nec << std::endl;


	return 0;
}