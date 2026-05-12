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
	int expReward;

public:
	Monster(string name, int hp, int power, int defense, string dropItemName, int dropItemPrice, int expReward);
	void attack(Player* player);

	// getter
	string getName() { return name; }
	int getHP() { return hp; }
	int getDefense() { return defense; }
	string getDropItemName() { return dropItemName; }
	int getDropItemPrice() { return dropItemPrice; }
	int getexpReward() { return expReward; }

	// setter
	void setHP(int value) { hp = value; }
};