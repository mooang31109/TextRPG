#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player
{
protected:
    string name;
    string job;
    int level;
    int hp;
    int mp;
    int power;
    int defense;

public:
    Player(string name, int hp, int mp, int power, int defense);

    virtual void attack() = 0; //순수 가상함수
    virtual ~Player() {} // 가상소멸자

    // getter
    int getHP() { return hp; }
    int getMP() { return mp; }
    int getPower() { return power; }
    int getDefense() { return defense; }
    string getName() { return name; }
    string getJob() { return job; }

    // setter
    void setHP(int value) { hp = value; }
    void setMP(int value) { mp = value; }
    void setPower(int value) { power = value; }
    void setDefense(int value) { defense = value; }

    void printPlayerStatus();
};