#include "Archer.h"

Archer::Archer(string name, int hp, int mp, int power, int defense)
	: Player(name, hp, mp, power, defense)
{
	job = "Archer";
	this->hp += 30;
}

void Archer::attack()
{
	cout << "[Archer] " << name << " : Shoots an arrow!" << endl;
}