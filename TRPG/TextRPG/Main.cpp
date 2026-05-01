#include <iostream>
#include <string>

using namespace std;
const int SIZE = 4;

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
        }
    }

	return 0;
}