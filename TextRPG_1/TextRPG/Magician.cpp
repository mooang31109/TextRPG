#include "Magician.h"
#include "Monster.h"

Magician::Magician(string name, int hp, int mp, int power, int defense)
	: Player(name, hp, mp, power, defense)
{
	job = "Magician";
	this->mp += 30;
}

void Magician::attack(Monster* monster)
{
	int damage = max(1, power - monster->getDefense());
	int prevHP = monster->getHP();
	monster->setHP(monster->getHP() - damage);
	cout << "[Magician] " << name << " : Fires a fireball!" << endl;
	cout << damage << " damage to " << monster->getName() << "!" << endl;
	cout << monster->getName() << " HP: " << prevHP
		<< " -> " << monster->getHP() << endl;
}