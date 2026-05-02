#include "Warrior.h"

Warrior::Warrior(string name, int hp, int mp, int power, int defense)
    : Player(name, hp, mp, power, defense)
{
    job = "Warrior";
    this->defense += 30;
}

void Warrior::attack()
{
    cout << "[Warrior] " << name << " Swings a greatsword!" << endl;
}