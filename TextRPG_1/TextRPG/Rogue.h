#pragma once
#include "Player.h"

class Rogue : public Player
{
public:
	Rogue(string name, int hp, int mp, int power, int defense);
	void attack() override;
};