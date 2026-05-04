#pragma once
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

class Monster
{
protected:
	string name;
	int hp;
	int power;
	int defense;
	string dropItemName;
	int dropItemPrice;

public:
	Monster(string name, int hp, int power, int defense, string dropItemName, int dropItemPrice);
	void attack(Player* player);

	// getter
	string getName() { return name; }
	int getHP() { return hp; }
	int getDefense() { return defense; }
	string getDropItemName() { return dropItemName; }
	int getDropItemPrice() { return dropItemPrice; }

	// setter
	void setHP(int value) { hp = value; }
};