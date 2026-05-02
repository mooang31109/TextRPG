#include "Rogue.h"

Rogue::Rogue(string name, int hp, int mp, int power, int defense)
	: Player(name, hp, mp, power, defense)
{
	job = "Rogue";
	this->power += 30;
}

void Rogue::attack()
{
	cout << "[Rogue] " << name << " Throws a dagger!" << endl;
}