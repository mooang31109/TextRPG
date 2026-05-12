#pragma once
#include "Player.h"

class Archer : public Player
{
public:
	Archer(string name, int hp, int mp, int power, int defense);
	void attack(Monster* monster) override;
};