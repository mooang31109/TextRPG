#pragma once
#include "Player.h"

class Warrior : public Player
{
public:
    Warrior(string name, int hp, int mp, int power, int defense);
    void attack() override;
};