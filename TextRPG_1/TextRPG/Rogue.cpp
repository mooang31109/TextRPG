#include "Rogue.h"
#include "Monster.h"

Rogue::Rogue(string name, int hp, int mp, int power, int defense)
	: Player(name, hp, mp, power, defense)
{
	job = "Rogue";
	this->power += 30;
}

void Rogue::attack(Monster* monster)
{
	int damage = max(1, (power - monster->getDefense()) / 5);
	int totalDamage = damage * 5;
	int prevHP = monster->getHP();
	monster->setHP(monster->getHP() - totalDamage);
	cout << "[Rogue] " << name << " : Throws a dagger!" << endl;
	cout << damage << " damage to " << monster->getName() << "! (x5)" << endl;
	cout << monster->getName() << " HP: " << prevHP
		<< " -> " << monster->getHP() << endl;
}