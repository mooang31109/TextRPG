#include <iostream>
#include <string>

using namespace std;

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
    const int SIZE = 4;
    int stat[SIZE] = { 0 };

    cout << "===========================================" << endl;
    cout << "   [ Dungeon Escape Text RPG ]" << endl;
    cout << "===========================================" << endl;
    cout << "Enter your hero's name: ";
    cin >> heroName;

    cout << "\nEnter HP and MP: ";
    cin >> stat[0] >> stat[1]; //stat[0] : HP , stat[1] : MP

    cout << "Enter Attack and Defense: ";
    cin >> stat[2] >> stat[3]; //stat[2] : Attack , stat[3] : Defense

    printStatus(heroName, stat);
	return 0;
}