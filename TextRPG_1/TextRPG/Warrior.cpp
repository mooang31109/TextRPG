#include "Warrior.h"
#include "Monster.h"

Warrior::Warrior(string name, int hp, int mp, int power, int defense)
    : Player(name, hp, mp, power, defense)
{
    job = "Warrior";
    this->defense += 30;
}

void Warrior::attack(Monster* monster)
{
    int damage = max(1, power - monster->getDefense());
    int prevHP = monster->getHP();
    monster->setHP(monster->getHP() - damage);
    cout << "[Warrior] " << name << " : Swings a greatsword!" << endl;
    cout << damage << " damage to " << monster->getName() << "!" << endl;
    cout << monster->getName() << " HP: " << prevHP
        << " -> " << monster->getHP() << endl;
}