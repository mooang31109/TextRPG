#include "Archer.h"
#include "Monster.h"

Archer::Archer(string name, int hp, int mp, int power, int defense)
	: Player(name, hp, mp, power, defense)
{
	job = "Archer";
	this->hp += 30;
}

void Archer::attack(Monster* monster)
{
	int damage = max(1, (power - monster->getDefense()) / 3);
	int totalDamage = damage * 3;
	int prevHP = monster->getHP();
	monster->setHP(monster->getHP() - totalDamage);
	cout << "[Archer] " << name << " : Shoots an arrow!" << endl;
	cout << damage << " damage to " << monster->getName() << "! (x3)" << endl;
	cout << monster->getName() << " HP: " << prevHP
		<< " -> " << monster->getHP() << endl;
}