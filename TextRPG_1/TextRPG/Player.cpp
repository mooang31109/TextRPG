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
    this->exp = 0;
    this->maxExp = 100;
}

void Player::printPlayerStatus()
{
    cout << "------------------------------------" << endl;
    cout << "Name: " << name
        << " | Job: " << job
        << " | Lv." << level << endl;
    cout << "HP: " << hp
        << " | MP: " << mp
        << " | Attack: " << power  // 버그 수정: attack 함수 포인터 -> power 값
        << " | Defense: " << defense << endl;
    cout << "EXP: " << exp << "/" << maxExp << endl; // 경험치 추가
    cout << "------------------------------------" << endl;
}

void Player::levelUp()
{
    level++;
    hp += 10;
    mp += 5;
    power += 5;
    exp = 0;
    maxExp += 50;

    cout << "... Level up condition met" << endl;
    cout << "  -> Level Up! Lv." << level - 1
        << "  -> Lv." << level << endl;
    cout << "  -> HP +10, MP +5, Attack +5" << endl;
}