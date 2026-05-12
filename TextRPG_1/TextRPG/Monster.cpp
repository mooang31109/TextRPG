#include "Monster.h"
#include "Player.h"

Monster::Monster(string name, int hp, int power, int defense, string dropItemName, int dropItemPrice, int expReward)
{
	this->name = name;
	this->hp = hp;
	this->power = power;
	this->defense = defense;
	this->dropItemName = dropItemName;
	this->dropItemPrice = dropItemPrice;
	this->expReward = expReward;
}

void Monster::attack(Player* player)
{
	int damage = power - player->getDefense(); //데미지 공식: 공격력 - 방어력
	if (damage <= 0) damage = 1; //데미지가 0 이하이면 1로 고정하기
	player->setHP(player->getHP() - damage); //데미지 받은만큼 hp감소
}