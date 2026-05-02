#include "Player.h"

Player::Player(string name, int hp, int mp, int power, int defense)
{
    this->name = name;
    this->hp = hp;
    this->mp = mp;
    this->power = power;
    this->defense = defense;
    this->level = 1;
    this->job = "None";
}

void Player::printPlayerStatus()
{
    cout << "------------------------------------" << endl;
    cout << "Name: " << name
        << " | Job: " << job
        << " | Lv." << level << endl;
    cout << "HP: " << hp
        << " | MP: " << mp
        << " | Attack: " << power  // ← 버그 수정: attack 함수 포인터 → power 값
        << " | Defense: " << defense << endl;
    cout << "------------------------------------" << endl;
}