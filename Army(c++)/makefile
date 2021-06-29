all: main.out

main.out: Attack.o Health.o MagicPower.o SpellCaster.o Unit.o Spell.o SpellBook.o SoldierState.o State.o VampireState.o WereWolfState.o WolfState.o Berserker.o Demon.o Healer.o Necromancer.o Priest.o Rogue.o Soldier.o Vampire.o Warlock.o WereWolf.o Wizard.o
	g++ main.cpp *.o -o main.out

Attack.o:
	g++ -c Basic/Attack.cpp

Health.o:
	g++ -c Basic/Health.cpp

MagicPower.o:
	g++ -c Basic/MagicPower.cpp

SpellCaster.o:
	g++ -c Basic/SpellCaster.cpp

Unit.o:
	g++ -c Basic/Unit.cpp

Spell.o:
	g++ -c Magic/Spell.cpp

SpellBook.o:
	g++ -c Magic/SpellBook.cpp

SoldierState.o:
	g++ -c State/SoldierState.cpp

State.o:
	g++ -c State/State.cpp

VampireState.o:
	g++ -c State/VampireState.cpp

WereWolfState.o:
	g++ -c State/WereWolfState.cpp

WolfState.o:
	g++ -c State/WolfState.cpp

Berserker.o:
	g++ -c Warriors/Berserker.cpp

Demon.o:
	g++ -c Warriors/Demon.cpp

Healer.o:
	g++ -c Warriors/Healer.cpp

Necromancer.o:
	g++ -c Warriors/Necromancer.cpp

Priest.o:
	g++ -c Warriors/Priest.cpp

Rogue.o:
	g++ -c Warriors/Rogue.cpp

Soldier.o:
	g++ -c Warriors/Soldier.cpp

Vampire.o:
	g++ -c Warriors/Vampire.cpp

Warlock.o:
	g++ -c Warriors/Warlock.cpp

WereWolf.o:
	g++ -c Warriors/WereWolf.cpp

Wizard.o:
	g++ -c Warriors/Wizard.cpp

clean:
	rm -f *.o
