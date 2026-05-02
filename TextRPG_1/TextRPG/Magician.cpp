#include "Magician.h"

Magician::Magician(string name, int hp, int mp, int power, int defense)
	: Player(name, hp, mp, power, defense)
{
	job = "Magician";
	this->mp += 30;
}

void Magician::attack()
{
	cout << "[Magician] " << name << " Fires a fireball!" << endl;
}