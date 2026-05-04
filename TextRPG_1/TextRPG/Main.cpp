#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Rogue.h"
#include "Archer.h"
#include "Monster.h"
#include "Battle.h"
#include "Item.h"
#include "AlchemyWorkshop.h"

using namespace std;
const int SIZE = 4;
//인벤토리
vector <Item> inventory;

void printStatus(string name, int stat[])
{
    cout << "\n====================================" << endl;
    cout << "  " << name << "\'s Stats" << endl;
    cout << "====================================" << endl;
    cout << "HP: " << stat[0] << "\t\t" << "MP: " << stat[1] << endl;
    cout << "Attack: " << stat[2] << "\t" << "Defense: " << stat[3] << endl;
    cout << "====================================" << endl;
}

int main(void)
{
    string heroName;
    int stat[SIZE] = { 0 };
    int HP_Potion = 5, MP_Potion = 5;
    int Attack_UP = 1, Defense_UP = 1;
    int choice;
    bool isGameStart = false;
    bool isRunning = true;

    //플레이어 세팅
    cout << "===========================================" << endl;
    cout << "   [ Dungeon Escape Text RPG ]" << endl;
    cout << "===========================================" << endl;
    cout << "Enter your hero's name: ";
    cin >> heroName;

    while (true)
    {
        cout << "\nEnter HP and MP: ";
        cin >> stat[0] >> stat[1]; //stat[0] : HP , stat[1] : MP       
        if (stat[0] > 50 && stat[1] > 50)
        {
            break;
        }
        else
        {
            cout << "HP or MP is too low. Try again.";
        }
    }
    while(true)
    {
        cout << "Enter Attack and Defense: ";
        cin >> stat[2] >> stat[3]; //stat[2] : Attack , stat[3] : Defense
        if (stat[2] > 50 && stat[3] > 50)
        {
            break;
        }
        else
        {
            cout << "Attack or Defense is too low. Try again." << endl;
        }
    }
    printStatus(heroName, stat);

    //캐릭터 업그레이드
    cout << "* You received 5 HP Potions and 5 MP Potions." << endl;
    cout << "============================================" << endl;
    cout << " < Character Upgrade >" << '\n'
        << "1. HP UP" << '\t'
        << "2. MP UP" << '\t'
        << "3. Attack x2" << '\n'
        << "4. Defense x2" << '\t'
        << "5. Show stats" << '\t'
        << "0. Start Game" << endl;
    cout << "============================================" << endl;
    while (!isGameStart)
    {
        cout << "Choose: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Starting the game!" << endl;
            isGameStart = true;
            break;
        case 1:
            if (HP_Potion <= 0)
            {
                cout << "There are no potions left." << endl;
                break;
            }
            else
            {
                HP_Potion -= 1;
                cout << "* HP increased by 20. (HP Potion used: " << HP_Potion << " Left)" << endl;
                stat[0] += 20;
                break;
            }
        case 2:
            if (MP_Potion <= 0)
            {
                cout << "There are no potions left." << endl;
                break;
            }
            else
            {
                MP_Potion -= 1;
                cout << "* MP increased by 20. (MP Potion used: " << MP_Potion << " Left)" << endl;
                stat[1] += 20;
                break;
            }
        case 3:
            if (Attack_UP <= 0)
            {
                cout << "You already used the chance." << endl;
                break;
            }
            else
            {
                Attack_UP -= 1;
                cout << "* Attack increased by x2. (Attack_UP used: " << Attack_UP << " Left)" << endl;
                stat[2] *= 2;
                break;
            }
        case 4:
            if (Defense_UP <= 0)
            {
                cout << "You already used the chance." << endl;
                break;
            }
            else
            {
                Defense_UP -= 1;
                cout << "* Defense increased by x2. (Defense_UP used: " << Defense_UP << " Left)" << endl;
                stat[3] *= 2;
                break;
            }
        case 5:
            printStatus(heroName, stat);
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

    //직업 선택
    Player* player = nullptr;
    cout << "\n< Job selection >" << endl;
    cout << heroName << ", choose your job!" << endl;
    cout << "1. Warrior   2. Mage   3. Rogue   4. Archer" << endl;
    
    while (player == nullptr)
    {
        cout << "Choose: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            player = new Warrior(heroName, stat[0], stat[1], stat[2], stat[3]);
            cout << "* You became a Warrior! (Defense +30)" << endl;
            cout << "* Swings a greatsword!" << endl;
            break;
        case 2:
            player = new Magician(heroName, stat[0], stat[1], stat[2], stat[3]);
            cout << "* You became a Magician! (MP +30)" << endl;
            cout << "* Fires a fireball!" << endl;
            break;
        case 3:
            player = new Rogue(heroName, stat[0], stat[1], stat[2], stat[3]);
            cout << "* You became a Rogue! (Attack +30)" << endl;
            cout << "* Throws a dagger!" << endl;
            break;
        case 4:
            player = new Archer(heroName, stat[0], stat[1], stat[2], stat[3]);
            cout << "* You became a Archer! (HP +30)" << endl;
            cout << "* Shoots an arrow!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

    player->printPlayerStatus();

    //전투 시작
    Monster slime("[Slime]", 30, 20, 10, "[Slime Jelly]", 50);
    if (!battle(player, slime, inventory)) //전투 패배시 게임 종료
    {
        delete player;
        player = nullptr;
        return 0;
    }

    //포션 샵
    AlchemyWorkshop potionshop;

    //인벤토리
    while (isRunning)
    {
        cout << "\n=== Main Menu ===" << endl;
        cout << "1. Enter Dungeon" << endl;
        cout << "2. Check Inventory" << endl;
        cout << "3. Portion Shop" << endl;
        cout << "0. Quit" << endl;
        cout << "\nChoose: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Exit the Game. GoodBye!" << endl;
            isRunning = false;
            break;
        case 1:
        {
            //던전 입장
            int monsterChoice = rand() % 2;
            if (monsterChoice == 0)
            {
                Monster goblin("[Goblin]", 50, 40, 50, "[Goblin Skin]", 60);
                if (!battle(player, goblin, inventory))
                {
                    isRunning = false;
                }
            }
            else
            {
                Monster ork("[Ork]", 80, 90, 100, "[Ork Hair]", 100);
                if (!battle(player, ork, inventory))
                {
                    isRunning = false;
                }
            }
            break;
        }
        case 2:
            //인벤토리 확인
            cout << "[ Inventory (" << inventory.size() << "/10) ]" << endl;
            if (inventory.empty())
            {
                cout << " (Empty)" << endl;
            }
            else
            {
                int index = 1;
                for (const Item& item : inventory)
                {
                    cout << index++ << ". ";
                    item.PrintInfo();
                }
            }
            break;
        case 3:
            potionshop.Run();
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

    delete player;
    player = nullptr;
	return 0;
}